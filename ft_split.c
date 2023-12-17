/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:22:51 by kahmada           #+#    #+#             */
/*   Updated: 2023/12/03 21:12:30 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_sp(char **str, size_t count)
{
	size_t	i;

	i = 0;
	while (str[i] && i < count)
		free(str[i++]);
	free(str);
}

static	int	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static	char	**fill_sp(char **res, char const *s, char c)
{
	int	i;
	int	temp;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			temp = i;
			while (s[i] != c && s[i])
				i++;
			res[j] = malloc(i - temp + 1);
			if (!res[j])
				return (NULL);
			ft_strlcpy(res[j++], s + temp, i - temp + 1);
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_word(s, c);
	result = malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!fill_sp(result, s, c))
	{
		free_sp(result, count);
		return (NULL);
	}
	return (result);
}
