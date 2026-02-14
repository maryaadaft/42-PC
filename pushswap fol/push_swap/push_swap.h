/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:20:43 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/14 19:41:50 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack_list
{
	int					data;
	int					pos;
	int					rank;
	int					cost_a;
	int					cost_b;
	int					total_cost;
	struct s_stack_list	*target;
	struct s_stack_list	*next;
}	t_list;

void	ft_listadd_back(t_list **lst, t_list *new);
int		ft_listsize(t_list *lst);
t_list	*ft_listnew(int data);
void	free_all_stack(t_list	**stack);
int		to_num(const char *str, int *over_check);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		arg_is_num(char *argv);
int		arg_is_dup(t_list *stack, int data);
int		is_it_space(char *argv);
void	err_ret(void);
void	free_split_args(char **split_args);
int		is_list_sorted(t_list **stack_a);
void	ps_pa(t_list **stack_a, t_list **stack_b);
void	ps_pb(t_list **stack_a, t_list **stack_b);
void	ps_swap(t_list **stack);
void	ps_sa(t_list **stack_a);
void	ps_sb(t_list **stack_b);
void	ps_rotate(t_list **stack);
void	ps_ra(t_list **stack_a);
void	ps_rb(t_list **stack_b);
void	ps_rr(t_list **stack_a, t_list **stack_b);
void	ps_rev_rotate(t_list **stack);
void	ps_rra(t_list **stack_a);
void	ps_rrb(t_list **stack_b);
void	ps_rrr(t_list **stack_a, t_list **stack_b);
void	sort_two(t_list **stack_a);
void	sort_three(t_list **stack_a);
t_list	*max_num(t_list *stack_a);
t_list	*min_num(t_list *stack);
void	node_rank(t_list **stack);
void	target_in_a(t_list *stack_a, t_list *stack_b);
void	calculate_costs(t_list *stack_a, t_list *stack_b);
t_list	*find_cheapest(t_list *stack_b, t_list *cheapest);
void	execute_moves(t_list **stack_a, t_list **stack_b, t_list *cheapest);
void	sort_turk(t_list **stack_a, t_list **stack_b);
void	update_stacks(t_list **stack_a, t_list **stack_b);

#endif