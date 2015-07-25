#include <iostream>
#include <vector>
#include <map>
#include <limits>
class ChessFloor {
    
public:
    int minimumChanges(std::vector<std::string> floor) {
        using namespace std;
        map<char, int> cacheA;
        map<char, int> cacheB;
        
        int fsiz= (int) floor.size();
        for(int i=0;i<fsiz;i++) {
            std::string line = floor.at(i);
            int a = (int) line.length();
            for(int j =0;j<a;j++) {
                char c = line.at(j);
                if(!cacheA.count(c)) {
                    cacheA.insert(map<char, int>::value_type(c, solveA(c, floor)));
                }
                if(!cacheB.count(c)) {
                    cacheB.insert(map<char,int>::value_type(c,solveB(c,floor)));
                }
            }
            
        }
        if(cacheA.size() == 1) {
            return (int) (floor.size() * floor.size())/2;
        }
        //
        char fstCA='\0', sndCA;
        int fstIA = std::numeric_limits<int>::max();
        int sndIA= std::numeric_limits<int>::max();
        char fstCB='\0', sndCB;
        int fstIB= numeric_limits<int>::max(), sndIB= numeric_limits<int>::max();
        for(auto itr = cacheA.begin(); itr != cacheA.end(); ++itr) {
            if(fstIA > itr->second) {
                sndIA = fstIA;
                sndCA = fstCA;
                fstIA = itr->second;
                fstCA = itr->first;
                continue;
            }
            if(sndIA > itr->second) {
                sndIA = itr->second;
                sndCA = itr->first;
            }
        }
        for(auto itr = cacheB.begin(); itr != cacheB.end(); ++itr) {
            if(fstIB > itr->second) {
                sndIB = fstIB;
                sndCB = fstCB;
                fstIB = itr->second;
                fstCB = itr->first;
                continue;
            }
            if(sndIB > itr->second) {
                sndIB = itr->second;
                sndCB = itr->first;
            }
        }
        if(fstCA == fstCB) {
            if(sndIA > sndIB) {
                return fstIA + sndIB;
            }
            return fstIB + sndIA;
        }
        return fstIA + fstIB;
    }
    
    int solveA(char c, std::vector<std::string> floor) {
        int count = 0;
        int fsiz = (int) floor.size();
        for(int i=0;i<fsiz;i++) {
            std::string line = floor.at(i);
            int a =(int ) line.length();
            if(i % 2 == 0) {
                
                for(int j =0;j<a;j=j+2) {
                    if(c == line.at(j)) {
                        continue;
                    }
                    count++;
                }
            } else {
                for(int j =1;j<a;j=j+2) {
                    if(c == line.at(j)) {
                        continue;
                    }
                    count++;
                }
            }
            
        }
        return count;
    }
    int solveB(char c, std::vector<std::string> floor) {
        int count = 0;
        int fsiz = (int) floor.size();
        for(int i=0;i<fsiz;i++) {
            std::string line = floor.at(i);
            int a = (int) line.length();
            if(i % 2 == 0) {
                for(int j =1;j<a;j=j+2) {
                    if(c == line.at(j)) {
                        continue;
                    }
                    count++;
                }
            } else {
                for(int j =0;j<a;j=j+2) {
                    if(c == line.at(j)) {
                        continue;
                    }
                    count++;
                }
            }
            
        }
        return count;
    }
    
};

