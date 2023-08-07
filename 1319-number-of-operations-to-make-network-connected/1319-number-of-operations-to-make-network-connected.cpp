class dSet{
	vector<int> rank,parent;
	public:
	dSet(int n )
	{
		rank.resize(n+1,0);
		parent.resize(n+1);
		for( int i = 0; i <= n; ++i ) parent[i] = i;
	}
	int findParent(int node )
	{
		if( node == parent[node] ) return node;
		return parent[node] = findParent(parent[node]);
	}
	void uByRank( int u, int v )
	{
		int upar = findParent(u), vpar = findParent(v);
		if( upar == vpar ) return;
		if( rank[upar] > rank[vpar] )
			parent[vpar] = upar;
		else if( rank[upar] < rank[vpar] )
			parent[upar] = vpar;
		else
		{
			parent[vpar] = upar;
			rank[upar]++;
		}
	}
	int compnents()
	{
		int c = 0;
		for( int i = 0; i < parent.size()-1; ++i ) if(parent[i] == i ) c++;
		return c;
	}
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        dSet d(n);   
	int extraEdges = 0;

	for( auto e: edges )
	{
		int u = e[0], v = e[1], uParent = d.findParent(u), vParent = d.findParent(v);

		if( uParent == vParent ) { extraEdges++; continue;}

		d.uByRank(u,v);
		
	}  
	int unconnectedComponents = d.compnents() - 1;
	cout<<"components "<<unconnectedComponents<<endl;
	if( unconnectedComponents == 0 ) return 0;
	else if( unconnectedComponents > extraEdges ) return -1;
	else {
		return unconnectedComponents;
	} 
    }
};