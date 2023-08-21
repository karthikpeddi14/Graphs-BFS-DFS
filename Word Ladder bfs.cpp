// bfs method
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty())
        {
            string s = q.front().first;
            int c = q.front().second;
            q.pop();
            if(s==endWord) return c;
            for(int i=0 ; i<s.size() ; i++)
            {
                char original = s[i];
                for(char k='a' ; k<='z' ; k++)
                {
                    s[i] = k;
                    if(st.find(s)!=st.end())
                    {
                        st.erase(s);
                        q.push({s,c+1});
                    }
                }
                s[i] = original;
            }
        }
        return 0;
        
    }
};
