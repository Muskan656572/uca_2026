#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function pointer */
typedef int (*CompareFunc)(const void *, const void *);


/* ==================== SWAP ==================== */

void swap(void *a, void *b, size_t size)
{
    void *temp = malloc(size);

    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}


/* ==================== HEAPIFY ==================== */

void heapify(void *arr, size_t n, size_t i,
             size_t size, CompareFunc cmp)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    char *array = (char *)arr;

    if (left < n &&
        cmp(array + left * size,
            array + largest * size) > 0)
    {
        largest = left;
    }

    if (right < n &&
        cmp(array + right * size,
            array + largest * size) > 0)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(array + i * size,
             array + largest * size,
             size);

        heapify(arr, n, largest, size, cmp);
    }
}


/* ==================== GENERIC HEAP SORT ==================== */

void heap_sort(void *arr, size_t n,
               size_t size, CompareFunc cmp)
{
    size_t i;

    if (arr == NULL || n < 2 || size == 0 || cmp == NULL)
        return;

    /* Build max heap */
    for (i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i - 1, size, cmp);
    }

    /* Extract elements */
    for (i = n - 1; i > 0; i--)
    {
        char *array = (char *)arr;

        swap(array, array + i * size, size);

        heapify(arr, i, 0, size, cmp);
    }
}


/* ==================== INT COMPARISON ==================== */

int compare_int(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}


/* ==================== FLOAT COMPARISON ==================== */

int compare_float(const void *a, const void *b)
{
    float x = *(const float *)a;
    float y = *(const float *)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}


/* ==================== DOUBLE COMPARISON ==================== */

int compare_double(const void *a, const void *b)
{
    double x = *(const double *)a;
    double y = *(const double *)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}


/* ==================== STRUCT ==================== */

struct Student
{
    int roll_no;
    char name[50];
    float marks;
};


/* Compare students by marks */
int compare_student(const void *a, const void *b)
{
    const struct Student *s1 =
        (const struct Student *)a;

    const struct Student *s2 =
        (const struct Student *)b;

    if (s1->marks < s2->marks)
        return -1;

    if (s1->marks > s2->marks)
        return 1;

    return 0;
}


/* ==================== MAIN ==================== */

int main(void)
{
    /* ---------- INT ---------- */

    int numbers[] = {42, 7, 19, 3, 25, 10, 1};
    size_t n = sizeof(numbers) / sizeof(numbers[0]);

    printf("INT ARRAY\n");
    printf("Before: ");

    for (size_t i = 0; i < n; i++)
        printf("%d ", numbers[i]);

    printf("\n");

    heap_sort(numbers, n, sizeof(numbers[0]), compare_int);

    printf("After:  ");

    for (size_t i = 0; i < n; i++)
        printf("%d ", numbers[i]);

    printf("\n\n");


    /* ---------- FLOAT ---------- */

    float floats[] = {
        4.5f, 1.2f, 9.8f, 3.3f, 2.1f
    };

    size_t f = sizeof(floats) / sizeof(floats[0]);

    printf("FLOAT ARRAY\n");
    printf("Before: ");

    for (size_t i = 0; i < f; i++)
        printf("%.2f ", floats[i]);

    printf("\n");

    heap_sort(floats, f, sizeof(floats[0]), compare_float);

    printf("After:  ");

    for (size_t i = 0; i < f; i++)
        printf("%.2f ", floats[i]);

    printf("\n\n");


    /* ---------- DOUBLE ---------- */

    double doubles[] = {
        8.45, 2.13, 9.87, 1.56, 5.21
    };

    size_t d = sizeof(doubles) / sizeof(doubles[0]);

    printf("DOUBLE ARRAY\n");
    printf("Before: ");

    for (size_t i = 0; i < d; i++)
        printf("%.2lf ", doubles[i]);

    printf("\n");

    heap_sort(doubles, d,
              sizeof(doubles[0]),
              compare_double);

    printf("After:  ");

    for (size_t i = 0; i < d; i++)
        printf("%.2lf ", doubles[i]);

    printf("\n\n");


    /* ---------- STRUCT ---------- */

    struct Student students[] =
    {
        {101, "Alice", 85.5f},
        {102, "Bob", 72.0f},
        {103, "Charlie", 91.5f},
        {104, "David", 68.5f},
        {105, "Emma", 78.0f}
    };

    size_t s = sizeof(students) / sizeof(students[0]);

    printf("STRUCT ARRAY\n");
    printf("Before sorting:\n");

    for (size_t i = 0; i < s; i++)
    {
        printf("%d  %-10s  %.2f\n",
               students[i].roll_no,
               students[i].name,
               students[i].marks);
    }

    heap_sort(students, s,
              sizeof(students[0]),
              compare_student);

    printf("\nAfter sorting by marks:\n");

    for (size_t i = 0; i < s; i++)
    {
        printf("%d  %-10s  %.2f\n",
               students[i].roll_no,
               students[i].name,
               students[i].marks);
    }

    return 0;
}