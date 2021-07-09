/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:58:51 by dju               #+#    #+#             */
/*   Updated: 2021/05/26 18:53:57 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*cmd;
	int		i;

	if (ac < 2)
		return (0);
	get_arg(ac, av, &a, &b);
	i = 0;
	while (get_next_line(0, &cmd) && ++i)
		run(cmd, &a, &b);
	if (!i && (!is_sorted(&a) || b.size))
		error();
	if (is_sorted(&a) && !b.size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a.arr);
	free(b.arr);
	return (0);
}
