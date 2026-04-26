// Shortest Job first

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of process: ";
    cin >> n;

    int at[n], bt[n], ct[n], tat[n], wt[n], squ[n], completion[n] = {0};

    for(int i = 0; i < n; i++){
        cout << "For process: " << i + 1 << endl << "Arrival time: ";
        cin >> at[i];
        cout << "Brust time: ";
        cin >> bt[i];
    }
    for(int i = 0; i < n; i++){
        cout << at[i] << " " << bt[i] << endl;
    }

    int current_time = 0, finished = 0, squ_idx = 0;

    while(finished < n){
        int idx = -1, mn_bt = INT_MAX;
        for(int i = 0; i < n; i++){
            if(at[i] <= current_time && completion[i] == 0 && bt[i] < mn_bt){
                idx = i;
                mn_bt = bt[i];
            }
        }
        if(idx != -1){
            completion[idx] = 1;
            squ[squ_idx++] = idx;
            current_time += bt[idx];
            finished++;
        }else{
            current_time++;
        }
    }
    current_time = at[squ[0]];
    for(int i = 0; i < n; i++){
        ct[squ[i]] = bt[squ[i]] + current_time;
        current_time += bt[squ[i]];
    }
    float avg_tat = 0, avg_wt = 0;
    for(int i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    cout << "Gantt Cheat: ";
    for(int i = 0; i < n; i++){
        cout << " | p" << squ[i] + 1 << " ";
    }
    cout << " |" << endl;

    cout << "\nPid\tAT\tBT\tTAT\tWT\n";
    for(int i = 0; i < n; i++){
        cout << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" << tat[i] << "\t" << wt[i] << "\t" << endl;
    }
    cout << "Average turn around time: " << avg_tat / n << endl;
    cout << "Average waiting time: " << avg_wt / n << endl;
}
