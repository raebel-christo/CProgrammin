class Solution {
public:
    string shortestPalindrome(string s) {
        //We will use KMP, hence first we will generate a pattern string.
        //We need a reverse string concatenated with the original string separated by a token
        //so that the lps array will become 0 and the start of the reverse string
        string revs = s;
        reverse(revs.begin(),revs.end());
        string patt = s + '$' + revs;
        vector<int> lps(patt.size(), 0);
        int i,j;
        int n = patt.size();
        //Generating the lps array using KMP algorithm
        for(i=1,j=0; i<n; ) {
            if(patt[i]==patt[j]) {
                lps[i++] = ++j;
            } else if (j>0) {
                j = lps[j-1];
            } else {
                ++i;
            }
        }

        //Debugging code, please ignore
        /*
        for (auto x:lps) {
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<n-lps[n-1];*/

        //we return the reversed part of the pattern string while removing parts of it which already match in the original string.
        return patt.substr(s.size()+1, (s.size() - lps[n-1])) + s;
    }
};