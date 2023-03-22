/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:13:24 by atoof             #+#    #+#             */
/*   Updated: 2023/03/08 13:56:23 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(char const *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static int	ft_words_len(const char *s, char c, int index)
{
	int	len;

	len = 0;
	while (s[index] != c && s[index])
	{
		index++;
		len++;
	}
	return (len);
}

static void	free_memory(char **str, int index)
{
	while (index--)
		free(str[index]);
	free(str);
}

static char	**make_words(char **str, char const *s, char c, int w_count)
{
	int	index;
	int	counter;
	int	w_length;

	counter = 0;
	index = 0;
	while (counter < w_count)
	{
		while (s[index] == c && s[index])
			index++;
		w_length = ft_words_len(s, c, index);
		str[counter] = ft_substr(s, index, w_length);
		if (!str[counter])
		{
			free_memory(str, counter);
			return (NULL);
		}
		counter++;
		index += w_length;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**str;

	if (!s)
		return (NULL);
	count = count_str(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	str = make_words(str, s, c, count);
	str[count] = 0;
	return (str);
}
