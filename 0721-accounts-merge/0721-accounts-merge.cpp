class dSet {
    vector<int> rank, parent, size;
public:
    dSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void uByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

  
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        	int row = a.size();
            vector<vector<string>> sol(row);
            dSet d(row);
            map<string,int> p;

            for( int i = 0; i < row; ++i )
            {
                for( int j = 1; j < a[i].size(); ++j )
                {
                    string mail = a[i][j];
                    if( p.find(mail) == p.end() )
                    {
                        p[mail] = i;
                    }
                    else 
                    {
                        d.uByRank(i, p[mail]);
                    }
                    // cout<<mail<<endl;
                }
            }
            
            for( auto i: p)
            {
                string t = i.first;
                int par = d.findParent(i.second);
                sol[par].push_back(t);
            }
            vector<vector<string>> ans;
            for( int i = 0; i < row; ++i )
            {
                if( sol[i].size() == 0 ) continue;
                sort( sol[i].begin(), sol[i].end());
                vector<string> temp;
                temp.push_back(a[i][0]);
                for( auto it:sol[i] )
                {
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        sort(ans.begin(),ans.end());
        return ans;
    }
};