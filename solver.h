/*
** solver.h for solver.h in /home/dams/delivery/perso/sudoku_resolver/
**
** Made by Damien Laurent
** Login   <damien.laurent@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 11 14:53:49 2017 Damien Laurent
** Last update Sat Mar 11 18:52:47 2017 Damien Laurent
*/
#include <stdbool.h>
#ifndef SOLVER_H
#define SOLVER_H_

bool		is_not_on_line(int	line, int **tab, int nb);
bool		is_not_on_col(int col, int **tab, int nb);
bool		is_not_on_square(int col, int line, int **tab, int nb);
bool		is_valid(int **tab, int pos);

/*get_next_line*/
char		*get_next_line(int fd);

/*open_file*/
int		**open_file(char *name);
void		write_in_file(int **tab, char *name);

#endif /*SOLVER*/
