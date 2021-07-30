/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:16:33 by abridger          #+#    #+#             */
/*   Updated: 2021/07/30 14:45:13 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(pid_t nbr, char *str)
{
	int				i;
	size_t			offset;

	i = 0;
	while (i < ft_strlen(str))
	{
		offset = 0;
		while (offset < sizeof(char) * CHAR_BIT)
		{
			if ((str[i] >> offset) & 1)
			{
				if (kill(nbr, SIGUSR1) < -1)
					ft_puterror("Error signal SIGUSR2 to server.");
			}
			else
			{
				if (kill(nbr, SIGUSR2) < -1)
					ft_puterror("Error signal SIGUSR1 to server.");
			}
			offset++;
			usleep(100);
		}
		i++;
	}
}

static void	client_hdl(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
	{
		ft_putstr("Server with PID: ");
		ft_putnbr(siginfo->si_pid);
		ft_putstr(" got a message.\n");
	}
	else
		ft_puterror("Error signal.");
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;
	int					nbr;

	if (argc != 3)
		wrong_args(1);
	nbr = ft_atoi(argv[1]);
	if (!nbr)
		wrong_args(2);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &client_hdl;
	if ((sigaction(SIGUSR1, &act, NULL)) < 0)
		ft_puterror("Message confirmation error.");
	send_message(nbr, argv[2]);
	send_message(nbr, "\n");
	while (1)
		pause();
	return (0);
}
