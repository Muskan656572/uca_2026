#include <stdio.h>
#include <stdlib.h>

typedef struct Pair {
    int value;
    int index;
}Pair;

void merge(Pair arr[], int left, int mid, int right, int ans[]) {
    int i, j;
    Pair *temp = (Pair *)malloc((right - left + 1) * sizeof(Pair));

    // Count smaller elements
    j = mid + 1;
    for (i = left; i <= mid; i++) {
        while (j <= right && arr[i].value > arr[j].value)
            j++;

        ans[arr[i].index] += j - (mid + 1);
    }

    // Merge
    i = left;
    j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i].value <= arr[j].value)
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    k=0;
    for (i = left; i <= right; i++) {
        arr[i] = temp[k];
        k++;
    }

    free(temp);
}

void mergeSort(Pair arr[], int left, int right, int ans[]) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, ans);
    mergeSort(arr, mid + 1, right, ans);

    merge(arr, left, mid, right, ans);
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    Pair arr[n];
    int ans[n];

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        ans[i] = 0;
    }

    mergeSort(arr, 0, n - 1, ans);

    printf("Output:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    printf("\n");

    return 0;
}