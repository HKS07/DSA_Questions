class Solution {
public:
    int divisorSubstrings(int nums, int k) {
        int sol = 0;
        string num = to_string(nums);
        int n , i = 0,j = k-1,mul = 1;
        n = stoi(num.substr(0,k));
         
        while(  j < num.length() )
        {
                if( j != k-1 )
                {
                    n = n*10 + num[j]-'0';
                }
                // cout<<n<<" ";
                if( n != 0 && nums % n == 0 )
                 sol++;
                
                //subtract the first digit
                n = n - (num[i]-'0')*pow(10,k-1);
                ++i;++j;
            
        }
        
        return sol;
    }
};