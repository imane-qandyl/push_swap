/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:35:04 by imqandyl          #+#    #+#             */
/*   Updated: 2024/10/11 19:56:23 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_array(int arr[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
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
void handle_operations(int *sorted_array, int n, char **actions, int num_actions) {
    int *stack_a = malloc(n * sizeof(int));
    int *stack_b = malloc(n * sizeof(int));
    int top_a = n - 1;
    int top_b = -1;
    int i = 0;

    while (i < n) {
        stack_a[i] = sorted_array[i];
        i++;
    }

    i = 0;
    while (i < num_actions) {
        if (strcmp(actions[i], "pb") == 0) {
            pb(stack_a, stack_b, &top_a, &top_b);
        } else if (strcmp(actions[i], "pa") == 0) {
            pa(stack_a, stack_b, &top_a, &top_b);
        } else if (strcmp(actions[i], "ra") == 0) {
            ra(stack_a, top_a);
        } else if (strcmp(actions[i], "sa") == 0) {
            sa(stack_a);
        }
        i++;
    }

    free(stack_a);
    free(stack_b);
}
int	main(int argc, char **argv)
{
	int	size;
	int	*array;
	int num_actions;

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
		return (free(array), 0);
	radix_sort(array, size);
	char *actions[] = {"pb", "ra", "pb", "ra", "sa", "ra", "pa", "pa"};
    num_actions = sizeof(actions) / sizeof(actions[0]);
    handle_operations(array, size, actions, num_actions);
	print_array(array, size);
	free(array);
	return (0);
}
