//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Answer
class Solution
{
	public:
	    
		vector<string>find_permutation(string S)
		{
            //We create a set so that the elements are unique and the elements stored are automatically stored in a sorted manner.
		    set<string> result;
		    recurssive_permutation(result,S,0,S.size()-1);
		    vector<string> output(result.begin(),result.end());
		    return output;
		    
		}
		
		void recurssive_permutation(set<string>& result, string s, int start, int end) {

            //Base case where start and end indices are equal. This happens in the case where all previous characters have been locked and this is the last recurssive call
            //after having swapped under possibilities in that respective branch of calls.
            if (start == end) {
                result.insert(s);
                return;
            }
            
            for(int i=start; i<=end; i++) {
                //We swap the characters
                swap(s[start], s[i]);

                // We call the function recurssively by locking the starting character by passing the start index ahead of current index.
                //This will happen until start==end. 
                recurssive_permutation(result,s,start+1, end);

                //We backtrack to the permutation, and move i forward for a new permutation.
                swap(s[start],s[i]);
            }
            
            return;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends