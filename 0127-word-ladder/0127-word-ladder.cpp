class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wordList) {
        unordered_set<string> wl(begin(wordList),end(wordList));
        int sol = INT_MAX;
        queue<pair<string,int>> q;
        q.push({bw,1});
        
        while( !q.empty() )
        {
            string org = q.front().first;
            int lvl = q.front().second;
            q.pop();
            
            if( org == ew ) 
            {
                sol = min( sol, lvl );
                return sol==INT_MAX?0:sol;
            }
            
            for( int i = 0; i < org.length(); ++i )
            {
                char orgChar = org[i];
                for( char j = 'a'; j <= 'z'; ++j )
                {
                    org[i] = j;
                    if( wl.find(org) != wl.end() )
                    {
                        wl.erase(org);
                        q.push({org,lvl+1});
                    }
                    org[i] = orgChar;
                }
            }
        }
        return sol==INT_MAX?0:sol;
    }
};