/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:14:25 by imqandyl          #+#    #+#             */
/*   Updated: 2024/09/28 16:36:07 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	size;
	int	*arr;
	int	i;

	i = 0;
	if (argc < 2)
	{
		ft_error();
		return (1);
	}
	arr = convert_args_to_unique_int(argc, argv, &size);
	if (!arr)
	{
		return (1);
	}
	radixsort(arr, size);
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return (0);
}
