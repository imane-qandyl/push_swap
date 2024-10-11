/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:24:29 by imqandyl          #+#    #+#             */
/*   Updated: 2024/10/11 19:31:09 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_max(int arr[], int n)
{
	int	mx;
	int	i;
	if (n <= 0) return MININT;
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

	if (n <= 0) return MAXINT;
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

void count_sort(int arr[], int n, long long exp)
{
	long long	*output;
	int			count[10];
	int			i;

	output = (long long *)malloc(n * sizeof(long long));
	if (output == NULL)
		return ;
	i = 0; 
	while(i < n)
	{
		 output[i] = 0;
		 i++;
	}
	initialize_count(count, 10);
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
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];//gives the current position in the output array where the number arr[i] shoul go.
        count[(arr[i] / exp) % 10]--;
		i--;
	}
	i = 0;
	while (i < n)
	{
		arr[i] = output[i];
		i++;
	}
	free(output);
}
void radix_sort_positive(int arr[], int n) {
    int m = get_max(arr, n);
    long long exp = 1;

    while (m / exp > 0) {
        count_sort(arr, n, exp);
        exp *= 10;
    }
}

void radix_sort(int arr[], int n) {
    int *neg = malloc(n * sizeof(int));
    int *pos = malloc(n * sizeof(int));
    int neg_count = 0, pos_count = 0;
	if (!neg || !pos) {
        free(neg);
        free(pos);
        return;
    }
    int i = 0;
	int j = 0;
	int has_min_int = 0;
    while (i < n) {
		if (arr[i] == MININT) {
            has_min_int = 1;
		}
        else if (arr[i] < 0)
				neg[neg_count++] = -arr[i];
         else 
            pos[pos_count++] = arr[i];
        i++;
    }

    radix_sort_positive(pos, pos_count);
	radix_sort_positive(neg, neg_count);
    i = 0;
	j = neg_count - 1;
	if (has_min_int) {
        arr[i++] = INT_MIN;
    }
	while (j >= 0) {
        arr[i++] = -neg[j];;
        j--;
    }

	j = 0;
    while (j < pos_count) {
        arr[i++] = pos[j];
        j++;
    }    
    free(neg);
    free(pos);
}