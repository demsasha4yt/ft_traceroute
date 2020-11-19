/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:41:09 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/19 18:26:03 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

static void		mainloop(t_trace *trace)
{
	int		ret;
	t_probe	probe;

	while (trace->ttlst <= trace->ttl)
	{
		set_ttl(trace->socket, trace->ttlst);
		ret = run_probes(trace, &probe);
		if (ret)
			break ;
		trace->ttlst++;
		printf("\n");
	}
}

static void		defaults(t_trace *trace)
{
	ft_memset(trace, 0, sizeof(t_trace));
	trace->ttl = 30;
	trace->ttlst = 1;
	trace->port = 33434;
	trace->timeout = 2;
	trace->probes = 3;
	trace->socket = -1;
	trace->socket_icmp = -1;
}

int				main(int argc, char **argv)
{
	t_trace		trace;

	defaults(&trace);
	if (check_input(argc, argv))
	{
		print_error(USAGE_ERROR);
		return (EXIT_FAILURE);
	}
	if (parse_input(argv, &trace))
		return (EXIT_FAILURE);
	trace.socket = init_socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	trace.socket_icmp = init_socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (trace.socket < 0 || trace.socket_icmp < 0)
		return (EXIT_FAILURE);
	mainloop(&trace);
	close(trace.socket);
	return (EXIT_SUCCESS);
}
