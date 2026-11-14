#include "malcolm.h"

int main(int argc, char **argv)
{
	t_malcolm ctx;
	int ret;

	if (parse_args(&ctx.args, argc, argv) != 0)
		return (1);

	ret = malcolm(&ctx);

	return (ret);
}
