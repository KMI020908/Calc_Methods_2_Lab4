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
    return 1.0 + y +  x;
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
    return 1.0;
}


// Третий тест из методички 
template<typename Type>
Type f3(Type x, Type y){
    return -4.0;
}

template<typename Type>
Type xi3(Type x, Type y){
    if (y == 0){
        return std::pow(x, 2.0);
    }
    
    return 1.0 + std::pow(x, 2.0);
}

template<typename Type>
Type psi3(Type x, Type y){
    if (x == 0.0){
        return 0.0;
    }
    
    return 2.0;
}

template<typename Type>
Type U03(Type x, Type y){
    return x * x + y * y;
}


// Тест для проверки сходимости
template<typename Type>
Type f4(Type t, Type x, Type y){
    return (2.0 * M_PI * M_PI - 1.0) * std::exp(-t) * std::sin(M_PI * x) * std::sin(M_PI * y);
}

template<typename Type>
Type xi4(Type x, Type y){
    return 0.0;
}

template<typename Type>
Type U04(Type x, Type y){
    return std::sin(M_PI * x) * std::sin(M_PI * y);
}
#endif