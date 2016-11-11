//
//  main.cpp
//  Maximum Sum Subsequence Non-Adjacent DP
//
//  Created by Zijian Xie on 2016/11/11.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//  Given an array of positive number, find maximum sum subsequence such that elements in this subsequence are not adjacent to each other.
// This question is the same as leetcode "Rober" question.

// Time: O(n), Space: O(1)
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class maxSumNonAdj{
private:
    vector<int> nums;
public:
    maxSumNonAdj(vector<int>& nums){
        this->nums = nums;
    }
    
    int DP(){
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int pre1 = nums[0];
        int pre2 = max(nums[0], nums[1]);
        for(int i = 2; i < (int)nums.size(); ++i){
            int res = max(pre1 + nums[i], pre2);
            pre1 = pre2;
            pre2 = res;
        }
        cout<<"The maximum sum is: " <<pre2 <<endl;
        return pre2;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {4,1,1,4,2,1};
    maxSumNonAdj* test = new maxSumNonAdj(nums);
    test->DP();
    return 0;
}
