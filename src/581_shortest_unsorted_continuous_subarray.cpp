#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

#include "utils/utils.h"

using namespace std;

class Solution {
public:
    bool checkIncrease(vector<int> &nums){
        for(auto i = nums.begin(), j = i+1; j != nums.end(); i++,j++){
            if (*i > *j){
                return false;
            }
        }
        return true;
    }
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (checkIncrease(nums)) return 0;
        
        int i = 0, j = nums.size()-1;

        for(; i < j; i++){
            if (nums[i] > nums[i+1]){
                break;
            }
        }
        
        for(; j >= i; j--){
            if (nums[j-1] > nums[j]){
                break;
            }
        }

        while(i > 0 && ((nums[i-1] == nums[i]) || nums[i-1] > *min_element(nums.begin()+i, nums.begin()+j+1))){
            i--;
        }
        
        while(j < nums.size()-1 && ((nums[j] == nums[j+1]) || *max_element(nums.begin()+i, nums.begin()+j+1) > nums[j+1])){
            j++;
        }

        if ((j - i) > 0){
            return j - i + 1;
        }
        else{
            return 0;
        }
    }
};

void printTest(Solution sol, vector<int> nums, int expect){
    int actual = sol.findUnsortedSubarray(nums);

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

    printTest(sol, {2,6,4,8,10,9,15}, 5);
    printTest(sol, {1,2,3,4}, 0);
    printTest(sol, {1}, 0);
    printTest(sol, {2,1}, 2);
    printTest(sol, {1,2,3,6,5,4,7,8,9,12,11,10,13,14,15}, 9);
    printTest(sol, {1,2,3,3,3}, 0);
    printTest(sol, {1,3,2,2,2}, 4);
    printTest(sol, {1,3,3,3,2}, 4);
    printTest(sol, {1,1,1,1}, 0);
    printTest(sol, {1,2,4,5,3}, 3);
    printTest(sol, {1,2,5,3,4}, 3);
}