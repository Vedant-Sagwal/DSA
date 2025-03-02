#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    vector<vector<int> > ans;         
    int i = 0;
    int j = 0;
    while(i < nums1.size() && j < nums2.size()) {
        vector<int> temp(2, 0);
        //equal ids
        if (nums1[i][0] == nums2[j][0]) {
            temp[0] = nums1[i][0];
            temp[1] = nums1[i++][1] + nums2[j++][1];
       }
        //nums1 < nums2
        else if (nums1[i][0] < nums2[j][0]) {
            temp[0] = nums1[i][0];
            temp[1] = nums1[i++][1];
        }
        else {
            temp[0] = nums2[j][0];
            temp[1] = nums2[j++][1];

        }
        ans.push_back(temp);
    }
    while (i < nums1.size()) {
        vector<int> temp(2, 0);
        temp[0] = nums1[i][0];
        temp[1] = nums1[i++][1];
        ans.push_back(temp);
    }
    while (j < nums2.size()) {
        vector<int> temp(2, 0);
        temp[0] = nums2[j][0];
        temp[1] = nums2[j++][1];
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    return 0;
}
