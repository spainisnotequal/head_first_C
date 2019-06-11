/*
 * Program to learn about sockets and networking
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h> // to close the conexion
#include <signal.h>


void error (const char *msg)
{
        fprintf(stderr, "%s: %s\n", msg, strerror(errno));
        exit(1);
}

int open_listener_socket (void)
{
        int s = socket(PF_INET, SOCK_STREAM, 0);
        if (s == -1) {
                error("Can't open socket");
        }

        return s;
}

void bind_to_port (int socket, int port)
{
        struct sockaddr_in name;
        name.sin_family = PF_INET;
        name.sin_port = (in_port_t) htons(port);
        name.sin_addr.s_addr = htonl(INADDR_ANY);
        int reuse = 1;
        if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse,
                       sizeof(int)) == -1) {
                error("Can't set the reuse option on the socket");
        }
        int c = bind (socket, (struct sockaddr *) &name, sizeof(name));
        if (c == -1) {
                error("Can't bind to socket");
        }
}

int say (int socket, const char *s)
{
        int result = send(socket, s, strlen(s), 0);
        if (result == -1) {
                fprintf(stderr, "%s: %s\n", "Error talking to the client",
                        strerror(errno));
        }

        return result;
}

int read_in(int socket, char *buf, int len)
{
        char *s = buf;
        int slen = len;
        int c = recv(socket, s, slen, 0);
        while ((c > 0) && (s[c-1] != '\n')) {
                s += c;
                slen -= c;
                c = recv(socket, s, slen, 0);
        }
        if (c < 0) {           // in case there's an error
                return c;
        } else if (c == 0) {   // nothing read; send back an empty string
                buf[0] = '\0';
        } else {
                s[c-1] = '\0'; // replace the '\r' character with a '\0'
        }

        return len -slen;
}
