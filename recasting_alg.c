/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting_alg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarroll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 00:59:29 by acarroll          #+#    #+#             */
/*   Updated: 2021/03/10 00:59:31 by acarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "cub3d.h"

//void ft_drawline(double lx , double ly, t_plr *p)
//{
//	int dist = sqrt(pow(lx, 2) + pow(ly, 2));
////	printf("%d \n", dist);
//	int lineH = (int) (480  / dist );
//	printf("%d \n", lineH);
//	int drawstart = 480/ 2 - lineH /2;
//	if (drawstart < 0)
//		drawstart = 0;
//	int drawend = 480 / 2 +lineH / 2;
//	if (drawend >= 480)
//		drawend = 480 - 1;
//
//}

void	ft_cast_ray(t_all *all)
{
	t_plr p = *all->plr; // задаем координаты луча равные координатам игрока
	p.x = all->plr->y;
	p.y = all->plr->x;
	p.start = p.dir - M_PI_4;
	p.end = p.dir + M_PI_4;
//	double linex;
//	double liney;
//	double r1;
//	double r2;


	while(p.start <= p.end)
	{
	//	r1 = all->plr->x;
	//	r2 = all->plr->y;
		p.x = all->plr->y;
		p.y = all->plr->x;
		while (all->map[(int) (p.y / 15)][(int) (p.x / 15)] != '1')
		{
			p.x += cos(p.start);
			p.y += sin(p.start);
			my_mlx_pixel_put(all->win, p.x, p.y, 0x990099);
		}
	//	linex = fabs(r1 - p.x);
	//	liney = fabs(r2 - p.y);
	//	ft_drawline(linex, liney, &p);
		p.start += M_PI_2 / 640;
	}
}

