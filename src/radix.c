/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:24:29 by imqandyl          #+#    #+#             */
/*   Updated: 2024/10/04 20:29:15 by imqandyl         ###   ########.fr       */
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

void	count_sort(int arr[], int n, int exp, int min_val)
{
	int	output[n];
	int	count[10];
	int	i;
	int	index;
	int	index;

	count[10] = {0};
	i = 0;
	while (i < n)
	{
		index = (arr[i] - min_val) / exp % 10;
		count[index]++;
		i++;
	}
	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}
	i = n - 1;
	while (i >= 0)
	{
		index = (arr[i] - min_val) / exp % 10;
		output[count[index] - 1] = arr[i];
		count[index]--;
		i--;
	}
	i = 0;
	while (i < n)
	{
		arr[i] = output[i];
		i++;
	}
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
