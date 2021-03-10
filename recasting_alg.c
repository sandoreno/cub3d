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

#include "cub3d.h"

void	ft_cast_ray(t_all *all)
{
	t_plr p = *all->plr; // задаем координаты луча равные координатам игрока
	p.x = all->plr->y;
	p.y = all->plr->x;
	p.start = p.dir - M_PI_4;
	p.end = p.dir + M_PI_4;

	while(p.start <= p.end)
	{
		p.x = all->plr->y;
		p.y = all->plr->x;
		while (all->map[(int) (p.y / 15)][(int) (p.x / 15)] != '1')
		{
			p.x += cos(p.start);
			p.y += sin(p.start);
			mlx_pixel_put(all->win->mlx, all->win->win, p.x, p.y, 0x990099);
		}
		p.start += M_PI_2 / 640;
	}
}
