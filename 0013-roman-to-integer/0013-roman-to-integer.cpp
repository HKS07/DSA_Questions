class Solution {
public:
    int romanToInt(string s) {
        map<string,int> m,n;
        m.insert({"IV", 4});
        m.insert({"IX", 9});
        m.insert({"XL", 40});
        m.insert({"XC", 90});
        m.insert({"CD", 400});
        m.insert({"CM", 900});
        
        n.insert({"I", 1});
        n.insert({"V", 5});
        n.insert({"X", 10});
        n.insert({"L", 50});
        n.insert({"C", 100});
        n.insert({"D", 500});
        n.insert({"M", 1000});
        int sum = 0;
        
        for( int i = 0; i < s.length(); )
        {
            // string t1 = ;
            if( i + 1 < s.length() && m.find(s.substr(i,2)) != m.end() )
               {
                   sum += m[s.substr(i,2)];
                   i += 2; 
                   
               }
             else
               {
                   sum += n[s.substr(i,1)];
                   ++i;
               }
        }
               return sum;
        
    }
};