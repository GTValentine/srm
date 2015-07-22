#include <iostream>
#include <vector>

class ExactTreeEasy {
public:
    std::vector<int> getTree(int n, int m) {
        int lng = (n-1)-(m-2);
        std::vector<int> rtn = std::vector<int>();
        for(int i = 0;i<lng;i++) {
            rtn.push_back(i);
            rtn.push_back(i+1);
        }
        for(int i = lng + 1;i<=(n-1);i++) {
            rtn.push_back(0);
            rtn.push_back(i);
        }
        
        
        return rtn;
    }
};