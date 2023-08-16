
class dSet{
	public:
	vector<int> rank, parent;
	dSet(int n)
	{
		rank.resize(n+1,0);
		parent.resize(n+1);
		for( int i = 0; i <= n; ++i ) parent[i] = i;
	}
	int findParent(int node)
	{
		if( node == parent[node] ) return node;
		return parent[node] = findParent(parent[node]);
	}
	void uByRank(int u, int v )
	{
		int upar = findParent(u), vpar = findParent(v);
		if( upar == vpar ) return;

		if( rank[upar] > rank[vpar] ) parent[vpar] = upar;
		else if ( rank[upar] > rank[vpar] ) parent[upar] = vpar;
		else {
			rank[upar]++;
			parent[vpar] = upar;
		}
	}
};
class Solution {
public:
    int removeStones(vector<vector<int>>& s) {
        int n = 0 , m = 0;
        for( auto i: s )
        {
            n = max( n, i[0]);
            m = max( m, i[1]);
        }
        dSet ds(n+m+1);
        map<int,int> mp;
        for( auto it: s )
        {
            int row = it[0];
            int col = it[1]+n+1;
            ds.uByRank(row, col);
            mp[row] = 1;
            mp[col] = 1;
        }
        int count = 0;
        for( auto it: mp )
        {
            if( ds.findParent(it.first) == it.first ) 
            {
                count++;
            }
        }
        return s.size() - count;
    }
};