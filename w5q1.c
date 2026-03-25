#include <stdio.h>
#include <stdlib.h>
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        char arr[n];
        int farr[26] = {0};
        for (int i = 0; i < n; i++) {
            scanf(" %c", &arr[i]);
        }
        for (int i = 0; i < n; i++) {
            int index = arr[i] - 'a';
            farr[index]++;
        }
        int max_count = 0;
        int max_char_index = -1;
        for (int i = 0; i < 26; i++) {
            if (farr[i] > max_count) {
                max_count = farr[i];
                max_char_index = i;
            }
        }
        if (max_count > 1) {
            printf("%c - %d\n", max_char_index + 'a', max_count);
        } else {
            printf("No Duplicates Present\n");
        }
    }
    return 0;
}