#include <stdlib.h>
#include <time.h>
#include "util.h"

short row_size,col_size;

typedef struct{
	int next,current,color;
	WINDOW *win; 
}Unit;

void create_unit(Unit *c,int posx,int posy) {
	c->win = newwin(1,2,posy,posx*2);
}

void set_unit_color(Unit c) {
	c.color = c.current ? MAGENTA_PAIR : BLACK_PAIR;
	wbkgd(c.win,COLOR_PAIR(c.color));
	wrefresh(c.win);
}

int main() {
	initscr();
	noecho();
	curs_set(0);
	begin_color();
	getmaxyx(stdscr,row_size,col_size);
	col_size = col_size>>1; 
	Unit cell[col_size][row_size];
	check_grid {
		create_unit(&cell[i][j],i,j);
		cell[i][j].next = 0;
	}
	srand ( (unsigned)time(0) );
	grid_populate {
		cell[rand_var * (col_size - 0) + 0)]
		    [rand_var * (row_size - 0) + 0)].next = 1;
	}
	int surround = 0;
	while(1) {
		check_grid cell[i][j].current = cell[i][j].next;
		check_grid {
			set_unit_color(cell[i][j]);
			surround  = check_surround;
			if ( (surround==2 || surround==3 ) && cell[i][j].current)
				cell[i][j].next = 1;
			if (surround == 3 && !cell[i][j].current ) 
				cell[i][j].next = 1;
			if ( (surround<=1 || surround>=4 ) && cell[i][j].current) 
				cell[i][j].next = 0;
			
			surround = 0;
		}
	}  
	getchar();
	endwin();
}
