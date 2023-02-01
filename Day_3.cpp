#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

//Solution
class Solution {
    public:
    void solution(vector<ll> arr, int n) {
        //We make a copy of the given array
        vector<ll> nums = arr;
        //One of the array is sorted into ascending order
        sort(arr.begin(), arr.end());
        //We compare each element of the copy array with the sorted array to see if there is a possible element
        //that can be swaped.
        for(int i=0; i<n; i++) {
            //If any of the swappable elements exist, we check if the element requiring the swap is divisible by the minimum element
            //so that we can see if it had any gcd in the given array.
            if(arr[i]!=nums[i] && nums[i]%arr[0]!=0) {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
        return;
    }
};

int main() {
    //Driver Code
    int n,t;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        Solution solution;
        solution.solution(arr, n);
    }
    return 0;
}