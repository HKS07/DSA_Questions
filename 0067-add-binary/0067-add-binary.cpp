class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.length()-1, j = b.length()-1;
        if(i < j ) {swap(i,j); swap(a,b);}
        while( i >= 0 && j >= 0 )
        {
            int n = a[i]-'0' + b[j]-'0' + carry;
            a[i] = n%2 + '0';
            carry = n >= 2 ? 1:0;
            --i;--j;
        }
        while( i >= 0 && carry == 1)
        {
            int n = a[i] - '0' + carry;
            if( n == 0 )
            {
                a[i] = 0;
                carry = 0;
            }
            else if( n == 1 )
            {
                a[i] = '1';
                carry = 0;
            }
            else if( n == 2 )
            {
                a[i] = '0';
                carry = 1;
            }
            --i;
        }
        string sol = "";
        cout<<a;
        if(carry == 1) 
        {
            sol += '1'+a;
            return sol;
        }
        else return a;
        
        
        
    }
};