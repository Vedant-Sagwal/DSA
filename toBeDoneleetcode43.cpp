#include <iostream>
using namespace std;
//
//to be completed.......

string multiply(string num1, string num2) {
    int n1 = num1.length();
    int n2 = num2.length();
    string ans = "";
    vector <int> sum;
    for (int i = n1 - 1; i >= 0; i--) {
        vector<
        int carry = 0;
        int nums1 = num1[i] - '0';
        for (int j = n2 - 1; j >= 0; j--) {
            int nums2 = num2[j] - '0'; 
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a1;
        string a2;
        cin >> a1 >> a2;
        cout << multiply(a1, a2) << endl;
    }
    return 0;
}
