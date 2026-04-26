// First come first serve


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of process: ";
    cin >> n;

    int at[n], bt[n], ct[n], tat[n], wt[n];
    for(int i = 0; i < n; i++){
        cout << "For process: " << i + 1 << endl;
        cout << "Arrival time: ";
        cin >> at[i];
        cout << "Burst time: ";
        cin >> bt[i];
    }

    ct[0] = bt[0];
    for(int i = 1; i < n; i++){
        if(ct[i-1] >= at[i]){
            ct[i] = ct[i-1] + bt[i];
        }else{
            ct[i] = at[i] + bt[i];
        }
    }

    // Calculate turnaround time
    for(int i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
    }

    //Calculate waiting time
    for(int i = 0; i < n; i++){
        wt[i] = tat[i] - bt[i];
    }


    double avg_wt = 0, avg_tat = 0;
    for(int i = 0; i < n; i++){
        avg_tat += tat[i];
        avg_wt += wt[i];
    }
    avg_tat /= n;
    avg_wt /= n;

    cout << "\nPid\tAT\tBT\tTAT\tWT\n";
    for(int i = 0; i < n; i++){
        cout << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" << tat[i] << "\t" << wt[i] << "\t" << endl;
    }
    cout << "Average turn around time: " << avg_tat << endl;
    cout << "Average waiting time: " << avg_wt << endl;
}