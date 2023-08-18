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

int	solve_board(int **board, int row, int col, int **argv)
{
	int	next_row;
	int	num;
	int	next_col;

	// 全てのセルに箱が配置された場合
	if (row == g_size)
	{
		// is_correct_boxで盤面が正しいか確認
		if (is_correct_box(board, argv))
		{
			print_board(board); // 解の盤面を印刷
			return (1);         // 解が見つかった
		}
		return (0); // 解が見つからなかった
	}
	next_row = row;
	next_col = col + 1;
	if (next_col == g_size)
	{
		next_row++;
		next_col = 0;
	}
	// 現在のセルに箱が既に配置されている場合（値が0でない場合）、次のセルに進む
	if (board[row][col] != 0)
	{
		return (solve_board(board, next_row, next_col, argv));
	}
	// 現在のセルに1からg_sizeまでの各値を試す
	num = 1;
	while (num <= g_size)
	{
		if (!is_duplicate(board, row, col, num))
		{
			board[row][col] = num; // 重複がない場合、値を配置
			if (solve_board(board, next_row, next_col, argv))
			{
				return (1); // 次のセルで解が見つかった場合
			}
			board[row][col] = 0; // 解が見つからなかった場合、値をリセットして次の値を試す
		}
		num++;
	}
	return (0); // このセルで解が見つからなかった場合
}

int	main(int argc, char *argv[])
{
	int	**view_args;
	int	**board;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <view_string>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	// 引数の解析
	view_args = parse_arguments(argv[1]);
	if (view_args == NULL)
	{
		fprintf(stderr, "Invalid view string\n");
		return (EXIT_FAILURE);
	}
	// 盤面の初期化
	board = initialize_board();
	if (board == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		return (EXIT_FAILURE);
	}
	// 解の探索
	if (!solve_board(board, 0, 0, view_args))
	{
		printf("No solution found\n");
	}
	// メモリの解放
	for (int i = 0; i < g_size; i++)
	{
		free(board[i]);
		free(view_args[i]);
	}
	free(board);
	free(view_args);
	return (EXIT_SUCCESS);
}
