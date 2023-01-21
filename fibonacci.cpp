#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//memoisation
int fib(int n, vector<int>& table)
{
    cout<<"x";
    if(table[n]==-1)
    {
        if(n<=1)
        {
            table[n] = n;
        }
        else
        {
            table[n] = fib(n-1, table) + fib(n-2, table);
        }
    }

    return table[n];
    
}

//driver code)
int main(int argc, char *argv[])
{

    int n = stoi(argv[1]);
    vector<int> table(n+1,-1);
    int val = fib(n, table);
    cout<<val<<endl;
    return 0;
}