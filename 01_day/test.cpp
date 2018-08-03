#include<iostream>
using namespace std;

namespace fangjc{
    void func(int i){
        cout<<"fangjc"<<i<<endl;
    }
}
namespace jc{
    void func(int i){
        cout<<"jc"<<ｉ<<endl;
    }
}


// 内联函数
inline int mymax(int a ,b){
    return a>b?a:b;
}

// 引用
void myswap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}


using namespace fangjc;

int main(int argc, char const *argv[])
{
    for(int i=0;i<100;i++){
        mymax(i,10);
    }
    return 0;
}
