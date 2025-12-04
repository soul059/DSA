/*
 * Zigzag Pattern Recursion
 * Approach: Print n, recurse, print n, recurse, print n - creates ternary tree pattern
 * Time: O(3^n) - ternary recursive structure
 * Space: O(n) recursive stack
 * Key: Demonstrates multiple recursive calls with prints before/between/after
 */
#include<iostream>

void zigzeg(int n)
{
    if(n==0) return;
    printf("%d ",n);
    zigzeg(n-1);
    printf("%d ",n);
    zigzeg(n-1);
    printf("%d ",n);
    return;
}

int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);

    zigzeg(n);
}