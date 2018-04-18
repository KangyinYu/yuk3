#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a,b;
    char c;
    int i,sum;
    while(scanf("%d %c",&a,&c)!=EOF)
    {
        if(c!='!')
        {
            scanf(" %d",&b);
            if(c=='+')
                cout<<a+b<<endl;
            if(c=='-')
                cout<<a-b<<endl;
            if(c=='*')
                cout<<a*b<<endl;
            if(c=='/')
            {
                if(b==0)
                    cout<<"error"<<endl;
                else
                {
                    cout<<a/b<<endl;
                }
            }
            if(c=='%')
            {
                if(b==0)
                    cout<<"error"<<endl;
                else
                {
                    cout<<a%b<<endl;
                }
            }
        }
        else
        {
            if(a<0)
                cout<<"error"<<endl;
            else
            {
                sum=1;
                for(i=1;i<=a;i++)
                    sum*=i;
                cout<<sum<<endl;
            }
        }
    }
    return 0;
}
