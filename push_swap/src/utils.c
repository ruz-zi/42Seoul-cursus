/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:00:48 by dju               #+#    #+#             */
/*   Updated: 2021/05/26 17:44:17 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	atoi(const char *s)
{
	long	r;
	int		n;

	r = 0;
	n = 0;
	if (*s == '-' || *s == '+')
		n = *s++ == '-';
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + (*s++ & 15);
		if (r > 2147483648)
			error();
	}
	if (*s || (!n && r > 2147483647))
		error();
	if (n)
		return (-r);
	return (r);
}

void	ranking(int *a, int *b, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (j-- > 0 && a[i] < b[j])
			b[j + 1] = b[j];
		if (j >= 0 && a[i] == b[j])
			error();
		b[j + 1] = a[i];
	}
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			if (a[i] == b[j])
				a[i] = j + 1;
	}
}

void	run(const char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(cmd, "pa"))
		pa(a, b);
	else if (!ft_strcmp(cmd, "pb"))
		pa(b, a);
	else if (!ft_strcmp(cmd, "sa"))
		sa(a);
	else if (!ft_strcmp(cmd, "sb"))
		sa(b);
	else if (!ft_strcmp(cmd, "ra"))
		ra(a);
	else if (!ft_strcmp(cmd, "rb"))
		ra(b);
	else if (!ft_strcmp(cmd, "rra"))
		rra(a);
	else if (!ft_strcmp(cmd, "rrb"))
		rra(b);
	else if (!ft_strcmp(cmd, "ss"))
		sa(a), sa(b);
	else if (!ft_strcmp(cmd, "rr"))
		ra(a), ra(b);
	else if (!ft_strcmp(cmd, "rrr"))
		rra(a), rra(b);
	else
		error();
}

void	wrun(const char *cmd, t_stack *a, t_stack *b)
{
	run(cmd, a, b);
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
}
