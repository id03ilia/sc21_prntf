#include "ft_printf.h"

int	ft_putchar_fd_p(int fd, unsigned char c, t_fpnt_list flagi)
{
	write(fd, &c, 1);
	flagi.length++;
	return (flagi.length);
}

int	ft_putchar_fd_p_0x(int fd, t_fpnt_list flagi)
{
	write(fd, "0x", 2);
	flagi.length++;
	flagi.length++;
	return (flagi.length);
}
