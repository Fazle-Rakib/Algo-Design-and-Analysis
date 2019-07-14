#include<bits/stdc++.h>
using namespace std;
vector <string> ara;
long long int mod = 10001;
struct points
{
    int key;
    string s;
};
int word(string str)
{
    string word = "";
    int j = 0;
    for(int i = 0; i < str.length();i++)
    {
        if(str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            ara.push_back(word);
            j++;
            word = "";
        }
        else
        {
            word += (char)str[i];
        }
    }
    if(word != "")
    {
        ara.push_back(word);
        j++;
    }
    return j;
}
int rad(string s,long long int radix)
{
    long long int temp = 0,j = 0;
    for(int i = s.length()-1;i >=0;i--,j++)
    {
        temp += (long long int)(s[i]*pow(radix,j)) % mod;
    }
    //cout << temp << endl;
    return temp % mod;
}
int main()
{
    string s;
    long long int radix = 0;
    vector <int> v;
    cout << "String : ";
    getline(cin,s);
    cout << endl;
    cout << "Radix : ";
    cin >> radix;
    cout << endl;
    int cont = word(s);
    for(int i = 0; i < cont;i++)
    {
        v.push_back(rad(ara[i],radix));
    }
    sort(v.begin(),v.end());
    int result = 0;
    for(int i = 0; i < cont;i++)
    {
        //cout << v[i] << " ";
        int temp = v[i];
        while(temp == v[i+1])
        {
            i++;
        }
        result++;
    }
    cout << "Unique Words : ";
    cout <<  result << endl;
}
