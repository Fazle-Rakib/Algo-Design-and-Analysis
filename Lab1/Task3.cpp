#include<bits/stdc++.h>
using namespace std;

int log2(long long int k)
{
    int c=0;
    while(k != 0)
    {
        k/=2;
        c++;
    }
    return c;
}

int main()
{
    long long int k;
    cin>> k;
    int w = log2(k);                /// w = word size = size of(k)
    long long int m = 8;
    long long int p = log2(m);      /// m = 2^p
    int s=rand() % (long long int)pow(2,w);    /// 0 < s < 2^w :=> s = rand % (2^w)
    s+=1;                                            /// s =? 0; s+=1
    k*=s;
    k&=((long long)pow(2,w)-1);                 /// k = 10011101 * 00001111 => (2^w-1) => 1111 = 15
    if(w > p)
    {
        k >>= (w-p);
    }
    else
    {
        k <<= (p-w);
    }
    cout << k << endl;
}
