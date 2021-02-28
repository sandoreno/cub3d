/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 04:51:30 by acarroll          #+#    #+#             */
/*   Updated: 2021/02/20 04:51:33 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

char *ft_parser_map(t_list *head, int size)
{
	char **map;


	while(head != NULL)
	{
		printf("%s", head->content);
		head = head->next;
	}

	return (map);
}