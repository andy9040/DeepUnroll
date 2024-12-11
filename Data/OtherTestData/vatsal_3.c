#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void pyramid_nested_loops();
void jagged_nested_loops();
void nested_randomized_loops();
void prime_number_nested_loops();
void matrix_multiplication();
void triangular_number_loop();
void nested_fibonacci_loop();
void fractal_nested_loop();
void multi_condition_nested_loop();
void nested_sum_of_squares();

int is_prime(int num);
int fibonacci(int n);

int main() {
    pyramid_nested_loops();
    jagged_nested_loops();
    nested_randomized_loops();
    prime_number_nested_loops();
    matrix_multiplication();
    triangular_number_loop();
    nested_fibonacci_loop();
    fractal_nested_loop();
    multi_condition_nested_loop();
    nested_sum_of_squares();

    return 0;
}

// Function definitions

void pyramid_nested_loops() {
    int rows = 5;
    for (int i = 1; i <= rows; i++) {
        for (int j = i; j < rows; j++) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

void jagged_nested_loops() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i * 2; j++) {
            printf("jagged_nested_loops: i = %d, j = %d\n", i, j);
        }
    }
}

void nested_randomized_loops() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < (rand() % 10); j++) {
            printf("nested_randomized_loops: i = %d, j = %d\n", i, j);
        }
    }
}

void prime_number_nested_loops() {
    int limit = 50;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            for (int j = 1; j <= i; j++) {
                printf("prime_number_nested_loops: i = %d, j = %d\n", i, j);
            }
        }
    }
}

void matrix_multiplication() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int c[2][2] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("matrix_multiplication: c[%d][%d] = %d\n", i, j, c[i][j]);
        }
    }
}

void triangular_number_loop() {
    int rows = 5;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("triangular_number_loop: %d ", i * (i + 1) / 2);
        }
        printf("\n");
    }
}

void nested_fibonacci_loop() {
    int levels = 5;
    for (int i = 1; i <= levels; i++) {
        for (int j = 1; j <= i; j++) {
            printf("nested_fibonacci_loop: fib(%d) = %d\n", j, fibonacci(j));
        }
    }
}

void fractal_nested_loop() {
    int depth = 3;
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < pow(2, i); j++) {
            for (int k = 0; k < pow(2, i); k++) {
                printf("fractal_nested_loop: i = %d, j = %d, k = %d\n", i, j, k);
            }
        }
    }
}

void multi_condition_nested_loop() {
    for (int i = 1; i <= 5; i++) {
        for (int j = i; j <= 5; j++) {
            if ((i + j) % 2 == 0 && i * j < 20) {
                printf("multi_condition_nested_loop: i = %d, j = %d\n", i, j);
            }
        }
    }
}

void nested_sum_of_squares() {
    int limit = 3;
    for (int i = 1; i <= limit; i++) {
        for (int j = 1; j <= limit; j++) {
            int sum_of_squares = (i * i) + (j * j);
            printf("nested_sum_of_squares: i = %d, j = %d, sum = %d\n", i, j, sum_of_squares);
        }
    }
}

// Utility functions
int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

