/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:20:43 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/14 17:40:51 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h> //malloc & NULL
#include <unistd.h>
#include <stdio.h> //remove this at some point
#include <limits.h>

//change s_stack_list
//change alias to t_list
//suffer
typedef struct stack_list {
	int data;
	int pos;
	int rank;
	struct stack_list *target;
	int	cost_a;
	int	cost_b;
	int	total_cost;
	struct stack_list *next;
} s_list;

//new list fn, not from libft
void	ft_listadd_back(s_list **lst, s_list *new);
int		ft_listsize(s_list *lst);
s_list	*ft_listnew(int data); //new list fn with content type int
void    free_all_stack(s_list   **stack);

//own library
int	to_num(const char *str, int *over_check);
int	ft_isdigit(int c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

//error fns ps_error
int arg_is_num(char *argv);
int arg_is_dup(s_list *stack, int data);
int arg_overflow(char **argv);
int	is_it_space(char *argv);
void    err_ret();
void	free_split_args(char **split_args);

int	is_list_sorted(s_list **stack_a);

//operations
void	ps_pa(s_list **stack_a, s_list **stack_b);
void	ps_pb(s_list **stack_a, s_list **stack_b);
void    ps_swap(s_list **stack);
void	ps_sa(s_list **stack_a);
void	ps_sb(s_list **stack_b);
void	ps_rotate(s_list **stack);
void    ps_ra(s_list **stack_a);
void    ps_rb(s_list **stack_b);
void    ps_rr(s_list **stack_a, s_list **stack_b);
void    ps_rev_rotate(s_list **stack);
void    ps_rra(s_list **stack_a);
void    ps_rrb(s_list **stack_b);
void	ps_rrr(s_list **stack_a, s_list **stack_b);

//sorts
void	sort_two(s_list **stack_a);
void	sort_three(s_list **stack_a);

s_list	*max_num(s_list *stack_a);
s_list	*min_num(s_list *stack);

// void	set_pos(s_list *stack);
// int	get_cost(int pos, int size);
// void	reset_rank(s_list *stack);
void	node_rank(s_list **stack);
void	target_in_a(s_list *stack_a, s_list *stack_b);
void	calculate_costs(s_list *stack_a, s_list *stack_b);
s_list	*find_cheapest(s_list *stack_b, s_list *cheapest);
void	execute_moves(s_list **stack_a, s_list **stack_b, s_list *cheapest);
void	sort_turk(s_list **stack_a, s_list **stack_b);

void update_stacks(s_list **stack_a, s_list **stack_b);


#endif