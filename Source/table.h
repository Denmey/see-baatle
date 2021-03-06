#pragma once
#include <curses.h>
#include "ships.h"

extern int calculateArrangeHeight(struct ShipsInfo Ships);

void initWindowsParametres(struct ShipsInfo ships, struct Board board, Indents Indents, WindowParametres*, WindowParametres*, WindowParametres*, WindowParametres*, WindowParametres*);
void DrawTableWindow(WindowParametres *Wship);
void DrawMainWindow(WindowParametres *Wmain);
void str_top(WINDOW*, int);
void str_line(WINDOW*,int, int);
void str_numb(WINDOW*,int, int);
void str_bottom(WINDOW*, int, int);