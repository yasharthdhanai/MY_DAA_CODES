#include<bits/stdc++.h>
using namespace std;
    
// Moore’s Voting Algorithm.

int main(){
    int n;
    cin >> n;
    vector<int>arr(n); // n should be greater than 0
    
    for(int i=0 ;i<arr.size(); i++){
        cin >> arr[i];
    }

    int x = arr[0];
    int count = 1;
    for(int i=1 ; i<arr.size(); i++){
        if(count == 0){
            x = arr[i];
            count = 1;
        }
        if(arr[i] == x)
            count++;
        else
            count--;
    }

    int newcount = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == x)
            newcount++;
    }
    if(newcount > arr.size()/2)
        cout << "yes : " << x << endl;
    else
        cout << "no"<< endl;
    return 0;
}