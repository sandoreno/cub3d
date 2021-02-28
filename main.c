
#include "cub3d.h"
#include <stdio.h>
#include <fcntl.h>


int main() {

	int fd;
	fd = open("/Users/acarroll/CLionProjects/cub/map.cub", O_RDONLY);
	char *line = NULL;
	t_list *head = NULL;


	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	free(line);
	ft_parser_map(head, ft_lstsize(head));

// тут начинается работа с окном
	void *mlx;
	void *img;
	void *mlx_win;

	mlx = mlx_init();
//	img = mlx_new_image(mlx, 640, 480);

//	mlx_win = mlx_new_window(mlx, 640, 480, "new window");
//	mlx_loop(mlx);


	return 0;
}
