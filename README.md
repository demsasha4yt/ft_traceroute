# FT_PING
Собственная реализация утилиты traceroute по проекту ft_traceroute в школе программирования 21.


## RUN

```ruby
docker-machine create --driver virtualbox default
eval "$(docker-machine env default)"
docker-compose build
docker-compose run app bash
```

## Inside VM
```ruby
make
./ft_traceroute [-v] host
```

## Refs
*IPv4* - https://ru.wikipedia.org/wiki/IPv4

*ICMP* - https://en.wikipedia.org/wiki/Internet_Control_Message_Protocol

*Ping* - https://ru.wikipedia.org/wiki/Ping

*Traceroute* - https://en.wikipedia.org/wiki/Traceroute

*Internet protocol checksum* - https://tools.ietf.org/html/rfc1071

*tcpdump* - https://ru.wikipedia.org/wiki/Tcpdump
