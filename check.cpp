#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {1, 2, 2, 4, 5};
    int position = find(arr.begin(), arr.end(), 2) - arr.begin();
    cout << "Position of 3 is: " << position << endl;

    // arr.erase(arr.begin() + position);
    // cout << "Array after deletion: ";
    // for(int num : arr){
    //     cout << num << " "; 
    // }

    arr.insert(arr.begin() + position, 10);
    cout << "Array after insertion: ";
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}