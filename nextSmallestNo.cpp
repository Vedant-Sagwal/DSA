#include <iostream>
using namespace std;

int no_of_ones(int num) {
    int count = 0;
    while (num != 0) {
        if ((num & 1) == 1) {
            count++ ;
        }
        num = num >> 1;
    }
    return count;
}

int bruteForce(int num) {
    int numOnes = no_of_ones(num);
    while (true) {
        num++;
        int numPOnes = no_of_ones(num);
        if (numPOnes == numOnes) {
            break;
        }
    }
    return num;
}

int nextSmallest(int num) {
    if (num == 0) {
        return 0;
    }
    int cpy = num;
    int count = 0;
    bool stop = false;
    int k = 0;
    while(cpy != 0) {
        int bit =  cpy & 1;
        if (bit == 1) {
            count++;
            stop = true;
            k++;
        }
        else {
            if (stop) {
                stop = false;
                break;
            }
            else {
                stop = false;
            }
            k++;
        }
        cpy = cpy >> 1;
    }
    //kth bit set
    num = num | (1 << k);
    //reset (k - 1)th bit
    num = num & ~(1 << (k - 1));
    int i = 0;
    while (i < (k - 1)) {
        num = num & ~(1 << i);
        i++;
    }
    int j = 0;
    while (j < (count - 1)) {
        num = num | (1 << j);
        j++;
    }
    return num;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int ans = nextSmallest(i);
            int brute = bruteForce(i);
            if (ans == brute) {
                cout << ans << endl;
            }
            else {
                cout << "-1111111111111111111111111111111" << endl;
            }
        }
    }
    return 0;
}
