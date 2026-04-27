// FIFO page replecement algorithm

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, frames;
    cout << "Enter the length of page sequence: ";
    cin >> n;
    int pages[n];
    cout << "Enter the page sequence: ";
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }
    cout << "Enter the number of frames: ";
    cin >> frames;
    cout << endl;

    int memory[frames];
    for(int i = 0; i < frames; i++){
        memory[i] = -1;
    }


    int page_fault = 0, page_hit = 0, ptr = 0;

    for(int i = 0; i < n; i++){
        int found = 0;
        for(int j = 0; j < frames; j++){
            if(pages[i] == memory[j]){
                found = 1;
                break;
            }
        }
        if(found == 0){
            memory[ptr++] = pages[i];
            ptr %= frames;
            page_fault++;
        }else{
            page_hit++;
        }
        cout << "page " << pages[i] << ": ";
        for(int j = 0; j < frames; j++){
            if(memory[j] == -1){
                cout << "- ";
            }else{
                cout << memory[j] << ' ';
            }
        }
        if(found == 0){
            cout << "(Fault)" << endl;
        }else{
            cout << "(Hit)" << endl;
        }
    }
    cout << "Page Hit: " << page_hit << endl;
    cout << "Page Fault: " << page_fault << endl;
}