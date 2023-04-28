// Файл, содержащий функции для тестов
#ifndef TEST_FUNC_H
#define TEST_FUNC_H
#include<cmath>

// Первый тест из методички 
template<typename Type>
Type f1(Type x, Type y){
    return 0.0;
}

template<typename Type>
Type xi1(Type x, Type y){
    return 1.0;
}

template<typename Type>
Type U01(Type x, Type y){
    Type L1 = 1.0;
    Type L2 = 1.0;
    if (x == L1 || y == L2 || x == 0.0 || y == 0.0){
        return 1.0;
    }
    return 2.0;
}
#endif