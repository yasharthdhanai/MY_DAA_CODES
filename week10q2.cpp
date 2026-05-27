#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Number of tasks : ";
    cin >> n;
    vector<int> time(n);
    vector<int> deadline(n);

    for(int i=0; i<n ; i++){
        cin >> time[i];
        cin >> deadline[i];
    }

    vector<pair<pair<int,int>, int>> tasks(n);

    for(int i=0 ; i<n ; i++){
        tasks[i] = {{deadline[i] , time[i]}, i};
    }

    sort(tasks.begin(), tasks.end());

    priority_queue<pair<int, int>> pq;

    int total_time = 0;

    for(int i=0 ; i<n ; i++){
        int curr_deadline = tasks[i].first.first;
        int curr_time = tasks[i].first.second;
        int task_no = tasks[i].second;

        total_time = total_time + curr_time;
        pq.push({curr_time, task_no}); //1st insertion....

        // If deadline crossed
        if(total_time > curr_deadline){ 
            total_time = total_time - pq.top().first;
            pq.pop(); // then delection is correct....
        }
    }

    vector<int> task_completed;
    while(!pq.empty()){
        task_completed.push_back(pq.top().second);
        pq.pop();
    }

    sort(task_completed.begin(), task_completed.end());
    cout << "\nMax number of tasks = " << task_completed.size() << "\n";
    cout << "Selected task numbers : ";
    for(int i=0 ; i<task_completed.size() ; i++){
        cout << task_completed[i] << " ";
    }

    return 0;
}