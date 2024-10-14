/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:25:27 by imqandyl          #+#    #+#             */
/*   Updated: 2024/10/14 01:46:08 by imqandyl         ###   ########.fr       */
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

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *s);
void		sort_four_to_five_elements(t_stacks *s);
void		radix_sort(t_stacks *s);
void		parse_args(t_stacks *s);
void		create_index(t_stacks *s);
void		initialize_stacks(int argc, char **argv, t_stacks *s);
void		free_and_exit(t_stacks *s, char *msg);
void		exit_if_sorted_or_has_duplicate(t_stacks *s, int i);
int			is_sorted(t_stacks *s);
int			ft_atol(const char *str, t_stacks *s);
int			ft_count_words(char const *s, char c);

#endif