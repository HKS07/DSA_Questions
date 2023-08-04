class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int distinct = 0, sol = 0;
        map<int,int> mp;
        for( auto it:nums ) mp[it]++;
        distinct = mp.size();
        mp = {};
        int i = 0, j = 0, n = nums.size();
        cout<<"distinct "<<distinct<<endl;
        cout<<"i j l s"<<endl;
        while( j < n )
        {
            mp[nums[j]]++;
            while( mp.size() == distinct )
            {
                if( --mp[nums[i]] == 0 ) mp.erase(nums[i]);
                cout<<i << " "<<j <<" "<< j-i+1;
                // sol += (j-i+1) - distinct  + 1;
                cout<<" "<<sol<<endl;
                ++i;
                // sol += (j + 1) - distinct + 1;
                sol += n - j;
            }
            ++j;
        }
        
        return sol;
    }
};