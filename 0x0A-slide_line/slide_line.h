#ifndef _SLIDE_LINE_H_
#define _SLIDE_LINE_H_

/* LIBS */
#include <stdio.h>
#include <stdlib.h>

/* MACROS */
#define SLIDE_LEFT 1
#define SLIDE_RIGHT 0

/* FUNCTIONS PROTOS*/
int slide_line(int *line, size_t size, int direction);

#endif
