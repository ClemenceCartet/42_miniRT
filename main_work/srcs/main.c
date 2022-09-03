/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:44:34 by ljohnson          #+#    #+#             */
/*   Updated: 2022/09/03 11:58:35 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

void	rt_display_scene(t_master *master)
{
	master->mlx->img = mlx_new_image(master->init, W, H);
	master->mlx->addr = mlx_get_data_addr(master->mlx->img, &(master->mlx->bpp),
			&(master->mlx->line_length), &(master->mlx->endian));
	rt_ray_tracer(master);
	mlx_put_image_to_window(master->init, master->wdw, master->mlx->img, 0, 0);
	mlx_destroy_image(master->init, master->mlx->img);
}

int	main(int ac, char **av)
{
	t_master	master;

	if (ac != 2)
		return (rt_write_int_error(E_USAGE, NULL, DFI, DLI));
	if (rt_init_master(&master, av[1]))
		return (rt_free_master(&master) + 1);
	master.init = mlx_init();
	master.wdw = mlx_new_window(master.init, W, H, "miniRT");
	rt_display_scene(&master);
	mlx_hook(master.wdw, 2, 0, key_hook, &master);
	mlx_hook(master.wdw, 17, 0, exit_x, &master);
	mlx_loop(master.init);
	return (rt_free_master(&master));
}
