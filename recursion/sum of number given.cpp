/*
 * Sum of Digits of a Number
 * Approach: Extract last digit (a%10), recursively sum remaining digits (a/10)
 * Time: O(d) where d = number of digits
 * Space: O(d) recursive stack
 * Key: Base case when number becomes 0; accumulate digit sum during return
 */
#include<iostream>

int sum(int a)
{
    int n,c=0;
    if(a==0) return 0;
    n = a%10;
    c=n+sum(a/10);

    return c; 
}
int main()
{
    int n;
    printf("enter the number");
    scanf("%d",&n);
    printf("%d",sum(n));
    return 0;
}  