#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &nums, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && nums[left] > nums[largest]) {
        largest = left;
    }
    if (right < size && nums[right] > nums[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(nums[i], nums[largest]);
        heapify(nums, size, largest);
    }
}

void buildHeap(vector<int> &nums) {
    for (int i = (nums.size()) / 2; i >= 0; i--) {
        heapify(nums, nums.size(), i); 
    } 
}

void heapSort(vector<int> &nums) {
    buildHeap(nums);
    int size = nums.size();
    for (int i = size - 1; i >= 0;i--) {
        swap(nums[0], nums[i]); 
        heapify(nums, i, 0);
    }
}

vector<int> sortArray(vector<int>& nums) {
    heapSort(nums);    
    return nums;
}

int main() {
    return 0;
}
