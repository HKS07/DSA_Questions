class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int mA = 0;
        stack<int> s;
        
        for(int i = 0; i <= heights.size(); ++i )
        {
            while( !s.empty() && ( i == heights.size() || heights[i] <= heights[s.top()]))
            {
                int lb , rb = i-1;
                int ht = heights[s.top()]; s.pop();
                if( s.empty() ) lb = 0;
                else lb = s.top() + 1;
                
                mA = max( mA, (rb-lb+1)*ht);
            }
            s.push(i);
        }
        return mA;
        
    }
};