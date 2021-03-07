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

// создаем окно
void new_win(t_win win)
{
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 640, 480, "new window");
	win.img = mlx_new_image(win.mlx, 640, 480);

}



// создаем игрока
void new_player(t_plr plr)
{
	plr.x = 12;
	plr.y = 12;
//	plr.dir = ..;
//	plr.start =..;
//	plr.end =..;
}

// вычитываем все аргументы из карты
char *ft_parser_argument(char **map)
{
	int i;
	char **str;

	i = 0;
	while((ft_strlen(str = ft_split(map[i], ' ')) != 0) || (str == NULL))
	{ // прописываем проверку значений
		if(ft_strncmp(str[0], "R", 1) == 0)
		{printf("Bingo R\n");}
		else if(ft_strncmp(str[0], "NO", 2) == 0)
		{printf("Bingo NO\n");}
		else if(ft_strncmp(str[0], "SO", 2) == 0)
		{printf("Bingo SO\n");}
		else if(ft_strncmp(str[0], "WE", 2) == 0)
		{printf("Bingo WE\n");}
		else if(ft_strncmp(str[0], "EA", 2) == 0)
		{printf("Bingo EA\n");}
		else if(ft_strncmp(str[0], "S", 1) == 0)
		{printf("Bingo S\n");}
		else if(ft_strncmp(str[0], "F", 1) == 0)
		{printf("Bingo F\n");}
		else
		{printf("Bingo");}
		i++;
	}
}

char *ft_parser_map(t_list *head, int size)
{
	char **map;
	int i;

	i = 0;
	map = ft_calloc(size + 1, sizeof(char *));

	while(head != NULL)
	{
		map[i] = head->content;
		head = head->next;
		i++;
	}
	i = 0;
	// просто вывод карты
	while (map[i] != NULL)
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
	ft_parser_argument(map);
	return (map);
}
