/*
 * Fibonacci Series
 * Approach: fib(n) = fib(n-1) + fib(n-2); base: fib(0)=0, fib(1)=1
 * Time: O(2^n) - exponential due to overlapping subproblems
 * Space: O(n) recursive stack
 * Key: Can be optimized to O(n) using memoization or iteration
 */
#include<iostream>

int fibonacci(int n) {
    if(n <= 1)
        return n;
    else
        return(fibonacci(n-1) + fibonacci(n-2));
}

int main() {
    int num;
    printf("Enter the number of terms: ");
    scanf("%d",&num);
    printf("Fibonacci Series: ");
    for(int i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}
