/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 07:54:32 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/20 16:33:55 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	g_size;

// 上からみたときの箱の数がargv_colと一致しているか確認
// board: g_size * g_sizeの配列: ex [[1,2,3,4],[2,3,4,1],[3,4,1,2],[4,1,2,3]
// argv_col: g_sizeの配列: ex. [1, 2, 3, 4]
// return: 一致していれば1, 一致していなければ0
int	check_from_top(int **board, int *argv_col)
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
		if (visible_box_num != argv_col[col])
			return (0);
		col++;
	}
	return (1);
}

int	check_from_bottom(int **board, int *argv_col)
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
		if (visible_box_num != argv_col[col])
			return (0);
		col++;
	}
	return (1);
}

int	check_from_left(int **board, int *argv_row)
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
		if (visible_box_num != argv_row[row])
			return (0);
		row++;
	}
	return (1);
}

int	check_from_right(int **board, int *argv_row)
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
		if (visible_box_num != argv_row[row])
			return (0);
		row++;
	}
	return (1);
}

// 上下左右から見たときの箱の数がargvと一致しているか確認
// board: g_size * g_sizeの配列: ex [[1,2,3,4],[2,3,4,1],[3,4,1,2],[4,1,2,3]]
// argv: parse_argした4*g_sizeの配列
// return: 一致していれば1, 一致していなければ0
int	is_correct_box(int **board, int **argv)
{
	if (!check_from_top(board, argv[0]))
		return (0);
	if (!check_from_bottom(board, argv[1]))
		return (0);
	if (!check_from_left(board, argv[2]))
		return (0);
	if (!check_from_right(board, argv[3]))
		return (0);
	return (1);
}
