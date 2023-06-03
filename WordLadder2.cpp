#include<bits/stdc++.h>

using namespace std;
int main()
{
 vector<string> wordlist={"des","der","dfr","dgt","dfs"};
 string startWord = "der", targetWord = "dfs";

// use bfs 
vector<string> storeonlevel={startWord};
queue<vector<string>> q;
unordered_set<string>(wordlist.begin(), wordlist.end());
q.push({startWord});
int level =0;
vector<vector<string>> ans;
while(!q.empty()){
    vector<string vec= q.front();
    q.pop();
   if(vec.size()>level){
         level++;
         for(auto it: storeonlevel){
            st.erase(it);
         }
         storeonlevel.clear();
   }
string word=vec.back();
 if (word == targetWord)
            {
                // the first sequence where we reached end
                if (ans.size() == 0 || ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
                
            }
for(int di=0;di<word.size();di++){
  char original = word[i];
  for(char ch='a' ch<='z';ch++){
    word[i]=ch;
    if(st.count(word)>0){
        vec.push_back(word);
        q.push({vec});
       storeonlevel.push(word);
       vec.pop_back();        
    }
  }
  word[i]=original;
}





}


return ans;

}