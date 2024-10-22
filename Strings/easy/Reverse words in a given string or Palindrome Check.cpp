#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string revWords(string s)
{
    reverse(s.begin(), s.end());
    int n = s.size();
    int left = 0;
    int right = 0;
    int i = 0;
    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;
        if (i == n)
            break; // to stop index going out of bounds
        while (i < n && s[i] != ' ')
        {
            s[right++] = s[i++];
        }
        reverse(s.begin() + left, s.begin() + right);
        s[right++] = ' ';
        left = right;
        i++;
    }
    s.resize(right - 1);
    return s;
}

int main()
{
    string s;
    getline(cin, s);
    cout << "input string is: " << s << endl;
    string ans = revWords(s);
    cout << "output string is: " << ans << endl;
    return 0;
}