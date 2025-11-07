/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:45:14 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/07 23:34:25 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	comm_pipe(int file, int write_end)
{
	int		wr[1024];
	int		count;

	count = 1024;
	while (count == 1024)
	{
		count = read(file, wr, 1024);
		write(write_end, wr, count);
	}
}

char	**check_args(char *file, char *command, int *fd)
{
	char	**args;
	int		fdf;

	if (access(file, F_OK) || access(file, R_OK))
		return (perror(file), NULL);
	args = ft_split(command, ' ');
	if (!args)
		return (ft_printf("ft_split: %s\n", strerror(ENOMEM)), NULL);
	fdf = open(file, O_RDONLY);
	if (fdf == -1)
		return (perror(file), NULL);
	if (pipe(fd))
		return (perror("pipe"), NULL);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		return (perror("dup2"), NULL);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (perror("dup2"), NULL);
	comm_pipe(fdf, fd[1]);
	close(fdf);
	return (args);
}

int	main(int ac, char **av)
{
	int		pid;
	char	**args;
	char	*aux;
	int		fd[2];

	pid = 0;
	if (ac != 5)
		return (ft_printf("Error: %s\n", strerror(EINVAL)), 1);
	args = check_args(av[1], av[2], fd);
	if (!args)
		return (1);
	pid = fork();
	if (!pid)
	{
		close(fd[1]);
		if (!ft_strchr(args[0], '/'))
		{
			aux = ft_strjoin("/bin/", args[0]);
			if (!aux)
				return (ft_printf("ft_strjoin: %s\n", strerror(ENOMEM)), 1);
			free(args[0]);
			args[0] = aux;
		}
		execve(args[0], args, NULL);
		return (perror(args[0]), 1);
	}
	close(fd[1]);
	ft_printf("Waiting for %d\n", pid);
	waitpid(pid, NULL, 0);
	ft_printf("pass\n");
	return (0);
}
