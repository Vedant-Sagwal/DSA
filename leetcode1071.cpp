#include <iostream>
using namespace std;
//
//string gcdOfStrings(string str1, string str2) {
//    int n1 = str1.length();
//    int n2 = str2.length();
//    int i = 0;
//    int j = 0;
//    int a = 0;
//    string temp = "";
//    string temp1 = "";
//    while (i < n1 && j < n2) {
//        if (str1[i] != str2[j]) {
//            return "";
//        }
//        else {
//            if (temp.length() == 0) {
//                temp.push_back(str1[i]);
//            }
//            else if (temp[a] == str1[i]) {
//                temp1.push_back(str1[i]); 
//                a++;
//            }
//            else {
//                if (temp1.length() != 0) {
//                    temp.push_back(str1[i]);
//                }
//                temp.push_back(str1[i]);
//            }
//        }
//        i++;
//        j++;
//    }
//    int k1 = 0;
//    int k2 = 0;
//    while (i < n1) {
//        if (str1[i] != temp[k1]) {
//            return "";
//        }
//        i++;
//        k1++;
//    }
//    while (j < n2) {
//        if (str2[j] != temp[k2]) {
//            cout << "temp" << temp << endl;
//            return "";
//        }
//        j++;
//        k2++;
//    }
//    return temp;
//}

int gcdEucledian(int a, int b) {
    //Base Case
    if (a == 0) {
        return b;
    }
    return gcdEucledian(b % a, a);
}

int gcd(int a, int b) {
    if (a > b) {
        return gcdEucledian(b, a);
    }
    else {
        return gcdEucledian(a, b);
    }
}

string gcdOfStrings(string str1, string str2) {
    string str1P2 = str1 + str2;
    string str2P1 = str2 + str1;
    int length1;
    int n1 = str1.length();
    int n2 = str2.length();
    if (str1P2 == str2P1) {
        length1 = gcd(n1, n2);
        return str1.substr(0, length1);
    }
    else {
        return "";
    }
}

int main() {
    return 0;
}
