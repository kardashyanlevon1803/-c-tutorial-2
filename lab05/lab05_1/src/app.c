#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int x;
    scanf("%d", &x);

    int l = 0, r = n - 1, mid, pos = -1;

    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] == x) {
            pos = mid;
            break;
        } else if (a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    printf("%d", pos);
    return 0;
}
