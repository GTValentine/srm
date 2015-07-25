#include <iostream>
#include <vector>
#include <map>
#include<algorithm>

class ABBA {
    
public:
    std::string canObtain(std::string initial, std::string target) {
        if(possible(initial, target)) {
            return std::string("Possible");
        }
        return std::string("Impossible");
    }
    
    bool possible(std::string mid, std::string target) {
        if(target.compare(mid)==0) {
            return true;
        }
        std::string str = std::string(mid);
        std::string rev = std::string(mid);
        std::reverse(rev.begin(),rev.end());
        
        if (target.find(str) == std::string::npos && target.find(mid) == std::string::npos) {
            return false;
        }
        
        return possible(str.append("A"), target) || possible(rev.append("B"), target);
        
    }
    
};