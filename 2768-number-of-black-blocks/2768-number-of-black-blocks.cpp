class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& c) {
        map<long long,int> mp;
        vector<long long> sol(5,0);
        for( int i = 0; i < c.size(); ++i )
        {
           long long row = c[i][0], col = c[i][1], pos;
            // cout<<row<<" "<<col<<endl;
            if( row-1>=0 && col-1>=0 )
            {   
                // cout<<"diagonal ";
                // pos = (row-1)*col+col-1;
                mp[(row-1)*n+col-1]++;
            }
            if( row-1>=0 && col < n-1 )
            {   
                // cout<<"up ";
                // pos = (row-1)*col+col;
                mp[(row-1)*n+col]++;
            }
            if( row < m-1 && col-1>=0 )
            {   
                // cout<<"left ";
                // pos = (row)*col+col-1;
                mp[(row)*n+col-1]++;
            }
            if( row < m -1 && col < n-1 )
            {   
                // cout<<"current ";
                // pos = (row)*col+col;
                mp[(row)*n+col]++;
            }
            cout<<endl;
        }
        for(auto it:mp) 
            sol[it.second]++;
        // black boxes with zeros
        sol[0] = (long long)(m-1)*(n-1) - sol[1]-sol[2]-sol[3]-sol[4];
        return sol;
    }
};