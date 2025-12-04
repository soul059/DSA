/*
 * Print N to 1 and 1 to N
 * Approach: Print before recursion (N to 1), print after recursion returns (1 to N)
 * Time: O(n)
 * Space: O(n) recursive stack
 * Key: Code before recursive call executes during descent, code after executes during ascent
 */
#include<iostream>

void numbers(int n)
{
    if(n==0) return; // bace case

    printf("%d\n",n); // code this wiil work before call every time until bace case

    numbers(n-1);    // call

    printf("%d\n",n); // code this will work when it is return form bace case
    return ;
}

int main()
{
    int n;
    
    printf("enter the number : ");
    scanf("%d",&n);

    numbers(n);
    return 0;
}