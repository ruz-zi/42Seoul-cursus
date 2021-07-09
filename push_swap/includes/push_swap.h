/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 01:30:47 by dju               #+#    #+#             */
/*   Updated: 2021/05/26 17:53:41 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define MAX_FD 10

typedef struct s_stack
{
	int			*arr;
	int			front;
	int			size;
	int			n;
}				t_stack;

void	get_arg(int ac, char **av, t_stack *a, t_stack *b);
char	*tern(int condition, char *a, char *b);

void	init(t_stack *a, int n);
int		at(t_stack *a, int i);
int		front(t_stack *a);
int		back(t_stack *a);
int		is_sorted(t_stack *a);

int		min_elem(t_stack *a, int size);
int		max_elem(t_stack *a, int size);
int		nth_elem(t_stack *a, int size, int nth);
int		avg_elem(t_stack *a, int size);
int		get_unsorted_size(t_stack *a);

void	pa(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	ra(t_stack *a);
void	rra(t_stack *a);
int		well_rotate(t_stack *a);

void	error(void);
int		atoi(const char *s);
void	ranking(int *a, int *b, int n);
void	run(const char *cmd, t_stack *a, t_stack *b);
void	wrun(const char *cmd, t_stack *a, t_stack *b);

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

#endif
