//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int k = pat.length();
	    int i = 0, j = 0, sol = 0,count;
	    
	    map<char,int> freq;
	    for(int i = 0; i < k; ++i ) freq[pat[i]]++;
	    count = freq.size();
	   // cout<<count;
	    while( j < txt.length() )
	    {
	        if( freq.find(txt[j]) != freq.end() )
	           {
	               freq[txt[j]]--;
	               if(freq[txt[j]]==0) count--;
	           }
	        if( j - i + 1 < k )
	            ++j;
	       else if( j - i + 1 == k )
	       {
	           if( count == 0 )
	           {
	               sol++;
	           }
	           if( freq.find(txt[i]) != freq.end() )
	           {
	               if(freq[txt[i]] == 0) count++;
	               freq[txt[i]]++;
	           }
	           ++i;++j;
	       }
	    }
	    return sol;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends