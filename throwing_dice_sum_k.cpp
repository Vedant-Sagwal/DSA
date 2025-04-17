#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solve(int n, int k, int target, int n_count, int target_count) {
    //base case
    //on n_count , start with 0
    if (n_count > n) {
        //no dice remaining
        return 0;
    }
    //on target_count, start with target
    if (n_count == n && target_count == 0) {
        //target achieved
        return 1;
    }
    if (n_count != n && target_count == 0) {
        return 0;
    }
    int ans = 0;
    //for loop to try every k value
    for (int k_count = 1; k_count <= k; k_count++) {
        ans += solve(n, k, target, n_count + 1, target_count - k_count);
    }
    return ans;
}


int solveMem(int n, int k, int target, int n_count, int target_count, vector <vector <int> > &dp) {
    //base case
    //on n_count , start with 0
    if (n_count > n) {
        //no dice remaining
        return 0;
    }
    if (target_count < 0) {
        return 0;
    }
    //on target_count, start with target
    if (n_count == n && target_count == 0) {
        //target achieved
        return 1;
    }
    if (n_count == n && target_count != 0) {
        return 0;
    }
    if (n_count != n && target_count == 0) {
        return 0;
    }
    if (dp[n_count][target_count] != -1) {
        return dp[n_count][target_count];
    }
    int ans = 0;
    int mod = 1e9 + 7;
    //for loop to try every k value
    for (int k_count = 1; k_count <= k; k_count++) {
        if (target_count - k_count >= 0) {
            ans = (ans + solveMem(n, k, target, n_count + 1, target_count - k_count, dp)) % mod;
        }
    }
    dp[n_count][target_count] = ans;
    return dp[n_count][target_count];
}

int solveTab(int n, int k, int target) {
    vector <vector <int> > dp(n + 1, vector <int> (target + 1, 0));
    dp[n][0] = 1;
    for (int n_count = n - 1; n_count >= 0; n_count--) {
        for (int target_count = 0; target_count <= target; target_count++) {
            int ans = 0;
            int mod = 1e9 + 7;
            for (int k_count = 1; k_count <= k; k_count++ )  {
                if (target_count - k_count >= 0) {
                    ans = (ans + dp[n_count + 1][target_count - k_count]) % mod;
                }
            }
            dp[n_count][target_count] = ans;
        }
    }
    return dp[0][target];
}


int solveOpt(int n, int k, int target) {
    vector <int> curr(target + 1, 0);
    vector <int> next(target + 1, 0);
    next[0] = 1;
    for (int n_count = n - 1; n_count >= 0; n_count--) {
        for (int target_count = 0; target_count <= target; target_count++) {
            int ans = 0;
            int mod = 1e9 + 7;
            for (int k_count = 1; k_count <= k; k_count++ )  {
                if (target_count - k_count >= 0) {
                    ans = (ans + next[target_count - k_count]) % mod;
                }
            }
            curr[target_count ] = ans;
        }
        next = curr;
    }
    return curr[target];
}

int numRollsToTarget(int n, int k, int target) {
    return solveOpt(n, k, target);
}

int main() {
    return 0;
}
