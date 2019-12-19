/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putstrchr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:06:06 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/11 17:06:48 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	printf_putchar(char c, int *printed, int fd)
{
	*printed = *printed + 1;
	write(fd, &c, 1);
}

void	printf_putstr(char const *s, int *printed, int fd)
{
	unsigned int i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
		printf_putchar(s[i++], printed, fd);
}
