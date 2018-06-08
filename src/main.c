#include "corewar.h"

void	exit_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

int		main(int argc, char *argv[])
{
	t_lemin		lemin;
	t_room		*room;

	(void)argv;
	if (argc != 1)
		exit_error("ERROR");
	
	return (0);
}
