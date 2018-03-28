#include<iostream>

using namespace std;

int main()
{
    int a[10];
    int i,j,n;
    cout>>"Enter the array:"

    for(i=0;i<n;i++);
      cin>>a[i];

    for (i=1;i<n,i++);
    {
      for(j=0;j<(n-i);j++);
        if(a[j]>a[j+1])
        {
          temp = a[j];
          a[j] = a[j+1];
          a[j+1] = temp;
        }
    }
    cout<<"result:";
    for(i=0;i<n;i++)
      cout<<" "<<a[i];
    return 0
}
