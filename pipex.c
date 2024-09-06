/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:01:45 by lrafael           #+#    #+#             */
/*   Updated: 2024/07/15 12:36:59 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./libft/libft.h"

/* Function that will print the error. */
static void	error(const char *msg)
{
	ft_printf("%sError:%s %s\n", RED, RESET, msg);
	exit(EXIT_FAILURE);
}

/* Function that will execute the commands. */
static void	execute(char *cmd[])
{
	char	*pathname;

	pathname = ft_strjoin("/bin/", cmd[0]);
	if (!pathname)
		error("path not found");
	if (execve(pathname, cmd, NULL) < 0)
		error("execve failed");
}

/* Child process that run inside a fork, take the file_in, put the output inside
 a pipe, close unused file descriptors and then call the exec function */
static void	child_process(char **argv, int *fd)
{
	int		file_in;
	char	**arg;

	file_in = open(argv[1], O_RDONLY, 0644);
	if (file_in < 0)
		error("open failed for input file");
	if (dup2(fd[1], STDOUT_FILENO) < 0 || dup2(file_in, STDIN_FILENO) < 0)
		error("dup2 failed");
	arg = ft_split(argv[2], ' ');
	if (!arg)
		error("command not found");
	close(file_in);
	close(fd[0]);
	close(fd[1]);
	execute(arg);
}

/* Parent process that take the data from the pipe, change the output for the
 file_out, close unused file descriptors and also call the exec function */
static void	parent_process(char **argv, int *fd)
{
	int		file_out;
	char	**arg;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out < 0)
		error("open failed for output file");
	if (dup2(fd[0], STDIN_FILENO) < 0 || dup2(file_out, STDOUT_FILENO) < 0)
		error("dup2 failed");
	arg = ft_split(argv[3], ' ');
	if (!arg)
		error("command not found");
	close(file_out);
	close(fd[0]);
	close(fd[1]);
	execute(arg);
}

/* Main function that run the child and parent process or display an error
 message if arguments are wrong */
int	main(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5 && argv[1][0] && argv[2][0] && argv[3][0] && argv[4][0])
	{
		if (pipe(fd) < 0)
			error("pipe failed");
		pid = fork();
		if (pid < 0)
			error("fork failed");
		if (pid == 0)
			child_process(argv, fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, fd);
	}
	else
	{
		ft_putstr_fd("\033[31m\033[1mError: Bad arguments!\n\e[0m", 2);
		ft_putstr_fd("\033[35mEx: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
