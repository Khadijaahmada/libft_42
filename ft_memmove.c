/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:21:37 by kahmada           #+#    #+#             */
/*   Updated: 2023/12/03 21:01:17 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_src;
	unsigned char	*c_dst;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	c_src = (unsigned char *) src;
	c_dst = (unsigned char *) dst;
	if (c_dst > c_src && c_dst < c_src + len)
	{
		i = len;
		while (i--)
		{
			c_dst[i] = c_src[i];
		}
	}
	else
		ft_memcpy(c_dst, c_src, len);
	return (c_dst);
}
