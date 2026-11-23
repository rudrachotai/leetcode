class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string,int> map;
        for(int i=0;i<n;i++){
            map[wordList[i]]++;
        }
        if(map.find(beginWord)==map.end()) map[beginWord]++;
        if(map.find(endWord)==map.end()) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        map.erase(beginWord);
        while(q.size()!=0){
         pair<string,int> p = q.front();
         q.pop();
         string str = p.first;
         int lvl = p.second;
         
         if(str == endWord) return lvl;
         for(int i=0;i<str.size();i++){
            char c = str[i];
            for(int j=0;j<=25;j++){
                if('a'+j==c) continue;
                str[i] = 'a'+j;
                if(map.find(str)!=map.end()){
                    q.push({str,lvl+1});
                    map.erase(str);
                }
            }
            str[i] = c;
         }
        }
        return 0;
    }
};