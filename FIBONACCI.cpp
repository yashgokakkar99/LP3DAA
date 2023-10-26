#include<bits/stdc++.h>
using namespace std;

void fib(int n)
{
    int a,b;
    a=0;
    b=1;
    cout<<a<<" "<<b<<" ";
    for(int i=3;i<=n;i++)
    {
        int next = a+b;
        cout<<next<<" ";
        a=b;
        b=next;
    }
}

int main()
{
    int n;
    cout<<"Enter n => ";
    cin>>n;
    fib(n);
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n<=1)
    {
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

void print(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<fib(i)<<" ";
    }
}
int main()
{
    int n;
    cout<<"Enter n => ";
    cin>>n;
    print(n);
    return 0;
}
