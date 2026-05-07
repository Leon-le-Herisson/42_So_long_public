/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:30:41 by bamagere          #+#    #+#             */
/*   Updated: 2026/05/01 10:38:02 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_hero(void)
{
	ft_path_checker("./textures/bonus/hero/N/n1.xpm");
	ft_path_checker("./textures/bonus/hero/N/n2.xpm");
	ft_path_checker("./textures/bonus/hero/N/n3.xpm");
	ft_path_checker("./textures/bonus/hero/N/n4.xpm");
	ft_path_checker("./textures/bonus/hero/E/e1.xpm");
	ft_path_checker("./textures/bonus/hero/E/e2.xpm");
	ft_path_checker("./textures/bonus/hero/E/e3.xpm");
	ft_path_checker("./textures/bonus/hero/E/e4.xpm");
	ft_path_checker("./textures/bonus/hero/W/w1.xpm");
	ft_path_checker("./textures/bonus/hero/W/w2.xpm");
	ft_path_checker("./textures/bonus/hero/W/w3.xpm");
	ft_path_checker("./textures/bonus/hero/W/w4.xpm");
	ft_path_checker("./textures/bonus/hero/S/s1.xpm");
	ft_path_checker("./textures/bonus/hero/S/s2.xpm");
	ft_path_checker("./textures/bonus/hero/S/s3.xpm");
	ft_path_checker("./textures/bonus/hero/S/s4.xpm");
}

static void	check_monster(void)
{
	ft_path_checker("./textures/bonus/monster/bs1.xpm");
	ft_path_checker("./textures/bonus/monster/bs2.xpm");
	ft_path_checker("./textures/bonus/monster/bs3.xpm");
	ft_path_checker("./textures/bonus/monster/bs4.xpm");
}

static void	check_power_1(void)
{
	ft_path_checker("./textures/bonus/attack/a1.xpm");
	ft_path_checker("./textures/bonus/attack/a2.xpm");
	ft_path_checker("./textures/bonus/attack/a3.xpm");
	ft_path_checker("./textures/bonus/attack/a4.xpm");
	ft_path_checker("./textures/bonus/attack/a5.xpm");
	ft_path_checker("./textures/bonus/attack/a6.xpm");
	ft_path_checker("./textures/bonus/attack/a7.xpm");
	ft_path_checker("./textures/bonus/attack/d1.xpm");
	ft_path_checker("./textures/bonus/attack/d2.xpm");
	ft_path_checker("./textures/bonus/attack/d3.xpm");
	ft_path_checker("./textures/bonus/attack/d4.xpm");
	ft_path_checker("./textures/bonus/attack/d5.xpm");
	ft_path_checker("./textures/bonus/attack/d6.xpm");
	ft_path_checker("./textures/bonus/attack/d7.xpm");
}

static void	check_power_2(void)
{
	ft_path_checker("./textures/bonus/attack/l1.xpm");
	ft_path_checker("./textures/bonus/attack/l2.xpm");
	ft_path_checker("./textures/bonus/attack/l3.xpm");
	ft_path_checker("./textures/bonus/attack/l4.xpm");
	ft_path_checker("./textures/bonus/attack/l5.xpm");
	ft_path_checker("./textures/bonus/attack/l6.xpm");
	ft_path_checker("./textures/bonus/attack/l7.xpm");
	ft_path_checker("./textures/bonus/attack/r1.xpm");
	ft_path_checker("./textures/bonus/attack/r2.xpm");
	ft_path_checker("./textures/bonus/attack/r3.xpm");
	ft_path_checker("./textures/bonus/attack/r4.xpm");
	ft_path_checker("./textures/bonus/attack/r5.xpm");
	ft_path_checker("./textures/bonus/attack/r6.xpm");
	ft_path_checker("./textures/bonus/attack/r7.xpm");
}

void	xpm_checker_2(void)
{
	check_hero();
	check_monster();
	check_power_1();
	check_power_2();
}
