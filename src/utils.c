/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:14:42 by imqandyl          #+#    #+#             */
/*   Updated: 2024/09/28 16:37:03 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(const char *str)
{
	if (str)
	{
		while (*str)
		{
			write(1, str++, 1);
		}
	}
}

void	ft_error(void)
{
	ft_putstr(ERROR_MESSAGE);
	exit(1);
}

int	count_numbers_in_args(int argc, char **argv)
{
	int		count;
	int		i;
	char	**tokens;
	int		j;
	char	**subtokens;
	int		k;

	count = 0;
	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		j = 0;
		while (tokens[j])
		{
			subtokens = ft_split(tokens[j], ',');
			k = 0;
			while (subtokens[k])
			{
				if (!ft_isdigit(subtokens[k][0]) && subtokens[k][0] != '-'
					&& subtokens[k][0] != '+')
				{
					free(tokens);
					free(subtokens);
					ft_error();
				}
				count++;
				free(subtokens[k]);
				k++;
			}
			free(subtokens);
			free(tokens[j]);
			j++;
		}
		free(tokens);
		i++;
	}
	return (count);
}

int	*convert_args_to_unique_int(int argc, char **argv, int *size)
{
	int		count;
	int		*arr;
	int		index;
	int		i;
	char	**tokens;
	int		j;
	char	**subtokens;
	int		k;
	int		num;
	int		is_unique;
	int		l;

	count = count_numbers_in_args(argc, argv);
	arr = malloc(count * sizeof(int));
	if (!arr)
		return (NULL);
	index = 0;
	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		j = 0;
		while (tokens[j])
		{
			subtokens = ft_split(tokens[j], ',');
			k = 0;
			while (subtokens[k])
			{
				num = ft_atoi(subtokens[k]);
				is_unique = 1;
				l = 0;
				while (l < index)
				{
					if (arr[l] == num)
					{
						is_unique = 0;
						break ;
					}
					l++;
				}
				if (is_unique)
				{
					arr[index++] = num;
				}
				free(subtokens[k]);
				k++;
			}
			free(subtokens);
			free(tokens[j]);
			j++;
		}
		free(tokens);
		i++;
	}
	*size = index;
	return (arr);
}
