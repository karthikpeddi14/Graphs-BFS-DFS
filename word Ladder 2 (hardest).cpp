class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        vector<string> usedInthisLevel;
        q.push({beginWord});
        usedInthisLevel.push_back(beginWord);
        vector<vector<string>> ans;
        int level = 0;
        
        while(!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();
            
            if(vec.size()>level)
            {
                level++;
                for(auto it:usedInthisLevel)
                {
                    st.erase(it);
                }
                usedInthisLevel.clear();
            }
            
            string last = vec.back();
            if(last==endWord)
            {
                if(ans.empty()) ans.push_back(vec);
                else
                {
                    if(vec.size()==ans[0].size()) ans.push_back(vec);
                }
            }
            
            for(int i=0; i <last.size() ; i++)
            {
                char original= last[i];
                for(char c='a' ; c<='z' ; c++)
                {
                    last[i] = c;
                    if(st.find(last)!=st.end())
                    {
                        vec.push_back(last);
                        q.push(vec);
                        usedInthisLevel.push_back(last);
                        vec.pop_back();
                    }
                }
                last[i] = original;
            }
        }
        return ans;
    }
};
