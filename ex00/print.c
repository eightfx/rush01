/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:08:49 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/20 17:04:04 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		g_size;

// int数値をcharに変換して標準出力する
// args:
//     num: 変換する数値
// return:
//     なし
void	write_num(int num)
{
	char	c;

	c = '0' + num;
	write(1, &c, 1);
}

// 盤面を標準出力する
// args:
//     board: 盤面(g_size*g_sizeの２次元配列)
// return:
//     なし
// example:
//     1 2 3 4
//     2 3 4 1
//     3 4 1 2
//     4 1 2 3と標準出力する
void	print_board(int **board)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			write_num(board[i][j]);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
