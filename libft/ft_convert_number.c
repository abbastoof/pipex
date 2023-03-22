/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:36:11 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/23 03:25:02 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlength(unsigned long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = (n / base);
		i++;
	}
	return (i);
}

int	ft_convert_number(unsigned long num, int base, char sign)
{
	int		length;
	char	*ptr;
	char	*numbers;
	int		returnlength;

	returnlength = 0;
	numbers = "0123456789ABCDEF";
	length = numlength(num, base);
	ptr = (char *)malloc(sizeof(char) * length + 1);
	if (!ptr)
		return (0);
	ptr[length--] = '\0';
	if (num == 0)
		ptr[0] = '0';
	while (num != 0)
	{
		if (numbers[num % base] > '9')
			ptr[length--] = (numbers[num % base] + sign);
		else
			ptr[length--] = numbers[num % base];
		num /= base;
	}
	returnlength += ft_putstr(ptr);
	free(ptr);
	return (returnlength);
}
