#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

string removeOutPer(string s){
    int n = s.size();
        int i = 0;
        int count = 0;
        string ans = "";
        for(int i = 0;i<n;i++){
            //case1
            if(s[i] == '(' && count  == 0){
                count++;//outermost bracket dont include
            }
            //case2
            else if(s[i] == '(' && count >= 1){
                ans += s[i];//include in ans
                count++;
            }
            //case3
            else if(s[i] == ')' && count > 1){
                ans += s[i]; //include in ans as it is not the closing bracket of outermost opening bracket
                count--;
            }
            //case4
            else if(s[i] == ')' && count == 1){
                count--;//dont inlcude as it is the closing bracket of outer most opening bracket
            }
        }
        return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<"input string is: "<<s<<endl;
    string ans = removeOutPer(s);
    cout<<"output string is: "<<ans<<endl;
    return 0;
}