/*
 * Power of a Number (Linear Recursion)
 * Approach: Multiply 'a' recursively b times; a^b = a * a^(b-1), base: a^0 = 1
 * Time: O(b)
 * Space: O(b) recursive stack
 * Key: Simple but inefficient for large exponents
 */
#include<iostream>

int power(int a, int b)
{
    if(b==0) return 1;
    return a*power(a,b-1);
}

int main()
{
    int a,b,pow;
    printf("enter the number : ");
    scanf("%d",&a);
    printf("enter the power of number : ");
    scanf("%d",&b);

    pow = power(a,b);
    printf("the power of %d^%d is %d",a,b,pow);
    return 0;
}