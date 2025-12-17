#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n], b[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                int t = b[j];
                b[j] = b[j + 1];
                b[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }

    return 0;
}