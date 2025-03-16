#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector <int> prime_between_two_numbers(int a, int b) {
    if (b < 2) return {}; 
    vector <int> ans;
    vector <bool> isPrime(b + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i*i <= b; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= b; j = j + i) {
                isPrime[j] = false;
            }
        }
    }
   for (int i = max(2,a); i <= b; i++) {
        if (isPrime[i]) {
            ans.push_back(i);
        }
    } 
    return ans;
}

vector<int> closestPrimes(int left, int right) {
    vector <int> ans(2, -1);
    vector <int> allPrimes = prime_between_two_numbers(left, right); 
    if (allPrimes.size() < 2) {
        return ans;
    }
    int i = 0;
    int ans1 = allPrimes[0];
    int ans2 = allPrimes[1];
    int mini = INT_MAX;
    for (i = 0; i < allPrimes.size() - 1; i++) {
        if ((allPrimes[i + 1] - allPrimes[i]) < mini) {
            mini = allPrimes[i + 1] - allPrimes[i];
            ans1 = allPrimes[i];
            ans2 = allPrimes[i + 1];
        }
    }
    ans[0] = ans1;
    ans[1] = ans2;
    return ans;
}



int main() {
    return 0;
}
