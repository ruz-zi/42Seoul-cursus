/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:41:56 by dju               #+#    #+#             */
/*   Updated: 2021/05/26 17:30:04 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *a, int n)
{
	a->arr = malloc(sizeof(int) * n);
	a->front = 0;
	a->size = 0;
	a->n = n;
}

int	at(t_stack *a, int i)
{
	return (a->arr[(a->front + i) % a->n]);
}

int	front(t_stack *a)
{
	return (at(a, 0));
}

int	back(t_stack *a)
{
	return (at(a, a->size - 1));
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (++i < a->size)
		if (at(a, i - 1) > at(a, i))
			return (0);
	return (1);
}
