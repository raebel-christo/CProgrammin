#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin>>t;

    while(t--) {
        int n,m;
        cin>>n>>m;
        pair<int,int> A,B;
        cin>>A.first>>A.second>>B.first>>B.second;
        int obstacles1=0,obstacles2=0;
        if(A.first-1>=1) obstacles1++;
        if(A.first+1<=n) obstacles1++;
        if(A.second-1>=1) obstacles1++;
        if(A.second+1<=m) obstacles1++;

        if(obstacles1==2) {
            cout<<obstacles1<<endl;
            continue;
        }

        if(B.first-1>=1) obstacles2++;
        if(B.first+1<=n) obstacles2++;
        if(B.second-1>=1) obstacles2++;
        if(B.second+1<=m) obstacles2++;

        cout<<min(obstacles1,obstacles2)<<endl;
    }

    return 0;
}