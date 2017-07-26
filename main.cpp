#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

class Point
{
  public:
    float x;
    float y;
    Point(float xx, float yy)
        : x(xx), y(yy)
    {
    }

    virtual void print()
    {
        cout << "in func print1123456" << endl;
    }
    virtual void none()
    {
        cout << "in func none" << endl;
    }
    virtual void m() { cout << "in func m" << endl; }

    void f()
    {
        cout << "in nonevirtaul func" << endl;
    }
};

typedef void (Point::*member_func)();
typedef void (*func)();

int main()
{
    printf("%d\n", &Point::y);
    Point *p = new Point(101.8, 206.230);

    char *baseAddr = (char *)p;
    float *px = (float *)(baseAddr + 8);
    cout << "p->x = " << *px << endl;
    float *py = (float *)(baseAddr + 12);
    cout << "p->y = " << *py << endl;

    intptr_t *vtable = (intptr_t *)*(intptr_t *)baseAddr;

    cout << "call func:" << endl;
    for (int i = 0; i < 3; i++)
    {
        func ff1 = (func) * (vtable + i);
        ff1();
    }

    cout << "exec end" << endl;

    //((Point*)0)->f();
    /*cout<<sizeof(Point)<<endl;
    float Point::*px = &Point::x;
    Point* p = new Point(1.0,2.0);
    cout<<px<<endl;
    printf("%p %p\n",&Point::m,p->*px);

    intptr_t ptr = *(intptr_t*)p;
    intptr_t vtb = *(intptr_t*)ptr;
    func f = (func)(vtb+8);

    intptr_t* ptr1 = (intptr_t*)*(intptr_t*)p;

    *(float*)(ptr1+1) = 99.99;
    cout<<p->x<<endl;

    intptr_t* pvt = (intptr_t*)(*ptr1);
    func f2 = (func)(pvt+11);
    printf("%p %p\n",f,f2);
    //f();
    cout<<"111111111111111"<<endl;
    f2();

    /*member_func f1 = &Point::m;
    printf("%p\n",f1);
    (p->*f1)();*/
    return 0;
}