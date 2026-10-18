class Solution {
public:
    //BFS as shortest is asked also move everything to set for better tc
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            if(word==endWord){
                return level;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        s.erase(word);//minimize ie shortest ke liye
                        q.push({word,level+1});
                    }
                }
                word[i]=original;
            }

        }
        return 0;
    }
};
