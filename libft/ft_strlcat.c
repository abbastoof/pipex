/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:36:14 by atoof             #+#    #+#             */
/*   Updated: 2022/11/17 13:11:29 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_lng;
	size_t	src_lng;
	size_t	i;

	src_lng = ft_strlen(src);
	dest_lng = 0;
	if (dst)
		dest_lng = ft_strlen(dst);
	i = dest_lng;
	if (!src || !*src)
		return (dest_lng);
	else if (dstsize <= dest_lng)
		return (dstsize + src_lng);
	while (*src && dstsize > dest_lng && i != dstsize - 1)
		*(dst + i++) = *src++;
	*(dst + i) = '\0';
	return (dest_lng + src_lng);
}
