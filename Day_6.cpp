#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

class Solution {
    public:
    ll findShortest(vector<ll>& cities, vector<ll>& towers, int n, int m) {
        vector<ll>::iterator city = cities.begin();
        vector<ll>::iterator tower = towers.begin();
        ll result = 0;
        ll lowerDistance = LONG_LONG_MAX;
        ll distance;
        while(city < cities.end()) {
            while(*tower<=*city &&tower+1 != towers.end()) {
                distance = abs(*city - *tower);
                if(distance<lowerDistance) {
                    lowerDistance = distance;
                }
                if(tower+1!=towers.end())
                    tower++;
            }
            distance = abs(*city - *tower);
            if(distance<lowerDistance)
                lowerDistance = distance;
            if(result<lowerDistance)
                result = lowerDistance;
            city++;
            lowerDistance = LONG_LONG_MAX;
        }
        return result;
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<ll> cities(m);
    vector<ll> towers(n);
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