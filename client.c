/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:38:08 by thi-phng          #+#    #+#             */
/*   Updated: 2021/09/01 20:09:37 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long		res;
	int						neg;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * neg);
}

void	convert_char(char c, int pid)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(125);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	i = 0;
	if (argc > 1 && argc < 4)
	{
		pid = ft_atoi(argv[1]);
		if (pid == 0 || argc == 1)
		{
			printf("ERROR: Remember to put server's PID !\n");
			exit (EXIT_FAILURE);
		}
		if (argc == 3)
		{
			while (argv[2][i])
				convert_char(argv[2][i++], pid);
		}
		if (argc == 2)
		{
			printf("ERROR: Hello?! You forgot your string genious! ;> \n");
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}
