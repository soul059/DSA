#include <iostream>
#include <vector>
using namespace std;

void arrayInput(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void arrayPrint(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> unionOfTwoSorted(int arr1[], int n1, int arr2[], int n2)
{
    int i = 0;
    int j = 0;
    vector<int> temp;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (temp.size() == 0 || temp.back() != arr1[i])
            {
                temp.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (temp.size() == 0 || temp.back() != arr2[j])
            {
                temp.push_back(arr2[j]);
            }
            j++;
        }
    }
    
    // Handle remaining elements in arr1 or arr2
    while (i < n1)
    {
        if (temp.size() == 0 || temp.back() != arr1[i])
        {
            temp.push_back(arr1[i]);
        }
        i++;
    }
    
    while (j < n2)
    {
        if (temp.size() == 0 || temp.back() != arr2[j])
        {
            temp.push_back(arr2[j]);
        }
        j++;
    }
    
    return temp;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1];
    int arr2[n2];
    arrayInput(arr1, n1);
    arrayInput(arr2, n2);

    arrayPrint(arr1, n1);
    arrayPrint(arr2, n2);
    cout << endl;

    vector<int> result = unionOfTwoSorted(arr1, n1, arr2, n2);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}