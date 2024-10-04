/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:25:27 by imqandyl          #+#    #+#             */
/*   Updated: 2024/10/04 21:38:33 by imqandyl         ###   ########.fr       */
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

int		get_max(int arr[], int n);
void	count_sort(int arr[], int n, int exp, int min_val);
void	radix_sort(int arr[], int n);
void	print_array(int arr[], int n);
void	ft_error(void);
int		is_digit_string(char *str);
int		ft_safe_atoi(const char *str);
int		*convert_args_to_int(int argc, char **argv, int *size);
int		has_duplicates(int *array, int size);
void	initialize_count(int *count, int size);

#endif