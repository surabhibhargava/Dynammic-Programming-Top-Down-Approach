// https://leetcode.com/problems/house-robber/

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    // create a function f which returns the maximum amount of money that can be robbed.
    // let i denote the current house the robber is at and e denote the last house
    int f(int i, map<int, int> &hash, vector<int> nums){
        // robber starts at 0 and if all the houses have been covered, then the money he can rob is zero
        if(i>=nums.size()){
            return 0;
        }
        if(hash.find(i)==hash.end()){
            // at each house the robber has the option of robbing that house and moving to the house after the adjacent house or to leave that particular house and move to the next. We need to take the maximum of the amount from both the cases.
            int t=max(nums[i]+f(i+2,hash,nums),f(i+1,hash,nums));
            return hash[i]=t;
        }
        else return hash[i];
        
    }


    int rob(vector<int>& nums) {
        map<int, int> hash;
        return f(0,hash,nums);
    }
};