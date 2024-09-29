/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:14:25 by imqandyl          #+#    #+#             */
/*   Updated: 2024/09/28 19:20:12 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	size;
	int	*arr;

	i = 1;
	while (i < argc)
	{
		if (is_empty_or_space(argv[i]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	arr = convert_args_to_int(argc, argv, &size);
	if (!arr)
	{
		return (1);
	}
	if (has_duplicates(arr, size))
	{
		write(2, "Error\n", 6);
		free(arr);
		return (1);
	}
	radix_sort(arr, size);
	printarray(arr, size);
	free(arr);
	return (0);
}
