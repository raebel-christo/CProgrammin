class Solution {
public:
    int recurssive(int k, int n, vector<vector<int>>& dp) {
        //Base cases
        if(n<=1) return n;
        if(k==1) return n;
        
        //If value is already calculated, we return it
        if(dp[k][n]!=-1) return dp[k][n];

        
        int ans = 1e6;
        /*
        for(int i=1; i<=n; i++) {
            int temp = 1+max(recurssive(k-1, i-1, dp), recurssive(k, n-i, dp));
            ans = min(ans, temp);
        }
        */

        int l=1, u=n, temp=0, mid;
        while(l<=u) {
            //Biary search is used instead of the above commented linear search to zero in on the correct answer faster.
            mid = l + (u-l)/2;

            //If egg is broken, reduce number of eggs by 1 and move down a floor and recompute
            int left = recurssive(k-1, mid-1, dp);

            //If egg is not brokem, number of eggs remain same and we move up a floor
            int right = recurssive(k,n-mid,dp);

            //We keep adding up the number of moves and look for the maximum of them.
            temp = 1 + max(left,right);

            if(left<right) {
                l = mid+1;
            } else {
                u = mid-1;
            }

            //The minimum of the two number of mmoves is selected.
            ans = min(temp,ans);
        }

        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return recurssive(k,n, dp);
    }
};