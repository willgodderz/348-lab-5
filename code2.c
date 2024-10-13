#include <stdio.h>

#define SIZE 5 

// declaires functions types and parameters
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(int m[SIZE][SIZE]);

int main() {
    // Sample matrices m1 and m2 5X5
      int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int result[SIZE][SIZE];  // declaires result matrix

    // calls add m1 and m2
    printf("Sum of matrices m1 and m2:\n");
    addMatrices(m1, m2, result);
    printMatrix(result);

    // calls multiply m1 and m2
    printf("\nProduct of matrices m1 and m2:\n");
    multiplyMatrices(m1, m2, result);
    printMatrix(result);

    // calls transpose of m1
    printf("\nTranspose of matrix m1:\n");
    transposeMatrix(m1, result);
    printMatrix(result);

    return 0;
}

// Function to add 
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) { //loops through rows
        for (int j = 0; j < SIZE; j++) { //loops through columes
            result[i][j] = m1[i][j] + m2[i][j]; //adds element
        }
    }
}

// Function to multiply 
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    //inits result matrix to 0
    for (int i = 0; i < SIZE; i++) { //loops through rows of m1
        for (int j = 0; j < SIZE; j++) { //loops through columes of m2
            result[i][j] = 0; //sets equal to 0
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) { //loops through rows of m1
            for (int k = 0; k < SIZE; k++) { //loops through columes of m2
                result[i][j] += m1[i][k] * m2[k][j]; //multiplys
            }
        }
    }
}

// Function to transpose 
void transposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) { //loops through each row
        for (int j = 0; j < SIZE; j++) { //loops through each colume
            result[j][i] = m[i][j]; //swaps rows and columes
        }
    }
}

// Function to print 
void printMatrix(int m[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", m[i][j]);  // Print each element in the row
        }
        printf("\n");  // New line after each row
    }
}
