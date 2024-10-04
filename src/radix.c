/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:24:29 by imqandyl          #+#    #+#             */
/*   Updated: 2024/10/04 22:05:04 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_max(int arr[], int n)
{
	int	mx;
	int	i;

	mx = arr[0];
	i = 1;
	while (i < n)
	{
		if (arr[i] > mx)
			mx = arr[i];
		i++;
	}
	return (mx);
}

int	get_min(int arr[], int n)
{
	int	mn;
	int	i;

	mn = arr[0];
	i = 1;
	while (i < n)
	{
		if (arr[i] < mn)
			mn = arr[i];
		i++;
	}
	return (mn);
}

void	initialize_count(int *count, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		count[i] = 0;
		i++;
	}
}

void	count_sort(int arr[], int n, int exp, int min_val)
{
	int	*output;
	int	count[10];
	int	i;

	output = (int *)malloc(n * sizeof(int));
	if (output == NULL)
		return ;
	initialize_count(count, 10);
	i = 0;
	while (i++ < n)
		count[(arr[i - 1] - min_val) / exp % 10]++;
	i = 1;
	while (i++ < 10)
		count[i - 1] += count[i - 2];
	i = n;
	while (--i >= 0)
	{
		output[count[(arr[i] - min_val) / exp % 10] - 1] = arr[i];
		count[(arr[i] - min_val) / exp % 10]--;
	}
	i = 0;
	while (i++ < n)
		arr[i] = output[i];
	free(output);
}

void	radix_sort(int arr[], int n)
{
	int	max_val;
	int	min_val;
	int	exp;

	max_val = get_max(arr, n);
	min_val = get_min(arr, n);
	exp = 1;
	while ((max_val - min_val) / exp > 0)
	{
		count_sort(arr, n, exp, min_val);
		exp *= 10;
	}
}
