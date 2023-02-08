#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

class Solution {
    public:
    ll findShortest(vector<ll>& cities, vector<ll>& towers, int n, int m) {
        ll radius = 0;
        ll result = 0;
        ll distanceR=LONG_LONG_MAX;
        ll distanceL=LONG_LONG_MIN;
        ll tower = 0;
        for(ll city=0; city<n; city++) {
            while(towers[tower]<cities[city] && tower<m-1) {
                tower++;
            }
            distanceR = abs(towers[tower]-cities[city]);
            if(tower>0)
                distanceL = abs(towers[tower-1] - cities[city]);
            radius = (distanceL<0)?distanceR:(distanceR<distanceL)?distanceR:distanceL;
            result = (result<radius)?radius:result;
        }
        return result;
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<ll> cities(n);
    vector<ll> towers(m);
    for(int i=0; i<n; i++) {
        cin>>cities[i];
    }
    for(int i=0; i<m; i++) {
        cin>>towers[i];
    }
    Solution solution;
    cout<<solution.findShortest(cities,towers,n,m);
    return 0;
}