#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    vector<char> arr(n);
    cout << "Enter characters : ";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    // Hashing for frequency
    map<char, int> freq;
    for(int i=0 ; i<n ; i++){
        freq[arr[i]]++;
    }

    cout << "\nCharacters and their frequencies :\n";

    // Map stores keys in sorted order
    for(auto it : freq){
        cout << it.first << " " << it.second<< "\n";
    }

    return 0;
}