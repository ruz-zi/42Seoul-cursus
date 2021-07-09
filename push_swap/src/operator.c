/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 02:42:56 by dju               #+#    #+#             */
/*   Updated: 2021/05/26 18:10:31 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
	{
		a->front = (a->front - 1 + a->n) % a->n;
		a->arr[a->front] = b->arr[b->front];
		b->front = (b->front + 1) % b->n;
		a->size++;
		b->size--;
	}
}

void	sa(t_stack *a)
{
	int	tmp;

	if (a->size >= 2)
	{
		tmp = a->arr[a->front];
		a->arr[a->front] = a->arr[(a->front + 1) % a->n];
		a->arr[(a->front + 1) % a->n] = tmp;
	}
}

void	ra(t_stack *a)
{
	a->arr[(a->front + a->size) % a->n] = a->arr[a->front];
	a->front = (a->front + 1) % a->n;
}

void	rra(t_stack *a)
{
	a->front = (a->front - 1 + a->n) % a->n;
	a->arr[a->front] = a->arr[(a->front + a->size) % a->n];
}

int	well_rotate(t_stack *b)
{
	int	mn_i;
	int	mx_i;
	int	rcnt;
	int	rrcnt;

	mn_i = min_elem(b, b->size);
	mx_i = max_elem(b, b->size);
	rcnt = mx_i;
	if (rcnt > mn_i)
		rcnt = mn_i;
	rrcnt = b->size - mn_i;
	if (rrcnt > b->size - mx_i)
		rrcnt = b->size - mx_i;
	return (rcnt < rrcnt);
}
