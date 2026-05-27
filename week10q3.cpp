#include<bits/stdc++.h>
using namespace std;

//Finding majority element in an array.
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }

    int x = arr[0];
    int count = 1;
    
    for(int i=1; i<n; i++){
        if(x == arr[i]){
            count++;
        }
        else if(x != arr[i] && count != 0){
            count--;
        }
        else{
            x = arr[i];
            count = 1;
        }
    }

    int new_count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            new_count++;
        }
    }
    if(new_count >= n/2){
        cout << "Majority element is : " << x << endl;
    }
    else{
        cout<< "No majority element is present." << endl;
    }

    return 0;
}