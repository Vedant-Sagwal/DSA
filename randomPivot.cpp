#include <iostream>
using namespace std;

vector <int> solve(vector <int> &nums) {
    int n = nums.size();
    int pivot = nums[n - 1];
    cout << "pivot : " << pivot << endl;
    int i = -1;
    int j = 0; 
    for (j = 0; j < n - 1; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        } 
    }
    i++;
    swap(nums[i], nums[n - 1]);
    return nums;
}


vector<int> pivotArray(vector<int>& nums, int pivot) {
    int index = 0;
    for (int i = 0 ; i < nums.size(); i++) {
        if (nums[i] == pivot) {
            index = i;
            break;
        }
    }
    swap(nums[nums.size() - 1], nums[index]);
    return solve(nums);

}


int main() {
    return 0;
}
