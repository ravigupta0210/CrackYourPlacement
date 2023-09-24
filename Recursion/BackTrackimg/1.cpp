//Permutations of a given string


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void solve(string &s,set<string> &ans,int index){
	    if(index == s.length()) {
	        ans.insert(s);
	        return ;
	    }
	   
	    for(int j=index;j<s.length();j++){
	        swap(s[index],s[j]);
	        solve(s,ans,index+1);
	        swap(s[index],s[j]);
	        
	    }
	}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> ans;
		    solve(S,ans,0);
		    vector<string> result;
		    result.assign(ans.begin(),ans.end());
		    return result;
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
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
