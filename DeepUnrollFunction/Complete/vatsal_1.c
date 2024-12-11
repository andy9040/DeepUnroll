#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void basic_for_loop();
void basic_while_loop();
void basic_do_while_loop();
void nested_loops();
void loop_with_condition();
void variable_step_loop();
void reverse_loop();
void infinite_loop();
void loop_with_break();
void loop_with_continue();
void manually_unrolled_loop();
void loop_with_complex_condition();
void loop_with_function_calls();
void nested_dependent_loops();
void dynamic_loop_bound(int n);
void loop_with_array(int* arr, int n);
void parallelizable_loop(int* arr, int size);
void loop_with_dependencies(int* arr, int n);
void loop_with_early_exit();
void recursive_loop(int n);
void floating_point_loop();
void irregular_loop();

int some_function(int x) {
    return x * x + 2 * x + 1;
}

int some_condition(int x) {
    return x % 7 == 0;
}

int main() {
    int arr[100];
    for (int i = 0; i < 100; i++) arr[i] = i;

    basic_for_loop();
    basic_while_loop();
    basic_do_while_loop();
    nested_loops();
    loop_with_condition();
    variable_step_loop();
    reverse_loop();
    infinite_loop();
    loop_with_break();
    loop_with_continue();
    manually_unrolled_loop();
    loop_with_complex_condition();
    loop_with_function_calls();
    nested_dependent_loops();
    dynamic_loop_bound(10);
    loop_with_array(arr, 100);
    parallelizable_loop(arr, 100);
    loop_with_dependencies(arr, 100);
    loop_with_early_exit();
    recursive_loop(5);
    floating_point_loop();
    irregular_loop();

    return 0;
}

// Function definitions
void basic_for_loop() {
    for (int i = 0; i < 10; i++) {
        printf("basic_for_loop: i = %d\n", i);
    }
}

void basic_while_loop() {
    int i = 0;
    while (i < 10) {
        printf("basic_while_loop: i = %d\n", i);
        i++;
    }
}

void basic_do_while_loop() {
    int i = 0;
    do {
        printf("basic_do_while_loop: i = %d\n", i);
        i++;
    } while (i < 10);
}

void nested_loops() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            printf("nested_loops: i = %d, j = %d\n", i, j);
        }
    }
}

void loop_with_condition() {
    for (int i = 0; i < 20; i++) {
        if (i % 3 == 0) {
            printf("loop_with_condition: i = %d is divisible by 3\n", i);
        }
    }
}

void variable_step_loop() {
    for (int i = 0; i < 50; i += 5) {
        printf("variable_step_loop: i = %d\n", i);
    }
}

void reverse_loop() {
    for (int i = 10; i >= 0; i--) {
        printf("reverse_loop: i = %d\n", i);
    }
}

void infinite_loop() {
    int count = 0;
    while (1) {
        printf("infinite_loop: count = %d\n", count);
        count++;
        if (count == 5) break; // Exit condition
    }
}

void loop_with_break() {
    for (int i = 0; i < 10; i++) {
        if (i == 7) {
            printf("loop_with_break: Breaking at i = %d\n", i);
            break;
        }
        printf("loop_with_break: i = %d\n", i);
    }
}

void loop_with_continue() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) continue;
        printf("loop_with_continue: i = %d\n", i);
    }
}

void manually_unrolled_loop() {
    for (int i = 0; i < 10; i += 2) {
        printf("manually_unrolled_loop: i = %d\n", i);
        printf("manually_unrolled_loop: i+1 = %d\n", i + 1);
    }
}

void loop_with_complex_condition() {
    for (int i = 0, j = 10; i < j; i++, j--) {
        printf("loop_with_complex_condition: i = %d, j = %d\n", i, j);
    }
}

void loop_with_function_calls() {
    for (int i = 0; i < 10; i++) {
        int result = some_function(i);
        printf("loop_with_function_calls: i = %d, result = %d\n", i, result);
    }
}

void nested_dependent_loops() {
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            printf("nested_dependent_loops: i = %d, j = %d\n", i, j);
        }
    }
}

void dynamic_loop_bound(int n) {
    for (int i = 0; i < n; i++) {
        printf("dynamic_loop_bound: i = %d\n", i);
    }
}

void loop_with_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] += 2;
        printf("loop_with_array: arr[%d] = %d\n", i, arr[i]);
    }
}

void parallelizable_loop(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
        printf("parallelizable_loop: arr[%d] = %d\n", i, arr[i]);
    }
}

void loop_with_dependencies(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] + i;
        printf("loop_with_dependencies: arr[%d] = %d\n", i, arr[i]);
    }
}

void loop_with_early_exit() {
    for (int i = 0; i < 10; i++) {
        if (some_condition(i)) {
            printf("loop_with_early_exit: Exiting at i = %d\n", i);
            return;
        }
        printf("loop_with_early_exit: i = %d\n", i);
    }
}

void recursive_loop(int n) {
    if (n <= 0) return;
    printf("recursive_loop: n = %d\n", n);
    recursive_loop(n - 1);
}

void floating_point_loop() {
    for (float i = 0.0; i < 1.0; i += 0.1) {
        printf("floating_point_loop: i = %.1f\n", i);
    }
}

void irregular_loop() {
    for (int i = 0; i < 10;) {
        int step = rand() % 3 + 1;
        printf("irregular_loop: i = %d, step = %d\n", i, step);
        i += step;
    }
}

