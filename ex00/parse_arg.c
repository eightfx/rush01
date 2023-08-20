/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:15:47 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/20 16:50:19 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		g_size;

// strを4*g_sizeの２次元配列resultに代入する
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

// 引数の文字列を4*g_sizeの２次元配列に変換する
// example:
// str: "1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5"
// result:
// [[1,2,3,4,5], // top
// [1,2,3,4,5, ... , g_size], // bottom
// [1,2,3,4,5], // left
// [1,2,3,4,5]] // right
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
