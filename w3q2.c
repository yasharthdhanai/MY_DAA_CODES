#include<stdio.h>
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d",& arr[i]);
    }
    
    int temp, smallestIndex;
    for(int i=0 ; i < n-1 ; i++){
        smallestIndex = i;
        for(int j=i+1 ; j < n ; j++){
            if(arr[j] < arr[smallestIndex]){
                smallestIndex = j;
            }
        }
        temp = arr[smallestIndex];
        arr[smallestIndex] = arr[i];
        arr[i] = temp;
    }

return 0;
}