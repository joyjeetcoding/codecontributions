#include <bits/stdc++.h> 

void solve(string str, int index, vector<string>& ans, string output)
{
    //base case
    if(index == str.length())
    {
        if(output.length() > 0)
        {
            ans.push_back(output);    
        }
        return;
    }
    
    //exclude
    solve(str, index + 1, ans, output);
    
    //include
    char element = str[index];
    output.push_back(element);
    solve(str, index + 1, ans, output);
}

vector<string> subsequences(string str){
    int index = 0;
    string output = "";
    vector<string> ans;
    solve(str, index, ans, output);
    
    return ans;
}
