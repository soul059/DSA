/*
 * Power of a Number (Optimized - Binary Exponentiation)
 * Approach: a^b = (a^(b/2))^2 if even, a * (a^(b/2))^2 if odd
 * Time: O(log b)
 * Space: O(log b) recursive stack
 * Key: Divide exponent by 2 each step - much faster than linear approach
 */
#include<iostream>

int power(int a,int b)
{
    if(b==0) return 1;
    int po,x = power(a,b/2);
    if(b%2==0)
    po = x*x;
    else if (b%2 != 0)
    po = x*x*a;

    return po;

}

int main()
{
    int a,b,pow;
    printf("enter the number: ");
    scanf("%d",&a);
    printf("enter the power of a : ");
    scanf("%d", &b );

    pow = power(a,b);
    printf("\nThe value is %d ",pow);
}