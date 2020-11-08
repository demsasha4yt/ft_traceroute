/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_net_tpacket.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:12:43 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/08 17:11:28 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NET_TPACKET_H
# define FT_NET_TPACKET_H

#include "ft_net_types.h"

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
	char				*msg;
	uint16_t				msglen;
	t_iphdr					iphdr;
	t_icmphdr				icmphdr;
	t_udphdr				udphdr;
	t_tcphdr				tcphdr;
	t_tcpopts				tcpopts;
	uint8_t					*buf;
	uint16_t				buflen;
}							t_packet;

#endif
