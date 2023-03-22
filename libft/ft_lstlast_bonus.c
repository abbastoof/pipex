/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:40:36 by atoof             #+#    #+#             */
/*   Updated: 2022/11/23 12:08:45 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*currentelement;

	currentelement = lst;
	if (currentelement == NULL)
		return (NULL);
	while (currentelement ->next != NULL)
		currentelement = currentelement->next;
	return (currentelement);
}
