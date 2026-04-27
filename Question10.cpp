#include <bits/stdc++.h>
using namespace std;
int main(){
    int p, r;
    cout << "Enter the number of processes: ";
    cin >> p;
    cout << "Enter the number of resources: ";
    cin >> r;

    int allocation[p][r], request[p][r], available[r], completion[p] = {0};
    for(int i = 0; i < p; i++){
        for(int j = 0; j < r; j++){
            cin >> allocation[i][j];
        }
    }

    for(int i = 0; i < p; i++){
        for(int j = 0; j < r; j++){
            cin >> request[i][j];
        }
    }

    for(int i = 0; i < r; i++){
        cin >> available[i];
    }

    cout << "Allocation matrix:\n";
    for(int i = 0; i < p; i++){
        for(int j = 0; j < r; j++){
            cout << allocation[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "Request matrix:\n";
    for(int i = 0; i < p; i++){
        for(int j = 0; j < r; j++){
            cout << request[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "Available Mat:\n";
    for(int i = 0; i < r; i++){
        cout << available[i] << ' ';
    }
    cout << endl;


    int finished = 0;
    while(finished < p){
        bool update = false;
        for(int i = 0; i < p; i++){
            if(completion[i] == 0){
                int flag = 1;
                for(int j = 0; j < r; j++){
                    if(available[j] < request[i][j]){
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1){
                    update = true;
                    completion[i] = 1;
                    finished++;
                    for(int j = 0; j < r; j++){
                        available[j] += allocation[i][j];
                    }
                }
            }
        }
        if(update == false){
            cout << "Deadlock Detected!\n";
            return 0;
        }
    }
    cout << "No Deadlock detected.\n";
    
}