// Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.

//same as allocate minimum number of pages

#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size(); // size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            // add pages to current student
            pagesStudent += arr[i];
        }
        else
        {
            // add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    // book allocation impossible:
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{

    int n,m;
    cin >> n>>m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
