#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int *p=new int;
    *p=10;
    cout<<*p<<endl;
    delete p;


    int *q=new int[10];
    for(int i=0;i<10;i++){
        q[i]=i;
    }
    for(int i=0;i<10;i++){
        cout<<q[10]<<endl;
    }

    delete []q;
    p=NULL;
    delete p;


    return 0;
}
