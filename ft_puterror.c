/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:29:13 by abridger          #+#    #+#             */
/*   Updated: 2021/07/29 17:59:49 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_puterror(char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
	exit (0);
}

void	wrong_args(int check)
{
	if (check == 1)
		ft_puterror("Client must be launched\
	with server's PID and string, that should be sent.");
	else if (check == 2)
		ft_puterror("First argument should be server's PID,\
	second is a string, that should be sent.");
}
