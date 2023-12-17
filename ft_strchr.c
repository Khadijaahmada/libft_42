/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:18:56 by kahmada           #+#    #+#             */
/*   Updated: 2023/12/07 21:26:21 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*str;
	char		x;

	x = (char)c;
	i = 0;
	str = (char *)s;
	while (i < ft_strlen(s))
	{
		if (str[i] == x)
			break ;
		i++;
	}
	if (s[i] != x)
		return (NULL);
	return (&str[i]);
}
