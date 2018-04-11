#include <iostream>
using namespace std;
int main()
{
 int a[10];
 int i,j;
 cout<<"输入数字："<<endl;
 for(i=0;i<10;i++)
  cin>>a[i];
 for(j=1;j<10;j++)
 for(i=0;i<10-j;i++)
  {
    if(a[i]>a[i+1])
      {
        int t=a[i];
        a[i]=a[i+1];
        a[i+1]=t;
      }

  }
    for(i=0;i<10;i++)
    cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}
