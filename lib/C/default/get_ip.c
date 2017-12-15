/*
** EPITECH PROJECT, 2017
** lbl-libc
** File description:
** get_ip
*/

#include <sys/types.h>
#include <ifaddrs.h>
#include <arpa/inet.h>

#include "my.h"
#include "defines.h"

# define NO_IP		("0.0.0.0")
# define LOCAL_IP	("127.0.0.1")

static int		is_working_ip(const char *ip)
{
  if (ip == NULL)
    return (0);
  if (my_strcmp(ip, NO_IP) == 0)
    return (0);
  if (my_strcmp(ip, LOCAL_IP) == 0)
    return (0);
  return (1);
}

char			*get_ip(const char *interface)
{
  struct ifaddrs	*ifaddr;
  struct ifaddrs	*cursor;
  struct sockaddr_in	*saddr;
  char			*ip;

  if (getifaddrs(&ifaddr) == -1)
    return (NULL);
  cursor = ifaddr;
  while (cursor != NULL)
  {
    if (cursor->ifa_addr && cursor->ifa_addr->sa_family == AF_INET)
    {
      saddr = (struct sockaddr_in *)cursor->ifa_addr;
      ip = my_strdup(inet_ntoa(saddr->sin_addr));
      if (interface == NULL && is_working_ip(ip))
	break;
      if (interface != NULL && my_strcmp(cursor->ifa_name, interface) == 0)
	break;
      sfree(&ip);
    }
    cursor = cursor->ifa_next;
  }
  freeifaddrs(ifaddr);
  return (ip);
}
