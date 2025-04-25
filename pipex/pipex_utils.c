/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:56:30 by mrocher           #+#    #+#             */
/*   Updated: 2023/12/06 10:48:27 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
* Read the file I want based on 0 for file1 and 1 for file2.
* Depending on the file1 or file2, the read function will do more or less action
*/
int	open_modif(char *files, int file1orfile2)
{
	int	res;

	if (file1orfile2 == 0)
		res = open(files, O_RDONLY, 0777);
	if (file1orfile2 == 1)
		res = open(files, O_WRONLY || O_CREAT || O_TRUNC, 0777);
	if (res == -1)
		exit_modif(0);
	return (res);
}

/*
* Frees the memory of the entire array
*/
void	ft_free(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/*
* Getenv modified to recover the environment we want.
* If I want USER, I create a substr and I do a comparison with strcmp
*/
char	*getenv_modif(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

/**
 * * With my getenv_modif, I will retrieve the PATH environment.
 * ? I'm going to split the PATH directory into an array so I can browse it. 
 * ? Then my path_valid variable, I will try to construct a valid path.
 * * Then I check if the path found is accessible and executable with access
 */
char	*getpath_modif(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**path_valid;
	char	*path_part;
	char	**split_cmd;

	i = -1;
	path_valid = ft_split(getenv_modif("PATH", env), ':');
	split_cmd = ft_split(cmd, ' ');
	while (path_valid[++i])
	{
		path_part = ft_strjoin(path_valid[i], "/");
		exec = ft_strjoin(path_part, split_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free(split_cmd);
			return (exec);
		}
		free(exec);
	}
	ft_free(path_valid);
	ft_free(split_cmd);
	return (cmd);
}
