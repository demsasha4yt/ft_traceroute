/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:00:13 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/28 17:17:29 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

static void		defaultprobe(t_trace *trace, t_probe *probe, int probeid)
{
	ft_memset(probe, 0, sizeof(t_probe));
	probe->probe = probeid;
	probe->ttl = trace->ttlst;
	probe->tv_select.tv_sec = (long)trace->timeout;
	probe->tv_select.tv_usec = 0;
	FD_ZERO(&probe->readfs);
}

static int		select_probe(t_trace *trace, t_probe *probe, int i)
{
	FD_SET(trace->socket_icmp, &probe->readfs);
	probe->ret = select(trace->socket_icmp + 1, &probe->readfs, NULL, NULL,
		&probe->tv_select);
	if (probe->ret < 0)
		return (1);
	if (probe->ret == 0 && i == 0)
		printf("%2d ", probe->ttl);
	if (probe->ret == 0)
		printf(" *");
	if (FD_ISSET(trace->socket_icmp, &probe->readfs))
	{
		probe->ret = read_packet(trace->socket_icmp, probe);
		if ((probe->ret == 0 || probe->ret == 3) && (i + 1) == trace->probes)
		{
			printf("\n");
			return (1);
		}
	}
	return (0);
}

int				run_probes(t_trace *trace, t_probe *probe)
{
	int				i;
	int				ret;

	i = 0;
	while (i < trace->probes)
	{
		defaultprobe(trace, probe, i);
		send_packet(trace->socket, trace->port, trace->s_addr, &probe->tv_send);
		ret = select_probe(trace, probe, i);
		if (ret)
			return (ret);
		i++;
	}
	return (0);
}
