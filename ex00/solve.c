/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:08:28 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/20 18:48:33 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_size;
int		**parse_arguments(char *str);
int		is_correct_box(int **board, int **building_views);
void	print_board(int **board);

int		solve_board(int **board, int row, int col, int **building_views);
int		process_cell(int **board, int row, int col, int **building_views);

// Check for duplicates at top, bottom, left, and right
// args:
//     board: 2-dimentional array of g_size*g_size
//     row: current row
//     col: current column
//     num: Height of the box to be placed in (row, column)
// return:
//     1 if there is a duplicate
//     0 if there is no duplicate
int	is_duplicate(int **board, int row, int col, int num)
{
	int	c;
	int	r;

	c = 0;
	while (c < g_size)
	{
		if (board[row][c] == num && c != col)
		{
			return (1);
		}
		c++;
	}
	r = 0;
	while (r < g_size)
	{
		if (board[r][col] == num && r != row)
		{
			return (1);
		}
		r++;
	}
	return (0);
}

// calculate the next position to place
// args:
//     row: current row
//     col: current column
//     next_row: next row
//     next_col: next column
// return:
//     0: success
int	next_position(int row, int col, int *next_row, int *next_col)
{
	*next_row = row;
	*next_col = col + 1;
	if (*next_col == g_size)
	{
		(*next_row)++;
		*next_col = 0;
	}
	return (0);
}

// Check the board for correct placement.
// args:
//     board: 2-dimentional array of g_size*g_size
//     building_views: Number of boxes visible from the top, bottom,
//         left and right ( 2-dimensional array of g_size*4)
//     row: current row
// result:
//     1: correct
//     0: incorrect
//     -1: not finished
int	is_finish(int **board, int **building_views, int row)
{
	if (row == g_size)
	{
		if (is_correct_box(board, building_views))
		{
			print_board(board);
			return (1);
		}
		return (0);
	}
	return (-1);
}

// Backtracking to solve the board
// args:
//     board: 2-dimentional array of g_size*g_size
//     row: current row
//     col: current column
//     building_views: Number of boxes visible from the top, bottom,
//         left and right ( 2-dimensional array of g_size*4)
// return:
//     1: correct
//     0: incorrect
// note:
// 1. place the number at the current position
// 2. move to the next position
// 3. check for duplicate numbers
// If no duplicates, move to next position
// If there is a duplicate, go back one recurrence up
int	solve_board(int **board, int row, int col, int **building_views)
{
	int	next_row;
	int	num;
	int	next_col;
	int	finish_flag;

	finish_flag = is_finish(board, building_views, row);
	if (finish_flag != -1)
		return (finish_flag);
	next_position(row, col, &next_row, &next_col);
	if (board[row][col] != 0)
		return (solve_board(board, next_row, next_col, building_views));
	num = 1;
	while (num <= g_size)
	{
		if (!is_duplicate(board, row, col, num))
		{
			board[row][col] = num;
			if (solve_board(board, next_row, next_col, building_views))
				return (1);
			board[row][col] = 0;
		}
		num++;
	}
	return (0);
}
