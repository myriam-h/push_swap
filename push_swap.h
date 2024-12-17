/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:20:31 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/17 20:20:31 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					data;
	int					index;
	int					push_cost;
	bool				cheapest_cost;
	bool				above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

void				clean_array(char **argv);
void				prog_exit(bool clean, t_stack_node **sa);
char				**one_arg(char **argv, t_stack_node **sa);
int					ft_atoi(char *str);
void				ft_clean(char **arr, int i);
int					ft_isspace(char c);
int					count_words(const char *str);
char				*malloc_number(const char *str);
char				**ft_split(const char *str);
int					ft_strlen(const char *str);
char				*ft_strjoin(const char *s1, const char *s2);
void				clean_stack(t_stack_node **sa);
t_stack_node		*get_last_node(t_stack_node *sa);
int					add_node(t_stack_node **sa, int num);
void				fill_stack(t_stack_node **sa, char **argv);
int					ft_is_dup(int num, int pos, int *arr);
int					ft_size(char **argv);
int					ft_check(char **argv);
void				sort(t_stack_node **sa, t_stack_node **sb, int numb_nodes);
void				sort_3(t_stack_node **sa);
void				push_swap(t_stack_node **sa, t_stack_node **sb);
void				push_b(t_stack_node **sa, t_stack_node **sb);
void				push(t_stack_node **sa, t_stack_node **sb, int n);
void				reverse_rotate(t_stack_node **stack, int n);
void				rrr(t_stack_node **sa, t_stack_node **sb, int n);
void				reverse_rotate_same_time(t_stack_node **sa,
						t_stack_node **sb,
						t_stack_node *cheapest);
void				swap(t_stack_node **stack, int n);
void				rotate(t_stack_node **stack, int n);
void				rr(t_stack_node **sa, t_stack_node **sb, int n);
void				rotate_same_time(t_stack_node **sa, t_stack_node **sb,
						t_stack_node *cheapest);
void				sa_below_median_cost(t_stack_node *sa, int size_a,
						int size_b);
void				sa_above_median_cost(t_stack_node *sa, int size_b);
void				set_push_cost(t_stack_node *sa, int size_a, int size_b);
t_stack_node		*find_last_node(t_stack_node *stack);
t_stack_node		*find_minimum(t_stack_node *stack);
t_stack_node		*find_maximum(t_stack_node *stack);
int					stack_in_ascend(t_stack_node *sa);
int					stack_size(t_stack_node *sa);
void				special_case(t_stack_node **sa, t_stack_node **sb,
						t_stack_node *cheapest);
t_stack_node		*is_cheapest_node(t_stack_node *sa);
void				transf_a_to_b(t_stack_node **sa, t_stack_node **sb);
void				set_cheapest_cost(t_stack_node *sa);
void				set_target_node_sa(t_stack_node *sa, t_stack_node *sb);
void				set_index(t_stack_node *stack);
void				oper_on_a(t_stack_node *sa, t_stack_node *sb);
void				transf_b_to_a(t_stack_node **sb, t_stack_node **sa);
void				set_target_node_sb(t_stack_node *sa, t_stack_node *sb);
void				oper_on_b(t_stack_node *sa, t_stack_node *sb);
void				top_process(t_stack_node **stack, t_stack_node *node,
						int n);

#endif
