/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_battery.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:26:12 by ljohnson          #+#    #+#             */
/*   Updated: 2022/08/06 16:56:11 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mini_rt.h>

static void	error_messages_int(void)
{
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
	dprintf(STDOUT_FILENO, "\033[1m\033[32mError messages : rt_write_int_error\033[0m\n\n");
	rt_write_int_error(E_MALLOC, NULL, DFI, DLI);
	rt_write_int_error(E_USAGE, NULL, DFI, DLI);
	rt_write_int_error(E_NO_FILENAME, NULL, DFI, DLI);
	rt_write_int_error(E_NO_EXT, NULL, DFI, DLI);
	rt_write_int_error(E_WRONG_EXT, NULL, DFI, DLI);
	rt_write_int_error(E_OPEN, NULL, DFI, DLI);
	rt_write_int_error(E_READ, NULL, DFI, DLI);
	rt_write_int_error(E_CLOSE, NULL, DFI, DLI);
	rt_write_int_error(E_MISSING, NULL, DFI, DLI);
	rt_write_int_error(E_ID, NULL, DFI, DLI);
	rt_write_int_error(E_EXISTING_ID, NULL, DFI, DLI);
	rt_write_int_error(E_SPLIT_SIZE, NULL, DFI, DLI);
	rt_write_int_error(E_RANGE, NULL, DFI, DLI);
	rt_write_int_error(E_SYNTAX, NULL, DFI, DLI);
	rt_write_int_error(E_NUMBER, NULL, DFI, DLI);
	rt_write_int_error(E_NO_VALUE, NULL, DFI, DLI);
	
	dprintf(STDOUT_FILENO, "\n");
	
	rt_write_int_error(E_MALLOC, "ouaf", DFI, DLI);
	rt_write_int_error(E_USAGE, "ouaf", DFI, DLI);
	rt_write_int_error(E_NO_FILENAME, "ouaf", DFI, DLI);
	rt_write_int_error(E_NO_EXT, "ouaf", DFI, DLI);
	rt_write_int_error(E_WRONG_EXT, "ouaf", DFI, DLI);
	rt_write_int_error(E_OPEN, "ouaf", DFI, DLI);
	rt_write_int_error(E_READ, "ouaf", DFI, DLI);
	rt_write_int_error(E_CLOSE, "ouaf", DFI, DLI);
	rt_write_int_error(E_MISSING, "ouaf", DFI, DLI);
	rt_write_int_error(E_ID, "ouaf", DFI, DLI);
	rt_write_int_error(E_EXISTING_ID, "ouaf", DFI, DLI);
	rt_write_int_error(E_SPLIT_SIZE, "ouaf", DFI, DLI);
	rt_write_int_error(E_RANGE, "ouaf", DFI, DLI);
	rt_write_int_error(E_SYNTAX, "ouaf", DFI, DLI);
	rt_write_int_error(E_NUMBER, "ouaf", DFI, DLI);
	rt_write_int_error(E_NO_VALUE, "ouaf", DFI, DLI);
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
}

static void	error_messages_char(void)
{
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
	dprintf(STDOUT_FILENO, "\033[1m\033[32mError messages : rt_write_char_error\033[0m\n\n");
	rt_write_char_error(E_MALLOC, NULL, DFI, DLI);
	rt_write_char_error(E_USAGE, NULL, DFI, DLI);
	rt_write_char_error(E_NO_FILENAME, NULL, DFI, DLI);
	rt_write_char_error(E_NO_EXT, NULL, DFI, DLI);
	rt_write_char_error(E_WRONG_EXT, NULL, DFI, DLI);
	rt_write_char_error(E_OPEN, NULL, DFI, DLI);
	rt_write_char_error(E_READ, NULL, DFI, DLI);
	rt_write_char_error(E_CLOSE, NULL, DFI, DLI);
	rt_write_char_error(E_MISSING, NULL, DFI, DLI);
	rt_write_char_error(E_ID, NULL, DFI, DLI);
	rt_write_char_error(E_EXISTING_ID, NULL, DFI, DLI);
	rt_write_char_error(E_SPLIT_SIZE, NULL, DFI, DLI);
	rt_write_char_error(E_RANGE, NULL, DFI, DLI);
	rt_write_char_error(E_SYNTAX, NULL, DFI, DLI);
	rt_write_char_error(E_NUMBER, NULL, DFI, DLI);
	rt_write_char_error(E_NO_VALUE, NULL, DFI, DLI);
	
	dprintf(STDOUT_FILENO, "\n");
	
	rt_write_char_error(E_MALLOC, "ouaf", DFI, DLI);
	rt_write_char_error(E_USAGE, "ouaf", DFI, DLI);
	rt_write_char_error(E_NO_FILENAME, "ouaf", DFI, DLI);
	rt_write_char_error(E_NO_EXT, "ouaf", DFI, DLI);
	rt_write_char_error(E_WRONG_EXT, "ouaf", DFI, DLI);
	rt_write_char_error(E_OPEN, "ouaf", DFI, DLI);
	rt_write_char_error(E_READ, "ouaf", DFI, DLI);
	rt_write_char_error(E_CLOSE, "ouaf", DFI, DLI);
	rt_write_char_error(E_MISSING, "ouaf", DFI, DLI);
	rt_write_char_error(E_ID, "ouaf", DFI, DLI);
	rt_write_char_error(E_EXISTING_ID, "ouaf", DFI, DLI);
	rt_write_char_error(E_SPLIT_SIZE, "ouaf", DFI, DLI);
	rt_write_char_error(E_RANGE, "ouaf", DFI, DLI);
	rt_write_char_error(E_SYNTAX, "ouaf", DFI, DLI);
	rt_write_char_error(E_NUMBER, "ouaf", DFI, DLI);
	rt_write_char_error(E_NO_VALUE, "ouaf", DFI, DLI);
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
}

static void	error_messages_ptr(void)
{
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
	dprintf(STDOUT_FILENO, "\033[1m\033[32mError messages : rt_write_ptr_error\033[0m\n\n");
	rt_write_ptr_error(E_MALLOC, NULL, DFI, DLI);
	rt_write_ptr_error(E_USAGE, NULL, DFI, DLI);
	rt_write_ptr_error(E_NO_FILENAME, NULL, DFI, DLI);
	rt_write_ptr_error(E_NO_EXT, NULL, DFI, DLI);
	rt_write_ptr_error(E_WRONG_EXT, NULL, DFI, DLI);
	rt_write_ptr_error(E_OPEN, NULL, DFI, DLI);
	rt_write_ptr_error(E_READ, NULL, DFI, DLI);
	rt_write_ptr_error(E_CLOSE, NULL, DFI, DLI);
	rt_write_ptr_error(E_MISSING, NULL, DFI, DLI);
	rt_write_ptr_error(E_ID, NULL, DFI, DLI);
	rt_write_ptr_error(E_EXISTING_ID, NULL, DFI, DLI);
	rt_write_ptr_error(E_SPLIT_SIZE, NULL, DFI, DLI);
	rt_write_ptr_error(E_RANGE, NULL, DFI, DLI);
	rt_write_ptr_error(E_SYNTAX, NULL, DFI, DLI);
	rt_write_ptr_error(E_NUMBER, NULL, DFI, DLI);
	rt_write_ptr_error(E_NO_VALUE, NULL, DFI, DLI);
	
	dprintf(STDOUT_FILENO, "\n");
	
	rt_write_ptr_error(E_MALLOC, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_USAGE, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_NO_FILENAME, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_NO_EXT, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_WRONG_EXT, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_OPEN, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_READ, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_CLOSE, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_MISSING, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_ID, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_EXISTING_ID, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_SPLIT_SIZE, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_RANGE, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_SYNTAX, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_NUMBER, "ouaf", DFI, DLI);
	rt_write_ptr_error(E_NO_VALUE, "ouaf", DFI, DLI);
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
}

static void	error_messages_split(void)
{
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
	dprintf(STDOUT_FILENO, "\033[1m\033[32mError messages : rt_write_split_error\033[0m\n\n");
	rt_write_split_error(E_MALLOC, NULL, DFI, DLI);
	rt_write_split_error(E_USAGE, NULL, DFI, DLI);
	rt_write_split_error(E_NO_FILENAME, NULL, DFI, DLI);
	rt_write_split_error(E_NO_EXT, NULL, DFI, DLI);
	rt_write_split_error(E_WRONG_EXT, NULL, DFI, DLI);
	rt_write_split_error(E_OPEN, NULL, DFI, DLI);
	rt_write_split_error(E_READ, NULL, DFI, DLI);
	rt_write_split_error(E_CLOSE, NULL, DFI, DLI);
	rt_write_split_error(E_MISSING, NULL, DFI, DLI);
	rt_write_split_error(E_ID, NULL, DFI, DLI);
	rt_write_split_error(E_EXISTING_ID, NULL, DFI, DLI);
	rt_write_split_error(E_SPLIT_SIZE, NULL, DFI, DLI);
	rt_write_split_error(E_RANGE, NULL, DFI, DLI);
	rt_write_split_error(E_SYNTAX, NULL, DFI, DLI);
	rt_write_split_error(E_NUMBER, NULL, DFI, DLI);
	rt_write_split_error(E_NO_VALUE, NULL, DFI, DLI);
	
	dprintf(STDOUT_FILENO, "\n");
	
	rt_write_split_error(E_MALLOC, "ouaf", DFI, DLI);
	rt_write_split_error(E_USAGE, "ouaf", DFI, DLI);
	rt_write_split_error(E_NO_FILENAME, "ouaf", DFI, DLI);
	rt_write_split_error(E_NO_EXT, "ouaf", DFI, DLI);
	rt_write_split_error(E_WRONG_EXT, "ouaf", DFI, DLI);
	rt_write_split_error(E_OPEN, "ouaf", DFI, DLI);
	rt_write_split_error(E_READ, "ouaf", DFI, DLI);
	rt_write_split_error(E_CLOSE, "ouaf", DFI, DLI);
	rt_write_split_error(E_MISSING, "ouaf", DFI, DLI);
	rt_write_split_error(E_ID, "ouaf", DFI, DLI);
	rt_write_split_error(E_EXISTING_ID, "ouaf", DFI, DLI);
	rt_write_split_error(E_SPLIT_SIZE, "ouaf", DFI, DLI);
	rt_write_split_error(E_RANGE, "ouaf", DFI, DLI);
	rt_write_split_error(E_SYNTAX, "ouaf", DFI, DLI);
	rt_write_split_error(E_NUMBER, "ouaf", DFI, DLI);
	rt_write_split_error(E_NO_VALUE, "ouaf", DFI, DLI);
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
}

static void	display_mlx_data(t_mlx_data *mlx_data)
{
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
	dprintf(STDOUT_FILENO, "\033[1m\033[32mdisplay_mlx_data\033[0m\n\n");
	if (mlx_data->init)
		dprintf(STDOUT_FILENO, "mlx_data->init = \033[36m%p\033[0m\n", mlx_data->init);
	if (mlx_data->window)
		dprintf(STDOUT_FILENO, "mlx_data->window = \033[36m%p\033[0m\n", mlx_data->window);
	dprintf(STDOUT_FILENO, "mlx_data->width = \033[36m%d\033[0m\n", mlx_data->width);
	dprintf(STDOUT_FILENO, "mlx_data->height = \033[36m%d\033[0m\n", mlx_data->height);
	dprintf(STDOUT_FILENO, "mlx_data->loop = \033[36m%d\033[0m\n", mlx_data->loop);
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
}

static void	display_ambient(t_ambient *ambient)
{
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
	dprintf(STDOUT_FILENO, "\033[1m\033[32mdisplay_ambient\033[0m\n\n");
	dprintf(STDOUT_FILENO, "ambient->ratio = \033[36m%f\033[0m\n", ambient->ratio);
	if (ambient->rgb)
	{
		dprintf(STDOUT_FILENO, "ambient->rgb->r = \033[36m%d\033[0m\n", ambient->rgb->r);
		dprintf(STDOUT_FILENO, "ambient->rgb->g = \033[36m%d\033[0m\n", ambient->rgb->g);
		dprintf(STDOUT_FILENO, "ambient->rgb->b = \033[36m%d\033[0m\n", ambient->rgb->b);
	}
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
}

static void	display_camera(t_camera *camera)
{
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
	dprintf(STDOUT_FILENO, "\033[1m\033[32mcamera->display_camera\033[0m\n\n");
	if (camera->pos)
	{
		dprintf(STDOUT_FILENO, "camera->pos->x = \033[36m%f\033[0m\n", camera->pos->x);
		dprintf(STDOUT_FILENO, "camera->pos->y = \033[36m%f\033[0m\n", camera->pos->y);
		dprintf(STDOUT_FILENO, "camera->pos->z = \033[36m%f\033[0m\n", camera->pos->z);
	}
	if (camera->dir)
	{
		dprintf(STDOUT_FILENO, "camera->dir->x = \033[36m%f\033[0m\n", camera->dir->x);
		dprintf(STDOUT_FILENO, "camera->dir->y = \033[36m%f\033[0m\n", camera->dir->y);
		dprintf(STDOUT_FILENO, "camera->dir->z = \033[36m%f\033[0m\n", camera->dir->z);
	}
	dprintf(STDOUT_FILENO, "camera->fov = \033[36m%d\033[0m\n", camera->fov);
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
}

static void	display_light(t_light *light)
{
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
	dprintf(STDOUT_FILENO, "\033[1m\033[32mdisplay_light\033[0m\n\n");
	if (light->pos)
	{
		dprintf(STDOUT_FILENO, "light->pos->x = \033[36m%f\033[0m\n", light->pos->x);
		dprintf(STDOUT_FILENO, "light->pos->y = \033[36m%f\033[0m\n", light->pos->y);
		dprintf(STDOUT_FILENO, "light->pos->z = \033[36m%f\033[0m\n", light->pos->z);
	}
	dprintf(STDOUT_FILENO, "ratio = \033[36m%f\033[0m\n", light->ratio);
	if (light->rgb)
	{
		dprintf(STDOUT_FILENO, "light->rgb->r = \033[36m%d\033[0m\n", light->rgb->r);
		dprintf(STDOUT_FILENO, "light->rgb->g = \033[36m%d\033[0m\n", light->rgb->g);
		dprintf(STDOUT_FILENO, "light->rgb->b = \033[36m%d\033[0m\n", light->rgb->b);
	}
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
}

static void	display_object(t_object *object)
{
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
	dprintf(STDOUT_FILENO, "\033[1m\033[32mdisplay_object\033[0m\n\n");
	dprintf(STDOUT_FILENO, "\033[1m\033[35mSP\033[0m = 1 | ");
	dprintf(STDOUT_FILENO, "\033[1m\033[35mPL\033[0m = 2 | ");
	dprintf(STDOUT_FILENO, "\033[1m\033[35mCY\033[0m = 3\n");
	dprintf(STDOUT_FILENO, "object->id = \033[1m\033[35m%d\033[0m\n", object->id);
	if (object->pos)
	{
		dprintf(STDOUT_FILENO, "\n\033[1m\033[35mSP | PL | CY\033[0m\n");
		dprintf(STDOUT_FILENO, "object->pos->x = \033[36m%f\033[0m\n", object->pos->x);
		dprintf(STDOUT_FILENO, "object->pos->y = \033[36m%f\033[0m\n", object->pos->y);
		dprintf(STDOUT_FILENO, "object->pos->z = \033[36m%f\033[0m\n", object->pos->z);
	}
	if ((object->id == 2 || object->id == 3) && object->dir)
	{
		dprintf(STDOUT_FILENO, "\n\033[1m\033[35mPL | CY\033[0m\n");
		dprintf(STDOUT_FILENO, "object->dir->x = \033[36m%f\033[0m\n", object->dir->x);
		dprintf(STDOUT_FILENO, "object->dir->y = \033[36m%f\033[0m\n", object->dir->y);
		dprintf(STDOUT_FILENO, "object->dir->z = \033[36m%f\033[0m\n", object->dir->z);
	}
	if (object->rgb)
	{
		dprintf(STDOUT_FILENO, "\n\033[1m\033[35mSP | PL | CY\033[0m\n");
		dprintf(STDOUT_FILENO, "object->rgb->r = \033[36m%d\033[0m\n", object->rgb->r);
		dprintf(STDOUT_FILENO, "object->rgb->g = \033[36m%d\033[0m\n", object->rgb->g);
		dprintf(STDOUT_FILENO, "object->rgb->b = \033[36m%d\033[0m\n", object->rgb->b);
	}
	if (object->id == 1 || object->id == 3)
	{
		dprintf(STDOUT_FILENO, "\n\033[1m\033[35mSP | CY\033[0m\n");
		dprintf(STDOUT_FILENO, "object->diameter = \033[36m%f\033[0m\n", object->diameter);
	}
	if (object->id == 3)
	{
		dprintf(STDOUT_FILENO, "\n\033[1m\033[35mCY\033[0m\n");
		dprintf(STDOUT_FILENO, "object->height = \033[36m%f\033[0m\n", object->height);
	}
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
}

static void	display_obj_data(t_obj_data *obj_data)
{
	t_object	*object;

	object = NULL;
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
	dprintf(STDOUT_FILENO, "\033[1m\033[32mdisplay_obj_data\033[0m\n\n");
	dprintf(STDOUT_FILENO, "obj_data->lst = \033[36m%p\033[0m\n", obj_data->lst);
	dprintf(STDOUT_FILENO, "obj_data->lst_size = \033[36m%zu\033[0m\n", obj_data->lst_size);
	dprintf(STDOUT_FILENO, "obj_data->start = \033[36m%p\033[0m\n", obj_data->start);
	if (obj_data->start)
	{
		obj_data->lst = obj_data->start;
		while (obj_data->lst)
		{
			object = obj_data->lst->content;
			display_object(object);
			obj_data->lst = obj_data->lst->next;
		}
	}
	dprintf(STDOUT_FILENO, "\n\033[2m==================================================\033[0m\n");
}

static void	display_master(t_master *master)
{
	if (master)
	{
		if (master->mlx_data)
			display_mlx_data(master->mlx_data);
		if (master->obj_data)
			display_obj_data(master->obj_data);
		if (master->ambient)
			display_ambient(master->ambient);
		if (master->camera)
			display_camera(master->camera);
		if (master->light)
			display_light(master->light);
	}
}

static void	display_file_content(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = (char *)1;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			dprintf(STDOUT_FILENO, "file_line = %s", line);
		free (line);
	}
	close (fd);
}

void	test_battery(t_master *master, int ac, char **av)
{
	error_messages_int();
	error_messages_char();
	error_messages_ptr();
	error_messages_split();
	dprintf(STDOUT_FILENO, "\n");
	dprintf(STDOUT_FILENO, "ac = %d\n", ac);
	for (int i = 0; av[i]; i++)
		dprintf(STDOUT_FILENO, "av[%d] = %s\n", i, av[i]);
	dprintf(STDOUT_FILENO, "%p\n\n", master);
	display_file_content(av[1]);
	dprintf(STDOUT_FILENO, "\n");
	display_master(master);
}
