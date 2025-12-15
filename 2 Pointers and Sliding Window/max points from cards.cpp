#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

int maxPoints(vector<int>& cards, int k) {
    int n = cards.size();
    int leftSum = 0;
    for (int i = 0; i < k; ++i) {
        leftSum += cards[i];
    }
    int maxPoints = leftSum;
    int rightSum = 0;
    for (int i = 0; i < k; ++i) {
        rightSum += cards[n - 1 - i];
        leftSum -= cards[k - 1 - i];
        maxPoints = max(maxPoints, leftSum + rightSum);
    }
    return maxPoints;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }
    cout << maxPoints(cards, k) << endl; 
    return 0;
}