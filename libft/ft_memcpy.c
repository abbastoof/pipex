/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:39:43 by atoof             #+#    #+#             */
/*   Updated: 2022/10/31 16:15:20 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, unsigned int size)
{
	unsigned int	i;
	char			*from_cpy;
	char			*to_cpy;

	from_cpy = (char *)from;
	to_cpy = (char *)to;
	i = 0;
	if (!to && !from)
		return ((void *)0);
	while (i < size)
	{
		to_cpy[i] = from_cpy[i];
		i++;
	}
	return (to_cpy);
}
