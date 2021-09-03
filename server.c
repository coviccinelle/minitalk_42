/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <thi-phng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:59:13 by thi-phng          #+#    #+#             */
/*   Updated: 2021/09/01 20:11:03 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_put_char(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_put_char('-');
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_put_char(nb % 10 + '0');
}

/* ------- You can you printf in client but not server, 
 * if not it won't capture the signals--------- */

/*Translate all the different sent bits (in chain) to reconstruct the char */
void	decipher_message(int digit)
{
	static int	n;
	static int	byte;

	if (digit == SIGUSR1)
		byte += 1 << (7 - n);
	n++;
	if (n == 8)
	{
		ft_put_char(byte);
		n = 0;
		byte = 0;
	}
}

/* We'll print the letter once 8 bits arrived  */
int	main(int ac, char **av)
{
	pid_t	pid;

	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		ft_putstr("Hello! My PID is: ");
		ft_putnbr(pid);
		ft_put_char('\n');
		signal(SIGUSR1, decipher_message);
		signal(SIGUSR2, decipher_message);
		while (42)
			pause();
	}
	ft_put_char('\n');
	return (0);
}
