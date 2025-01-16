#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//it returns a pair of no. of stars and leftmost coordinate
pair <int, int> skyWatcher(vector <int> &xCoordinates, int length) { 
    sort(xCoordinates.begin(), xCoordinates.end());
    int i = 0;
    int j = 0;
    int leftMost = xCoordinates[0];
    int currLeft = xCoordinates[0];
    int maxStars = 1;
    int currMax = 1;
    while (i < xCoordinates.size() && j < xCoordinates.size()) {
        if (i == j) {
            j++;
        }
        else if (abs(xCoordinates[j] - xCoordinates[i]) <= length) {
            currMax += 1; 
            j++;
        }
        else {
            if (currMax >= maxStars) {
                maxStars = currMax;
                leftMost = currLeft;
            }
            i++;
            currLeft = xCoordinates[i];
            currMax--;
            if (currMax == 0) {
                    currMax = 1;
            }
        } 
    }
    if (currMax >= maxStars) {
        maxStars = currMax;
        leftMost = currLeft;
    }

    return make_pair(maxStars, leftMost);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int length;
        cin >> length;
        vector <int> xCoordinates(n);
        for (int i = 0; i < n; i++) {
            cin >> xCoordinates[i];
        }
        pair<int, int> ans = skyWatcher(xCoordinates, length); 
        cout << ans.first <<"  " <<  ans.second << endl;
    }
    return 0;
}
