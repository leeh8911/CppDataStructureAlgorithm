#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        s = backspacedString(s);
        t = backspacedString(t);

        return s == t;
    }
    string backspacedString(string s){
        
        for(int i = 0; i < s.size();){
            if (s[i] == '#'){
                if (i == 0){
                    s.erase(0, 1);
                }
                else{
                    s.erase(i-1,2);
                    i--;
                }
            }
            else{
                i++;
            }
        }
        return s;
    }
};

void printTest(Solution sol, string s, string t, bool expect){
    bool actual = sol.backspaceCompare(s, t);
    if (actual == expect){
        cout << "\033[32m" << "[PASS] " << "\033[0m" << s << ", " << t << "\n";
    }
    else{
        cout << "\033[31m" << "[FAIL] " << "\033[0m" << s << ", " << t << "\n";
        cout << "EXPECT : " << expect << "\n";
        cout << "ACTUAL : " << actual << "\n";
    }

}

int main(void){
    Solution sol;

    printTest(sol, "ab#c", "ad#c", true);
    printTest(sol, "ab##", "c#d#", true);
    printTest(sol, "a#c", "b", false);
    printTest(sol, "#", "#", true);
    printTest(sol, "#a", "#c", false);
}