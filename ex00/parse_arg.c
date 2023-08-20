/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eokoshi <eokoshi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:15:47 by eokoshi           #+#    #+#             */
/*   Updated: 2023/08/20 19:41:52 by eokoshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		g_size;

// Assign str to a 2-dimensional array of 4*g_size
// args:
//     result: 2-dimensional array (4*g_size)
//     str: command line argument string
// return:
//     None
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

// Count the number of numbers in the argument string
// args:
//     str: command line argument string
// return:
//     number of numbers
int	count_num(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			count++;
			while (str[i + 1] != '\0' && str[i + 1] != ' ')
				i++;
		}
		i++;
	}
	return (count);
}

// Convert the argument string to a 2-dimensional array of size 4*g_size
// args:
//     str: command line argument string
// return:
//    2-dimensional array (4*g_size)
// example:
//     str: "1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5"
//     result:
//     [[1,2,3,4,5], // top
//    [1,2,3,4,5, ... , g_size], // bottom
//    [1,2,3,4,5], // left
//   [1,2,3,4,5]] // right
int	**parse_arguments(char *str)
{
	int	**result;
	int	i;

	if (count_num(str) != g_size * 4)
		return (NULL);
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
