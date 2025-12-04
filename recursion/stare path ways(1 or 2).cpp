/*
 * Staircase Problem (1 or 2 steps)
 * Approach: ways(n) = ways(n-1) + ways(n-2); similar to Fibonacci
 * Time: O(2^n) without memoization
 * Space: O(n) recursive stack
 * Key: From step n, you could have come from n-1 (1 step) or n-2 (2 steps)
 */
#include<iostream>

int stare(int n)
{
    if (n==1 || n ==2){
        return n;
    }
    return stare(n-1) +stare(n-2);
}

int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    printf("%d",stare(n));
    return 0;
}