// 防卫式的声明
#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

// 前置声明
#include<iostream>
using namespace std;

class complex;
complex &
__doapl(complex *ths, const complex &r);

class complex
{
  public:
    //构造函数最好使用初始化列表,能加快速度
    complex(double r = 0, double i = 0) : re(r), im(i) {}

    // 设置为成员函数和非成员函数都可以，成员函数会带一个默认的this 指针
    complex &operator+=(const complex &);

    //函数里面不会改变数据，最好加上const
    double real() const { return re; }
    double imag() const { return im; }

  private:
    double re, im;

    // 设置为友元函数，可以直接取private 数据，this 是一个指针，所以第一个参数是一个指针类
    friend complex &__doapl(complex *, const complex &);
};

// 是成员函数，左边是默认的this 指针，不会改变改变右边这个函数的值。所以要加const
// 传出去的数据不是在函数里面创建的，所以可以直接传reference
inline complex &
complex::operator+=(const complex &r)
{
    //this 函数是成员函数自带的指针
    return __doapl(this, r);
}

//左边的参数会发生变化，所以不能加const

inline complex &
__doapl(complex *ths, const complex &r)
{
    ths->re += r.re;
    ths->im += r.im;

    // ths是指针，解指针之后就是返回的一个值，作为引用是没有问题的
    return *ths;
}

// 全局函数

// !!!!!!!!!!!!!!!会返回一个全新的对象，不能返回引用,必须返回值
inline double
real(const complex &x) { return x.real(); }
inline double
imag(const complex &y) { return y.imag(); }


//加法，如果设置为成员函数，只能复数加复数
inline complex
operator+(const complex &x, const complex &y)
{
    return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex
operator+(const double x,const complex &y){
    return complex(x+real(y),imag(y));
}

inline complex
operator+(const complex &y,const double x){
    return  complex(x+real(y),imag(y));
}


// 输出流的重载,写成非成员函数
ostream &
operator << (ostream& os,const complex & x){
    return os<<"("<<real(x)<<","<<imag(x)<<")"<<endl;
}


#endif
