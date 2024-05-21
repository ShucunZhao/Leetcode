#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        *   target = 5
            [[1, 4, 7, 11,15],
             [2, 5, 8, 12,19],
             [3, 6, 9, 16,22],
             [10,13,14,17,24],
             [18,21,23,26,30]]
             ans: true
             If we look at the right-up corner, its a binary-search-tree
             So we can start with right-up corner.
             Its not really a binary search question, just only BST.

        */
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0, j = n - 1; i < m && j >= 0;) {
            if (matrix[i][j] > target) {
                j--;
            }
            else if (matrix[i][j] < target) {
                i++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the matrix: " << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        cout << "Enter the target: " << endl;
        string T;
        getline(cin, T);
        if (T == "q") break;
        In = In.substr(2, In.size() - 4);
        size_t pos;
        vector<vector<int> > matrix;
        while((pos=In.find("],["))!=string::npos){
            string token = In.substr(0, pos);
            In = In.substr(pos + 3);
            stringstream ss(token);
            string token2;
            vector<int> tmp;
            while (getline(ss, token2, ',')) {
                size_t l = token2.find_first_not_of(" ");
                size_t r = token2.find_last_not_of(" ");
                tmp.push_back(stoi(token2));
            }
            matrix.push_back(tmp);
        }
        stringstream ss(In);
        string token2;
        vector<int> tmp;
        while (getline(ss, token2, ',')) {
            size_t l = token2.find_first_not_of(" ");
            size_t r = token2.find_last_not_of(" ");
            tmp.push_back(stoi(token2));
        }
        matrix.push_back(tmp);
        int target = stoi(T);
        cout << "Res: " << S1.searchMatrix(matrix, target) << endl;
    }
}