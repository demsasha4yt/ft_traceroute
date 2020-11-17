/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_net.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:46:12 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/16 23:28:46 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NET_H
# define FT_NET_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netinet/ip_icmp.h>
# include <netinet/ip.h>
# include <netdb.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/time.h>

# include "ft_net_types.h"
# include "ft_net_tpacket.h"

typedef int 					t_socket;

# define SOCKET_CREATE_ERROR	-1
# define SOCKET_SEND_ERROR		-2
# define DEFAULT_TIMEOUT		2000
# define DEFAULT_TTL			110

/*
** =========Helpers==========
*/

/*
** net_gettime returns current time in suseconds_t
*/
suseconds_t			net_gettime(void);

/*
** print_by_byte prints uint8_t array by byte
*/
void				print_by_byte(uint8_t *packet, int size);

/*
** in_cksum calcs internet cheksum
*/
uint16_t			in_cksum(uint8_t *data, size_t length);

/*
** packet_create creates new packet with type(IPPROTO_ICMP, IPPROTO_UDP,IPPROTO_TCP etc..)
** type: type of packet
** to: destination sockaddr
*/
t_packet			*packet_create(int32_t type, t_sockaddr_in to);

/*
** packet_destroy_buffer destroys buffer of packet
*/
void				packet_destroy_buffer(t_packet *packet);

/*
** packet_destroy_message destroys message of packet
*/
void				packet_destroy_message(t_packet *packet);

/*
* packet_destroy destroys packet.
*/
void				packet_destroy(t_packet *packet);

/*
** packet_fill_icmp fills packet icmp header
*/
void				packet_fill_icmp(t_packet *packet, uint8_t type, uint8_t code);

/*
** packet_fill_udp fills packet udp header
*/
void				packet_fill_udp(t_packet *packet, uint16_t dstport, uint16_t srcport);

/*
** packet_fill_ip fills packet ip header
*/
void				packet_fill_ip(t_packet *packet);

/*
** packet_set_message set message for packet
*/
void				packet_set_message(t_packet *packet, char *message);

/*
** packet_get_hdr_len returns packet hdr length
*/
uint16_t			packet_get_hdr_len(t_packet *packet);

/*
** packet_print_debug prints packet structure to screen
*/

void				packet_print_debug(t_packet *packet);
/*
** packet_set_ttl sets ttl to packet;
*/
void				packet_set_ttl(t_packet *packet, uint8_t ttl);
/* 
** calc_icmp_cksum calcs icmp checksum.
*/
void				calc_icmp_cksum(t_icmphdr *icmphdr, t_packet *packet, uint16_t offset);

/* 
** calc_udp_cksum calcs udp checksum.
*/
void				calc_udp_cksum(t_udphdr *udphdr, t_packet *packet, uint16_t offset);

/* 
** calc_tcp_cksum calcs tcp checksum.
*/
void				calc_tcp_cksum(t_tcphdr *tcphdr, t_packet *packet, uint16_t offset);

/*
**	packet_calc calculate message and checksums
*/
int					packet_calc(t_packet *packet, int withip);

/*
**  Sockets ** 
*/

/* 
** calc_ip_cksum calcs ip checksum.
*/
void	calc_ip_cksum(t_iphdr *iphdr, t_packet *packet);

t_socket			socket_create(int32_t protocol, int32_t hdrincl, int32_t broadcast, int32_t timeout);
void				socket_close(t_socket socket);
int					send_socket_raw(t_socket socket, int32_t flags, t_packet *pckt);
int					socket_settimeout(t_socket sock, int32_t timeout_sec);

#endif
