/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbazire <tbazire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 15:02:02 by tbazire           #+#    #+#             */
/*   Updated: 2014/01/03 22:34:27 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_pipex.h"

void		ft_exit(int code, char *str)
{
	if (code < 0)
	{
		ft_putstr_fd(APP_NAME, 2);
		ft_putendl_fd(str, 2);
		_exit(1);
	}
}

void	zbra(int s)
{
	ft_putstr_fd("OKJDFPK\n", 2);
	s = 0;
}

int			main(int ac, char **av)
{
	char			*path;
	extern char		**environ;

	if (ac < 4)
		ft_exit(-1, ": usage: ./pipex file1 cmd1 cmd2 file2");
	if ((path = get_env("PATH", environ)) == NULL)
		ft_exit(-1, "error: can't get PATH environment variable");
	signal(SIGPIPE, SIG_IGN);
	ft_pipex(path, av, environ);
	return (EXIT_SUCCESS);
}
