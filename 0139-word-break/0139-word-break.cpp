
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int,vector<string>> mp;
        //create an unordered map
        for(string word:wordDict){
            int size=word.size();
            mp[size].push_back(word);
        }
        map<tuple<int, int, string>, bool> dp;
        return func(0, 0, "", mp, s, dp);
    }

    bool func(int ind, int cnt, string x, unordered_map<int,vector<string>>& mp, string& s, map<tuple<int, int, string>, bool>& dp){
        // memoization check
        if(dp.find({ind, cnt, x}) != dp.end()) return dp[{ind, cnt, x}];

        //base case
        if(ind == s.size()){
            if(findInd(cnt, mp) && findString(cnt, x, mp)){
                return dp[{ind, cnt, x}] = true;
            } else return dp[{ind, cnt, x}] = false;
        }

        //conditions
        if(findInd(cnt, mp)){
            bool b = findString(cnt, x, mp);
            if(b) {
                if(func(ind+1, 1, string(1, s[ind]), mp, s, dp) || func(ind+1, cnt+1, x + s[ind], mp, s, dp))
                    return dp[{ind, cnt, x}] = true;
            }
        }

        return dp[{ind, cnt, x}] = func(ind+1, cnt+1, x + s[ind], mp, s, dp);
    }

    bool findInd(int cnt, unordered_map<int,vector<string>>& mp){
        for(auto it:mp){
            if(it.first==cnt)return true;
        }
        return false;
    }

    bool findString(int cnt, string s, unordered_map<int,vector<string>>& mp){
        vector<string> v = mp[cnt];
        for(string x : v){
            if(x == s) return true;
        }
        return false;
    }
};


// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_map<int,vector<string>> mp;
//         vector<vector<int>> 
//         //create an unordered map
//         for(string word:wordDict){
//             int size=word.size();
//             mp[size].push_back(word);
//         }
//         return func(0,0,"",mp,s);
//     }

//     bool func(int ind,int cnt,string x,unordered_map<int,vector<string>>& mp,string& s){
//         //base case
//         if(ind == s.size()){
//             if(findInd(cnt, mp) && findString(cnt, x, mp)){
//                 return true;
//             } else return false;
//         }
//         //conditions
//         if(findInd(cnt,mp)){
//             bool b=findString(cnt,x,mp);
//             if(b) return (func(ind+1,1,string(1,s[ind]),mp,s) || func(ind+1,cnt+1,x+s[ind],mp,s));
//         }
//         return func(ind+1,cnt+1,x+s[ind],mp,s);
//     }

//     bool findInd(int cnt,unordered_map<int,vector<string>>& mp){
//         for(auto it:mp){
//             if(it.first==cnt)return true;
//         }
//         return false;
//     }

//     bool findString(int cnt,string s,unordered_map<int,vector<string>>& mp){
//         vector<string> v=mp[cnt];
//         for(string x:v){
//             if(x==s) return true;
//         }
//         return false;
//     }
// };
