/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconso <sconso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 19:39:42 by sconso            #+#    #+#             */
/*   Updated: 2013/12/31 18:25:23 by sconso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*get_env(char *key, char **env)
{
	int		i;
	size_t	key_len;

	i = 0;
	key = ft_strjoin(key, "=");
	key_len = ft_strlen(key);
	while (env[i] != '\0')
	{
		if (ft_strncmp(env[i], key, key_len) == 0)
		{
			free(key);
			return (env[i] + key_len);
		}
		i++;
	}
	free(key);
	return (NULL);
}

char	*ft_str3join(char const *s1, char const *s2, char const *s3)
{
	int		size;
	int		i;
	char	*str;

	if (s1 == 0 || s2 == 0 || s3 == 0)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	str = (char *)malloc((size + 1) * sizeof(*str));
	i = -1;
	while (*s1)
		str[++i] = *s1++;
	while (*s2)
		str[++i] = *s2++;
	while (*s3)
		str[++i] = *s3++;
	str[++i] = 0;
	return (str);
}

void	ft_freematrice(char ***matrice)
{
	int		i;

	i = -1;
	while ((*matrice)[++i])
		free((*matrice)[i]);
	free(*matrice);
}
