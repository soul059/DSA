#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string longestComPrefix(vector<string> &s)
{

    // best approch is to sort all then last one is most diffrent one that's why compair only first and last one
    string ans = "";
    sort(s.begin(), s.end());
    int n = s.size();
    string first = s[0], last = s[n - 1];
    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
        if (first[i] != last[i])
        {
            return ans;
        }
        ans += first[i];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin>>s[i];
    
    string ans = longestComPrefix(s);
    cout << "output string is: " << ans << endl;
    return 0;
}