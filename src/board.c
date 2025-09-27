/**
 * @file board.c
 * @brief ボードの実装
 *
 * @author N.Nobuoka
 *
 * @copyright Copyright (c) 2025 N.Nobuoka
*/

#include "board.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief ボードを生成する関数
 *
 * @param[out] board テトリスを行うボード
 *
 * @return 0=成功、0以外=エラー
 */
int game_init_board(struct tetris_board *board) {
	int size;
	char *p = NULL;

	if (board == NULL) {
		return -EINVAL;
	}

	/* 領域の確保 */
	size = (BOARD_WIDTH + (BOARD_MARGIN * 2)) * (BOARD_HEIGHT + BOARD_MARGIN);
	p = malloc((size_t)size);
	if (p == NULL) {
		return -errno;
	}

	/* 確保した領域の初期化を行う */
	memset(p, 0x00, (size_t)size);

	board->field = p;
	board->size = size;

	return 0;
}

/**
 * @brief 生成したボードを消す関数
 * 
 * @param board 消すボード
 * 
 * @return 0=成功、0以外=エラー
 */
int game_deinit_board(struct tetris_board *board) {
	if (board->field == NULL || board->size <= 0) {
		return -EINVAL;
	}

	free(board->field);
	board->field = NULL;

	return 0;
}

/**
 * @brief ボード上の指定した座標の値を取る関数
 *
 * @param board 値を取り出すボード
 * @param x 値を取り出す座標 (左下を原点とする)
 * @param y 値を取り出す座標 (左下を原点とする)
 *
 * @return 0=成功、0以外=エラー
 */
int game_get_pos_val(struct tetris_board *board, int x, int y, char *res) {
	int pos;

	if (board == NULL || res == NULL) {
		return -EINVAL;
	}

	pos = x + (BOARD_WIDTH + (BOARD_MARGIN * 2)) * y;

	if (pos >= board->size) {
		return -ERANGE;
	}

	*res = board->field[pos];

	return 0;
}

/**
 * @brief ボード上の指定した座標に値を書き込む関数
 *
 * @param board 値を書き込むボード
 * @param x 値を書き込む座標 (左下を原点とする)
 * @param y 値を書き込む座標 (左下を原点とする)
 * @param val 書き込む値
 *
 * @return 0=成功、0以外=エラー
 */
int game_set_pos_val(struct tetris_board *board, int x, int y, char val) {
	int pos;

	if (board == NULL) {
		return -EINVAL;
	}

	pos = x + (BOARD_WIDTH + (BOARD_MARGIN * 2)) * y;

	if (pos >= board->size) {
		return -ERANGE;
	}

	board->field[pos] = val;

	return 0;
}
