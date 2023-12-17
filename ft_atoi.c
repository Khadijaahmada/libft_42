/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:45:22 by kahmada           #+#    #+#             */
/*   Updated: 2023/12/05 17:02:06 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static void	skip_whitespace(const char *str, int *i)
{
	while (ft_isspace(str[*i]))
		(*i)++;
}

static int	process_sign(const char *str, int *i, int *sign)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (*sign);
}

static int	convert_to_int(const char *str, int *i,
						int sign, unsigned long long *result)
{
	while (str[*i] != '\0' && ft_isdigit(str[*i]))
	{
		if (sign == 1 && *result > LONG_MAX / 10)
			return (-1);
		else if (sign == -1 && *result > LONG_MAX / 10)
			return (0);
		*result = *result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	result;
	int						conversion_result;

	i = 0;
	sign = 1;
	result = 0;
	skip_whitespace(str, &i);
	process_sign(str, &i, &sign);
	conversion_result = convert_to_int(str, &i, sign, &result);
	if (conversion_result == -1)
		return (-1);
	else if (conversion_result == 0)
		return (0);
	return ((int)result * sign);
}
