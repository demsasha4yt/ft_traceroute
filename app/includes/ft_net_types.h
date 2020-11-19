/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_net_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:43:58 by bharrold          #+#    #+#             */
/*   Updated: 2020/11/19 18:06:38 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NET_TYPES_H
# define FT_NET_TYPES_H

# include <stdlib.h>
# include <sys/time.h>

# if defined(__linux__)
#  include <asm/byteorder.h>
# elif __APPLE__
#  include <architecture/byte_order.h>
#  if defined(__LITTLE_ENDIAN__)
#   define __LITTLE_ENDIAN_BITFIELD
#  elif __BIG_ENDIAN__
#   define __BIG_ENDIAN_BITFIELD
#  endif
# endif

# define IP_HDR_SIZE 20
# define ICMP_HDR_SIZE 8
# define UDP_HDR_SIZE 8

typedef struct addrinfo		t_addrinfo;
typedef struct sockaddr_in	t_sockaddr_in;
typedef struct in_addr		t_in_addr;
typedef struct sockaddr		t_sockaddr;
typedef struct timeval		t_timeval;
typedef struct timezone		t_timezone;
typedef struct msghdr		t_msghdr;
typedef struct iovec		t_iovec;

/*
** [IP HEADER FORMAT]:
** 4-bit IPv4 version 4-bit header length (in 32-bit words)
** IP type of service
** Total length
** Unique identifier
** Fragment offset field
** Time to live
** Protocol(TCP,UDP etc)
** IP checksum
** Source address
** Dest address
*/
typedef struct				s_iphdr {
# if defined(__LITTLE_ENDIAN_BITFIELD)

	uint16_t				ihl:4;
	uint16_t				version:4;

# elif defined (__BIG_ENDIAN_BITFIELD)

	uint8_t					version:4;
	uint8_t					ihl:4;

# else
#  error "Adjust your <asm/byteorder.h> or <architecture/byte_order.h> defines"
# endif

	uint8_t					tos;
	uint16_t				tot_len;
	uint16_t				id;
	uint16_t				frag_off;
	uint8_t					ttl;
	uint8_t					protocol;
	uint16_t				check;
	uint32_t				saddr;
	uint32_t				daddr;
}							t_iphdr;

/*
** [ICMP HEADER FORMAT]
** Version/ihl
** Type of service
** Length of packet
** Packet ID
** Packet offset
** Checksum
** Sequence
** + TIMESTAMP [NEED TO EASY GENERATE BY CASTING uint8_t* to t_icmphdr*]
*/

typedef struct				s_icmphdr
{
	uint8_t					icmp__type;
	uint8_t					icmp__code;
	uint16_t				icmp__cksum;
	uint16_t				icmp__id;
	uint16_t				icmp__sequence;
	suseconds_t				icmp__timestamp;
}							t_icmphdr;

/*
** [t_udphdr format]:
** source port
** destination port
** length
** udp checksum
*/
typedef struct				s_udphdr
{
	uint16_t				udp_srcport;
	uint16_t				udp_dstport;
	uint16_t				udp_len;
	uint16_t				udp_cksum;
}							t_udphdr;

typedef struct				s_flag
{
	char					*flag;
	char					*value;
	struct s_flag			*next;
}							t_flag;

#endif
