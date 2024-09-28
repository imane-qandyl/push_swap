/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:42:48 by imqandyl          #+#    #+#             */
/*   Updated: 2024/09/28 16:42:49 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getmax(int arr[], int n)
{
	int	mx;
	int	i;

	mx = arr[0];
	i = 1;
	while (i < n)
	{
		if (arr[i] > mx)
		{
			mx = arr[i];
		}
		i++;
	}
	return (mx);
}

void	countsort(int arr[], int n, int exp)
{
	int	output[n];
	int	count[10] = {0};
	int	i;

	i = 0;
	while (i < n)
	{
		count[(arr[i] / exp) % 10]++;
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
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
		i--;
	}
	i = 0;
	while (i < n)
	{
		arr[i] = output[i];
		i++;
	}
}

void	radixsort(int arr[], int n)
{
	int	positive[n];
	int	negative[n];
	int	pos_count;
	int	neg_count;
	int	i;
	int	m;
	int	exp;
	int	index;

	pos_count = 0;
	neg_count = 0;
	i = 0;
	while (i < n)
	{
		if (arr[i] < 0)
		{
			negative[neg_count++] = -arr[i];
		}
		else
		{
			positive[pos_count++] = arr[i];
		}
		i++;
	}
	if (pos_count > 0)
	{
		m = getmax(positive, pos_count);
		exp = 1;
		while (m / exp > 0)
		{
			countsort(positive, pos_count, exp);
			exp *= 10;
		}
	}
	if (neg_count > 0)
	{
		m = getmax(negative, neg_count);
		exp = 1;
		while (m / exp > 0)
		{
			countsort(negative, neg_count, exp);
			exp *= 10;
		}
	}
	index = 0;
	while (neg_count > 0)
	{
		arr[index++] = -negative[--neg_count];
	}
	i = 0;
	while (i < pos_count)
	{
		arr[index++] = positive[i++];
	}
}

void	printarray(int arr[], int n)
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
