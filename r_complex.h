//
// Created by Athena on 22/11/2017.
//

#ifndef COMPLEX_R_COMPLEX_H
#define COMPLEX_R_COMPLEX_H

#include <iostream>
#include <cmath>

template <typename T> class u_complex;

template <typename T>
class u_complex {
public:
    u_complex() = default;
    u_complex(const T &r, const T &i) : re(r), im(i) { }
    u_complex(const u_complex<T>& v1) : re(v1.real()), im(v1.image()) { }
    T real() const { return re; }
    T image() const { return im; }
    void show() const {
        std::cout << "(" << re << "," << im << ")" << std::endl;
    }

    u_complex<T> conj() const {
        u_complex<T> v1(re, -im);
        return v1;
    }

    T abs() const {
        return hypot(re, im);
    }

    T norm() const {
        return re * re + im * im;
    }

    T arg() const {
        return atan2(im, re);
    }

    //polar
    //proj


    template <class U> u_complex& operator=(const u_complex&);
    template <class U> u_complex& operator+=(const u_complex&);
    template <class U> u_complex& operator-=(const u_complex&);
    template <class U> u_complex& operator*=(const u_complex&);
    template <class U> u_complex& operator/=(const u_complex&);


    template <class U> u_complex& operator=(const u_complex<U> &v1)
    {
        re = v1.real();
        im = v1.image();
        return *this;
    }

    template <class U> u_complex& operator+=(const u_complex<U> &v1)
    {
        //u_complex<T> v3(v1.real() + v2.real(), v1.image() + v2.image());
        re = re + v1.real();
        im = im + v1.image();
        return *this;
    }

    template <class U> u_complex& operator-=(const u_complex<U> &v1)
    {
        //u_complex<T> v3(v1.real() - v2.real(), v1.image() - v2.image());
        re = re - v1.real();
        im = im - v1.image();
        return *this;
    }

    template <class U> u_complex& operator*=(const u_complex<U> &v1)
    {
        re = v1.real()*re - v1.image()*im;
        im = v1.image()*re + v1.real()*im;
        return *this;
    }

    template <class U> u_complex& operator/=(const u_complex<U> &v1)
    {
        re = (re*v1.real() + im*v1.image()) / (v1.real()*v1.real() + v1.image()*v1.image());
        im = (im*v1.real() - re*v1.image()) / (v1.real()*v1.real() + v1.image()*v1.image());
        return *this;
    }


private:
    T re = 0;   // real part
    T im = 0;   // image part

//friend std::ostream &print(std::ostream&, const u_complex<T>&);
};

template <class T> std::ostream &print(std::ostream&, const u_complex<T>&);
template <class T> u_complex<T> operator+(const u_complex<T>&, const u_complex<T>&);
template <class T> u_complex<T> operator+(const T&, const u_complex<T>&);
template <class T> u_complex<T> operator+(const u_complex<T>&, const T&);
template <class T> u_complex<T> operator-(const u_complex<T>&, const u_complex<T>&);
template <class T> u_complex<T> operator-(const T&, const u_complex<T>&);
template <class T> u_complex<T> operator-(const u_complex<T>&, const T&);
template <class T> u_complex<T> operator*(const u_complex<T>&, const u_complex<T>&);
template <class T> u_complex<T> operator*(const T&, const u_complex<T>&);
template <class T> u_complex<T> operator*(const u_complex<T>&, const T&);
template <class T> u_complex<T> operator/(const u_complex<T>&, const u_complex<T>&);
template <class T> u_complex<T> operator/(const T&, const u_complex<T>&);
template <class T> u_complex<T> operator/(const u_complex<T>&, const T&);
template <class T> u_complex<T> operator+(const u_complex<T>&);
template <class T> u_complex<T> operator-(const u_complex<T>&);
template <class T> bool operator==(const u_complex<T>&, const u_complex<T>&);
template <class T> bool operator!=(const u_complex<T>&, const u_complex<T>&);



/*template <class T>
u_complex<T>& u_complex::operator=(const u_complex<T> &v1)
{
    re = v1.real();
    im = v1.image();
    return *this;
}*/

template <class T>
std::ostream &print(std::ostream &os, const u_complex<T> &v)
{
    os << "(" << v.real() << "," << v.image() << ")" << std::endl;
    // os << "(" << v.re << "," << v.im << ")" << std::endl;
    return os;
}

template <class T>
u_complex<T> operator+(const u_complex<T> &v1, const u_complex<T> &v2)
{
    u_complex<T> v3(v1.real() + v2.real(), v1.image() + v2.image());
    return v3;
}

