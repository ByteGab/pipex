/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:45:02 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/23 08:44:01 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>
#include <stdlib.h>

// ------------------------------------------------------------------------------
// TODO 		- If find command, return all path it not find clean all.|
// ------------------------------------------------------------------------------

char	*search_prcs(char *cmd, char **envp)
{
	int		i;
	char	**path;
	char	*full_cmd;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (envp[i] == NULL)
		return (NULL);
	path = ft_split(envp[i] + 5, ':');
	if (path == NULL)
		return (NULL);
	full_cmd = ft_cmd_complete(path,cmd);
	// ft_free(path);
	return (full_cmd);
}
// ------------------------------------------------------------------------
// TODO 		- Splits the command argument into an array of arguments.		|
// ------------------------------------------------------------------------

int	exc_prcs(char *cmd, char **envp)
{
	char	*path;
	char	**args;

	args = ft_split(cmd, ' ');
	if (args == NULL)
		return (1);
	path = search_prcs(args[0], envp);
	if (path == NULL)
	{
		ft_error("Error: path vacio",1);
		//! free all
		// ft_free(args);
		return (1);
	}
	args[0] = path;
	if (execve(args[0], args, envp) == -1)
	{
		ft_error("Error: comando",1);
		// ft_free(args);
		return (1);
	}
	// ft_free(args);
	return (0);
}

void	child1(char *file, char *cmd, int *pip, char **envp)
{
	int	infile;

	infile = 0;
	close(pip[0]);
	infile = open(file, O_RDONLY);
	if (infile < 0)
		ft_error("Error: outfile",1);
	dup2(infile, STDIN_FILENO);
	dup2(pip[1], STDOUT_FILENO);
	close(infile);
	close(pip[1]);
	exc_prcs(cmd, envp);
}

void	child2(char *file, char *cmd, int *pip, char **envp)
{
	int	outfile;

	outfile = 0;
	close(pip[1]);
	outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		ft_error("Error: outfile",1);
	dup2(pip[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(pip[0]);
	exc_prcs(cmd, envp);
}
int	main(int argc, char *argv[], char **envp)
{
	int		pip[2];
	pid_t	pid1, pid2;
	
	if (argc != 5)
		ft_error("Error: argumentos invalidos", 1);
	if (pipe(pip) == -1)
		ft_error("Error: creación pipe", 1);
	pid1 = fork();
	if (pid1 == -1)
		check_pipe("Error: primer hijo", pip);
	else if (pid1 == 0)
		child1(argv[1], argv[2], pip, envp);
	pid2 = fork();
	if (pid2 == -1)
	check_pipe("Error: segundo hijo", pip);
	else if (pid2 == 0)
		child2(argv[4], argv[3], pip, envp);
	ft_free(1, pip);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
