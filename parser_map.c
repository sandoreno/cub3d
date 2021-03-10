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

int ft_key_press(int key, t_all *all)
{
	mlx_clear_window(all->win->mlx, all->win->win);
	if(key == 13)
		if(all->map[(int)(all->plr->x + (sin(all->plr->dir) * 8))/15]
		[(int)((all->plr->y) + (cos(all->plr->dir) * 8))/15] != '1')
			{
			all->plr->x += sin(all->plr->dir) * 8;
			all->plr->y += cos(all->plr->dir) * 8;
			}
	if(key == 1)
		if(all->map[(int)(all->plr->x - (sin(all->plr->dir) * 8))/15]
		   [(int)((all->plr->y) - (cos(all->plr->dir) * 8))/15] != '1')
			{
				all->plr->x -= sin(all->plr->dir) * 8;
				all->plr->y -= cos(all->plr->dir) * 8;
			}
	if(key == 0)
//		if(all->map[(int)(all->plr->x)/15][(int)(all->plr->y)/15] != '1')
			{all->plr->dir -= 0.2;}
	if(key == 2)
//		if(all->map[(int)(all->plr->x)/15][(int)(all->plr->y)/15] != '1')
			{all->plr->dir += 0.2;}
	draw_screen(all);
	return(0);
}

void ft_create_point(int x, int y, t_all all, int color)
{
	int i;
	int j;

	i = x;
	j = y;

	while(j++ < y + 15)
	{
		i = x;
		while(i++ < x + 15)
			mlx_pixel_put(all.win->mlx,all.win->win,j,i, color);
	}
}

int ft_player_pozition(t_all *all, t_plr *plr)
{
	int len;
	int i;
	int j;

	i = 0;
	while(all->map[i] != NULL)
	{
		j = 0;
		len = ft_strlen(all->map[i]);
		while(j < len)
		{
			if(all->map[i][j] == 'N')
			{
				plr->x = i * 15;
				plr->y = j * 15;
				plr->dir = M_PI_2 * 3;
//				ft_create_point(i* 15, j* 15, *all,0x000000FF);
			}
			else if(all->map[i][j] == 'S')
			{
				ft_create_point(i* 15, j* 15, *all,0x000000FF);
			}
			else if(all->map[i][j] == 'E')
			{
				ft_create_point(i* 15, j* 15, *all,0x000000FF);
			}
			else if(all->map[i][j] == 'W')
			{
				ft_create_point(i* 15, j* 15, *all,0x000000FF);
			}
			j++;
		}
		i++;
	}

	return (0);
}

int draw_screen(t_all *all)
{
	int i;
	int j;
	int len;

	i = 0;
	while(all->map[i] != NULL)
	{
		j = 0;
		len = ft_strlen(all->map[i]);
		while(j < len)
		{
			if(all->map[i][j] == '1') {
//				mlx_pixel_put(win.mlx,win.win,i,j, 0xFFFFFF);
				ft_create_point(i * 15, j * 15, *all, 0x00FF00);
			}
//			ft_player_pozition(i, j, &all, plr);
			j++;
		}
		i++;
	}
	//ft_create_point(all->plr->x, all->plr->y, *all, 0x0000FF);
	ft_cast_ray(all);
}

void ft_create_map(t_all all)
{
	t_plr plr;
	int i;
	int j;
	int len;

	i = 0;
	ft_player_pozition(&all, &plr);
	all.win->mlx = mlx_init();
	all.win->win = mlx_new_window(all.win->mlx, 640, 480, "new window");
	all.win->img = mlx_new_image(all.win->mlx, 640 , 480);
//	all.win->addr = mlx_get_data_addr(all.win->img, &all.win->bpp, &all.win->line_l, &all.win->en);

//	while(y++ < 40)
//	{
//		x = 20;
//		while(x++ < 40)
//			mlx_pixel_put(win.mlx,win.win,x,y, 0xFFFFFF);
//	}

	all.plr = &plr;
	draw_screen(&all);
	mlx_hook(all.win->win,2, (1L << 0), &ft_key_press, &all);
	mlx_loop(all.win->mlx);


}

char *ft_parser_map(char **map, int i, int size)
{
	t_all list;
	int s;

	list.map = ft_calloc((size - i) + 1, sizeof(char *));
	s = 0;
	while(map[i] != NULL)
	{
		list.map[s] = map[i];
		s++;
		i++;
	}
	s = 0;
	//вывод карты
	while (list.map[s] != NULL)
	{
		printf("%s\n", list.map[s]);
		s++;
	}
	ft_create_map(list);
	printf("%d\n", M_PI_2);
	return(list.map);
}

int *ft_strcount(char **str)
{
	int i;

	i = 0;
	while(str[i] != NULL)
		i++;
	return (i);
}

//int ft_wall_check(char **str)
//{
//	int i;
//
//
//	i = 0;
//	while(str[i] != NULL)
//		if(ft_split(str[0], '1') == NULL)
//			return (0);
//
//	return (1);
//}

// вычитываем все аргументы из карты
char *ft_parser_argument(char **map, int size)
{
	int i;
	char **str;

	i = 0;
	while((ft_strcount(str = ft_split(map[i], ' ')) > 1 || (str[0] == NULL)) && (ft_split(str[0], '1') != NULL))
	{ // прописываем проверку значений
		if(str[0] != NULL) {
			if (ft_strncmp(str[0], "R", 1) == 0) { printf("Bingo R\n"); }
			else if (ft_strncmp(str[0], "NO", 2) == 0) { printf("Bingo NO\n"); }
			else if (ft_strncmp(str[0], "SO", 2) == 0) { printf("Bingo SO\n"); }
			else if (ft_strncmp(str[0], "WE", 2) == 0) { printf("Bingo WE\n"); }
			else if (ft_strncmp(str[0], "EA", 2) == 0) { printf("Bingo EA\n"); }
			else if (ft_strncmp(str[0], "S", 1) == 0) { printf("Bingo S\n"); }
			else if (ft_strncmp(str[0], "F", 1) == 0) { printf("Bingo F\n"); }
			else {printf("Bingo\n");}
		}
		i++;
	}
	return (ft_parser_map(map, i, size));
}

char *ft_parser_file(t_list *head, int size)
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
//	while (map[i] != NULL)
//	{
//		ft_putendl_fd(map[i], 1);
//		i++;
//	}
	ft_parser_argument(map, size);
	return (map);
}
