class Solution {
public:
    set<vector<int>> temp;
    void help( int idx, vector<int>& n, vector<int> t )
    {
        if( n.size() == idx )
        {
            temp.insert(t);
            return;
        }
        help(idx+1, n, t);
        t.push_back(n[idx]);
        help(idx+1, n, t);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        help(0,nums,{});
        vector<vector<int>> sol(temp.begin(),temp.end());
        return sol;
    }
};