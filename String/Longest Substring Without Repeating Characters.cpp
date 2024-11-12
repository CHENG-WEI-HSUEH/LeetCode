class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size() == 0)   return 0;
        int l = 0, r = 1;
        unordered_map<char, int> dict;
        dict[s[0]] = 0;
        int answer = 0;

        for(r = 1; r < s.size(); r++)
        {
            //Update
            if(dict.find(s[r]) != dict.end())
            {
                //Update answer
                answer = max(answer, r-l);
                //Update l, the new l index should not be less than old l
                l = max(dict[s[r]] + 1, l);
                //Update Mark index
                dict[s[r]] = r;
            }
            //Mark index
            else
            {
                dict[s[r]] = r;
            }
        }
        //Calculate the final answer 
        //When the last letter is not duplicate, the answer will not be update
        return max(answer,r-l);
    }
};
