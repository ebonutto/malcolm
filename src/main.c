#include "malcolm.h"

int main(int argc, char **argv)
{
	t_malcolm_ctx ctx;

	if (parse_args(&ctx, argc, argv) != 0)
		return (1);
	return (malcolm(&ctx));
}
