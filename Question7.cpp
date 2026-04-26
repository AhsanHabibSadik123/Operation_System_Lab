// Round Robin

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of process: ";
    cin >> n;
    int bt_f[n], bt[n], ct[n], tat[n], wt[n];
    for(int i = 0; i < n; i++){
        cout << "For process: " << i + 1 << endl << "Burst time: ";
        cin >> bt_f[i];
    }
    for(int i = 0; i < n; i++){
        bt[i] = bt_f[i];
    }
    int quantum;
    cout << "Enter the time quantum: ";
    cin >> quantum;
    
    int finished = 0, current_time = 0;
    while(finished < n){
        for(int i = 0; i < n; i++){
            if(bt[i] > 0){
                if(bt[i] <= quantum){
                    current_time += bt[i];
                    ct[i] = current_time;
                    bt[i] = 0;
                    finished++;
                }else{
                    bt[i] -= quantum;
                    current_time += quantum;
                }
            }
        }
        cout << endl;
    }
    float avg_tat = 0, avg_wt = 0;
    for(int i = 0; i < n; i++){
        tat[i] = ct[i];
        wt[i] = tat[i] - bt_f[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    cout << "Pid\tbt\ttat\twt\n";
    for(int i = 0; i < n; i++){
        cout << i + 1 << "\t" << bt_f[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }
}