template <class T>
u_complex<T> operator+(const T &t, const u_complex<T> &v1)
{
    u_complex<T> v3(v1.real() + t, v1.image());
    return v3;
}

template <class T>
u_complex<T> operator+(const u_complex<T> &v1, const T &t)
{
    u_complex<T> v3(v1.real() + t, v1.image());
    return v3;
}

template <class T>
u_complex<T> operator-(const u_complex<T> &v1, const u_complex<T> &v2)
{
    u_complex<T> v3(v1.real() - v2.real(), v1.image() - v2.image());
    return v3;
}

template <class T>
u_complex<T> operator-(const T &t, const u_complex<T> &v1)
{
    u_complex<T> v3(t - v1.real(), 0 - v1.image());
    return v3;
}

template <class T>
u_complex<T> operator-(const u_complex<T> &v1, const T &t)
{
    u_complex<T> v3(v1.real() - t, v1.image());
    return v3;
}

template <class T>
u_complex<T> operator*(const u_complex<T> &v1, const u_complex<T> &v2)
{
    T re = v1.real()*v2.real() - v1.image()*v2.image();
    T im = v1.image()*v2.real() + v1.real()*v2.image();
    u_complex<T> v3(re, im);
    return v3;
}

template <class T>
u_complex<T> operator*(const T &t, const u_complex<T> &v1)
{
    T re = t*v1.real() - 0*v1.image();
    T im = 0*v1.real() + t*v1.image();
    u_complex<T> v3(re, im);
    return v3;
}

template <class T>
u_complex<T> operator*(const u_complex<T> &v1, const T &t)
{
    T re = t*v1.real() - 0*v1.image();
    T im = 0*v1.real() + t*v1.image();
    u_complex<T> v3(re, im);
    return v3;
}

template <class T>
u_complex<T> operator/(const u_complex<T> &v1, const u_complex<T> &v2)
{
    T re = (v1.real()*v2.real() + v1.image()*v2.image()) / (v2.real()*v2.real() + v2.image()*v2.image());
    T im = (v1.image()*v2.real() - v1.real()*v2.image()) / (v2.real()*v2.real() + v2.image()*v2.image());
    u_complex<T> v3(re, im);
    return v3;
}

template <class T>
u_complex<T> operator/(const T &t, const u_complex<T> &v1)
{
    T re = (t*v1.real() + 0*v1.image()) / (v1.real()*v1.real() + v1.image()*v1.image());
    T im = (0*v1.real() - t*v1.image()) / (v1.real()*v1.real() + v1.image()*v1.image());
    u_complex<T> v3(re, im);
    return v3;
}

template <class T>
u_complex<T> operator/(const u_complex<T> &v1, const T &t)
{
    T re = (v1.real()*t) / (t*t);
    T im = (v1.image()*t) / (t*t);
    u_complex<T> v3(re, im);
    return v3;
}

template<class T> u_complex<T> operator+(const u_complex<T> &v1)
{
    return v1;
}

template<class T> u_complex<T> operator-(const u_complex<T> &v1)
{
    u_complex<T> v2(-v1.real(), -v1.image());
    return v2;
}

template <class T>
bool operator==(const u_complex<T> &v1, const u_complex<T> &v2)
{
    return v1.real()==v2.real()&&v1.image()==v2.image();
}

template <class T>
bool operator!=(const u_complex<T> &v1, const u_complex<T> &v2)
{
    return v1.real()!=v2.real()||v1.image()!=v2.image();
}

/*template <class T>
u_complex<T>& u_complex::operator+=(const u_complex<T> &v1)
{
    //u_complex<T> v3(v1.real() + v2.real(), v1.image() + v2.image());
    re = re + v1.real();
    im = im + v1.image();
    return *this;
}

template <class T>
u_complex<T>& u_complex::operator-=(const u_complex<T> &v1)
{
    //u_complex<T> v3(v1.real() - v2.real(), v1.image() - v2.image());
    re = re - v1.real();
    im = im - v1.image();
    return *this;
}

template <class T>
u_complex<T>& u_complex::operator*=(const u_complex<T> &v1)
{
    re = v1.real()*re - v1.image()*im;
    im = v1.image()*re + v1.real()*im;
    return *this;
}

template <class T>
u_complex<T>& u_complex::operator/=(const u_complex<T> &v1)
{
    re = (re*v1.real() + im*v1.image()) / (v1.real()*v1.real() + v1.image()*v1.image());
    im = (im*v1.real() - re*v1.image()) / (v1.real()*v1.real() + v1.image()*v1.image());
    return *this;
}*/


#endif      //COMPLEX_R_COMPLEX_H
