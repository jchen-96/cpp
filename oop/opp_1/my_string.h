#ifndef __MYSTRING__
#define __MYSTRING__
#include <iostream>
using namespace std;
#include <string.h>

class String
{
  public:
  //声明的时候不需要进行初始化，真是日了狗了
    String(const char *cstr);
    String(const String &str);            //拷贝构造
    String &operator=(const String &str); //拷贝赋值

    ~String();                                 //析构函数
    char *get_c_str() const { return m_data; } //一般的成员函数,注意const

  private:
    char *m_data;
};

inline String::String(const char *cstr = 0)
{
    if (cstr)
    {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}
inline String::~String()
{
    delete[] m_data;
}
inline String::String(const String &str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}
inline String &String::operator=(const String &str)
{
    //取地址
    // !!!!!!!!!!!检测是不是自我赋值
    if (this == &str)
        return *this;
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

inline ostream &operator<<(ostream &os, const String &s)
{
    os << s.get_c_str();
    return os;
}

#endif