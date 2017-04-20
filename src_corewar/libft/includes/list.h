/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/05 13:44:18 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				lstadd(t_list **alst, t_list *new);
void				lstpush(t_list **alst, t_list *new);
void				lstdel(t_list **alist, void (*del)(void *));
void				lstdelone(t_list **alst, void (*del)(void *));
void				lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*lstnew(void *content);
void				lstprint(t_list *link);
void				lstreverse(t_list **alst);
void				lstsort(t_list **dir_lst, _Bool (compare)(void*, void*));

#endif
