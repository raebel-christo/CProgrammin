#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //Storing total size
        int n  = height.size();

        //Vectors to store the max left and max right element for each column
        vector<int> maxLeft(n);
        vector<int> maxRight(n);

        //Computing maximum left and maximum right for the i-th column
        for(int i=1; i<n; i++) {
            maxLeft[i] = max(height[i-1], maxLeft[i-1]);
        }
        for(int i=n-2; i>=0; i--) {
            maxRight[i] = max(height[i+1], maxRight[i+1]);
        }

        //Computing water trapped
        int waterlevel;
        int sum = 0;
        for(int i=0; i<n; i++) {
            waterlevel = min(maxLeft[i], maxRight[i]);
            sum = sum + ((waterlevel>=height[i])?(waterlevel - height[i] ): 0);
        }

        return sum;
    }
};

int main() {
    Solution solution;
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0; i<n; i++) {
        cin>>height[i];
    }
    cout<<solution.trap(height);
}
//0 1 0 2 1 0 1 3 2 1 2 1
//4 2 0 3 2 5