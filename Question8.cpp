#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of process: ";
    cin >> n;

    int at[n], priority[n], bt[n], completion[n] = {0}, ct[n];

    for(int i = 0; i < n; i++){
        cout << "process " << i + 1 << ":\n" << "Priority: ";
        cin >> priority[i];
        cout << "Arrival time: ";
        cin >> at[i];
        cout << "Burst time: ";
        cin >> bt[i];
    }

    int finished = 0, current_time = 0;
    while(finished < n){
        int mx_priority = INT_MAX, idx = -1;
        for(int i = 0; i < n; i++){
            if(completion[i] == 0 && at[i] <= current_time && priority[i] < mx_priority){
                idx = i;
                mx_priority = priority[i];
            }
        }
        if(idx != -1){
            bt[idx]--;
            if(bt[idx] == 0){
                ct[idx] = current_time + 1;
                completion[idx] = 1;
                finished++;
            }
        }
        current_time++;
    }
    for(int i = 0; i < n; i++){
        cout << ct[i] << ' ';
    }
}