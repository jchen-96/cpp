# 01
 标准库，包括标准模板库(stl)

# 02
stl 的六大组件
* 容器(Container)
* 分配器(allocator)
* 算法(algorithm)
* 迭代器(interator)
* 适配器(adapters)
* 仿函数(functors)

begin 指向起点，end指向最后一个元素的下一个位置


# 03
容器的分类

### 序列容器
* array 数组
* vector 动态数组
* deque 双端队列
* list  双端链表 
* tlist  单向链表

### 关联容器
<!-- multi 表示可以重复，键 -->
* set/multiset

* map/multimap

### array 相关
* array<type,size>  arr;初始化需要说明大小
* arr.size();
* arr.front();第一个
* arr.back();最后一个
* arr.data();传回数组的起点地址

```cpp
 qsort(begin,size,sizeof(type),compator);
```

计时程序
```cpp
timeStart=clock();
end=clock();
```

# 04

namespace 可以多用

## vector 动态数组
```cpp
vector<int> vec;
vec.push_back(2);//添加元素
//元素增长两倍增长
vec.size();
vec.front();
vec.back();
vec.data();//起始点的位置
//find(begin,end,target); find 的返回类型是一个iterator  顺序查找
//bsearch 二分查找
```

# 05

### list 双向链表

```cpp
list<string> c;
c.size();
c.max_size();//链表中最大容量？
c.front();
c.back();
//find()
c.sort()//容器自带的sort

```

### forward_list 单向链表

```cpp
forward_list<string> c;
c.max_size();
c.front();
//find 标准库提供的
//c.sort()
```

### slist 也是单向链表

```cpp
#include<ext/slist>
```


### deque 分段连续
```cpp
deque<string> c;
c.size();
c.front();
c.back();
c.max_size();
//find
//::sort() 用全局的sort 没有自己的sort
```

### stack
```cpp
stack.size();
stack.push();
stack.pop();
stack.top();
```

### queue

```cpp
queue.size();
queue.front();
queue.back();
queue.push();
queue.pop();
```

# 06
### multiset
```cpp
multiset.insert();
multiset.size();
multiset.max_size();
//::find() 标准库的find
//multiset.find();自己的find
```


### multimap

```cpp
multimap<long,string> mp;
mp.insert(pair<long,string>("aa",11));
//不能用下标进行数据的插入
mp.size();
mp.max_size();
mp.find(target);

```


### unordered_multiset

用hash 实现的集合
```cpp
insert();
size();
max_size();
bucket_count();//桶的数目
load_factor();//加载因子
max_buckeet_count();
max_load_factor();

//::find()
//find()
```


### unorder_multimap
    用hash 实现的map
    ```cpp
    ```

### set
    不可重复

### map 
    不可重复



    map/multimap 红黑树实现
    set/multimap 红黑树实现

    unordered_multimap/unordered_multiset 用hash 表实现
    unorder_map/unorder_set 用hash 表实现







































