/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 00:33:53 by dju               #+#    #+#             */
/*   Updated: 2020/11/02 19:41:03 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t len, size_t var)
{
	void	*p;

	if (!(p = malloc(len * var)))
		return (NULL);
	ft_bzero(p, len * var);
	return (p);
}
