#include <iostream>
#include <limits>

// 模板函数示例：打印类型的最小值和最大值
template <typename T>
void printMinMax() {
    std::cout << "Type: " << typeid(T).name() << std::endl;
    std::cout << "sizeof: " << sizeof(T) << std::endl;
    std::cout << "Minimum: " << std::numeric_limits<T>::min() << std::endl;
    std::cout << "Maximum: " << std::numeric_limits<T>::max() << std::endl;
    std::cout << std::endl;
}

int main() {
    // 使用模板函数打印不同类型的最小值和最大值
    printMinMax<int>();
    printMinMax<float>();
    printMinMax<double>();
    printMinMax<char>();

    return 0;
}
