#include <iostream>
using namespace std;

int minimumRecolors1(string blocks, int k) {
    int mini = INT_MAX;
    for (int i = 0; i < blocks.length() - k + 1; i++ ) {
        int change = 0;
        for (int j = i; j < i + k ; j++) {
            if (blocks[j] == 'W') {
                change++;
            } 
        }
        if (change < mini) {
            mini = change;
        }
    }        
    if (mini == INT_MAX) {
        mini = 0;
    }
    return mini;
}

int minimumRecolors(string blocks, int k) {
    int ans = 0;
    for (int i = 0; i < k; i++) {     
        if (blocks[i] == 'W') {
            ans++; 
        }
    }
    int change = ans;
    for (int  i = k; i < blocks.length(); i++) {
        if (blocks[i] == 'W') {
            change++;
            
        }
        if (blocks[i - k] == 'W') {
            change--;
        }
        ans = min(ans, change);
    }
    if (ans < 0) {
        return 0;
    }
    return ans;
}

int main() {
    return 0;
}
