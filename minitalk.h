#ifndef MINITALK_H
# define MINITALK_H
# define SIGUSR1 1
# define SIGUSR2 0
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

static size_t	g_offset = 0;
static uint8_t	g_ch = 0;

void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_puterror(char *str);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	wrong_args(int check);

#endif
