/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:57:37 by sconso            #+#    #+#             */
/*   Updated: 2013/12/08 19:37:42 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <libft.h>
# include <fcntl.h>

# define BUFF_SIZE 200

typedef struct			s_readline
{
	int					fd;
	char				*content;
	struct s_readline	*next;
}						t_readline;

int		get_next_line(int const fd, char ** line);

#endif /* !GET_NEXT_LINE_H */
