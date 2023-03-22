/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:53:55 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/22 19:49:42 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (str)
	{
		while (str[i] != '\0')
		{
			length += ft_putchar(str[i]);
			i++;
		}
	}
	return (length);
}
