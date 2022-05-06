#include <iostream>
#include <string>

#include "utils/utils.h"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        if (s.size() < k) return s;
        auto it = s.begin();
        auto jt = it;

        while(it != s.end()){
            int count = 1;
            bool erased = false;
            for(jt = it; jt != (s.end()-1); jt++){
                if (*jt == *(jt+1)){
                    count++;
                }
                else{
                    break;
                }

                if (count == k){
                    s.erase(it, jt+2);
                    erased=true;
                    break;
                }
            }

            if (!erased){
                it = jt + 1;
            }
            else{
                for(;it != s.begin(); it--){
                    if(*it != *(it-1)){
                        break;
                    }
                }
            }
        }

        return s;
    }
};

void printTest(Solution sol, string s, int k, string expect){
    string actual = sol.removeDuplicates(s, k);

    if (actual == expect){
        cout << "\033[32m" << "[PASS] " << "\033[0m" << s << ", " << k << "\n";
    }
    else{
        cout << "\033[31m" << "[FAIL] " << "\033[0m" << s << ", " << k << "\n";
        cout << "EXPECT : " << expect << "\n";
        cout << "ACTUAL : " << actual << "\n";
    }
}

int main(void){
    Solution sol;

    printTest(sol, "abcd", 2, "abcd");
    printTest(sol, "deeedbbcccbdaa", 3, "aa");
    printTest(sol, "pbbcggttciiippooaais", 2, "ps");
    printTest(sol, "aaaa", 3, "a");
    printTest(sol, "aabbccddeegggedcbaa", 3, "a");
    printTest(sol, "a", 3, "a");
    printTest(sol, "nnwssswwnvbnnnbbqhhbbbhmmmlllm", 3, "vqm");
    
    return 0;
}