/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:17:07 by acarroll          #+#    #+#             */
/*   Updated: 2020/11/19 13:18:41 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (*(s + i) != c && *(s + i) != '\0')
		i++;
	if (*(s + i) == c)
	{
		return ((char*)(s + i));
	}
	else
	{
		return (NULL);
	}
}
