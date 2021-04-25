# SGI_STL的学习

STL是C++标准库的一部分，占据了大部分的比例。STL借助模板把常用的数据结构及其算法都实现了一遍，且做到了数据结构和算法的分离。

STL有六大组件:

1. 容器(container)

容器可以分为序列容器(array（c++11)、vector、deque、List 和 Forward_List ) 和关联式容器(set / multiSet、 map / multiMap、 unordered set / multiSet、 unordered-map/multiMap)


2. 算法(algorithm)

STL常见的算法有sort，search，copy，erase，for_each，unique。

3. 迭代器(iterator)

迭代器是连接算法和容器的方法，是一种广义的指针，使得算法能够独立于容器进行设计。

4. 仿函数(functor)

搭配STL算法使用，泛化算法的操作

5. 配置器(allocator)

为容器提供空间配置和释放，对象构造和析构的服务，也是一个class template。

6. 配接器(adapter)

将一种容器修饰为功能不同的另一种容器。例如deque，在此基础上禁用一些deque的功能实现队列和栈，这就是一种配接器。
