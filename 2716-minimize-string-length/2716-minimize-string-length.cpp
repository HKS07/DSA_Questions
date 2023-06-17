class Solution {
public:

//     int minimizedStringLength(string s) {
//         set<char> str;
        
//         for( int i = 0; i < s.length(); ++i )
//         {
//             str.insert(s[i]);
//         }
//         return str.size();
//     }
        int minimizedStringLength(string s) {
        
            return unordered_set<char>(s.begin(),s.end()).size();
    }
};