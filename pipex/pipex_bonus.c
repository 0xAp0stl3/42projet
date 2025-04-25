/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:13:00 by mrocher           #+#    #+#             */
/*   Updated: 2023/12/06 10:09:11 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	if (ex == 1)
	{
		ft_putstr_fd("Error av\n", 2);
		ft_putstr_fd("./pipex file1 cmd1 cmd2 ... file2\n", 1);
		ft_putstr_fd("./pipex here_doc LIMITER cmd1 cmd2 ... file\n", 1);
		exit(EXIT_SUCCESS);
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
* Create a pipe to establish a connection between the child 
* process and the parent process.
* The child process will close the read pipe and redirect to write.
*/
void	child_processus_bonus(char *av, char **env)
{
	int		pipefd[2];
	pid_t	pip;

	if (pipe(pipefd) == -1)
		exit_modif(0);
	pip = fork();
	if (pip == -1)
		exit_modif(0);
	if (pip == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		execve_modif(av, env);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(pip, NULL, 0);
	}
}

/*
* Creates a pipe creates a child process which reads lines 
* until it finds a line matching the LIMITER
*/
void	here_doc(char *limiter, int ac)
{
	int		pipefd[2];
	pid_t	pip;
	char	*line;

	if (ac < 6)
		exit_modif(1);
	if (pipe(pipefd) == -1)
		exit_modif(0);
	pip = fork();
	if (pip == 0)
	{
		close(pipefd[0]);
		while (gnl(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(pipefd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	f1;
	int	f2;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			i = 4;
			f2 = open_modif(av[ac - 1], 2);
			here_doc(av[2], ac);
		}
		else
		{
			i = 2;
			f2 = open_modif(av[ac - 1], 1);
			f1 = open_modif(av[1], 0);
			dup2(f1, STDIN_FILENO);
		}
		while (i < ac - 2)
			child_processus_bonus(av[i++], env);
		dup2(f2, STDOUT_FILENO);
		execve_modif(av[ac - 2], env);
	}
	exit_modif(1);
}
