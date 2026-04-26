// Shortest Remain time first

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of process: ";
    cin >> n;
    
    int at[n], bt_f[n], bt[n], ct[n], tat[n], wt[n];
        for(int i = 0; i < n; i++){
        cout << "For process: " << i + 1 << endl << "Arrival time: ";
        cin >> at[i];
        cout << "Brust time: ";
        cin >> bt_f[i];
    }
    for(int i = 0; i < n; i++){
        bt[i] = bt_f[i];
    }

    for(int i = 0; i < n; i++){
        cout << at[i] << " " << bt[i] << endl;
    }
    int finished = 0, current_time = 0;
    while(finished < n){
        int idx = -1, mn_bt = INT_MAX;
        for(int i = 0; i < n; i++){
            if(at[i] <= current_time && bt[i] > 0 && bt[i] < mn_bt){
                idx = i;
                mn_bt = bt[i];
            }
        }
        if(idx != -1){
            bt[idx]--;
            if(bt[idx] == 0){
                ct[idx] = current_time + 1;
                finished++;
            }
        }
        current_time++;
    }
    float avg_tat = 0, avg_wt = 0;
    for(int i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt_f[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    cout << "\nPid\tAT\tBT\tTAT\tWT\n";
    for(int i = 0; i < n; i++){
        cout << i + 1 << "\t" << at[i] << "\t" << bt_f[i] << "\t" << tat[i] << "\t" << wt[i] << "\t" << endl;
    }
    cout << "Average turn around time: " << avg_tat / n << endl;
    cout << "Average waiting time: " << avg_wt / n << endl;
}