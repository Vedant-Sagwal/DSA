#include <iostream>
#include <vector>
using namespace std;

bool can_be_k(vector<int> &piles, int h, int k) {
    long long int count = 0;    
    for (int i = 0; i < piles.size(); i++) {
        if (piles[i] % k == 0) {
            count += (piles[i] / k);
        }
        else {
            count += (piles[i] / k) + 1;
        }
    }
    if (count <= h) {
       return true;
    }
    return false;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int maxi = INT_MIN;
    for (auto i : piles) {
        if (i > maxi) {
            maxi = i;
        }
    }
    int i = 1;
    int j = maxi;
    while (i <= j) {
        int mid = (i + j) / 2;
        if (can_be_k(piles, h, mid)) {
            j = mid - 1;
        }
        else {
            i = mid + 1;
        }
    }
    return i;
}

int main() {
    return 0;
}
