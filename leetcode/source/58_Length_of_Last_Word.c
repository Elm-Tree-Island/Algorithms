// https://leetcode.com/problems/length-of-last-word/

/**
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:
Input: "Hello World"
Output: 5

*/

int lengthOfLastWord(char * s){
    if (s == NULL)
    {
        return 0;
    }
    
    int cur_word_length = 0;
    int prev_word_length = 0;
    int i = 0;
    while (s[i] != '\0') 
    {
        if (s[i] == ' ') 
        {
            if (cur_word_length != 0) 
            {
                prev_word_length = cur_word_length;
            }
            cur_word_length = 0;
            i++;
            continue;
        }
        
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            cur_word_length++;
        }
        
        i++;
    }
    
    return cur_word_length > 0 ? cur_word_length : prev_word_length;
}
