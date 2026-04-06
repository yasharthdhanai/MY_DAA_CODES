#include<bits/stdc++.h>
using namespace std;
    
struct info{
    int first;
    int second;
    int third;
};

static bool compare(info a, info b){
    if(a.third != b.third)
        return a.third > b.third; // sorting in decending order.
    if(a.second != b.second)
        return a.second < b.second; // sorting in ascending.
    return a.first > b.first; //(decending) if true no swap, if false swap.

}
    
int main(){
    int n;
    cin >> n;

    vector<info> arr(n);
    for(int i=0; i<n ; i++){
        cin >> arr[i].first;
        cin >> arr[i].second;
        cin >> arr[i].third;
    }

    sort(arr.begin(), arr.end(), compare);

    return 0;
}