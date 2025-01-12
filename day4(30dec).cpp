#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isSafe(vector <vector <char > > &board, int i, int j) {
    for(int a = 0; a < 9; a++) {
        if (i != a && board[i][a] == board[i][j]) {
            return false;
        }
        if (j != a && board[a][j] == board[i][j]) {
            return false;
        }
        int row = (3 * (i / 3)) + a / 3;
        int col = (3 * (j / 3)) + a % 3;
        if (!(row == i && col == j)&& board[row][col] == board[i][j]) {
            return false;
        }
    } 
    return true;
}

bool isValidSudoku(vector< vector<char> > &board){
        
   for (int i = 0; i < 9; i++) {
       for (int j = 0; j < 9; j++) {
           if (board[i][j] != '.') {
                if (!isSafe(board, i, j)) {
                    return false;
                }
           } 
       }
   }
   return true;
}

int main() {
    return 0;    
}
