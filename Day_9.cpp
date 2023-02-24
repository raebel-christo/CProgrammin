#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
class Solution {
    public:
    int solve(vector<int> xCost, vector<int> yCost, int m, int n) {
        //Sum
        int sum=0;
        //Edge/Base cases where only a single row or column exists
        while(m==1 && n>1) {
            sum += yCost[(n--)-2];
            if(n==1)
                return sum;
        }
        while(n==1 & m>1) {
            sum += xCost[(m--)-2];
            if(m==1)
                return sum;
        }
        //Iterators for max elements in both vectors
        auto xMax = max_element(xCost.begin(), xCost.end());
        auto yMax = max_element(yCost.begin(), yCost.end());

        //Comparing the values and cutting the chocolate along the costlier line and breakin the process into sub parts
        //recursively
        if(*xMax<*yMax) {
            vector<int> yCostL(yCost.begin(),yMax);
            vector<int> yCostR(yMax+1, yCost.end());
            sum += *yMax + solve(xCost, yCostL, m, yCostL.size()+1) + solve(xCost, yCostR, m, yCostR.size()+1);
        } else {
            vector<int> xCostL(xCost.begin(), xMax);
            vector<int> xCostR(xMax+1, xCost.end());
            sum += *xMax + solve(xCostL, yCost, xCostL.size()+1, n) + solve(xCostR, yCost, xCostR.size() + 1, n);
        }
        return sum;
    }
};
 
int main() {
 
    int t;
    cin>>t;
    Solution solution;
    while(t--) {
        int m,n;
        cin>>m>>n;
        vector<int> xCost(m-1);
        vector<int> yCost(n-1);
 
        for(int i=0; i<m-1; i++) {
            cin>>xCost[i];
        }
        for(int j=0; j<n-1; j++) {
            cin>>yCost[j];
        }
 
        cout<<solution.solve(xCost,yCost,m,n)<<endl;
    }
    return 0;
}
