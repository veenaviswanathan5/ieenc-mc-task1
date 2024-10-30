// Rotating clockwise 90 degree

#include <stdio.h>

#define MAX_SIZE 100 

void print_matrix(int mat[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void rotate(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    // finding Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    //  Reversing all rows
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}

int main() {
    int n;
    int matrix[MAX_SIZE][MAX_SIZE]; // Declare a fixed-size matrix

    // Input the size of the matrix
    printf("Enter the size of the matrix (N x N): ");
    scanf("%d", &n);

    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("given Matrix:\n");
    print_matrix(matrix, n);

    rotate(matrix, n);

    printf("\nRotated Matrix:\n");
    print_matrix(matrix, n);

    return 0;
}
