/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:39:20 by thi-phng          #+#    #+#             */
/*   Updated: 2021/09/01 18:39:01 by thi-phng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

void	ft_put_char(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	decipher_message(int digit);
int		ft_atoi(const char *str);
void	covert_char(char c, int pid);

#endif
