#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
//getchar()
#include<stdio.h>

using namespace std;

//六大组件的简单使用
int main(int argc, char const *argv[])
{
    int ia[6] = {27, 201, 12, 47, 109, 83};
    vector<int, allocator<int> > vi(ia, ia + 6);
    cout << count_if(vi.begin(), vi.end(),
                     not1(bind2nd(less<int>(), 40)));
    getchar();
    return 0;
}
