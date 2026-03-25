#include<stdio.h>
#include<stdlib.h>

// For sorted array inversion count = 0;
// inversion count tells how unsorted array is.
// inversion count -> (i>j) and arr[i]<arr[j].

int inv = 0;

void MergeArray(int* arr, int s, int m, int e){
    int ls = m-s+1 ;
    int rs = e-m ;
    int la[ls];
    int ra[rs];
    for(int i=0 ; i<ls ; i++){
        la[i] = arr[i];
    }
    for(int i=0 ; i<rs ; i++){
        ra[i] = arr[m+i-1];
    }

    int i = 0, j = 0, k = s;
    while(i<ls && j<rs){
        if(la[i] > ra[j]){
            inv = inv + ls-i+1;
        }
        if(la[i] <= ra[j]){
            j++;
        }
    }
    while(i<ls){

    }
    while(j<rs){

    }

}

int main(){
    int arr[8] = {11, 20, 32, 40, 9, 10, 54, 60} ;
    int n = 8;
    int mid = n/2;
    MergeArray(arr, 0, mid, n);

return 0;
}