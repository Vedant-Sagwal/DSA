#include <iostream>
#include <vector>
using namespace std;


void generateSpace(vector <char> &str, int i, int x1) {
    for (int j = i; j < 
}

vector<char> replacez(vector <char> str, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'z') {
            count++;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == 'z') {
            for (int j = i; j < n; j++) {
                int temp = str[j + 2];
                str[j + 2] = temp;
            }
            count--;     
        }
    }
}

int main() {
    return 0;
}
