#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void sswap(int& a, int& b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void zlicz(char * x, int& u, int& m, int& k)
{
    u=m=k=0;
    int b=strlen(x);
    for (int i=0; i<b; i++)
    {
        if (x[i]=='u') u++;
        else if (x[i]=='m') m++;
        else if (x[i]=='k') k++;
    }
}

void s_zlicz(const string& x, int& u, int& m, int& k)
{
    u=m=k=0;
    int b=x.length();
    for (int i=0; i<b; i++)
    {
        if (x[i]=='u') u++;
        else if (x[i]=='m') m++;
        else if (x[i]=='k') k++;
    }
}

int main(void)
{

}
