/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:15:47 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/18 21:23:53 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		g_size;
/* #include <unistd.h> */

void	insert(int **result, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < g_size)
		{
			result[i][j] = 0;
			k = 0;
			while (str[k] != ' ' && str[k] != '\0')
			{
				result[i][j] = result[i][j] * 10 + (str[k] - '0');
				k++;
			}
			if (str[k] == ' ')
				str += k + 1;
			else
				str += k;
			j++;
		}
		i++;
	}
}

int	**parse_arguments(char *str)
{
	int	**result;
	int	i;

	i = 0;
	result = (int **)malloc(4 * sizeof(int *));
	if (!result)
		return (NULL);
	while (i < 4)
	{
		result[i] = (int *)malloc(g_size * sizeof(int));
		if (!result[i])
			return (NULL);
		i++;
	}
	insert(result, str);
	return (result);
}

// 結果を確認するための簡単なテスト関数
/* int	main(void) */
/* { */
/* 	int	**result; */
/* 	int	i; */
/* 	int	j; */

/* 	char str[] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"; */
/* 	result = parse_arguments(str); */
/* 	if (!result) */
/* 		return (1); */
/* 	i = 0; */
/* 	while (i < 4) */
/* 	{ */
/* 		j = 0; */
/* 		while (j < g_size) */
/* 		{ */
/* 			write(1, &((char[]){result[i][j] + '0'}), 1); */
/* 			if (j < g_size - 1) */
/* 				write(1, " ", 1); */
/* 			j++; */
/* 		} */
/* 		write(1, "\n", 1); */
/* 		i++; */
/* 	} */
/* 	return (0); */
/* } */
