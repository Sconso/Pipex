/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 17:17:12 by sconso            #+#    #+#             */
/*   Updated: 2014/01/03 21:35:46 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# define APP_NAME "\033[1;34mpipex\033[0m"

# include <libft.h>
# include <fcntl.h>
# include <signal.h>

char	*get_env(char *key, char **env);
void	ft_exit(int code, char *str);
int		ft_pipex(char *path, char **av, char **env);
char	*ft_str3join(char const *s1, char const *s2, char const *s3);
void	ft_freematrice(char ***matrice);

#endif /* FT_PIPEX_H */
