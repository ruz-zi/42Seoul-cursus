/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:06:27 by dju               #+#    #+#             */
/*   Updated: 2021/05/26 19:07:05 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*tern(int condition, char *a, char *b)
{
	if (condition)
		return (a);
	else
		return (b);
}

static char	*sdup(char const *s, char c)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	res = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

static char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		cnt;

	if (!s)
		return (NULL);
	i = 0;
	cnt = !(!s[0] || s[0] == c);
	while (s[i] && s[++i])
		if (s[i - 1] == c && s[i] != c)
			cnt++;
	res = malloc(sizeof (char *) * (cnt + 2));
	if (!res)
		return (NULL);
	i = 0;
	if (*s && *s != c)
		res[++i] = sdup(s, c);
	while (*s && *++s)
		if (*(s - 1) == c && *s != c)
			res[++i] = sdup(s, c);
	res[++i] = NULL;
	return (res);
}

static void	safe_free(char **av)
{
	int	i;

	i = 0;
	free(av[i]);
	while (av[++i] != NULL)
		free(av[i]);
	free(av[i]);
	free(av);
}

void	get_arg(int ac, char **av, t_stack *a, t_stack *b)
{
	int	i;
	int	mem_alloced;

	mem_alloced = 0;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		ac = 0;
		while (av[++ac] != NULL)
			;
		mem_alloced = 1;
	}
	init(a, ac - 1);
	init(b, ac - 1);
	i = 0;
	while (++i < ac)
		a->arr[a->size++] = atoi(av[i]);
	ranking(a->arr, b->arr, a->n);
	if (mem_alloced)
		safe_free(av);
}
