/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:09:24 by imqandyl          #+#    #+#             */
/*   Updated: 2024/10/11 19:56:55 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void pb(int *stack_a, int *stack_b, int *top_a, int *top_b) {
    if (*top_a >= 0) {
        stack_b[++(*top_b)] = stack_a[(*top_a)--];
        printf("pb\n");
    }
}

void pa(int *stack_a, int *stack_b, int *top_a, int *top_b) {
    if (*top_b >= 0) {
        stack_a[++(*top_a)] = stack_b[(*top_b)--];
        printf("pa\n");
    }
}

void ra(int *stack_a, int top_a) {
    if (top_a > 0) {
        int temp = stack_a[0];
        int i = 0;
        while (i < top_a) {
            stack_a[i] = stack_a[i + 1];
            i++;
        }
        stack_a[top_a] = temp;
        printf("ra\n");
    }
}

void sa(int *stack_a) {
    if (stack_a[0] != stack_a[1]) {
        int temp = stack_a[0];
        stack_a[0] = stack_a[1];
        stack_a[1] = temp;
        printf("sa\n");
    }
}