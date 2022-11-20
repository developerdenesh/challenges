class Solution {
public:
    int longestPalindrome(string s) {
        int odd_characters = 0;
        for (char c ='A'; c <= 'z'; c++)
        {
            int count = std::count(s.begin(), s.end(), c);
            
            // returns 1 if both count and 1 are odd, else it returns 0
            odd_characters += count & 1;
        }
         
        int additional_odd_character = odd_characters > 0;
        return s.size() - odd_characters + additional_odd_character;
    }
};