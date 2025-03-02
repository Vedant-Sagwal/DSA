#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector <vector <int> > num_matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        vector <vector <int> > two_d_array(matrix.size(), vector <int> (matrix[0].size(), 0));
        //Base Case
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    two_d_array[i][j] = matrix[i][j] + two_d_array[i - 1][j] + two_d_array[i][j - 1] - two_d_array[i - 1][j - 1];
                }
                else if (j - 1 < 0 && i - 1 >= 0) {
                    two_d_array[i][j] = matrix[i][j] + two_d_array[i - 1][j] + 0 - 0;
                }
                else if (i - 1 < 0 && j - 1 >= 0) {
                    two_d_array[i][j] = matrix[i][j] + 0 + two_d_array[i][j - 1] - 0;
                }
                else {
                    two_d_array[i][j] = matrix[i][j] + 0;
                }
            }
        } 
        num_matrix = two_d_array;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 - 1 >= 0 && col1 - 1 >= 0) {
            return num_matrix[row2][col2] + num_matrix[row1 - 1][col1 - 1] - num_matrix[row1 - 1][col2] - num_matrix[row2][col1 - 1];
        }        
        else if (row1 - 1 < 0 && col1 - 1 >= 0) {
            return num_matrix[row2][col2] + num_matrix[row2][col1 - 1];
        }
        else if (col1 - 1 < 0 && row1 - 1 >= 0) {
            return num_matrix[row2][col2] + num_matrix[row1 - 1][col2] ;
        }
        else {
            return num_matrix[row2][col2] ;
        }
    }
};

int main() {
    return 0;
}
