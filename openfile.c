/*
** openfile.c for openfile.c in /home/dams/delivery/perso/sudoku_resolver/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 11 17:50:25 2017 Damien Laurent
** Last update Sat Mar 11 18:51:35 2017 Damien Laurent
*/

#include "solver.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int		**open_file(char *name)
{
  int		fd;
  int		i;
  char		*s;
  int		**tab;
  int		j;
  int		x;

  tab = malloc(sizeof(int*) * 20);
  if ((fd = open(name, O_RDONLY)) == -1)
    {
      printf("bad name input\n");
      exit(0);
    }
  x = 0;
  while ((s = get_next_line(fd)) != NULL)
    {
      i = 0;
      j = 0;
      tab[x] = malloc(sizeof(int) * 20);
      while (s[i] != '\0')
	{
	  if (s[i] == ' ')
	    tab[x][j] = 0;
	  else
	    tab[x][j] = s[i] - '0';
	  i++;
	  j++;
	}
      x++;
    }
  close(fd);
  return (tab);
}

void		print_line_write(int fd)
{
  int		i;

  i = -1;
  while (++i < 20)
    write(fd, "-", 1);
  write(fd, "\n", 1);
}

void		write_in_file(int **tab, char *name)
{
  int		fd;
  int		i;
  int		j;
  char		*tmp;

  tmp = malloc(sizeof(char*) * 10);
 if ((fd = open(name, O_WRONLY | O_CREAT, 0644)) == -1)
    {
      printf("cant open %s\n", name);
      exit (0);
    }
  i = -1;
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
	{
	  if (i == 3 && j == 0)
	    print_line_write(fd);
	  if (i == 6 && j == 0)
      	    print_line_write(fd);
	  if (j == 3 || j == 6)
      	    write(fd, "|", 1);
	  sprintf(tmp, "%d", tab[i][j]);
	  strcat(tmp, " ");
	  write(fd, tmp, strlen(tmp));
	}
      write(fd, "\n", 1);
    }
  close(fd);

}
