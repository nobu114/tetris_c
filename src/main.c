/**
 * @file main.c
 * @brief テトリス
 *
 * テトリス
 *
 * @author N.Nobuoka
 *
 * @copyright Copyright (c) 2025 N.Nobuoka
*/
#include "board.h"

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int app_deinit(void) {
	endwin();

	return 0;
}

static int app_init(void) {
	initscr();

	return 0;
}

static int app_loop(void) {
	int ch;

	
	for (; ; ) {
		ch = getch();

		switch (ch) {
		case 'q':
			return 0;
	
		default:
			break;
		}
	}

	return 0;
}

/* TODO 後で消す */
static int test(void) {
	struct tetris_board board;
	int i;
	char res;

	memset(&board, 0x00, sizeof(board));

	game_init_board(&board);

	game_set_pos_val(&board, 0, 0, 1);
	game_get_pos_val(&board, 0, 0, &res);
	printw("%d\n", res);

	for (i = 0; i < board.size; i++) {
		printw("%d ", board.field[i]);
	}
	printw("\n");

	printw("len: %d\n", i);

	game_deinit_board(&board);

	return 0;
}

/**
 * @brief メイン処理
 *
 * @param argc 
 * @param argv 
 *
 * @return 0=成功
 */
int main(int argc, char const *argv[])
{	
	app_init();

	test();

	app_loop();

	app_deinit();

	return 0;
}
