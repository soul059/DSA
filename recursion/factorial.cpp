/*
 * Factorial of a Number
 * Approach: n! = n * (n-1)!; base case: 0! = 1! = 1
 * Time: O(n)
 * Space: O(n) recursive stack
 * Key: Classic recursion example - multiply n with factorial of n-1
 */
#include<iostream>
int factorial(int n);
int main() 
{
    int num;
    printf("Enter the number to find its Factorial: ");
    scanf("%d",&num);
    printf("the factorial of number %d is %d",num,factorial(num));
    return 0;
}


int factorial(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else 
    {
        return (n * factorial(n-1));
    }
}