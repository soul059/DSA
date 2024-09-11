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

int findMissingNumber(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int totalSum = (n + 1) * (n + 2) / 2;
    return totalSum - sum;
}


int main()
{
    int n1;
    cin >> n1;
    int arr1[n1];

    arrayInput(arr1, n1);


    arrayPrint(arr1, n1);

    cout << "Missing number is: " << findMissingNumber(arr1, n1) << endl;
   

    return 0;
}