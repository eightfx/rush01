/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:08:28 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/20 18:43:30 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

// length of the board
int	g_size = 4;

int	**parse_arguments(char *str);
int	solve_board(int **board, int row, int col, int **building_views);

// Allocate a 2-dimensional array of g_size*g_size and initialize it with 0
// A value of 0 indicates that no box has been placed
// args:
//     None
// return:
//     2-dimensional array (g_size*g_size)
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

int	main(int argc, char *argv[])
{
	int	**view_args;
	int	**board;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	view_args = parse_arguments(argv[1]);
	if (argc > 2 || view_args == NULL)
	{
		write(1, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	board = initialize_board();
	if (!solve_board(board, 0, 0, view_args))
	{
		write(1, "Error\n", 6);
	}
	return (EXIT_SUCCESS);
}
