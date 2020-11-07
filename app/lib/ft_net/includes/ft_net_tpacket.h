/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_net_tpacket.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:12:43 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/07 17:51:08 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NET_TPACKET_H
# define FT_NET_TPACKET_H

# include "ft_traceroute_types.h"


/*
** [t_packet format]:
** type: IPPROTO_ICMP, IPPROTO_UDP, IPPROTO_TCP
** ip header
** icmp header
** udp header
** tcp header
** tcp options;
** destination addres
** message
** result buffer to send (IP_HDR + PROTO_HDR + MSG);
*/
typedef struct				s_packet
{
	int32_t					type;
	t_sockaddr_in			to;
	uint8_t					ttl;
	uint8_t					sequence;
	uint8_t					*msg;
	uint16_t				msglen;
	t_iphdr					iphdr;
	t_icmphdr				icmphdr;
	t_udphdr				udphdr;
	t_tcphdr				tcphdr;
	t_tcpopts				tcpopts;
	uint8_t					*buf;
}							t_packet;

#endif