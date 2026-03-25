#include<iostream>
using namespace std;

void mergearr(int* arr, int st, int mid, int end, bool* z){
    int* sortedarr = (int*)malloc((end-st+1) * sizeof(int));
    int i=st, j=mid+1, x=0;
    while(i<=mid && j<=end){
        if(arr[i] < arr[j]){
            sortedarr[x] = arr[i];
            x++;
            i++;
        }
        else if(arr[i] == arr[j]){
            sortedarr[x] = arr[i];
            x++;
            i++;
            (*z) = true;
        }
        else{
            sortedarr[x] = arr[j];
            x++;
            j++;
        }
    }
    while(j<=end){
        sortedarr[x] = arr[j];
        x++;
        j++;
    }
    while(i<=mid){
        sortedarr[x] = arr[i];
        x++;
        i++;
    }
    int a=0;
    for(int b=st; b<=end; b++){
        arr[b] = sortedarr[a];
        a++;
    }
    free(sortedarr);
}

bool mergesort(int* arr, int st, int end){
    if(st==end)
        return false;
    int mid = (end-st)/2 +st;
    bool a = mergesort(arr, st, mid);
    bool b = mergesort(arr, mid+1, end);
    bool z = false;
    mergearr(arr, st, mid, end, &z);
    return (a || b || z);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n, target;
        cin>>n;
        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin >> arr[i];
        }
        bool z = mergesort(arr, 0, n-1);
        for(int i=0 ; i<n ; i++){
            cout << arr[i] << " ";
        }
        if(z == true)
            cout << endl << "true" << endl; 
        else
            cout << endl << "false" << endl;
    }
    return 0;
}