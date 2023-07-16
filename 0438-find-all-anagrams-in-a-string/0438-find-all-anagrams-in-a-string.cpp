class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i = 0, j = 0, count, k = p.length();
        vector<int> sol;
        map<char,int> mp;
        for( int i = 0; i < k; ++i ) mp[p[i]]++;
        count = mp.size();
        while(  j < s.length() )
        {
            
            if( mp.find(s[j]) != mp.end() )
            {
                mp[s[j]]--;
                if( mp[s[j]] == 0 ) count--;
            }
            if( j - i + 1 < k )
                ++j;
            else if( j - i + 1 == k )
            {
                if( count == 0 )
                {
                    sol.push_back(i);
                }
                if( mp.find(s[i]) != mp.end() )
                {
                    if( mp[s[i]] == 0 ) count++;
                    mp[s[i]]++;
                }
                ++i;++j;
            }
        }
        return sol;
    }
};