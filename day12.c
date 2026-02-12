//Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

#include <stdio.h>

int main() {
    int m, n, i, j;
    int matrix[100][100];
    int isSymmetric = 1;

    // Read rows and columns
    scanf("%d %d", &m, &n);

    // Read matrix elements
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if matrix is square
    if (m != n) {
        printf("Not a symmetric matrix");
        return 0;
    }

    // Check symmetry
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric)
            break;
    }

    // Output result
    if (isSymmetric)
        printf("Symmetric matrix");
    else
        printf("Not a symmetric matrix");

    return 0;
}

