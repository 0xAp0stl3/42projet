/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:59:29 by mrocher           #+#    #+#             */
/*   Updated: 2023/12/06 10:33:47 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
* Write an argument error
*/
void	exit_modif(int ex)
{
	if (ex == 0)
	{
		ft_putstr_fd("Error av\n", 2);
		ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(EXIT_FAILURE);
	}
}

/*
* Modified version of execve which allows you to execute a program. 
* Replaces the process dump.
*/
void	execve_modif(char *av, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = getpath_modif(cmd[0], env);
	if (execve(path, cmd, env) == -1)
	{
		ft_putstr_fd("Error execve: ", 2);
		ft_putendl_fd(cmd[0], 2);
		ft_free(cmd);
		exit(0);
	}
}

/*
* Child process which takes into account the first command --> cmd1
* With the appropriate file which is file1 here
*/
void	cmd1_processus(char **av, char **env, int *end)
{
	int	f1;

	f1 = open_modif(av[1], 0);
	if (f1 == -1)
	{
		ft_putstr_fd("Error opening file\n", 2);
		exit_modif(0);
	}
	dup2(f1, STDIN_FILENO);
	close(f1);
	close(end[0]);
	dup2(end[1], STDOUT_FILENO);
	close(end[1]);
	execve_modif(av[2], env);
}

/*
* Child process which takes into account the second command --> cmd2 
* With the appropriate file which is file2 here
*/
void	cmd2_processus(char **av, char **env, int *end)
{
	int	f2;

	f2 = open_modif(av[4], 1);
	if (f2 == -1)
	{
		ft_putstr_fd("Error opening file\n", 2);
		exit_modif(0);
	}
	dup2(f2, STDOUT_FILENO);
	close(f2);
	close(end[1]);
	dup2(end[0], STDIN_FILENO);
	close(end[0]);
	execve_modif(av[3], env);
}

/*
* Main that allows you to manage the pipe.
* The second command waits for the first.
*/
int	main(int ac, char **av, char **env)
{
	int		end[2];
	pid_t	pid;

	if (ac != 5)
		exit_modif(0);
	if (pipe(end) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		cmd1_processus(av, env, end);
	else
	{
		waitpid(pid, NULL, 0);
		cmd2_processus(av, env, end);
	}
	return (0);
}
