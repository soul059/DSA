/*
 * Staircase Problem (1, 2, or 3 steps)
 * Approach: ways(n) = ways(n-1) + ways(n-2) + ways(n-3); Tribonacci-like
 * Time: O(3^n) without memoization
 * Space: O(n) recursive stack
 * Key: From step n, could have come from n-1, n-2, or n-3
 */
#include<iostream>

int stare(int n)
{
    if (n==1 || n ==2 ){
        return n;
    }
    if (n==3) return n+1;
    return stare(n-1) +stare(n-2) + stare(n-3);
}

int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    printf("%d",stare(n));
    return 0;
}