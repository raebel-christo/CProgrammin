#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int max=0,min=0,left=0,right=0;
        set<int> maxvals;
        /*
        Check subarray validity
        If valid: move right until invalid
        if invalid, move left until valid.
        if right reaches end of array, check validity
        if invalid, move left until valid

        */

        while(right<nums.size()) {
            if(nums[right]<=nums[min])
                min = right;
            else if(nums[right]>=nums[max])
                max = right;
            if(abs(nums[max] - nums[min]) <= limit) {
                maxvals.insert(right-left+1);
                right++;
                continue;
            }
            left++;
            if(max<left) {
                //find new max
                max = max_element(nums.begin()+left,nums.begin()+right+1) - nums.begin();
            }
            else if(min<left) {
                //find new min
                min = min_element(nums.begin()+left,nums.begin()+right+1) - nums.begin();
            }
        }
        right-=1;
        while(abs(nums[max]-nums[min]) > limit) {
            left++;
            if(max<left) {
                //find new max
                max = max_element(nums.begin()+left,nums.begin()+right+1) - nums.begin();
            }
            else if(min<left) {
                //find new min
                min = min_element(nums.begin()+left,nums.begin()+right+1) - nums.begin();
            }
        }
        return (*maxvals.rbegin());
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    int limit;
    cin>>limit;
    Solution solution;
    cout<<solution.longestSubarray(nums,limit);
    return 0;
}