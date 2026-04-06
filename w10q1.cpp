#include<bits/stdc++.h>
using namespace std;
   
// correct code but we are given 2 arrays for starting and ending .

static bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second; // sort according to end time.
}

int main(){
    int n;
    cin >> n; // n>0.

    vector<pair<int, int>> activity(n);
    for(int i=0 ;i<n ;i++){
        cin >> activity[i].first; // start time
        cin >> activity[i].second; // end time
    }

    sort(activity.begin(), activity.end(), compare);

    int count=1;
    int last_end = activity[0].second;
    for(int i=1 ; i<n ;i++){
        if(activity[i].first >= last_end){
            count++;
            last_end = activity[i].second;
        }
    }

    cout << count<< endl;
    return 0;
}