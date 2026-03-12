#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

/* Structure to store transaction details */
struct Transaction {
    int id;
    char account[20];
    float amount;
};

/* Comparison function for sorting transactions by amount */
int compare(const void *a, const void *b) {
    struct Transaction *t1 = (struct Transaction *)a;
    struct Transaction *t2 = (struct Transaction *)b;
    return (t1->amount - t2->amount);
}

/* Fraud detection using Two Pointer Algorithm */
void detectFraud(struct Transaction t[], int n, float threshold) {

    /* Sort transactions by amount */
    qsort(t, n, sizeof(struct Transaction), compare);

    int left = 0;
    int right = n - 1;

    printf("\nChecking transactions for suspicious combinations...\n");

    while (left < right) {

        float sum = t[left].amount + t[right].amount;

        if (sum >= threshold) {
            printf("\n⚠ FRAUD ALERT ⚠\n");
            printf("Suspicious pair detected\n");

            printf("\nTransaction 1\n");
            printf("ID: %d\n", t[left].id);
            printf("Account: %s\n", t[left].account);
            printf("Amount: %.2f\n", t[left].amount);

            printf("\nTransaction 2\n");
            printf("ID: %d\n", t[right].id);
            printf("Account: %s\n", t[right].account);
            printf("Amount: %.2f\n", t[right].amount);

            printf("\nCombined Amount = %.2f (Threshold = %.2f)\n", sum, threshold);
            return;
        }

        else if (sum < threshold) {
            left++;
        }

        else {
            right--;
        }
    }

    printf("\nNo suspicious transaction pair found.\n");
}

int main() {

    struct Transaction transactions[MAX] = {
        {101, "AC1001", 1200},
        {102, "AC2034", 5000},
        {103, "AC3456", 2200},
        {104, "AC5678", 7000},
        {105, "AC8765", 1800},
        {106, "AC9023", 2600}
    };

    int n = 6;

    float fraudThreshold = 8000;

    printf("BANK FRAUD DETECTION SYSTEM\n");
    printf("-----------------------------\n");

    detectFraud(transactions, n, fraudThreshold);

    return 0;
}