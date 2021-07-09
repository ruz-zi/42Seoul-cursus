/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 00:35:23 by dju               #+#    #+#             */
/*   Updated: 2020/10/02 23:26:38 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *c)
{
	register size_t	i;
	size_t			len;
	char			*ret;

	len = ft_strlen(c);
	if (!(ret = malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(ret + i) = *(c + i);
		i = i + 1;
	}
	*(ret + i) = 0;
	return (ret);
}
