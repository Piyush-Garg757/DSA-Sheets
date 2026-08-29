/*Word Ladder

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.*/


// Idea is simple jop jo words ek change karne pe ban sakte hai aur list me hain unhein q mein push kar rahe hain aise hi karte karte dest tak pahuch jayenge
class Solution
{
public:
    int ladderLength(string s1, string s2, vector<string> &a)
    {
        unordered_set<string> st(a.begin(), a.end());
        if (st.find(s2) == st.end())
            return 0;
        queue<pair<string, int>> q;
        q.push({s1, 1});
        while (!q.empty())
        {
            string s = q.front().first;
            int dist = q.front().second;
            if (s == s2)
                return dist;
            q.pop();
            st.erase(s);
            for (int i = 0; i < s.length(); i++)
            {
                string pseudo = s;
                for (int j = 0; j < 26; j++)
                {
                    pseudo[i] = 'a' + j;
                    if (st.find(pseudo) != st.end())
                    {
                        q.push({pseudo, dist + 1});
                        st.erase(pseudo);
                    }
                }
            }
        }
        return 0;
    }
};
// TC - O(n*l)  SC - O(n*l)  where n is number of words and l is length of each word