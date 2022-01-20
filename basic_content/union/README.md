# UNION那些事

## 关于作者：

个人公众号：

![](../img/wechat.jpg)

联合（union）是一种**节省空间的特殊的类**，一个 union 可以有多个数据成员，但是**在任意时刻**只有**一个**数据成员可以有值。当某个成员被赋值后其他成员变为未定义状态。联合有如下特点：

- 默认访问控制符为 public
- 可以含有构造函数、析构函数
- 不能含有引用类型的成员
- 不能继承自其他类，不能作为基类
- 不能含有虚函数
- 匿名 union 在定义所在作用域可直接访问 union 成员
- 匿名 union 不能包含 protected 成员或 private 成员
- 全局匿名联合必须是静态（static）的

> self: [where](1) to use union

[functionality_of_union]: https://stackoverflow.com/questions/4788965/when-would-anyone-use-a-union-is-it-a-remnant-from-the-c-only-days/4825047

```c++
struct my_variant_t {
    int type;
    union {
        char char_value;
        short short_value;
        int int_value;
        long long_value;
        float float_value;
        double double_value;
        void* ptr_value;
    };
};
```
> self: The benefits are simple: there is one single data type to **handle all event types** without using unnecessary memory.
