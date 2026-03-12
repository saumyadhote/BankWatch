#include <stdio.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {

    int transactions[] = {5000, 12000, 700, 150000, 3200, 89000, 450};
    int n = sizeof(transactions) / sizeof(transactions[0]);
    int threshold = 50000;

    mergeSort(transactions, 0, n - 1);

    printf("Sorted Transactions:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", transactions[i]);
    }

    printf("\n\nSuspicious Transactions (Above %d):\n", threshold);

    for(int i = 0; i < n; i++) {
        if(transactions[i] > threshold) {
            printf("%d\n", transactions[i]);
        }
    }

    return 0;
}