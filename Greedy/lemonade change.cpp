#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

/*
 * @brief Determine if exact change can be given to every customer in order.

 * Greedy algorithm that tracks counts of $5 and $10 bills. For each bill:
 * - $5: increment five-count.
 * - $10: require one $5 (decrement five-count) and increment ten-count.
 * - $20: prefer to give one $10 + one $5 (decrement ten-count and five-count);
 *        otherwise give three $5 (decrement five-count by 3).

 * @param bills Reference to vector of incoming bills (values 5, 10, 20).
 * @return true if change can be provided for all customers; false otherwise.

 * Complexity: O(n) time, O(1) additional space.
 */

bool lemonadeChange(vector<int>& bills) {
    int fiveCount = 0;
    int tenCount = 0;

    for(int bill : bills) {
        if(bill == 5) {
            fiveCount++;
        } else if(bill == 10) {
            if(fiveCount == 0) return false;
            fiveCount--;
            tenCount++;
        } else { // bill == 20
            if(tenCount > 0 && fiveCount > 0) {
                tenCount--;
                fiveCount--;
            } else if(fiveCount >= 3) {
                fiveCount -= 3;
            } else {
                return false;
            }
        }
    }

    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> bills(n);
    for(int i = 0; i < n; i++){
        cin >> bills[i];
    }
    cout << (lemonadeChange(bills) ? "true" : "false") << endl;
    return 0;
}