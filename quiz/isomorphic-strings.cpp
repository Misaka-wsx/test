#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> sMap,tMap;
        for(int i=0;i<s.size();i++)
        {
            auto chs=s[i];
            auto cht=t[i];
          
            if(sMap.count(chs)!=0)
            {
                if(tMap.count(cht)==0)
                {
                    return false;
                }
                if(sMap[chs]!=tMap[cht])
                {
                    return false;
                }
            }
            if (sMap.count(chs)==0&&tMap.count(cht)!=0)
            {
                return false;
            }
            
            sMap[chs]=i;
            tMap[cht]=i;
        }
        return true;
    }
};