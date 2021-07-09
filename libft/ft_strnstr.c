/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 00:09:05 by dju               #+#    #+#             */
/*   Updated: 2020/11/04 18:59:21 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	sl;
	size_t	tl;

	if (!big && !len)
		return (NULL);
	sl = ft_strlen(big);
	tl = ft_strlen(little);
	while (sl >= tl && len >= tl)
	{
		sl--;
		len--;
		if (ft_strncmp(big, little, tl) == 0)
			return ((char*)big);
		big++;
	}
	return (NULL);
}
