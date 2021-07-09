/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 05:38:26 by dju               #+#    #+#             */
/*   Updated: 2021/05/26 17:32:30 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_elem(t_stack *a, int size)
{
	int	mn;
	int	ret;
	int	i;

	mn = front(a);
	ret = 0;
	i = 0;
	while (++i < size)
	{
		if (mn > at(a, i))
		{
			mn = at(a, i);
			ret = i;
		}
	}
	return (ret);
}

int	max_elem(t_stack *a, int size)
{
	int	mx;
	int	ret;
	int	i;

	mx = front(a);
	ret = 0;
	i = 0;
	while (++i < size)
	{
		if (mx < at(a, i))
		{
			mx = at(a, i);
			ret = i;
		}
	}
	return (ret);
}

int	nth_elem(t_stack *a, int size, int nth)
{
	int	i;
	int	mn;
	int	ret;
	int	premin;

	ret = 0;
	premin = 0;
	while (nth--)
	{
		mn = 2147483647;
		i = -1;
		while (++i < size)
		{
			if (at(a, i) <= premin)
				continue ;
			if (at(a, i) < mn)
			{
				mn = at(a, i);
				ret = i;
			}
		}
	}
	return (ret);
}

int	avg_elem(t_stack *a, int size)
{
	int		i;
	long	sum;

	i = 0;
	sum = front(a);
	while (++i < size)
		sum += at(a, i);
	return (sum / size);
}

int	get_unsorted_size(t_stack *a)
{
	int	i;

	i = -1;
	while (++i < a->size)
		if (at(a, i) == 1)
			break ;
	return (i);
}
