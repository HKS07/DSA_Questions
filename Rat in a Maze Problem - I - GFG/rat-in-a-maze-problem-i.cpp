//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void help( int i, int j, vector<vector<int>> &m, int n, vector<string> &sol, string &s, vector<vector<int>> vis )
    {
        if( i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0)
        return;
        if( i == n-1 && j == n-1 ) 
        {
            sol.push_back(s);
            return;
        }
        if( vis[i][j] != -1 ) return;
        vis[i][j] = 1;
        //left
        string l = s + 'L';
        help(i,j-1,m,n,sol,l, vis);
        //right
        string r = s + 'R';
        help(i,j+1,m,n,sol,r,vis);
        //up
        string u = s + 'U';
        help(i-1,j,m,n,sol,u,vis);
        //down
        string d = s + 'D';
        help(i+1,j,m,n,sol,d,vis);
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
     vector<string> sol;
     vector<vector<int>> vis(n,vector<int> (n,-1));
     string s = "";
     help(0,0,m,n,sol,s, vis);
     return sol;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends