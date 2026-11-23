#include "malcolm.h"

#include <net/if.h>
#include <unistd.h> // sleep()

int malcolm(t_malcolm *ctx)
{

	if (setup_socket(ctx))
		return (1);
	if (setup_interface(ctx))
		return (1);

	return (0);
}
