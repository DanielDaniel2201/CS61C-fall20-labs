#include "transpose.h"

/* The naive transpose function as a reference. */
void transpose_naive(int n, int blocksize, int *dst, int *src) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dst[y + x * n] = src[x + y * n];
        }
    }
}

/* Implement cache blocking below. You should NOT assume that n is a
 * multiple of the block size. */
void transpose_blocking(int n, int blocksize, int *dst, int *src) {
    // YOUR CODE HERE
    for (int x = 0; x < n; x += blocksize) {
        for (int y = 0; y < n; y += blocksize) {
            for (int z = 0; z < blocksize; z++) {
                for (int w = 0; w < blocksize; w++) {
                    int row_num = x + z;
                    int col_num = y + w;
                    dst[col_num + row_num * n] = src[row_num + col_num * n];
                }
            }
        }
    }
}
