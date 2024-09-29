#include "push_swap.h"

 #include <unistd.h>

void sa(int *arr, int size) {
    if (size < 2)
        return;
    int temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
    write(1, "sa\n", 3);
}

void pb(int *arr_a, int *arr_b, int *size_a, int *size_b) {
    if (*size_a <= 0)
        return;
    arr_b[*size_b] = arr_a[0];
    (*size_b)++;
    int i = 0;
    while (i < *size_a - 1) {
        arr_a[i] = arr_a[i + 1];
        i++;
    }
    (*size_a)--;
    write(1, "pb\n", 3);
}

void pa(int *arr_a, int *arr_b, int *size_a, int *size_b) {
    if (*size_b <= 0)
        return;
    int i = *size_a;
    while (i > 0) {
        arr_a[i] = arr_a[i - 1];
        i--;
    }
    arr_a[0] = arr_b[0];
    (*size_a)++;
    (*size_b)--;
    i = 0;
    while (i < *size_b) {
        arr_b[i] = arr_b[i + 1];
        i++;
    }
    write(1, "pa\n", 3);
}

void perform_sorting_operations(int *arr, int size) {
    int arr_b[size];
    int size_b = 0;

    if (is_sorted(arr, size)) {
        return;
    }

    while (!is_sorted(arr, size)) {
        if (size > 1 && arr[0] > arr[1]) {
            sa(arr, size);
        }

        for (int i = 0; i < size - 1; ) {
            if (arr[i] > arr[i + 1]) {
                pb(arr, arr_b, &size, &size_b);
            } else {
                i++;
            }
        }

        while (size_b > 0) {
            pa(arr, arr_b, &size, &size_b);
        }

        if (is_sorted(arr, size)) {
            break;
        }

        if (size_b == 0) {
            break;
        }
    }
}