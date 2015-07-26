#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
#include<cmath>
using namespace std;
class FallingSand {
    
public:
    char** brd;
    int row_siz;
    int col_siz;
    vector<string> simulate(vector<string> board) {
        row_siz = (int) board.size();
        brd = new char*[row_siz];
        col_siz = (int) board.at(0).length();
        for(int i=0;i<row_siz;i++) {
            string s = board.at(i);
            brd[i] = new char[col_siz];
            for(int j = 0; j<s.size();j++) {
                brd[i][j] = s.at(j) == 'x' ? 'x' : '.';
            }
        }
        
        for(int i=col_siz-1;i>=0;i--) {
            for(int j = row_siz-1;j>=0;j--) {
                if(board.at(j).at(i) == 'o') {
                    brd[count(j,i, board)][i] = 'o';
                }
            }
        }

        vector<string>ans;
        for(int i = 0;i<row_siz;i++) {
            ans.push_back(brd[i]);
        }
        return ans;
    }
    
    int count(int row, int col, vector<string>board) {
        int bottom = row_siz - 1;
        int a = 0;
        for(int i=row+1;i<=bottom;i++) {
            if(board.at(i).at(col) == 'x') {
                return i-1 - a;
            }
            if(board.at(i).at(col) == 'o') {
                a++;
            }
        }
        return bottom - a;
    }
};