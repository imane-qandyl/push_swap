/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:14:42 by imqandyl          #+#    #+#             */
/*   Updated: 2024/09/29 10:47:59 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	const char	*error_msg;
	const char	*ptr;

	error_msg = "Error\n";
	ptr = error_msg;
	while (*ptr)
	{
		write(1, ptr++, 1);
	}
	exit(1);
}

int	count_numbers_in_args(int argc, char **argv)
{
	int		count;
	int		i;
	char	**tokens;
	int		j;

	count = 0;
	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			ft_error(); // Ensure split allocation was successful
		j = 0;
		while (tokens[j])
		{
			if (ft_strlen(tokens[j]) == 0 || is_empty_or_space(tokens[j]))
			{
				free(tokens);
				ft_error();
			}
			if (!ft_isdigit(tokens[j][0]) && !(tokens[j][0] == '-'
					&& ft_isdigit(tokens[j][1])) && !(tokens[j][0] == '+'
					&& ft_isdigit(tokens[j][1])))
			{
				free(tokens);
				ft_error();
			}
			count++;
			j++;
		}
		free(tokens);
		i++;
	}
	return (count);
}

int	*convert_args_to_int(int argc, char **argv, int *size)
{
	int		count;
	int		*arr;
	int		index;
	int		i;
	char	**tokens;
	int		j;

	count = count_numbers_in_args(argc, argv);
	arr = malloc(count * sizeof(int));
	if (!arr)
		return (NULL);
	index = 0;
	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
		{
			free(arr);
			return (NULL);
		}
		j = 0;
		while (tokens[j])
		{
			if (ft_strlen(tokens[j]) == 0)
			{
				free(tokens);
				free(arr);
				ft_error();
			}
			arr[index++] = ft_atoi(tokens[j]);
			j++;
		}
		free(tokens);
		i++;
	}
	*size = count;
	return (arr);
}

int	has_duplicates(int *array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] == array[j])
			{
				return (1);
			}
		}
	}
	return (0);
}

int	is_empty_or_space(const char *c)
{
	while (*c)
	{
		if (!(*c == ' ' || *c == '\t' || *c == '\n' || *c == '\v' || *c == '\f'
				|| *c == '\r'))
		{
			return (0);
		}
		c++;
	}
	return (1);
}