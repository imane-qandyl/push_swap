/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:42:48 by imqandyl          #+#    #+#             */
/*   Updated: 2024/09/28 19:05:54 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int getmax(int arr[], int n) {
    int mx = arr[0];
    int i = 1;
    while (i < n) {
        if (arr[i] > mx)
            mx = arr[i];
        i++;
    }
    return mx;
}

void countsort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    int i = 0;

    while (i < n) {
        count[(arr[i] / exp) % 10]++;
        i++;
    }

    i = 1;
    while (i < 10) {
        count[i] += count[i - 1];
        i++;
    }

    i = n - 1;
    while (i >= 0) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        i--;
    }

    i = 0;
    while (i < n) {
        arr[i] = output[i];
        i++;
    }
}

void radix_sort(int arr[], int n) {
    int positive[n], negative[n];
    int pos_count = 0, neg_count = 0;
    int i = 0;

    while (i < n) {
        if (arr[i] < 0) {
            negative[neg_count++] = -arr[i];
        } else {
            positive[pos_count++] = arr[i];
        }
        i++;
    }

    if (pos_count > 0) {
        countsort(positive, pos_count, 1);
    }

    if (neg_count > 0) {
        countsort(negative, neg_count, 1);
    }

    int index = 0;
    i = neg_count - 1;
    while (i >= 0) {
        arr[index++] = -negative[i];
        i--;
    }

    i = 0;
    while (i < pos_count) {
        arr[index++] = positive[i];
        i++;
    }
}

void printarray(int arr[], int n) {
    int i = 0;
    while (i < n) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}
