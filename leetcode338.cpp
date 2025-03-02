#include <iostream>
#include <vector>
using namespace std;

int no_of_ones(int n) {
    int count = 0;
    while(n != 0) {
        if ((n & 1) == 1) {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

vector<int> countBits(int n) {
    vector <int> ans;
    ans.push_back(0);
    for (int i = 1; i <= n; i++) {
        ans.push_back(no_of_ones(i));
    }
    return ans;
}

int main() {
    return 0;
}
