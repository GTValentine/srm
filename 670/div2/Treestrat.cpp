#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstddef>
using namespace std;
class Treestrat {
public:
    static const int N_MAX = 50;
    int distance[N_MAX][N_MAX] = {};
    int INF = 1000;
    int vertices = 0;
    int roundcnt(vector<int> tree, vector<int> A, vector<int> B) {
        vertices= (int) tree.size()+1;
        for(int i = 0; i < N_MAX;i++) {
            for(int j = 0; j< N_MAX;j++) {
                distance[i][j] = INF;
            }
            distance[i][i] = 0;
        }
        for(int i=0;i<tree.size();i++) {
            distance[i+1][tree[i]] = distance[tree[i]][i+1] = 1;
        }
        warshall_floyd();
        
        for(int i = 0;i < vertices;i++) {
            bool mat[N_MAX] = {};
            // init
            for(int j=0; j<vertices;j++) {
                mat[j] = false;
            }
            for(int j =0; j<B.size();j++) {
                for(int k =0;k<vertices;k++) {
                    if(distance[B[j]][k] <= i) {
                        mat[k] = true;
                    }
                }
            }
            
            for(int j=0;j<A.size();j++) {
                bool safe = false;
                for(int k=0;k<vertices;k++) {
                    if(distance[A[j]][k] > i) {
                        continue;
                    }
                    if(!mat[k]) {
                        safe = true;
                    }
                }
                if(!safe) {
                    return i;
                }
            }
            
        }
        return 0;
    }
private:
    void warshall_floyd() {
        for(int k = 0; k < vertices;k++) {
            for(int i=0; i < vertices;i++) {
                for(int j = 0; j < vertices;j++) {
                    distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
                }
            }
        }
    }
};