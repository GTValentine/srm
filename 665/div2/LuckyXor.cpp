#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class LuckyXor {
    int MAX_B = 100;
public:
    int construct(int a) {
      if(a == 100) {
          return -1;
      }

      for(int b=a+1;b<=MAX_B;b++) {
          int exclsv = a ^ b;
          string str = to_string(exclsv);
        
          bool hoge = true;
          for(int i = 0;i< str.size();i++) {
              if(str[i] != '7' && str[i] != '4') {
                  hoge = false;
                  break;
              }
          }
          if(hoge) {
              return b;
          }
      }
      return -1;
    }
};
