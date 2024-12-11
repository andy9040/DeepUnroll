#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void nested_basic_for_loop();
void nested_while_loop();
void nested_do_while_loop();
void complex_nested_loops();
void nested_condition_loops();
void nested_variable_step_loop();
void nested_reverse_loop();
void nested_infinite_loop();
void nested_break_loop();
void nested_continue_loop();
void nested_complex_condition_loop();
void nested_function_calls_loop();
void deeply_nested_loops();
void nested_dynamic_bound_loop(int n);
void nested_array_loop(int* arr, int rows, int cols);
void nested_parallelizable_loop(int* arr, int rows, int cols);
void nested_dependencies_loop(int* arr, int rows, int cols);
void nested_floating_point_loop();

int some_function(int x, int y) {
    return (x * x + y * y) % 7;
}

int main() {
    int arr[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = i + j;
        }
    }

    nested_basic_for_loop();
    nested_while_loop();
    nested_do_while_loop();
    complex_nested_loops();
    nested_condition_loops();
    nested_variable_step_loop();
    nested_reverse_loop();
    nested_infinite_loop();
    nested_break_loop();
    nested_continue_loop();
    nested_complex_condition_loop();
    nested_function_calls_loop();
    deeply_nested_loops();
    nested_dynamic_bound_loop(5);
    nested_array_loop((int*)arr, 5, 5);
    nested_parallelizable_loop((int*)arr, 5, 5);
    nested_dependencies_loop((int*)arr, 5, 5);
    nested_floating_point_loop();

    return 0;
}

// Function definitions
void nested_basic_for_loop() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("nested_basic_for_loop: i = %d, j = %d\n", i, j);
        }
    }
}

void nested_while_loop() {
    int i = 0;
    while (i < 3) {
        int j = 0;
        while (j < 3) {
            printf("nested_while_loop: i = %d, j = %d\n", i, j);
            j++;
        }
        i++;
    }
}

void nested_do_while_loop() {
    int i = 0;
    do {
        int j = 0;
        do {
            printf("nested_do_while_loop: i = %d, j = %d\n", i, j);
            j++;
        } while (j < 3);
        i++;
    } while (i < 3);
}

void complex_nested_loops() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((i + j) % 2 == 0) {
                for (int k = 0; k < 2; k++) {
                    printf("complex_nested_loops: i = %d, j = %d, k = %d\n", i, j, k);
                }
            }
        }
    }
}

void nested_condition_loops() {
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            if (j % 2 == 0) {
                printf("nested_condition_loops: i = %d, j = %d\n", i, j);
            }
        }
    }
}

void nested_variable_step_loop() {
    for (int i = 0; i < 10; i += 2) {
        for (int j = i; j < 10; j += 3) {
            printf("nested_variable_step_loop: i = %d, j = %d\n", i, j);
        }
    }
}

void nested_reverse_loop() {
    for (int i = 5; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            printf("nested_reverse_loop: i = %d, j = %d\n", i, j);
        }
    }
}

void nested_infinite_loop() {
    int count = 0;
    while (1) {
        for (int i = 0; i < 3; i++) {
            printf("nested_infinite_loop: i = %d, count = %d\n", i, count);
        }
        count++;
        if (count > 2) break;
    }
}

void nested_break_loop() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i + j == 4) {
                printf("nested_break_loop: Breaking at i = %d, j = %d\n", i, j);
                break;
            }
            printf("nested_break_loop: i = %d, j = %d\n", i, j);
        }
    }
}

void nested_continue_loop() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i + j) % 2 == 0) continue;
            printf("nested_continue_loop: i = %d, j = %d\n", i, j);
        }
    }
}

void nested_complex_condition_loop() {
    for (int i = 0, j = 10; i < 5 && j > 5; i++, j--) {
        for (int k = 0; k < i + j; k += 3) {
            printf("nested_complex_condition_loop: i = %d, j = %d, k = %d\n", i, j, k);
        }
    }
}

void nested_function_calls_loop() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int result = some_function(i, j);
            printf("nested_function_calls_loop: i = %d, j = %d, result = %d\n", i, j, result);
        }
    }
}

void deeply_nested_loops() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    printf("deeply_nested_loops: i = %d, j = %d, k = %d, l = %d\n", i, j, k, l);
                }
            }
        }
    }
}

void nested_dynamic_bound_loop(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            printf("nested_dynamic_bound_loop: i = %d, j = %d\n", i, j);
        }
    }
}

void nested_array_loop(int* arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = *((arr + i * cols) + j);
            printf("nested_array_loop: arr[%d][%d] = %d\n", i, j, value);
        }
    }
}

void nested_parallelizable_loop(int* arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *((arr + i * cols) + j) = i + j;
            printf("nested_parallelizable_loop: arr[%d][%d] = %d\n", i, j, *((arr + i * cols) + j));
        }
    }
}

void nested_dependencies_loop(int* arr, int rows, int cols) {
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            *((arr + i * cols) + j) += *((arr + (i - 1) * cols) + (j - 1));
            printf("nested_dependencies_loop: arr[%d][%d] = %d\n", i, j, *((arr + i * cols) + j));
        }
    }
}

void nested_floating_point_loop() {
    for (float i = 0; i < 1.0; i += 0.2) {
        for (float j = i; j < 1.0; j += 0.2) {
            printf("nested_floating_point_loop: i = %.1f, j = %.1f\n", i, j);
        }
    }
}

