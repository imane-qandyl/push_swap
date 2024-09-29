/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:14:42 by imqandyl          #+#    #+#             */
/*   Updated: 2024/09/29 19:51:29 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
void	free_tokens(char **tokens)
{
	int	j;

	j = 0;
	while (tokens[j])
	{
		free(tokens[j]);
		j++;
	}
	free(tokens);
}
int	is_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_safe_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		num = num * 10 + (*str - '0');
		if ((num * sign) > MAXINT || (num * sign) < MININT)
			ft_error();
		str++;
	}
	return ((int)(num * sign));
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
			ft_error();
		j = 0;
		while (tokens[j])
		{
			if (ft_strlen(tokens[j]) == 0 || is_empty_or_space(tokens[j]))
			{
				free_tokens(tokens);
				ft_error();
			}
			if (!ft_isdigit(tokens[j][0]) && !(tokens[j][0] == '-'
					&& ft_isdigit(tokens[j][1])) && !(tokens[j][0] == '+'
					&& ft_isdigit(tokens[j][1])))
			{
				free_tokens(tokens);
				ft_error();
			}
			count++;
			j++;
		}
		free_tokens(tokens);
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
	if (count == 0)
		exit(0);
	arr = malloc(count * sizeof(int));
	if (!arr)
		ft_error();
	index = 0;
	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
		{
			free(arr);
			ft_error();
		}
		j = 0;
		while (tokens[j])
		{
			arr[index++] = ft_safe_atoi(tokens[j]);
			j++;
		}
		free_tokens(tokens);
		i++;
	}
	*size = count;
	if (has_duplicates(arr, count))
		ft_error();
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