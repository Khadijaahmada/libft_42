/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:31:31 by kahmada           #+#    #+#             */
/*   Updated: 2023/12/08 16:19:14 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
// #include <stdio.h>
// int main()
// {
// 	int a[] = {1, 2, 3};
// 	unsigned char *c = (unsigned char *)a;
// 	ft_memset(c, 55, 1);
// 	ft_memset(c + 4, 56, 1);
// 	ft_memset(c + 8, 57, 1);
// 	printf("%d %d %d", a[0], a[1], a[2]);	
// }