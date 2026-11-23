#include "malcolm.h"

#include <ifaddrs.h> // freeifaddrs(), getifaddrs()
#include <net/if.h> // 
#include <string.h> // strncpy()
#include <stdio.h> // perror()

static int find_usable_ifname(char *out)
{
	struct ifaddrs *list;
	struct ifaddrs *cur;

	if (getifaddrs(&list) < 0) {
		perror("getifaddrs()");
		return (1);
	}

	cur = list;
	while (cur) {
		if (cur->ifa_addr
		    && cur->ifa_addr->sa_family == AF_INET
		    && (cur->ifa_flags & IFF_UP)
		    && !(cur->ifa_flags & IFF_LOOPBACK)) {
			strncpy(out, cur->ifa_name, IF_NAMESIZE);
			out[IF_NAMESIZE - 1] = '\0';
			freeifaddrs(list);
			return (0);
		}
		cur = cur->ifa_next;
	}

	freeifaddrs(list);
	return (0);
}

int setup_interface(t_malcolm *ctx)
{
	char ifname[IF_NAMESIZE];

	if (find_usable_ifname(ifname))
		return (1);

	ctx->ifindex = if_nametoindex(ifname);
	if (ctx->ifindex == 0)
		return (1);

	return (0);
}
