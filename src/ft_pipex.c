/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbazire <tbazire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 15:00:48 by tbazire           #+#    #+#             */
/*   Updated: 2014/01/03 22:45:31 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"ft_pipex.h"
#include		"errno.h"
static int		ft_execve(char *path, char **cmd, char **env)
{
	char		**tab;
	char		*tmp;
	int			i;

	i = 0;
	tab = ft_strsplit(path, ':');
	while (tab[i])
	{
		if (cmd[0][0] != '/')
			tmp = ft_str3join(tab[i], "/", cmd[0]);
		else
			tmp = cmd[0];
		execve(tmp, cmd, env);
		free(tmp);
		++i;
	}
	return (0);
}

static int		work1(int pfd, char *path, char **av, char **env)
{
	int			fd;
	char		**cmd;
	char		*err;

	cmd = ft_strsplit(av[2], ' ');
	if (!cmd[0])
		ft_exit(-1, ": \033[1;31mEmpty command\033[0m");
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_exit(access(av[1], F_OK), ft_str3join(": ", av[1], \
							", \033[1;31mno such file\033[0m"));
		ft_exit(access(av[1], R_OK), ft_str3join(": ", av[1], \
									", \033[1;31mpermission denied\033[0m"));
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pfd, STDOUT_FILENO);
	close(pfd);
	ft_execve(path, cmd, env);
	err = ft_str3join(": ", cmd[0], ", \033[1;31mcommand not found\033[0m");
	ft_freematrice(&cmd);
	ft_exit(-1, err);
	return (0);
}

static int		work2(int pfd, char *path, char **av, char **env)
{
	int			fd;
	char		**cmd;
	char		*err;

	cmd = ft_strsplit(av[3], ' ');
	if (!cmd[0])
		ft_exit(-1, ": \033[1;31mEmpty command\033[0m");
	if (av[4] && (fd = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU | S_IRGRP \
					| S_IROTH)) == -1)
	{
		ft_exit(access(av[4], R_OK), ft_str3join(": ", av[4], \
									", \033[1;31mpermission denied\033[0m"));
		ft_exit(-1, ft_str3join(": ", av[4], \
							", \033[1;31mno such file\033[0m"));
	}
	dup2(pfd, STDIN_FILENO);
	close(pfd);
	if (av[4])
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	ft_execve(path, cmd, env);
	err = ft_str3join(": ", cmd[0], ", \033[1;31mcommand not found\033[0m");
	ft_freematrice(&cmd);
	ft_exit(-1, err);
	return (0);
}

int				ft_pipex(char *path, char **av, char **env)
{
	pid_t		pid;
	int			pipefd[2];
	int			ret;

	ret = 0;
	ft_exit(pipe(pipefd), ", \033[1;31mpipe error\033[0m");
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[1]);
		work2(pipefd[0], path, av, env);
	}
	else
	{
		close(pipefd[0]);
		work1(pipefd[1], path, av, env);
	}
	return (0);
}
