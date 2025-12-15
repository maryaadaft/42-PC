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

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //remove this at some point

typedef struct stack_list {
	int data;
	void *next;
} s_list;

void	ft_lstadd_back(s_list **lst, s_list *new);
s_list	*ft_lstnew(int data);
int	mini_atoi(char *str);
int	ft_lstsize(s_list *lst);
char	**ft_split(char const *s, char c);

#endif