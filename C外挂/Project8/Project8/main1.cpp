#include <iostream>
#include <limits>

// ģ�庯��ʾ������ӡ���͵���Сֵ�����ֵ
template <typename T>
void printMinMax() {
    std::cout << "Type: " << typeid(T).name() << std::endl;
    std::cout << "sizeof: " << sizeof(T) << std::endl;
    std::cout << "Minimum: " << std::numeric_limits<T>::min() << std::endl;
    std::cout << "Maximum: " << std::numeric_limits<T>::max() << std::endl;
    std::cout << std::endl;
}

int main() {
    // ʹ��ģ�庯����ӡ��ͬ���͵���Сֵ�����ֵ
    printMinMax<int>();
    printMinMax<float>();
    printMinMax<double>();
    printMinMax<char>();

    return 0;
}
