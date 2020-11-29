#include "board.h"
#include "hal.h"

#define MATRIX_ROWS 8
#define MATRIX_COLS 9

const ioline_t row_list[MATRIX_ROWS] = {
    LINE_ROW1,
    LINE_ROW2,
    LINE_ROW3,
    LINE_ROW4,
    LINE_ROW5,
    LINE_ROW6,
    LINE_ROW7,
    LINE_ROW8,
};

const ioline_t col_list[MATRIX_COLS] = {
    LINE_COL1,
    LINE_COL2,
    LINE_COL3,
    LINE_COL4,
    LINE_COL5,
    LINE_COL6,
    LINE_COL7,
    LINE_COL8,
    LINE_COL9,
};

void boardInit(void) {
  palSetLineMode(LINE_LED, MODE_DIR_IN | MODE_MODE_PULL_UP | MODE_AD_DIGITAL);
  palSetLineMode(LINE_USBVBUS, MODE_FUNC_ALT1 | MODE_MODE_PULL_UP | MODE_AD_DIGITAL);
  palSetLineMode(LINE_USBCONN, MODE_FUNC_ALT1 | MODE_AD_DIGITAL);

  // Keyboard Matrix
    for (int i = 0; i < MATRIX_ROWS; ++i)
    {
        palSetLineMode(row_list[i], MODE_DIR_OUT | MODE_AD_DIGITAL);
        palClearLine(row_list[i]);
    }
    for (int i = 0; i < MATRIX_COLS; ++i)
    {
        palSetLineMode(col_list[i], MODE_DIR_IN | MODE_MODE_PULL_DOWN | MODE_AD_DIGITAL);
    }
}
