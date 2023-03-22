/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:04:26 by atoof             #+#    #+#             */
/*   Updated: 2022/11/22 16:26:57 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i + 1 > 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		if (!*s)
			return (NULL);
		i--;
	}
	return (NULL);
}
