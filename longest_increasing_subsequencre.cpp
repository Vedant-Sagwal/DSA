#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solveSir(vector<int> &nums, int index) {
  // Base Case
  if (index == 0) {
    return 1;
  }
  // recursive call
  if (nums[index] > nums[index - 1]) {
    // can include
    return 1 + solveSir(nums, index - 1);
  } else {
    // not include
    return solveSir(nums, index - 1);
  }
}

int solve(vector<int> &nums, int index, int mini) {
  // Base Case
  if (index == nums.size()) {
    return 0;
  }
  // recursive call
  // include
  int include = INT_MIN;
  if (nums[index] > nums[mini]) {
    include = 1 + solve(nums, index + 1, index);
  }
  // exclude
  int exclude = solve(nums, index + 1, mini);
  return max(include, exclude);
}

int solveMem(vector<int> &nums, int index, int mini, vector<vector<int>> &dp) {
  // Base Case
  if (index == nums.size()) {
    return 0;
  }
  if (dp[index][mini + 1] != -1) {
    return dp[index][mini + 1];
  }

  int include = 0;
  if (mini == -1 || nums[index] > nums[mini]) {
    include = 1 + solveMem(nums, index + 1, index, dp);
  }
  // exclude
  int exclude = solveMem(nums, index + 1, mini, dp);
  dp[index][mini + 1] = max(include, exclude);
  return dp[index][mini + 1];
}

int solveTab(vector<int> &nums) {
  vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
  for (int i = nums.size() - 1; i >= 0; i--) {
    for (int mini = i - 1; mini >= -1; mini--) {
      int include = 0;
      if (mini == -1 || nums[i] > nums[mini]) {
        include = 1 + dp[i + 1][i + 1];
      }
      int exclude = dp[i + 1][mini + 1];
      dp[i][mini + 1] = max(include, exclude);
    }
  }
  return dp[0][0];
}

int solveOpt(vector<int> &nums) {
  vector<int> prev(nums.size() + 1, 0);
  vector<int> next(nums.size() + 1, 0);
  for (int i = nums.size() - 1; i >= 0; i--) {
    for (int mini = i - 1; mini >= -1; mini--) {
      int include = 0;
      if (mini == -1 || nums[i] > nums[mini]) {
        include = 1 + next[i + 1];
      }
      int exclude = next[mini + 1];
      prev[mini + 1] = max(include, exclude);
    }
    next = prev;
  }
  return prev[0];
}

int lengthOfLIS(vector<int> &nums) { return solveOpt(nums); }

int main() { return 0; }
