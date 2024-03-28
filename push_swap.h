/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:13:10 by fbiberog          #+#    #+#             */
/*   Updated: 2024/03/20 17:09:33 by fbiberog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int 		index;
	int			middle;
	int			data;
	int			cost;
	int 		cheapest;
	struct node *target;
	struct node	*prev;
	struct node	*next;
}				node_t;

void sa(struct node **stack_a, char c);
void rrr(node_t **stack_a, node_t **stack_b);
int sort_three(node_t **stack_a);
void ra(node_t **stack_a, char c);
void rra(node_t **stack_a, char c);
struct node	*make_stack_a(struct node *stack_a, int argc, char **argv);
struct node	*add_last_node(struct node *head, int data);
void	remove_first_node(struct node **head);
void pa(node_t **stack_a, node_t **stack_b, char c);
int check_sorted(node_t *stack);
