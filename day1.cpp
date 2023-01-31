#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
    vector<int> trees;
    int n;
    int m;
    public:
    Solution(vector<int> trees, int n, int m) {
        this->trees = trees;
        this->n = n;
        this->m = m;
    }

    long long findMinTrees() {
        //Answer
        long long upperHeight = *max_element(trees.begin(), trees.end());
        long long lowerHeight = 0;
        long long sum,result;
        for(long long mid=(upperHeight+lowerHeight)/2; upperHeight>=lowerHeight; mid=(upperHeight+lowerHeight)/2) {
            //Here, mid will act as the height we cut the trees at. Since iterating the height from 0 to maxHeight is TLE, we
            //use binary search tactic to minimize the total iterations.
            sum=0;
            for(int i=0; i<n; i++) {
                //Checking if the tree is taller than the cutting height
                if(trees[i]>mid) {
                    //Adding the length of trees cut
                    sum += trees[i] - mid;
                }
            }

            if(sum>=m) {
                result = mid; // Storing a "possible" answer since his requirements are met
                lowerHeight = mid+1; //Increasing the lower bound to see if we can possibly reduce extra length by further searching
            } else {
                //Required length was not met, hence we decrease the upper height bound to increase length of logs cut
                upperHeight = mid-1;
            }
        }
        return result;
    }
};

int main() {
    //Driver Code
    int n,m;
    vector<int> trees;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        trees.push_back(a);
    }

    Solution answer(trees, n, m);
    cout<<answer.findMinTrees();
    return 0;
}