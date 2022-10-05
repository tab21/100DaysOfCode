
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isInterleave(string s1, string s2, string s3)
{
    if (s1.size() + s2.size() != s3.size())
    {
        return false;
    }

    vector<vector<int>> dp(s1.size() + 1, (vector<int>(s2.size() + 1, 0)));

    for (int i = s1.size(); i >= 0; i--)
    {
        for (int j = s2.size(); j >= 0; j--)
        {
            int k = i + j;
            if (i == s1.size() && j == s2.size())
            {
                dp[i][j] = 1;
            }
            else if (s3[k] == s2[j] && s3[k] == s1[i])
            {
                dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
            }
            else if (s1[i] == s3[k])
            {
                dp[i][j] = dp[i + 1][j];
            }
            else if (s3[k] == s2[j])
            {
                dp[i][j] = dp[i][j + 1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[0][0];
}

int main()
{
    // your code goes here
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    cout << isInterleave(s1, s2, s3);

    return 0;
}

// Time limit exceeded

// void dpfun (int i,int j, int k,vector<vector<int>>&dp,string s1,string s2,string s3){
//     if (i<0 || j<0){
//       return;
//     }

//     if(i==s1.size()&&j==s2.size()){
//       dp[i][j]=1;
//     }else if(s3[k]==s2[j]&&s3[k]==s1[i]){
//       dp[i][j]= dp[i+1][j]||dp[i][j+1];
//     }else if(s1[i]==s3[k]){
//       dp[i][j]= dp[i+1][j];
//     }else if(s3[k]==s2[j]){
//       dp[i][j]= dp[i][j+1];
//     }else{
//       dp[i][j]= false;
//     }

//     if (i==0 && j==0){
//       return;
//     }
//     dpfun(i-1,j,k-1,dp,s1,s2,s3);
//     dpfun(i,j-1,k-1,dp,s1,s2,s3);
// }
// bool isInterleave(string s1, string s2, string s3) {
//     if (s1.size()+s2.size()!=s3.size()){
//         return false;
//     }

//     vector<vector<int>>dp(s1.size()+1,(vector<int>(s2.size()+1,0)));

//     dpfun(s1.size(),s2.size(),s3.size(),dp,s1,s2,s3);

//     return dp[0][0];
// }
