/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:38:30 by imqandyl          #+#    #+#             */
/*   Updated: 2024/09/29 10:00:17 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_SIZE 100 // Define a maximum size for the stacks
#define MAXINT 2147483647
#define MININT -2147483648

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*array;
	int	size;
}		t_stack;

int		getmax(int arr[], int n);
void	countsort(int arr[], int n, int exp);
void	radix_sort(int arr[], int n);
void	printarray(int arr[], int n);
int		*convert_args_to_int(int argc, char **argv, int *size);
int		count_numbers_in_args(int argc, char **argv);
void	ft_error(void);
int		has_duplicates(int *array, int size);
int		is_empty_or_space(const char *str);
int	is_sorted(int *arr, int size);

#endif
