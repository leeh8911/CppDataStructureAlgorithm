#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){return (a % 2) < (b%2);});
        
        return nums;
    }
};

ostream& operator<<(ostream& os, vector<int> v){
    os << "[";
    for(auto elm : v){
        os << elm << " ";
    }
    os << "]";
    return os;
}
bool operator==(vector<int> a, vector<int> b){
    if (a.size() == b.size()){
        for(int i = 0; i < a.size(); i++){
            if (a[i] != b[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

void printTest(Solution sol, vector<int> nums, vector<int> expect){
    
    vector<int> actual = sol.sortArrayByParity(nums);
    if (actual == expect){
        cout << "\033[32m" << "[PASS] " << "\033[0m" << nums << "\n";
    }
    else{
        cout << "\033[31m" << "[FAIL] " << "\033[0m" << nums << "\n";
        cout << "EXPECT : " << expect << "\n";
        cout << "ACTUAL : " << actual << "\n";
    }
}

int main(void){
    Solution sol;

    printTest(sol, {3,1,2,4}, {2,4,3,1});
    printTest(sol, {0}, {0});

    return 0;
}