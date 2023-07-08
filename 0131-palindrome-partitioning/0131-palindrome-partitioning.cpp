class Solution {
public:
    vector<vector<string>> sol;
    void help( string s, int idx, vector<string>&t )
    {
        if(s.length()==idx) {sol.push_back(t); return;}
        
        for( int i = idx; i < s.length(); ++i )
        {
            if(isPalin(s,idx,i))
            {
                t.push_back(s.substr(idx,i-idx+1));
                help(s,i+1,t);
                t.pop_back();
            }
        }
    }
    bool isPalin( string s, int idx, int i )
    {
        while (idx <= i) {
      if (s[idx++] != s[i--])
        return false;
    }
    return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string> t;
        help(s,0,t);
        return sol;
    }
};