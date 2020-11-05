#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
unordered_map<string,int> wordId;
vector<vector<int>>edge;
int nodeNum=0;
void addWord(string& word)
{
    if(!wordId.count(word))
    {
        wordId[word]=nodeNum++;
        edge.emplace_back();
    }
}
void addEdge(string&word)
{
    addWord(word);
    int id1=wordId[word];
    for(char&it:word)
    {
        char tmp=it;
        it='*';
        addWord(word);
        int id2=wordId[word];
        edge[id1].push_back(id2);
        edge[id2].push_back(id1);
        it=tmp;
    }
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
        for (string &word:wordList)
        {
            addEdge(word);
        }
        addEdge(beginWord);
        if(!wordId.count(endWord))
        {
            return 0;
        }
        vector<int> dis(nodeNum,INT_MAX);
        int beginID=wordId[beginWord];
        int endID=wordId[endWord];
        dis[beginWord]=0;
        queue<int> que;
        que.push(beginID);
        while (!que.empty())
        {
            int x=que.front();
            que.pop();
            if(x==endID)
            {
                return dis[endID]/2+1;
            }
            for (int it:edge[x])
            {
                if(dis[it]==INT_MAX)
                {
                    dis[it]=dis[x]+1;
                    que.push(it);
                }
            }
            
        }
        return 0;
}
};
