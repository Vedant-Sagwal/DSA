#include <iostream>
#include <vector>
#include <queue>
#include <dequeue>
using namespace std;

priority_queue<int, vector <int> >  removeElement(priority_queue<int, vector <int> > pq1, int num ) {
    priority_queue<int, vector <int> > ans;
    bool done = false;
    while (!pq1.empty()) {
        int temp = pq1.top();
        pq1.pop(); 
        if (temp == num) {
            if (done == false) {
                done = true;
                continue;
            }
            done = true;
        }
        ans.push(temp);
    }
    return ans;
}


vector <int> maxSlidingWindowBRUTE(vector <int> &nums, int k) {
    vector <int> ans;
    priority_queue<int, vector <int> > pq1; 
    for (int i = 0; i < k; i++) {
        pq1.push(nums[i]);
    }
    ans.push_back(pq1.top());
    for (int i = k; i < nums.size(); i++) {
        int index = i - k; 
        pq1 = removeElement(pq1, nums[index]);
        pq1.push(nums[i]);
        ans.push_back(pq1.top());
    }
    return ans;
}


vector <int> maxSlidingWindow(vector <int> &nums, int k) {
    vector <int> ans;
    deque<int> dq1;    
    for (int i = 0; i < k; i++) {
        if (dq1.empty()) {
            dq1.push_back(i);
        }
        else {
            while (!dq1.empty() && nums[dq1.back()] < nums[i]) {
                dq1.pop_back();
            }
            dq1.push_back(i);
        }
    }
    ans.push_back(nums[dq1.front()]);
    for (int i = k; i < nums.size(); i++) {
        if (dq1.empty()) {
            dq1.push_back(i);
        }  
        else {
            if (i - k >= dq1.front()) {
                dq1.pop_front();
            }
            while (!dq1.empty() && nums[dq1.back()] < nums[i]) {
                dq1.pop_back();
            }
            dq1.push_back(i);
        }
        ans.push_back(nums[dq1.front()]);
    }
    return ans;
}

int main() {
    return 0;
}
