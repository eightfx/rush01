#include <unistd.h>

int		g_size;

void	write_num(int num)
{
	char	c;

	c = '0' + num;
	write(1, &c, 1);
}

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
