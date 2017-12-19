#include <bits/stdc++.h>
using namespace std;
#define MODD 1000000007

void multiply_matrix(long long int matrix1[2][2],long long int matrix2[2][2]){
    long long int a = ((matrix1[0][0]*matrix2[0][0])%MODD + (matrix1[0][1]*matrix2[1][0])%MODD)%MODD;
    long long int b = ((matrix1[0][0]*matrix2[0][1])%MODD + (matrix1[0][1]*matrix2[1][1])%MODD)%MODD;
    long long int c = ((matrix1[1][0]*matrix2[0][0])%MODD + (matrix1[1][1]*matrix2[1][0])%MODD)%MODD;
    long long int d = ((matrix1[1][0]*matrix2[0][1])%MODD + (matrix1[1][1]*matrix2[1][1])%MODD)%MODD;

    matrix1[0][0] = a;
    matrix1[0][1] = b;
    matrix1[1][0] = c;
    matrix1[1][1] = d;
}

void power_matrix(long long int fib_matrix[2][2],long long int n){
    long long int f[2][2] = {{1,1},{1,0}};
    if(n == 0 || n == 1){
        return;
    }
    power_matrix(fib_matrix,n/2);
    multiply_matrix(fib_matrix,fib_matrix);
    if(n%2 == 1){
        multiply_matrix(fib_matrix,f);
    }
}

long long int calculate_answer(long long int n){
    // Since n is large, dynamic programming solution and other methods with take a lot of time to compute hence using matrix method
    // Fib_matrix^n = {{F(n+1) , F(n)}, {F(n) , F(n-1)}}
    // Here we need to find the (n+2)th fibonacci number to find the solution
    long long int fib_matrix[2][2] = {{1,1},{1,0}};
    power_matrix(fib_matrix,n);
    return fib_matrix[0][1];
}

int main(){
    int t;
    cin>>t;

    while(t--){
        long long int n;
        cin>>n;
        // The answer can be seen as the (n+2)th Fibonacci number after taking some test cases
        cout<<calculate_answer(n+2)<<endl;
    }
}
