#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int m, n;
    scanf("%d", &m);
    int arr1[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &n);
    int arr2[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }
    qsort(arr1, m, sizeof(int), cmp);
    qsort(arr2, n, sizeof(int), cmp);
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {
            printf("%d ", arr1[i]);
            i++, j++;
        } else if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
    return 0;
}