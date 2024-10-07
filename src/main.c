/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:35:04 by imqandyl          #+#    #+#             */
/*   Updated: 2024/10/04 23:06:18 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_array(int arr[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
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

int	main(int argc, char **argv)
{
	int	size;
	int	*array;

	if (argc < 2)
	{
		return (1);
	}
	size = 0;
	array = convert_args_to_int(argc, argv, &size);
	if (!array)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (is_sorted(array, size))
		return (0);
	radix_sort(array, size);
	print_array(array, size);
	free(array);
	return (0);
}
