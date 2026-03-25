#include <stdio.h>
#include <stdlib.h>
int c(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void s() {
    int n, i, f = 0;
    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), c);
    for(i = 0; i < n - 1; i++) {
        if(a[i] == a[i+1]) {
            f = 1;
            break;
        }
    }
    if(f) printf("YES\n");
    else printf("NO\n");
    free(a);
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        s();
    }
    return 0;
}