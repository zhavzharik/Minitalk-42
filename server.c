/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:16:48 by abridger          #+#    #+#             */
/*   Updated: 2021/07/30 15:08:19 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_hdl(int sig, siginfo_t *siginfo, void *context)
{
	static uint8_t	g_ch;

	(void)context;
	if (sig == SIGUSR1)
	{
		g_ch += 1 << g_offset;
		g_offset++;
	}
	else if (sig == SIGUSR2)
		g_offset++;
	if (g_offset == sizeof(char) * CHAR_BIT)
	{
		if (g_ch == 0)
			write(1, "\n", 1);
		else
		{
			ft_putchar(g_ch);
			if (g_ch == 10)
				kill(siginfo->si_pid, SIGUSR1);
			g_ch = 0;
			g_offset = 0;
		}
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;
	pid_t				process_id;

	if (argc != 1 || argv[1])
		ft_puterror("Server must be launched without arguments.");
	process_id = getpid();
	ft_putstr("I'm a server. My PID is ");
	ft_putnbr(process_id);
	ft_putstr(".\nI'm waiting for a message from client...\n");
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &server_hdl;
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		ft_puterror("Error signal.");
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		ft_puterror("Error signal.");
	while (1)
		usleep (100);
	return (0);
}
