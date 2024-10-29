#include <iostream>
#include <vector>
#include<set>
#include <algorithm>
using namespace std;

bool Isomorphic(string s1, string s2) {
    if (s1.size() != s2.size()) return false;

    vector<int> map1(256, -1);
    vector<int> map2(256, -1);

    for (int i = 0; i < s1.size(); i++) {
        if (map1[s1[i]] != map2[s2[i]]) return false;
        map1[s1[i]] = i;
        map2[s2[i]] = i;
    }
    return true;
}


int main()
{
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << "input string 1 is: " << s1 << endl;
    cout << "input string 2 is: " << s2 << endl;
    bool ans = Isomorphic(s1,s2);
    cout << "ans is: " << ans << endl;
    return 0;
}