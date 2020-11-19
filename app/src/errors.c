/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 23:57:41 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/19 18:26:37 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void	print_usage(void)
{
	dprintf(2, "Usage: ft_traceroute [-h] [-p port] [-m max ttl] \
[-s start ttl] [-t timeout] [-q number of probes] host\n\n\
Usage: ft_traceroute -h for help\n");
}

void	print_error(int code)
{
	if (code == USAGE_ERROR)
		print_usage();
	else
		dprintf(2, "The program was exited with error code %d", code);
}
