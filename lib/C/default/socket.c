/*
** EPITECH PROJECT, 2017
** libc
** File description:
** socket C simple API
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "my.h"

int			create_server(uint16_t port)
{
  struct sockaddr_in	server;
  int			fd;

  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd == -1)
    return (-1);
  zeros(&server, sizeof(server));
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  if (bind(fd, (struct sockaddr *)&server,
	   sizeof(struct sockaddr_in)) == -1)
  {
    close(fd);
    return (-1);
  }
  return (fd);
}

int			accept_client(int sockfd, int backlog)
{
  socklen_t		clilen;
  struct sockaddr_in	client;
  int			fd;

  if (listen(sockfd, backlog) == -1)
    return (-1);
  clilen = sizeof(client);
  fd = accept(sockfd, (struct sockaddr *)&client, &clilen);
  if (fd == -1)
    return (-1);
  return (fd);
}

int			connect_to(const char *ip, uint16_t port)
{
  struct hostent	*info;
  struct sockaddr_in	serv_addr;
  int			fd;

  info = gethostbyname(ip);
  if (info == NULL)
    return (-1);
  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd == -1)
    return (-1);
  zeros(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_addr = *(struct in_addr *)info->h_addr;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_family = AF_INET;
  if (connect(fd, (struct sockaddr *)&serv_addr,
	      sizeof(struct sockaddr)) == -1)
  {
    close(fd);
    return (-1);
  }
  return (fd);
}
