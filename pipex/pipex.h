/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:54:14 by mrocher           #+#    #+#             */
/*   Updated: 2023/12/06 10:33:05 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>

int		open_modif(char *files, int file1orfile2);
void	ft_free(char **array);
int		spec(char *str, char *special);
char	*getenv_modif(char *name, char **env);
char	*getpath_modif(char *cmd, char **env);
void	exit_modif(int ex);
void	execve_modif(char *av, char **env);
void	cmd1_processus(char **av, char **env, int *end);
void	cmd2_processus(char **av, char **env, int *end);

#endif