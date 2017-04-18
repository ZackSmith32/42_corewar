/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:15:14 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/17 21:51:23 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

/*
** Steps to assembling:
**
** 1. Open and read file.
**
** 2. fill out header struct.
**		(Assign magic, Read program name and comment)
**			Calculate prog_size as you go.
**
** 3. Have an array of function pointers for translating individual operations
*/

static int	read_file(char *name, t_vec *file)
{
	char	buf[BUFF_SIZE];
	ssize_t	ret;
	int		fd;

	if (!(ft_initialize_vec(file, sizeof(char), BUFF_SIZE, 0)))
		return (1);
	if ((fd = open(name, O_RDONLY)) == -1)
		return (2);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!(ft_vecapp(file, buf, ret)))
		{
			close(fd);
			return (1);
		}
	}
	if (ret == -1 || close(fd) == -1)
		return (3);
	if (file->len == file->total)
		if (!(ft_grow_vec(file, file->len * file->size + 1)))
			return (1);
	return (0);
}

static int	write_file(char *name, t_asm *master)
{
	char	*end;
	size_t	dist;
/*	int		fd;*/

	dist = 0;
	ft_printf("Trying to rename name\n");///
	if ((end = ft_strrchr(name, '.')))
		dist = end - name;
	if (!(master->name = ft_strndup(name, dist + 4)))
		return (1);
	ft_memmove(master->name + dist, ".cor", 4);
	return (0);
/*	if ((fd = open(master->name*/
}

int	main(int argc, char **argv)
{
	t_asm			master;
	int				ern;

	if (argc != 2)
		return (ft_printf("Usage:./asm champion.s\n"));
	ft_bzero(&master, sizeof(master));
	if ((ern = read_file(argv[1], &master.file)))
		return (asm_error(&master, ern));
	if ((ern = read_header(&master)))
		return (asm_error(&master, ern));
//	ft_printf("%s", master.file.arr);///
	ern = write_file(argv[1], &master);
	return (asm_error(&master, ern));
}
