class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        
        for( auto it: nums )
        {
            if( s.find(it) != s.end() )
            {
                //exist
                s.erase(it);
            }
            else
            s.insert(it);
        }
        return *s.begin();
    }
};