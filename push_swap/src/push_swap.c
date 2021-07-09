/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:03:58 by dju               #+#    #+#             */
/*   Updated: 2021/05/26 18:56:46 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split(t_stack *a, t_stack *b, int size)
{
	int	i;
	int	avg;
	int	rcnt;

	i = -1;
	avg = avg_elem(a, size);
	rcnt = 0;
	while (++i < size)
	{
		if (front(a) <= avg)
			wrun("pb", a, b);
		else
		{
			wrun(tern(well_rotate(b), "rr", "ra"), a, b);
			rcnt++;
		}
	}
	if (size != a->n)
		while (rcnt-- > 0)
			wrun(tern(well_rotate(b), "rra", "rrr"), a, b);
}

void	merge(t_stack *a, t_stack *b)
{
	int	avg;

	if (!b->size)
		return ;
	avg = (at(b, max_elem(b, b->size)) + at(b, min_elem(b, b->size))) / 3 * 2;
	while (b->size > 0)
	{
		if (max_elem(b, b->size) == 0)
			wrun("pa", a, b);
		else if (front(b) == 1 || front(b) == back(a) + 1)
		{
			wrun("pa", a, b);
			wrun(tern(well_rotate(b), "rr", "ra"), a, b);
		}
		else if (front(b) > avg)
			wrun("pa", a, b);
		else
			wrun(tern(well_rotate(b), "rb", "rrb"), a, b);
	}
	while (!is_sorted(a) && (front(a) == 1 || front(a) == back(a) + 1))
		wrun("ra", a, b);
}

void	small_case(t_stack *a, t_stack *b)
{
	int	i;

	if (is_sorted(a))
		return ;
	while (a->size > 3)
	{
		if (min_elem(a, a->size) == 0)
			wrun("pb", a, b);
		i = min_elem(a, a->size);
		wrun(tern(i < a->size - i, "ra", "rra"), a, b);
	}
	if (max_elem(a, a->size) == 0)
		wrun(tern(b->size >= 2 && at(b, 0) < at(b, 1), "rr", "ra"), a, b);
	else if (max_elem(a, a->size) != a->size - 1)
		wrun(tern(b->size >= 2 && at(b, 0) < at(b, 1), "rrr", "rra"), a, b);
	if (at(a, 0) > at(a, 1))
		wrun(tern(b->size >= 2 && at(b, 0) < at(b, 1), "ss", "sa"), a, b);
	if (b->size >= 2 && at(b, 0) < at(b, 1))
		wrun("sb", a, b);
	while (b->size > 0)
		wrun("pa", a, b);
}

void	push_swap(t_stack *a, t_stack *b, int size)
{
	if (is_sorted(a))
		return ;
	split(a, b, size);
	merge(a, b);
	push_swap(a, b, get_unsorted_size(a));
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	get_arg(ac, av, &a, &b);
	if (a.size > 5)
		push_swap(&a, &b, a.size);
	else
		small_case(&a, &b);
	free(a.arr);
	free(b.arr);
	return (0);
}
