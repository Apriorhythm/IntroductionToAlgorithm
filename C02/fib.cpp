/*
 * 函数大部分来自知乎
 */

#include <iostream>
#include <functional>
#define NDEBUG
#include <assert.h>


int fib(int n) {

    assert(n >= 0);

    std::function<int(int, int, int)> iter;
    iter = [n, &iter](int a, int b, int i) {
        if(i >= n)
            return a;
        else
            return iter(b, b + a, i + 1);
    };
    return iter(0, 1, 0);
}

int main()
{
    std::cout << fib(9) << std::endl;

    return 0;
}


/*

    1. assert()在条件成立下继续执行，否则形成错误信息并退出
    2. #define NDEBUG 加在#include <assert.h>前可以让程序不输出错误信息
    3. [n, $iter](int a, int b, int i) {}是lambda表达式
        其中n只可用不可修改，iter可修改
    4. std::function类似于函数指针

*/
