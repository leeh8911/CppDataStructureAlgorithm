#include <iostream>
#include <string>
#include <vector>

#include "utils/utils.h"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        if (s.size() < k) return s;
        vector<pair<int, char>> buffer;
        buffer.emplace_back(make_pair(0, '!'));

        for(auto it = s.begin(); it != s.end(); it++){
            if(buffer.back().second == *it){
                buffer.back().first++;
                if (buffer.back().first == k){
                    buffer.pop_back();
                }
            }
            else{
                buffer.emplace_back(make_pair(1, *it));
            }
        }

        string result = "";
        for(const auto& p : buffer){
            result.append(p.first, p.second);
        }

        return result;
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