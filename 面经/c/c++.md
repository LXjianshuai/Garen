##### 1. c++const关键字？c语言中const关键字？
在c语言中const其实是可以被修改的
```c
{
    int b[3];
    const int a = 5;
    b[4] = 6;
    int *p = &a;
    *p = 8;
}
```

##### 2. static关键字
1.修饰普通变量，影响生命周期
2.修饰普通函数，仅该文件可调用
3.修饰成员变量，不同对象共享一个，且不需要创建对象就可以访问该成员
4.修饰成员函数，不需要生成对象即可访问该函数，但是静态成员函数不能访问非静态成员

##### 3. volatile

每次访问时都必须从内存中取出值（没有被 volatile 修饰的变量，可能由于编译器的优化，从 CPU 寄存器中取值）

##### 4. #pragma pack(n)和内存对齐
为什么需要内存对齐？
通常总线被设计成传送定长的字节块计算机的内存访问是以块为单位（4字节*8=32位）（8字节*8=64位）。
合理的内存对齐可以提高内存访问的效率，减少CPU访问内存的次数。
合理的内存对齐可以减少内存碎片，提高内存的使用效率。

在c/c++中，结构体/类的成员变量是如何进行内存对齐的？
```c
#include<stdio.h>

typedef struct A {
    char kk;
    int a;
    char ll;
}A;

typedef struct B {
    int c;
    char kk;
    char ll;
}B;

int main()
{
    printf("size of A %ld \n", sizeof(A));
    printf("size of B %ld \n", sizeof(B));
    return 0;
}
//输出结果
//size of A 12
//size of B 8
```

##### 5. 如何用c实现c++面向对象特性

封装、继承、多态

##### 6. 智能指针
C++ 11

    shared_ptr
    unique_ptr
    weak_ptr
    auto_ptr（被 C++11 弃用）

