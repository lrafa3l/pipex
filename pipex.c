/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:01:45 by lrafael           #+#    #+#             */
/*   Updated: 2024/09/06 07:17:04 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

static void	ft_print_error(const char *msg)
{
	ft_printf("%sError:%s %s\n", RED, RESET, msg);
	exit(EXIT_FAILURE);
}

static void	ft_execute(char *cmd[])
{
	char	*pathname;

	pathname = ft_strjoin("/bin/", cmd[0]);
	if (!pathname)
		ft_printf_error("path not found.");
	if (execve(pathname, cmd, NULL) < 0)
		ft_printf_error("execve failed");
}

static void	ft_child_process(char **argv, int *fd)
{
	int		file_in;
	char	**arg;

	file_in = open(argv[1], O_RDONLY, 0644);
	if (file_in < 0)
		ft_printf_error("input file failed.");
	if (dup2(fd[1], STDOUT_FILENO) < 0 || dup2(file_in, STDIN_FILENO) < 0)
		ft_printf_error("dup2 failed");
	arg = ft_split(argv[2], ' ');
	if (!arg)
		ft_printf_error("command not found.");
	close(file_in);
	close(fd[0]);
	close(fd[1]);
	ft_execute(arg);
}

static void	ft_parent_process(char **argv, int *fd)
{
	int		file_out;
	char	**arg;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out < 0)
		ft_printf_error("output file failed.");
	if (dup2(fd[0], STDIN_FILENO) < 0 || dup2(file_out, STDOUT_FILENO) < 0)
		ft_printf_error("dup2 failed");
	arg = ft_split(argv[3], ' ');
	if (!arg)
		ft_printf_error("command not found.");
	close(file_out);
	close(fd[0]);
	close(fd[1]);
	ft_execute(arg);
}

int	main(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5 && argv[1][0] && argv[2][0] && argv[3][0] && argv[4][0])
	{
		if (pipe(fd) < 0)
			ft_printf_error("pipe failed.");
		pid = fork();
		if (pid < 0)
			ft_printf_error("fork failed.");
		if (pid == 0)
			ft_child_process(argv, fd);
		waitpid(pid, NULL, 0);
		ft_parent_process(argv, fd);
	}
	else
	{
		ft_printf("%s%sError:%s Bad arguments!\n", RED, BOLD, RESET);
		ft_printf("%sEx: ./pipex <file1> <cmd1> <cmd2> <file2>\n%s", YELLOW,
			RESET);
	}
	return (0);
}
