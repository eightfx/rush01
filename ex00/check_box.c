/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 07:54:32 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/20 18:49:16 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	g_size;

// Check that the number of boxes when viewed
// from the top matches view_constraints
// args:
//    board: 2-dimensional array of g_size
// * g_size : ex [[1,2,3,4],[2,3,4,1],[3,4,1,2],[4,1,2,3]
//    view_constraints: array: ex. [1, 2, 3, 4]
// return: 1 if they match, 0 if they don't match
int	check_from_top(int **board, int *view_constraints)
{
	int	col;
	int	row;
	int	visible_box_num;
	int	max_height;

	col = 0;
	while (col < g_size)
	{
		visible_box_num = 0;
		max_height = 0;
		row = 0;
		while (row < g_size)
		{
			if (board[row][col] > max_height)
			{
				max_height = board[row][col];
				visible_box_num++;
			}
			row++;
		}
		if (visible_box_num != view_constraints[col])
			return (0);
		col++;
	}
	return (1);
}

int	check_from_bottom(int **board, int *view_constraints)
{
	int	col;
	int	row;
	int	visible_box_num;
	int	max_height;

	col = 0;
	while (col < g_size)
	{
		visible_box_num = 0;
		max_height = 0;
		row = g_size - 1;
		while (row >= 0)
		{
			if (board[row][col] > max_height)
			{
				max_height = board[row][col];
				visible_box_num++;
			}
			row--;
		}
		if (visible_box_num != view_constraints[col])
			return (0);
		col++;
	}
	return (1);
}

int	check_from_left(int **board, int *view_constraints)
{
	int	col;
	int	row;
	int	visible_box_num;
	int	max_height;

	row = 0;
	while (row < g_size)
	{
		visible_box_num = 0;
		max_height = 0;
		col = 0;
		while (col < g_size)
		{
			if (board[row][col] > max_height)
			{
				max_height = board[row][col];
				visible_box_num++;
			}
			col++;
		}
		if (visible_box_num != view_constraints[row])
			return (0);
		row++;
	}
	return (1);
}

int	check_from_right(int **board, int *view_constraints)
{
	int	col;
	int	row;
	int	visible_box_num;
	int	max_height;

	row = 0;
	while (row < g_size)
	{
		visible_box_num = 0;
		max_height = 0;
		col = g_size - 1;
		while (col >= 0)
		{
			if (board[row][col] > max_height)
			{
				max_height = board[row][col];
				visible_box_num++;
			}
			col--;
		}
		if (visible_box_num != view_constraints[row])
			return (0);
		row++;
	}
	return (1);
}

// Check that the number of boxes viewed from the top, bottom, left,
// and right matches building_views
// args:
//     board: 2-dimentional array of
//         g_size* g_size: ex [[1,2,3,4],[2,3,4,1],[3,4,1,2],[4,1,2,3]]
//     building_views: array of 4 * g_size with parse_arg
// return: 1 if a match is found, 0 if not
int	is_correct_box(int **board, int **building_views)
{
	if (!check_from_top(board, building_views[0]))
		return (0);
	if (!check_from_bottom(board, building_views[1]))
		return (0);
	if (!check_from_left(board, building_views[2]))
		return (0);
	if (!check_from_right(board, building_views[3]))
		return (0);
	return (1);
}
