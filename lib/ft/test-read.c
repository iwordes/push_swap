#include <libft.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_putstr(ft_read(open(argv[1], O_RDONLY)));
}
