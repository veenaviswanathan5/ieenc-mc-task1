#include <stdio.h>


void setMatrixZero(int matrix[][100], int n, int m) {
    int firstRowZero = 0, firstColZero = 0;

    // Check if the first row contains any 0-
    // else it leads to incorrect zeros later 
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    // Check if the first column contains any 0
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }

    // Use the first row and column as markers to check nrxt complete matrix later
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set rows to zero based on markers
    for (int i = 1; i < n; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set columns to zero based on markers
    for (int j = 1; j < m; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Handle the first row separately
    if (firstRowZero) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Handle the first column separately
    if (firstColZero) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}

// Helper function to print the matrix
void printMatrix(int matrix[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    
    // Input the dimensions of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int matrix[100][100];

    // Input the matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, n, m);

    // Modify the matrix as per the logic
    setMatrixZero(matrix, n, m);

    printf("\nModified Matrix:\n");
    printMatrix(matrix, n, m);

    return 0;
}
