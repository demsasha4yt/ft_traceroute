/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 22:04:37 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/19 17:40:05 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

static int		iflag(char *src, int32_t *dest, int min, int max)
{
	int	value;

	if (!ft_isnumeric(src))
		return (1);
	value = ft_atoi(src);
	if (value <= min || value >= max)
		return (1);
	*dest = value;
	return (0);
}

static int		ui8flag(char *src, uint8_t *dest, int min, int max)
{
	int	value;

	if (!ft_isnumeric(src))
		return (1);
	value = (uint8_t)ft_atoi(src);
	if (value <= min || value >= max)
		return (1);
	*dest = value;
	return (0);
}

static int		parse_flags(char ***av, t_trace *trace)
{
	while ((*av)[1] && (*av)[1][0] == '-')
	{
		if ((*av)[1][0] == '-' && (*av)[1][1] == 'h')
			return (1);
		else if ((*av)[1][0] == '-' && (*av)[1][1] == 'p' &&
			iflag((++(*av))[1], &trace->port, 1, 65535))
			return (1);
		else if ((*av)[1][0] == '-' && (*av)[1][1] == 'm' &&
			ui8flag((++(*av))[1], &trace->ttl, 1, 255))
			return (1);
		else if ((*av)[1][0] == '-' && (*av)[1][1] == 's' &&
			ui8flag((++(*av))[1], &trace->ttlst, 1, 255))
			return (1);
		else if ((*av)[1][0] == '-' && (*av)[1][1] == 't' &&
			iflag((++(*av))[1], &trace->timeout, 1, 255))
			return (1);
		else if ((*av)[1][0] == '-' && (*av)[1][1] == 'q' &&
			iflag((++(*av))[1], &trace->probes, 1, 10))
			return (1);
		(*av)++;
		(void)trace;
	}
	return ((*av)[1] == NULL);
}

int				parse_input(char **av, t_trace *trace)
{
	t_addrinfo	hints;
	t_addrinfo	*addrinfo;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	if (parse_flags(&av, trace))
	{
		print_error(USAGE_ERROR);
		return (USAGE_ERROR);
	}
	if (av[1] == NULL)
	{
		print_error(USAGE_ERROR);
		return (USAGE_ERROR);
	}
	if (getaddrinfo(av[1], NULL, &hints, &addrinfo))
	{
		dprintf(2, "ft_traceroute: Can't resolve host %s\n", av[1]);
		return (1);
	}
	trace->s_addr = ((t_sockaddr_in*)addrinfo->ai_addr)->sin_addr.s_addr;
	trace->addr = av[1];
	freeaddrinfo(addrinfo);
	return (0);
}

int				check_input(int ac, char **av)
{
	return (ac < 2 ||
		(av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0' && ac == 2));
}
