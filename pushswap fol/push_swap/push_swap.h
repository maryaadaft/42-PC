/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:20:43 by maryaada          #+#    #+#             */
/*   Updated: 2025/12/10 18:13:17 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// #include "libft/libft.h" //including the libft to include the fns
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //remove this at some point
#include <stdint.h> //for linux machines (limits.h), running project on codespace and later linux in labs!! include in libft
#include <limits.h>

typedef struct stack_list {
	int data;
	struct stack_list *next;
} s_list;

//new list fn, not from libft
void	ft_listadd_back(s_list **lst, s_list *new);
int		ft_listsize(s_list *lst);
s_list	*ft_listnew(int data); //new list fn with content type int

//own library
int	to_num(const char *str, int *over_check);
int	ft_isdigit(int c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

//error fns ps_error
int arg_is_num(char **argv);
int arg_is_dup(char **argv);
int arg_overflow(char **argv);
int	is_it_space(char **argv);
void    err_ret();

int	has_space(char **argv);

//operations
void	ps_sa(s_list **stack_a);
void	ps_sb(s_list **stack_b);
void	ps_pa(s_list **stack_a, s_list **stack_b);
void	ps_pb(s_list **stack_a, s_list **stack_b);
void    ps_ra(s_list **stack_a);
void    ps_rb(s_list **stack_b);
void    ps_rr(s_list **stack_a, s_list **stack_b);
void    ps_rra(s_list **stack_a);
void    ps_rrb(s_list **stack_b);
void ps_rrr(s_list **stack_a, s_list **stack_b);

//sorts
void	sort_two(s_list **stack_a);
void	sort_three(s_list **stack_a);

s_list	*max_num(s_list *stack_a);
s_list	*min_num(s_list *stack);

#endif