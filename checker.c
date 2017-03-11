/*
** checker.c for checker.c in /home/dams/delivery/perso/sudoku_resolver/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 11 15:24:43 2017 Damien Laurent
** Last update Sat Mar 11 18:53:06 2017 Damien Laurent
*/
#include "solver.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool		check_valid_number(int **tab, int i, int j)
{
  int		nb;

  nb = tab[i][j];
  if (is_not_on_line(i, tab, nb) && is_not_on_col(j, tab, nb) && is_not_on_square(i, j, tab, nb))
    return (false);
  return (true);
}

bool		is_valid(int **tab, int pos)
{
  int		i;
  int		j;
  int		nb;

  if (pos == 9*9)
    return (true);
  i = pos / 9;
  j = pos % 9;
  if (tab[i][j] != 0)
    return is_valid(tab, pos + 1);
  nb = 1;
  while (nb <= 9)
    {
      if (is_not_on_line(i, tab, nb) && is_not_on_col(j, tab, nb) && is_not_on_square(i, j, tab, nb))
	{
	  tab[i][j] = nb;
	  if (is_valid(tab, pos + 1))
	    return true;
	}
      nb++;
    }
  tab[i][j] = 0;
  return false;
}

bool		is_not_on_line(int line, int **tab, int nb)
{
  int		i;

  i = -1;
  while (++i < 9)
    {
      if (tab[line][i] == nb)
	return (false);
    }
  return (true);
}

bool		is_not_on_col(int col, int **tab, int nb)
{
  int		i;

  i = -1;
  while(++i < 9)
    {
      if (tab[i][col] == nb)
	return (false);
    }
  return (true);
}

bool		is_not_on_square(int i, int j, int **grille, int nb)
{
  int _i = i-(i%3), _j = j-(j%3);  // ou encore : _i = 3*(i/3), _j = 3*(j/3);
  for (i=_i; i < _i+3; i++)
    for (j=_j; j < _j+3; j++)
	if (grille[i][j] == nb)
	    return false;
      return true;
}
