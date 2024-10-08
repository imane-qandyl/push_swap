/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:14:42 by imqandyl          #+#    #+#             */
/*   Updated: 2024/10/04 22:58:08 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_safe_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > MAXINT || result * sign < MININT)
		{
			ft_error();
		}
		i++;
	}
	return ((int)(result * sign));
}

int	is_digit_string(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error();
		i++;
	}
	return (1);
}

int	has_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*convert_args_to_int(int argc, char **argv, int *size)
{
	int	count;
	int	i;
	int	*arr;
	int	index;

	count = 0;
	i = 1;
	while (i < argc)
	{
		if (is_digit_string(argv[i]))
			count++;
		else
			ft_error();
		i++;
	}
	arr = malloc(count * sizeof(int));
	if (!arr)
		ft_error();
	index = 0;
	i = 1;
	while (i < argc)
	{
		if (is_digit_string(argv[i]))
			arr[index++] = ft_safe_atoi(argv[i]);
		i++;
	}
	if (has_duplicates(arr, count))
		ft_error();
	*size = count;
	return (arr);
}
