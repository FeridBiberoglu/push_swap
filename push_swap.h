/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiberog <fbiberog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:13:10 by fbiberog          #+#    #+#             */
/*   Updated: 2024/04/11 17:04:55 by fbiberog         ###   ########.fr       */
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

void	print_list_data(node_t *stacka, node_t *stackb);

void sa(node_t **stack_a, char c);
void rrr(node_t **stack_a, node_t **stack_b);
void sort_three(node_t **stack_a);
void ra(node_t **stack_a, char c);
void rra(node_t **stack_a, char c);
struct node	*make_stack_a(node_t *stack_a, int argc, char **argv);
struct node	*add_last_node(node_t *head, int data);
void	remove_first_node(struct node **head);
void pa(node_t **stack_a, node_t **stack_b, char c);
void rr(node_t **stack_a, node_t **stack_b);
int check_sorted_a(node_t *stack);
int check_sorted_b(node_t *stack);
void sort(node_t **stack_a, int argc);
void init_stack_a(node_t **stack_a, node_t **stack_b);
struct node	*make_stack_b(node_t **stack_a, int argc);
int stack_size(node_t *stack);
void mark_cheapest(node_t *stack_a);
void init_stack_b(node_t **stack_a, node_t **stack_b);
int stack_size(node_t *stack);
void set_middle_node(node_t *stack);
node_t *biggestnumber(node_t *stack);
