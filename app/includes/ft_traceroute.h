/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:41:33 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/19 17:44:38 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

# include "ft_net.h"
# include "libft.h"

# define USAGE_ERROR 16

typedef struct			s_probe
{
	int					probe;
	int					ttl;
	t_timeval			tv_send;
	t_timeval			tv_select;
	t_timeval			tv_read;
	double				tv_delta;
	fd_set				readfs;
	int					ret;
	t_iphdr				*iphdr;
	t_icmphdr			*icmphdr;
	t_sockaddr_in		from;
	socklen_t			fromlen;
	uint8_t				buf[512];
	char				host[INET_ADDRSTRLEN + 1];
}						t_probe;

typedef struct			s_trace
{
	uint8_t				ttl;
	uint8_t				ttlst;
	int32_t				timeout;
	int32_t				probes;
	int32_t				port;
	char				*addr;
	uint32_t			s_addr;
	t_socket			socket;
	t_socket			socket_icmp;
}						t_trace;

int						check_input(int ac, char **av);
int						parse_input(char **av, t_trace *trace);
void					print_error(int code);
t_socket				init_socket(int domain, int type, int protocol);
void					set_ttl(t_socket socket, uint8_t ttl);
void					send_packet(t_socket socket, int port,
	uint32_t saddr, t_timeval *tv_send);
int						read_packet(int sock, t_probe *probe);
int						run_probes(t_trace *trace, t_probe *probe);
int						ft_isnumeric(char *str);

#endif
