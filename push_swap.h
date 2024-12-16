#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct stack_node
{
    int data;
    int index;
    int push_cost;
    bool cheapest_cost;
    bool above_median;
    struct stack_node *target_node;
    struct stack_node *next;
    struct stack_node *prev;
}   stack_node;

// main.c
void clean_array(char **argv);
void prog_exit(bool clean, stack_node **sa);
char **one_arg(char **argv, stack_node **sa);

// libraries
//ft_atoi.c :
int ft_atoi(char *str);
//ft_split.c
void ft_clean(char **arr, int i);
int ft_isspace(char c);
int count_words(const char *str);
char *malloc_number(const char *str);
char **ft_split(const char *str);
//ft_strjoin.c
int ft_strlen(const char *str);
char *ft_strjoin(const char *s1, const char *s2);

// filling_stack
//fill_stack.c
void clean_stack(stack_node **sa);
stack_node *get_last_node(stack_node *sa);
int add_node(stack_node **sa, int num);
void fill_stack(stack_node **sa, char **argv);
//ft_check.c
int ft_is_dup(int num, int pos, int *arr);
int ft_size(char **argv);
int ft_check(char **argv);

// algorithm
//push_swap.c
void sort(stack_node **sa, stack_node **sb, int numb_nodes);
void sort_3(stack_node **sa);
void push_swap(stack_node **sa, stack_node **sb);
//reverse_rotate_push.c
void push_b(stack_node **sa, stack_node **sb);
void push(stack_node **sa, stack_node **sb, int n);
void reverse_rotate(stack_node **stack, int n);
void rrr(stack_node **sa, stack_node **sb, int n);
void reverse_rotate_same_time(stack_node **sa, stack_node **sb, stack_node *cheapest);
//rotate_swap.c
void swap(stack_node **stack, int n);
void rotate(stack_node **stack, int n);
void rr(stack_node **sa, stack_node **sb, int n);
void rotate_same_time(stack_node **sa, stack_node **sb, stack_node *cheapest);
//sa_push_cost.c
void sa_below_median_cost(stack_node *sa, int size_a, int size_b);
void sa_above_median_cost(stack_node *sa, int size_b);
void set_push_cost(stack_node *sa, int size_a, int size_b);
//sorting.c
stack_node *find_last_node(stack_node *stack);
stack_node *find_minimum(stack_node *stack);
stack_node *find_maximum(stack_node *stack);
int stack_in_ascend(stack_node *sa);
int stack_size(stack_node *sa);
//stack_a_suite.c
void special_case(stack_node **sa, stack_node **sb, stack_node *cheapest);
stack_node *is_cheapest_node(stack_node *sa);
void transf_a_to_b(stack_node **sa, stack_node **sb);
//stack_a.c
void set_cheapest_cost(stack_node *sa);
void set_target_node_sa(stack_node *sa, stack_node *sb);
void set_index(stack_node *stack);
void oper_on_a(stack_node *sa, stack_node *sb);
//stack_b.c
void transf_b_to_a(stack_node **sb, stack_node **sa);
void set_target_node_sb(stack_node *sa, stack_node *sb);
void oper_on_b(stack_node *sa, stack_node *sb);
//top_process.c
void top_process(stack_node **stack, stack_node *node, int n);

#endif