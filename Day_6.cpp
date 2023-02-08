#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

class Solution {
    public:
    ll findShortest(vector<ll>& cities, vector<ll>& towers, int n, int m) {
        // Declaring variables
        ll radius = 0;
        ll result = 0;
        ll distanceR=LONG_LONG_MAX;
        ll distanceL=LONG_LONG_MIN;
        ll tower = 0;
        //Checking distances for each city
        for(ll city=0; city<n; city++) {
            //We keep going to the next tower until it is to the right or on the city
            while(towers[tower]<cities[city] && tower<m-1) {
                tower++;
            }
            //Checking distance of right tower
            distanceR = abs(towers[tower]-cities[city]);
            //Checking distance of left tower (Corner case considered)
            if(tower>0)
                distanceL = abs(towers[tower-1] - cities[city]);

            //Setting minumum required radius of the cellphone tower so that at least 1 tower covers the current city
            radius = (distanceL<0)?distanceR:(distanceR<distanceL)?distanceR:distanceL;

            //Setting overall required radius ensuring that all possible cities are covered. Since this is the bare minimum range required for all cities
            //to have atleast one tower, this value is essentially the maximum value in out of the minimum ranges per city.
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