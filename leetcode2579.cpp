#include <iostream>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        //Base Case
        if (n == 1) {
            return 1;
        }
        int i = 1;
        long long int ans = 1; 
        while (i != n) {
            ans += (4 * i);
            i++;
        }
        return ans;
    }
};

int main() {
    return 0;
}
