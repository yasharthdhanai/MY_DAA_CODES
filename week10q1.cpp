#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Number of tasks : ";
    cin >> n;

    vector<pair<int,int>> time(n);
    for(int i=0 ; i<n; i++){
        int st, end;
        cin >> st;
        cin >> end;
        time[i] = {end, st};
    }
    vector<int> tasks;

    sort(time.begin(), time.end());

    int count = 1;
    int end_time = time[0].first;
    tasks.push_back(1);
    for(int i=1 ; i<n ; i++){
        if(time[i].second >= end_time){
            count++;
            end_time = time[i].first;
            tasks.push_back(i+1);
        }
    }
    cout << "Number of Tasks : "<<count <<"\n";
    cout << "Tasks : ";
    for(int i=0; i< tasks.size() ; i++){
        cout << tasks[i] <<" ";
    }

    return 0;
}