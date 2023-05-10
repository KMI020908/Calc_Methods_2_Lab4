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
    return 1.0 + y;
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
    return 1.0;
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


// Тест. Вариант 1
template<typename Type>
Type f5(Type x, Type y){
    return 2.0 * std::cos(2.0 * x);
}

template<typename Type>
Type xi5(Type x, Type y){
    if (x == 0){
        return y;
    }
    
    return 1.0 + y;
}

template<typename Type>
Type psi5(Type x, Type y){
    if (y == 0.0){
        return -1.0;
    }
    
    return 1.0;
}

template<typename Type>
Type U05(Type x, Type y){
    return 1.0;
}


// Тест. Вариант 9
template<typename Type>
Type f6(Type x, Type y){
    return (std::pow(x, 2.0) + std::pow(y, 2.0)) * std::sin(x * y);
}

template<typename Type>
Type xi6(Type x, Type y){
    if (x == 0){
        return 0.0;
    }
    
    return -std::sin(y);
}

template<typename Type>
Type psi6(Type x, Type y){
    if (y == 0.0){
        return x;
    }
    
    return -x * std::cos(x);
}

template<typename Type>
Type U06(Type x, Type y){
    return 1.0;
}
#endif