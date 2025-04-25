/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:12:59 by mrocher           #+#    #+#             */
/*   Updated: 2023/12/05 00:29:13 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
int		gnl(char **line);
char	*getenv_modif(char *name, char **env);
char	*getpath_modif(char *cmd, char **env);
void	exit_modif(int ex);
void	execve_modif(char *av, char **env);
void	child_processus_bonus(char *av, char **env);
void	here_doc(char *limiter, int ac);

#endif