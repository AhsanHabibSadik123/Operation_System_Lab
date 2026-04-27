// Deadlock avoidance Banker's algorithm

#include <bits/stdc++.h>
using namespace std;

int main(){
    int p, r;
    cout << "Enter the number of processes: ";
    cin >> p;
    cout << "Enter the number of resources: ";
    cin >> r;

    int allocation[p][r], max_need[p][r], available[r], remain_need[p][r], squ[p], squ_idx = 0, completion[p] = {0};

    cout << "Enter the Allocation matrics: " << endl;
    for(int i = 0; i < p; i++){
        for(int j = 0; j < r; j++){
            cin >> allocation[i][j];
        }
    }

    cout << "Enter the Maximum Need matrics: " << endl;
    for(int i = 0; i < p; i++){
        for(int j = 0; j < r; j++){
            cin >> max_need[i][j];
        }
    }

    cout << "Enter the Resources available " << endl;
    for(int i = 0; i < p; i++){
        cin >> available[i];
    }
    cout << "Allocation mat: " << endl;
    for(int i = 0; i < p; i++){
        for(int j = 0; j < r; j++){
            cout << allocation[i][j] << " ";
        }
        cout << endl;
    }

    cout << "max need mat: " << endl;
    for(int i = 0; i < p; i++){
        for(int j = 0; j < r; j++){
            cout << max_need[i][j] << " ";
        }
        cout << endl;
    }

    cout << "available mat: " << endl;
    for(int i = 0; i < r; i++){
        cout << available[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < p; i++){
        for(int j = 0; j < r; j++){
            remain_need[i][j] = max_need[i][j] - allocation[i][j];
        }
    }
    cout << "Remaining need: " << endl;
    for(int i = 0; i < p; i++){
        for(int j = 0; j < r; j++){
            cout << remain_need[i][j] << " ";
        }
        cout << endl;
    }
    int finished = 0;
    while(finished < p){
        for(int i = 0; i < p; i++){
            if(completion[i] == 0){
                int flag = 1;
                for(int j = 0; j < r; j++){
                    if(available[j] < remain_need[i][j]){
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1){
                    for(int j = 0; j < r; j++){
                        available[j] += allocation[i][j];
                    }
                    squ[squ_idx++] = i;
                    completion[i] = 1;
                    finished++;
                }
            }
        }
    }

    cout << "Squence: " << endl;
    for(int i = 0; i < p; i++){
        cout << squ[i] << ' ';
    }
}