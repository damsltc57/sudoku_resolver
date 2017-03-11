/*
** delete_elem.c for delete_elem.c in /home/dams/delivery/perso/sudoku_resolver/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 11 16:37:33 2017 Damien Laurent
** Last update Sat Mar 11 17:41:32 2017 Damien Laurent
*/

#include "solver.h"
#include <stdio.h>

int		**check_for_delete(int **tab, int i, int j)
{
  print_map(tab);
  printf("arrive check: %d %d\n", i, j);
  if (!is_not_on_line(i, tab, tab[i][j]))
    tab = delete_line(i, tab);
  if (!is_not_on_col(j, tab, tab[i][j]))
    tab = delete_col(j, tab);
  if (!is_not_on_square(i, j, tab, tab[i][j]))
    tab = delete_square(i, j, tab);
  return (tab);
}

int		**delete_line(int i, int **tab)
{
  printf("deline line\n");
  int		j;

  j = -1;
  while (++j < 9)
    {
      tab[i][j] = 0;
    }
  return (tab);
}

int		**delete_col(int j, int **tab)
{
  int		i;
  printf("delete col\n");
  i = -1;
  while (++i < 9)
    {
      tab[i][j] = 0;
    }
  return (tab);
}

int		**delete_square(int i, int j, int **tab)
{
  printf("delete_square\n");
  int _i = i-(i%3), _j = j-(j%3);  // ou encore : _i = 3*(i/3), _j = 3*(j/3);
  for (i=_i; i < _i+3; i++)
    for (j=_j; j < _j+3; j++)
	tab[i][j] = 0;
      return (tab);
}
