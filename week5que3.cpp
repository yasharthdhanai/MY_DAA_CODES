#include<iostream>
#include<vector>

using namespace std;

int main(){
    int m, n;
    cin >> m;
    vector<int> arr1(m);
    for(int i=0 ; i<m ; i++){
        cin >> arr1[i]; // sorted array
    }
    cin >> n;
    vector<int> arr2(n);
    for(int i=0 ; i<n ; i++){
        cin >> arr2[i]; // sorted array
    }

    int i = 0, j = 0, a = 0;
    while(i<m && j<n){
        if(arr1[i] == arr2[j]){
            cout << arr1[i] << " ";
            a = 1;
            i++;
            j++;
        }
        else if(arr1[i] > arr2[j])
            j++;
        else
            i++;
    }
    if(!a){
        cout << "No Common Element Exists.\n";
    }

    return 0;

}
