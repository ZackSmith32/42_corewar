/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:15:14 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/17 21:20:50 by kdavis           ###   ########.fr       */
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

	end = ft_strrchr(name);
}

int	main(int argc, char **argv)
{
	t_asm			master;
	int				ern;
	int				fd;

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
