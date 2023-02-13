#include <stdio.h>
#include <ncurses.h>

#define check_grid for (int i = 0; i < col_size; i++) \
	for (int j = 0; j < row_size; j++)
#define grid_populate for (int i = 0; i < col_size>>1; i++) \
	for (int j = 0; j < row_size>>1; j++) 
#define check_surround cell[i+1][j].current + cell[i+1][j+1].current \
	+ cell[i+1][j-1].current + cell[i-1][j-1].current \
	+ cell[i-1][j+1].current + cell[i][j-1].current \
	+ cell[i][j+1].current + cell[i-1][j].current
#define rand_var (int)((double)rand()/(double)RAND_MAX 
#define BLACK_PAIR 0
#define MAGENTA_PAIR 1

void begin_color(){
	start_color();
	init_pair(BLACK_PAIR, COLOR_BLACK, COLOR_BLACK);
	init_pair(MAGENTA_PAIR, COLOR_MAGENTA, COLOR_MAGENTA);
}
