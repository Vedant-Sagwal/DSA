#include <iostream>
#include <vector>
using namespace std;

bool can_be_ans(vector<int> &ranks, int cars, long long int ans) {
    long long int time = 0;
    for (int i = 0; i < ranks.size(); i++) {
        long long int square = ans / ranks[i];
        long long int n = long(sqrt(square));
        time += n;
    }
    if (time >= cars) {
        return true;
    }
    return false;
}

long long repairCars(vector<int>& ranks, int cars) {
    long long int mini = ranks[0];
    for (int i = 0; i < ranks.size(); i++) {
        if (ranks[i] < mini) {
            mini = ranks[i];
        }
    }
    long long int i = 1;
    long long int j = mini * long(long(cars) * long(cars));
    while (i <= j) { 
        long long int mid = i + ((j - i) / 2);
        if (can_be_ans(ranks, cars, mid)) {
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
