/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 11:59:19 by dju               #+#    #+#             */
/*   Updated: 2021/01/25 11:26:08 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_newline(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (s[i] ? i : -1);
}

static int	sub_function(char **line, char **str)
{
	char	*ptr;
	int		sep;

	ptr = *str;
	sep = find_newline(ptr);
	ptr[sep] = 0;
	*line = ft_strdup(ptr);
	*str = ft_strdup(ptr + sep + 1);
	free(ptr);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char		*str[MAX_FD];
	char			buf[BUFFER_SIZE + 1];
	char			*ptr;
	int				len;

	if (fd < 0 || fd >= MAX_FD || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (str[fd] && find_newline(str[fd]) >= 0)
		return (sub_function(line, &str[fd]));
	while ((len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[len] = 0;
		ptr = str[fd];
		str[fd] = ft_strjoin(ptr, buf);
		free(ptr);
		if (find_newline(buf) >= 0)
			return (sub_function(line, &str[fd]));
	}
	*line = str[fd] ? str[fd] : ft_strdup("");
	str[fd] = 0;
	return (0);
}
