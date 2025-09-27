/**
 * @file BOARD.c
 * @brief ボードの実装
 *
 * @author N.Nobuoka
 *
 * @copyright Copyright (c) 2025 N.Nobuoka
*/

#ifndef BOARD_H
#define BOARD_H

/* ボードの横幅 */
#define BOARD_WIDTH 10
/* ボードの縦幅 */
#define BOARD_HEIGHT 40
/* どれだけ余分に配列のサイズを取るか */
#define BOARD_MARGIN 10

struct tetris_board {
	char *field;
	int size;
};

int game_init_board(struct tetris_board *board);

int game_deinit_board(struct tetris_board *board);

int game_get_pos_val(struct tetris_board *board, int x, int y, char *res);

int game_set_pos_val(struct tetris_board *board, int x, int y, char val);

#endif
