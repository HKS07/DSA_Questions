class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> wl(wordList.begin(),wordList.end());
        // wl.insert(beginWord);
        if( wl.find(beginWord) != wl.end() ) wl.erase(beginWord);
        queue<pair<string,int>> q;
        q.push({beginWord,0});
        
        while( !q.empty() )
        {
            int sz = q.size();
            
            for( int i = 0; i < sz; ++i )
            {
                string w = q.front().first;
                int lvl = q.front().second;
                q.pop();
                if( w == endWord ) return lvl+1;
                
                for( int pos = 0; pos < w.length(); ++pos )
                {
                    for( char letter = 'a'; letter <= 'z'; ++letter )
                    {
                        string t = w;
                        t[pos] = letter;
                        if( wl.find(t) != wl.end() )
                        {
                            q.push({t,lvl+1});
                            wl.erase(t);
                        }
                    }
                }
            }
        }
        return 0;
    }
};