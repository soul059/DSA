#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

// this is brute force approach
    // int freq[100000] = {0};
    // for (int i = 0; i < n; i++)
    //     freq[a[i]]++;
    // int min = INT_MAX;
    // int minele;
    // int maxele;
    // int max = INT_MIN;
    // for (int i = 0; i < 100000; i++)
    // {
    //     if (freq[i] != 0)
    //     {
    //         if (freq[i] > max)
    //         {
    //             max = freq[i];
    //             maxele = i;
    //         }
    //         if (freq[i] < min)
    //         {
    //             min = freq[i];
    //             minele = i;
    //         }
    //     }
    // }
    


// now we will use unorderd map to solve this problem

    unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
        m[a[i]]++;
    int min = INT_MAX;
    int minele;
    int maxele;
    int max = INT_MIN;
    for (auto x : m)
    {
        if (x.second > max)
        {
            max = x.second;
            maxele = x.first;
        }
        if (x.second < min)
        {
            min = x.second;
            minele = x.first;
        }
    }


    cout << "Max frequency element is: " << maxele << endl;
    cout << "Min frequency element is: " << minele << endl;
    return 0;
}