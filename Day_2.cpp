#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    long n;
    vector<long> sticks;
    public:
    Solution(vector<long> &lengths, long &total) {
        this->sticks = lengths;
        this->n = total;
    }

    long calculate() {
        //Declarations
        long sum;
        long length;
        sort(sticks.begin(), sticks.end());
        //Checking if the array length is even or odd
        if(n%2==0) {
            //If array is even, we will take the average of middle two elements
            length = (sticks[n/2] + sticks[n/2 - 1])/2;
        } else length = sticks[n/2]; //If array is odd, we are taking the middle element as the lenght to be subtracted
        /*
        The above method was done so that since naturally, increasing the length by 0 at median and then matching other sticks to the
        length of the median stick would be the cheapest. Naturally, the longer the stick, higher the expense, but more the sticks closer to the
        lenght of the median stick, it is cheaper.
        */
        sum = 0;
        for(long i=0; i<n; i++) {
            sum += abs(sticks[i] - length);
        }
        return sum;
    }
};

int main() {
    //Driver Code
    long n;
    vector<long>sticks;
    cin>>n;
    for(long i=0; i<n; i++) {
        long x;
        cin>>x;
        sticks.push_back(x);
    }

    Solution solution(sticks, n);
    cout<<solution.calculate();
    return 0;
}