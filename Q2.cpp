#include<bits/stdc++.h>
using namespace std;
    
void merge(vector<int>& arr1, vector<int>& arr2){
    int i=0, j=0;
    int n = arr1.size();
    int m = arr2.size();

    for(int i=0 ; i<n ;i++){
        if(m>0 && arr1[i] > arr2[0]){
            swap(arr1[i] , arr2[0]);
            int x = 0;
            while(x<m-1 && arr2[x] > arr2[x+1]){
                int temp;
                temp = arr2[x+1];
                arr2[x+1] = arr2[x];
                arr2[x] = temp;
                x++;
            }
        }
    }
}
    
int main(){
    int n; //package form A
    cin >> n;
    vector<int> arr1(n);
    for(int i=0 ; i<n ; i++)
        cin >> arr1[i];


    int m; //package form B
    cin >> m;
    vector<int> arr2(m);
    for(int i=0 ; i<m ; i++)
        cin >> arr2[i];

    merge(arr1, arr2);

    for(int x:arr1)
        cout<<x<<" ";

    for(int x:arr2)
        cout<<x<<" ";

    return 0;
}