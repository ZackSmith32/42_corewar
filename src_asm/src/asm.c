/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:15:14 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/25 22:46:37 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int	write_file(char *name, t_asm *master)
{
	char	*end;
	size_t	dist;
	int		fd;
	int		ern;

	dist = 0;
	if ((end = ft_strrchr(name, '.')))
		dist = end - name;
	if (!(master->name = ft_strndup(name, dist + 4)))
		return (1);
	ft_memmove(master->name + dist, ".cor", 4);
	if ((fd = open(master->name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)) == -1)
		return (2);
	if ((ern = write(fd, &HEADER, sizeof(HEADER))) != -1)
		ern = write(fd, OUTPUT.arr, OUTPUT.len * OUTPUT.size);
	if ((close(fd) == -1) ||  ern == -1)
		return (ern == -1 ? 5 : 3);
	return (0);
}

static int	init_assembler(char *file, t_asm *master)
{
	ft_bzero(master, sizeof(*master));
	master->cmd_info.name_cmd_len = ft_strlen(NAME_CMD_STRING);
	master->cmd_info.comment_cmd_len = ft_strlen(COMMENT_CMD_STRING);
	if (!(ft_initialize_vec(&master->labels, sizeof(t_label), 10, 0)) ||
		!(ft_initialize_vec(&master->opp.label_calls,
				sizeof(t_label_calls), 9, 0)) ||
		!(ft_initialize_vec(&master->opp.output, sizeof(char), 10, 0)))
		return (print_error(1, NULL, 0, 0));
	if ((master->pi.fd = open(file, O_RDONLY)) == -1)
		return (print_error(2, NULL, 0, 0));
	return (0);
}

int	main(int argc, char **argv)
{
	t_asm			master;
	int				ern;

	if (argc != 2)
		return (ft_printf("Usage:./asm champion.s\n"));
	if ((ern = init_assembler(argv[1], &master)))
		return (asm_error(&master, ern));
	if ((ern = read_header(&master)))
		return (asm_error(&master, ern));
	if ((ern = read_body(&master)))
		return (asm_error(&master, ern));
	ern = write_file(argv[1], &master);
	return (asm_error(&master, ern));
}
