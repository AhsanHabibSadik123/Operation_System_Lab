// LRU page replacement algorithm

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of pages: ";
    cin >> n;  

    vector<int>pages(n);

    cout << "Enter the page sequence: ";
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }
    
    int frames;
    cout << "Enter the number of frames: ";
    cin >> frames;
    cout << endl;

    vector<int> memory(frames, -1), last_use;
    int page_fault = 0, page_hit = 0;

    for(auto page : pages){
        bool found = false;
        for(int i = 0; i < frames; i++){
            if(page == memory[i]){
                found = true;
                break;
            }
        }
        if(!found){
            if(memory[frames-1] == -1){
                int position = find(memory.begin(), memory.end(), -1) - memory.begin();
                memory.insert(memory.begin() + position, page);
                last_use.push_back(page);
            }else{
                int position = find(memory.begin(), memory.end(), last_use[last_use.size()-3]) - memory.begin();
                memory[position] = page;
                last_use.push_back(page);
            }
            page_fault++;
        }else{
            int position = find(last_use.begin(), last_use.end(), page) - last_use.begin();
            last_use.erase(last_use.begin() + position);
            last_use.push_back(page);
            page_hit++;
        }
        cout << "Page " << page << ": ";
        for(int j = 0; j < frames; j++){
            cout << memory[j] << ' ';
        }
        cout << endl;
    }

}