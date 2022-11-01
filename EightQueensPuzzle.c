/*
 * @Name: Eight Queens Puzzle In C
 * @Author: Max Base
 * @Date: 2022-11-01
 * @Repository: https://github.com/BaseMax/EightQueensPuzzleC
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **board;
    int size;
} board;

/*
 * @brief Create a board object
 */
board* createBoard(int size) {
    board *b = malloc(sizeof(board));
    b->board = malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        b->board[i] = malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            b->board[i][j] = 0;
        }
    }
    b->size = size;
    return b;
}

/*
 * @brief Destroy the board object
 */
void destroyBoard(board *b) {
    for (int i = 0; i < b->size; i++) {
        free(b->board[i]);
    }
    free(b->board);
    free(b);
}

/*
 * @brief Print the board object
 */
void printBoard(board *b) {
    for (int i = 0; i < b->size; i++) {
        for (int j = 0; j < b->size; j++) {
            printf("%d ", b->board[i][j]);
        }
        printf("\n");
    }
}

/*
 * @brief Check if the board is safe
 */
int isSafe(board *b, int row, int col) {
    int i, j;
    for (i = 0; i < col; i++) {
        if (b->board[row][i]) {
            return 0;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (b->board[i][j]) {
            return 0;
        }
    }
    for (i = row, j = col; j >= 0 && i < b->size; i++, j--) {
        if (b->board[i][j]) {
            return 0;
        }
    }
    return 1;
}

/*
 * @brief Solve the board
 */
int solveBoard(board *b, int col) {
    if (col >= b->size) {
        return 1;
    }
    for (int i = 0; i < b->size; i++) {
        if (isSafe(b, i, col)) {
            b->board[i][col] = 1;
            if (solveBoard(b, col + 1)) {
                return 1;
            }
            b->board[i][col] = 0;
        }
    }
    return 0;
}

/*
 * @brief Solve the board
 */
int solve(board *b) {
    if (solveBoard(b, 0) == 0) {
        printf("Solution does not exist\n");
        return 0;
    }
    printBoard(b);
    return 1;
}

/*
 * @brief Main function
 */
int main() {
    board *b = createBoard(8);
    solve(b);
    destroyBoard(b);

    return 0;
}
