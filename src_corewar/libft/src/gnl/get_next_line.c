/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 11:08:38 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/20 15:42:03 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <unistd.h>

/*
** Parce_buffer will search the buffer for the new line. If a new line is found
** then set the lst->content to a duplicate of the buffer starting at the
** character after the new line, and set line to a substring of the start of the
** buffer up until the new line character. If no new line characters are found
** return NULL.
*/

static ssize_t	parce_buffer(t_list *lst, char *buf, char **line)
{
	ssize_t	buflen;
	ssize_t	nlen;
	char	*nl;
	char	*leftover;

	buflen = (ssize_t)ft_strlen(buf);
	if (!(nl = ft_memchr(buf, '\n', buflen)))
		return (0);
	nlen = nl - buf;
	if (!(*line = ft_strndup(buf, nlen)))
	{
		ft_memdel((void *)&buf);
		return (-1);
	}
	leftover = ft_strndup(nl + 1, buflen - nlen - 1);
	ft_memdel((void *)&buf);
	if (!(leftover))
	{
		ft_memdel((void **)line);
		return (-1);
	}
	lst->content = leftover;
	return (nlen);
}

/*
** Read_line will add content to the end of lst->content in chunks of BUFF_SIZE
** until a new line is found, or the file is read to completion.
*/

static ssize_t	read_line(t_list *lst, size_t o, char **line, ssize_t pflag)
{
	ssize_t	ret;

	while (!(pflag))
	{
		if ((ret = read(lst->content_size, lst->content + o - 1, BUFF_SIZE))
			== -1)
			return (-2);
		((char *)lst->content)[ret + o] = '\0';
		if ((pflag = parce_buffer(lst, lst->content, line)) != 0)
			break ;
		o += BUFF_SIZE;
		if (!(lst->content = ft_memreallocf(lst->content, BUFF_SIZE + o, o)))
			return (-1);
		if (!ret)
		{
			pflag = (ssize_t)ft_strlen((char*)lst->content);
			*line = ft_strndup((char *)lst->content, pflag);
			ft_memdel(&lst->content);
			if (**line && (lst->content = ft_memalloc(1)))
				return (pflag);
			return (!(*line) ? -1 : 0);
		}
	}
	return (pflag);
}

/*
** Search_line will search the left over contents in lst->content for a
** new line. If one is found then it returns succesful, but if one isn't
** found then it will initiate read line in order to find the next new line.
*/

static ssize_t	search_line(t_list *lst, char **line)
{
	ssize_t	parce_flag;
	size_t	o;

	if ((parce_flag = parce_buffer(lst, lst->content, line)) == -1)
		return (-1);
	if (parce_flag == 0)
	{
		o = ft_strlen(lst->content) + 1;
		if (!(lst->content = ft_memreallocf(lst->content, BUFF_SIZE + o, o)))
			return (-1);
		parce_flag = read_line(lst, o, line, parce_flag);
		if (parce_flag <= 0)
			ft_memdel(&lst->content);
	}
	return (parce_flag);
}

/*
** Scans fd_list for a link that contains the appropriate fd. If none are found
** then a new link is made and added to the front. WORKS!
*/

static t_list	*scan_list(t_list **fd_lst, const int fd)
{
	t_list	*tail;
	void	*ptr;

	tail = *fd_lst;
	while (tail)
	{
		if (tail->content_size == (size_t)fd)
			return (tail);
		tail = tail->next;
	}
	if (!(ptr = ft_memalloc(1)))
		return (NULL);
	tail = ft_lstnew(ptr, 1);
	ft_memdel(&ptr);
	if (!(tail))
		return (NULL);
	tail->content_size = fd;
	if (!(*fd_lst))
	{
		*fd_lst = tail;
		return (tail);
	}
	ft_lstadd(fd_lst, tail);
	return (tail);
}

/*
** get_next_line returns the next line in the file described by fd.
** It returns 1 in the case that it succesfully found a new line,
** 0 in the case that it has finished reading the file,
** and -1 in the case that there was an error.
*/

ssize_t			get_next_line(const int fd, char **line)
{
	static t_list	*fd_lst = 0;
	ssize_t			sl_flag;
	t_list			*tail;

	if (fd < 0 || line == NULL || !(tail = scan_list(&fd_lst, fd)))
		return (-1);
	*line = NULL;
	if (!(sl_flag = search_line(tail, line)))
	{
		ft_relink_lst(&fd_lst, tail);
		return (0);
	}
	if (sl_flag == -1)
	{
		ft_lstdel(&fd_lst, ft_delcontent);
		return (-1);
	}
	if (sl_flag == -2)
	{
		ft_relink_lst(&fd_lst, tail);
		return (-1);
	}
	return (sl_flag);
}
