
#include "../../cub3d.h"

int	check_extension(char *file)
{
	int		count;
	char	*tmp;

	count = 4;
	tmp = (char *)ft_strstr(file, ".cub");
	if (tmp == NULL)
		return (1);
	while (count)
	{
		tmp++;
		count--;
	}
	if ((int)*tmp != 0)
		return (1);
	count = open(file, O_RDONLY);
	if (count == -1)
		return (1);
	close(count);
	return (0);
}