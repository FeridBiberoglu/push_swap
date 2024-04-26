/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:13:10 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/26 12:35:49 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int			index;
	int			middle;
	long long	data;
	int			cost;
	int			cheapest;
	struct node	*target;
	struct node	*prev;
	struct node	*next;
}				t_node;

int				max_three_arg(int argc, char **argv);
int				check_args(int argc, char **argv);
void			move_nodes_a_b(t_node **stack_a, t_node **stack_b);
void			sort_three(t_node **stack_a);
void			sa(t_node **stack_a, char c);
void			rrr(t_node **stack_a, t_node **stack_b);
void			ra(t_node **stack_a, char c);
void			rra(t_node **stack_a, char c);
void			pa(t_node **stack_a, t_node **stack_b, char c);
void			rr(t_node **stack_a, t_node **stack_b);
// t_node			*make_stack_a(t_node *stack_a, int argc, char **argv);
t_node			*add_last_node(t_node *head, long long data);
void			remove_first_node(t_node **head);
int				check_sorted_a(t_node *stack);
int				check_sorted_b(t_node *stack);
void			sort(t_node **stack_a, int argc);
void			init_stack_a(t_node **stack_a, t_node **stack_b);
t_node			*make_stack_b(t_node **stack_a, int argc);
int				stack_size(t_node *stack);
// void			mark_cheapest(t_node *stack_a);
void			init_stack_b(t_node **stack_a, t_node **stack_b);
int				stack_size(t_node *stack);
void			set_middle_node(t_node *stack);
t_node			*biggestnumber(t_node *stack);
void			free_list(t_node **head);
int				stack_size(t_node *stack);
