/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 19:12:10 by sconso            #+#    #+#             */
/*   Updated: 2013/12/09 11:58:39 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_readline			*addlistitem(t_readline *list, int fd)
{
	t_readline				*tmp;

	tmp = (t_readline *)malloc(sizeof(*list));
	if (tmp)
	{
		tmp->fd = fd;
		tmp->content = ft_strdup("");
		if (list)
			list->next = tmp;
		tmp->next = NULL;
	}
	return (tmp);
}

static int					reading(int fd, char **len, t_readline **node)
{
	char					*buf;
	int						ret;
	char					*tmp;

	buf = (char *)malloc(sizeof(*buf) * (BUFF_SIZE + 1));
	if (!buf)
		return (-1);
	while (!(*len = ft_strchr((*node)->content, '\n'))
			&& (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		if ((*node)->content != 0)
		{
			tmp = (*node)->content;
			(*node)->content = ft_strjoin(tmp, buf);
			free(tmp);
		}
		else
			(*node)->content = ft_strdup(buf);
	}
	free(buf);
	if (ret < 0)
		return (-1);
	return (1);
}

int							get_next_line(int const fd, char **line)
{
	static t_readline		*first;
	t_readline				*node;
	char					*len;
	char					*tmp;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	first = (first ? first : addlistitem(first, fd));
	node = first;
	while (node->fd != fd && node->next != NULL)
		node = node->next;
	node = (node->fd == fd ? node : addlistitem(node, fd));
	if (reading(fd, &len, &node) == -1)
		return (-1);
	if (len || ((len = ft_strchr(node->content, '\0')) && node->content[0]))
	{
		*line = ft_strsub(node->content, 0, len - node->content);
		tmp = node->content;
		node->content = ft_strdup(len + 1);
		free(tmp);
		return (1);
	}
	return (0);
}
