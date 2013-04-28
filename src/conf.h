/*
Copyright 2006 Aiko Barz

This file is part of masala/tumbleweed.

masala/tumbleweed is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

masala/tumbleweed is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with masala/tumbleweed.  If not, see <http://www.gnu.org/licenses/>.
*/

#define CONF_CORES 2
#define CONF_PORTMIN 1
#define CONF_PORTMAX 65535

#define CONF_BEQUIET 0
#define CONF_VERBOSE 1

#define CONF_DAEMON 0
#define CONF_FOREGROUND 1

#define CONF_HOSTFILE "/etc/hostname"

#ifdef TUMBLEWEED
#define CONF_USER "tumbleweed"
#define CONF_EPOLL_WAIT 1000
#define CONF_SRVNAME "tumbleweed"
#define CONF_PORT "8080"
#define CONF_INDEX_NAME "index.html"
#define CONF_KEEPALIVE 5
#elif MASALA
#define CONF_USER "masala"
#define CONF_EPOLL_WAIT 2000
#define CONF_SRVNAME "masala"
#define CONF_PORT "8337"
#define CONF_BOOTSTRAP_NODE "ff0e::1"
#define CONF_BOOTSTRAP_PORT "8337"
#define CONF_KEY "open.p2p"
#define CONF_REALM "open.p2p"
#define CONF_DNS_ADDR "::1"
#define CONF_DNS_PORT "3444"
#else
#define CONF_SRVNAME "nss-masala"
#endif

struct obj_conf {
	char *user;

#ifdef MASALA
	char *pid_file;
	char *hostname;
	UCHAR node_id[SHA_DIGEST_LENGTH];
	UCHAR host_id[SHA_DIGEST_LENGTH];
	UCHAR null_id[SHA_DIGEST_LENGTH];
	char *bootstrap_node;
	char *bootstrap_port;

	char *key;
	int bool_encryption;

	char *realm;
	int bool_realm;

	char *dns_port;
	char *dns_addr;
	char *dns_ifce;
#endif

#ifdef TUMBLEWEED
	char home[MAIN_BUF+1];
	char index_name[MAIN_BUF+1];
	int ipv6_only;
#endif

	/* Number of cores */
	int cores;

	/* Verbosity */
	int quiet;

	/* Verbosity mode */
	int mode;

	/* TCP/UDP Port */
	char *port;
};

struct obj_conf *conf_init( void );
void conf_free( void );

void conf_check( void );
