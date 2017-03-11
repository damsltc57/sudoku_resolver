/*
** solver.c for solver.c in /home/dams/delivery/perso/sudoku_resolver/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 11 14:51:49 2017 Damien Laurent
** Last update Sat Mar 11 18:51:14 2017 Damien Laurent
*/

#include "solver.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void		print_line()
{
  int		i;

  i = -1;
  while (++i < 20)
    printf("-");
  printf("\n");
}

void		print_map(int **tab, int **old, int status)
{
  int		i;
  int		j;

  i = -1;
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
      	{
	  if (i == 3 && j == 0)
	    print_line();
	  if (i == 6 && j == 0)
	    print_line();
	  if (j == 3 || j == 6)
	    printf("|");
	  if (old[i][j] == 0 && tab[i][j] != 0)
	    printf("\033[31m%d \033[0m", tab[i][j]);
	  else if (status == 1)
	    printf("\033[32m%d \033[0m", old[i][j]);
	  else if (status == 0 && old[i][j] != 0)
	    printf("\033[32m%d \033[0m", old[i][j]);
	  else
            printf("%d ", old[i][j]);

	}
      printf("\n");
    }
  printf("\n\n");
}


int		main(int ac, char **av)
{
  int		**grille;
  int		**old;

  if (ac < 2)
    {
      printf("Usage: ./solver [filepath] [Output]\n");
      return (0);
    }
  grille = open_file(av[1]);
  old = open_file(av[1]);
  printf("\tInput\n");
  print_map(grille, old, 0);
  srand(time(NULL));
  is_valid(grille, 0);
  printf("\tOutput\n");
  print_map(grille, old, 1);
  if (ac > 2)
    {
      write_in_file(grille, av[2]);
    }
  return (0);
}
