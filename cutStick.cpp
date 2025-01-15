#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cutTheSticks(vector<int> arr) {
    vector <int> ans;
    int size = arr.size();
    sort(arr.begin(), arr.end());
    ans.push_back(size);
    int count = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i - 1]) {
            ans.push_back(size - count);
            size = size - count;
            count = 1;
        }
        else {
            count++;
        }
    }
    return ans;
}

int main() {
    vector <int> arr;
    int num;
    cout << "Enter arr : " << endl;
    while (num != -1) {
        cin >> num;
        if (num == -1) {
            break;
        }
        arr.push_back(num);
    } 
    vector <int> ans = cutTheSticks(arr);
    for(auto i : ans) {
        cout << i << "\t";
    }
    return 0;
}
