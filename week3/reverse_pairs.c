#include <stdio.h>
#include <stdlib.h>

int count = 0;

void merge(int arr[], int l, int mid, int r) {
    int j = mid + 1;

    
    for (int i = l; i <= mid; i++) {
        while (j <= r && (long long)arr[i] > 2LL * arr[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    int size1 = mid - l + 1;
    int size2 = r - mid;

    int *temp1 = (int *)malloc(size1 * sizeof(int));
    int *temp2 = (int *)malloc(size2 * sizeof(int));

    for (int i = 0; i < size1; i++)
        temp1[i] = arr[l + i];

    for (int i = 0; i < size2; i++)
        temp2[i] = arr[mid + 1 + i];

    int left = 0, k = l, right = 0;

    while (left < size1 && right < size2) {
        if (temp1[left] <= temp2[right])
            arr[k++] = temp1[left++];
        else
            arr[k++] = temp2[right++];
    }

    while (left < size1)
        arr[k++] = temp1[left++];

    while (right < size2)
        arr[k++] = temp2[right++];

    free(temp1);
    free(temp2);
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

int main() {
    int number;

    printf("Enter number of elements: ");
    scanf("%d", &number);

    int *arr = (int *)malloc(number * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < number; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, number- 1);

    printf("Number of significant reverse pairs = %d\n", count);

    free(arr);

    return 0;
}