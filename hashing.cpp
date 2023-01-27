#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {-6, -3, 2, -2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
   
    unordered_map<int, int> hash;

    for (int i = 0; i < n; i++) {
        if (hash.find(abs(arr[i])) == hash.end()) {
            hash[abs(arr[i])] = i;
        } else {
            cout <<"-"<<abs(arr[i]) << ", " << abs(arr[i]) << endl;
        }
    }

    return 0;
}
