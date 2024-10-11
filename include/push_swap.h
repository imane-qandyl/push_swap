/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:25:27 by imqandyl          #+#    #+#             */
/*   Updated: 2024/10/11 19:55:27 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_SIZE 100
# define MAXINT 2147483647
# define MININT -2147483648

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*data;
	int	top;
	int	size;
}		t_stack;

int				get_max(int arr[], int n);
void			count_sort(int arr[], int n, long long exp);
void			radix_sort(int arr[], int n);
void 			radix_sort_positive(int arr[], int n);
void			print_array(int arr[], int n);
void			ft_error(void);
int				is_digit_string(char *str);
long long int	ft_safe_atoi(const char *str);
int				*convert_args_to_int(int argc, char **argv, int *size);
void 			handle_operations(int *sorted_array, int n, char **actions, int num_actions);
int				has_duplicates(int *array, int size);
void			initialize_count(int *count, int size);
int				is_sorted(int *arr, int size);
void 			pa(int *stack_a, int *stack_b, int *top_a, int *top_b);
void 			pb(int *stack_a, int *stack_b, int *top_a, int *top_b);
void 			ra(int *stack_a, int top_a);
void 			sa(int *stack_a);

#endif