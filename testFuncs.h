// Файл, содержащий функции для тестов
#ifndef TEST_FUNC_H
#define TEST_FUNC_H
#include<cmath>

template<typename Type>
Type defaultFunc(Type x, Type y){
    return 0.0;
}

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

// Второй тест из методички 
template<typename Type>
Type f2(Type x, Type y){
    return 0.0;
}

template<typename Type>
Type xi2(Type x, Type y){
    return 1 + y;
}

template<typename Type>
Type psi2(Type x, Type y){
    if (y == 0.0){
        return -1.0;
    }
    
    return 1.0;
}

template<typename Type>
Type U02(Type x, Type y){
    return 1.0 + y;
}
#endif