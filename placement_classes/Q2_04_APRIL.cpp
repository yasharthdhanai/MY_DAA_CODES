#include<bits/stdc++.h>
using namespace std;
    
struct info {
    int first;
    char ch;
};

static bool compare(info a, info b){
    if(a.ch != b.ch)
        return a.ch > b.ch;
    return a.first < b.first;
}

int main(){
    int n;
    cin >> n;

    vector<info> arr(n);
    for(int i=0; i<n ; i++){
        cin >> arr[i].first; //2. ascending
        cin >> arr[i].ch; //1. decending
    }

    sort(arr.begin(), arr.end(), compare);
    return 0;
}