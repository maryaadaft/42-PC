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

#include "libft/libft.h" //including the libft to include the fns
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //remove this at some point
#include <stdint.h> //for linux machines (limits.h), running project on codespace and later linux in labs!! include in libft

typedef struct stack_list {
	int data;
	void *next;
} s_list;

//new list fn, not from libft
void	ft_listadd_back(s_list **lst, s_list *new);
int		ft_listsize(s_list *lst);
s_list	*ft_listnew(int data); //new list fn with content type int

//error fns ps_error
int arg_is_num(char **argv);
int arg_is_dup(char **argv);
int arg_overflow(char **argv);


#endif