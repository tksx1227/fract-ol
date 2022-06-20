/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:03:39 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/20 18:27:55 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	abs_double(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putstr_fd(char const *s, int fd)
{
	size_t	len;

	if (s == NULL)
		return ;
	len = 0;
	while (s[len] != '\0')
		len++;
	while (INT_MAX < len)
	{
		write(fd, s, INT_MAX);
		s += INT_MAX;
		len -= INT_MAX;
	}
	write(fd, s, len);
}

void	print_usage(void)
{
	ft_putstr_fd("Usage: fractol <TYPE NUMBER>\n", STDERR_FILENO);
	ft_putstr_fd("The available type numbers are:\n", STDERR_FILENO);
	ft_putstr_fd("  - 0: Julia\n", STDERR_FILENO);
	ft_putstr_fd("  - 1: Mandelbrot\n", STDERR_FILENO);
	ft_putstr_fd("  - 2: Burning ship\n", STDERR_FILENO);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	if (s1 == NULL || s2 == NULL)
		return (INT_MIN);
	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (p1[i] != '\0' || p2[i] != '\0')
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

uint32_t	rgb2hex(unsigned char r, unsigned char g, unsigned char b)
{
	uint32_t	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}
