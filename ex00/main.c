/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:08:28 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/19 19:24:22 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		g_size = 4;

int		**parse_arguments(char *str);
int		is_correct_box(int **board, int **argv);
void	print_board(int **board);

int	**initialize_board(void)
{
	int	**board;
	int	i;
	int	j;

	board = (int **)malloc(g_size * sizeof(int *));
	i = 0;
	while (i < g_size)
	{
		board[i] = (int *)malloc(g_size * sizeof(int));
		j = 0;
		while (j < g_size)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (board);
}

// (row,col)の座標にnumを配置した場合、重複する数字がないか確認
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

int	solve_board(int **board, int row, int col, int **argv)
{
	int	next_row;
	int	num;
	int	next_col;

	if (row == g_size)
	{
		if (is_correct_box(board, argv))
		{
			print_board(board);
			return (1);
		}
		return (0);
	}
	next_position(row, col, &next_row, &next_col);
	if (board[row][col] != 0)
	{
		return (solve_board(board, next_row, next_col, argv));
	}
	num = 1;
	while (num <= g_size)
	{
		if (!is_duplicate(board, row, col, num))
		{
			board[row][col] = num;
			if (solve_board(board, next_row, next_col, argv))
				return (1);
			board[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	**view_args;
	int	**board;
	int	i;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <view_string>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	view_args = parse_arguments(argv[1]);
	if (view_args == NULL)
	{
		fprintf(stderr, "Invalid view string\n");
		return (EXIT_FAILURE);
	}
	board = initialize_board();
	if (board == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		return (EXIT_FAILURE);
	}
	if (!solve_board(board, 0, 0, view_args))
	{
		printf("No solution found\n");
	}
	i = 0;
	while (i < g_size)
	{
		free(board[i]);
		free(view_args[i]);
		i++;
	}
	free(board);
	free(view_args);
	return (EXIT_SUCCESS);
}
