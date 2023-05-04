#include<vector>
#include"methods.cpp"
#include"ioData.cpp"
#include<iomanip>
#include"testFuncs.h"
#include<algorithm>
#include<cstdio>

// Процедура для заполнения названий файла
void getFileNames(std::size_t numOfEq, std::string &SOLUTION_FILE, std::string &DATA_FILE, std::string &INTERVAL_FILE){
    SOLUTION_FILE = "D:\\Calc_Methods_2\\Lab4\\Solutions\\solution" + std::to_string(numOfEq) + ".txt";
    DATA_FILE = "D:\\Calc_Methods_2\\Lab4\\Solutions\\data" + std::to_string(numOfEq) + ".txt";
    INTERVAL_FILE = "D:\\Calc_Methods_2\\Lab4\\Solutions\\interval" + std::to_string(numOfEq) + ".txt";
}

// Решенние уравнения Пуассона
template<typename Type>
void getPoisson2DEquationSolution(std::size_t numOfEq, Type L1, Type L2, Type tau,
std::size_t numOfXIntervals, std::size_t numOfYIntervals, CONDS_FLAG condsX, CONDS_FLAG condsY, 
Type(*U0)(Type x, Type y), Type(*xi)(Type x, Type y), Type(*psi)(Type x, Type y), Type(*f)(Type x, Type y), Type eps){ 
    std::string SOLUTION_FILE;
    std::string DATA_FILE;
    std::string INTERVAL_FILE;
    std::vector<Type> dataVec = {L1, L2, tau, eps};
    std::vector<std::size_t> numOfIntervalsVec = {numOfXIntervals, numOfYIntervals};
    
    getFileNames(numOfEq, SOLUTION_FILE, DATA_FILE, INTERVAL_FILE);
    std::cout << "Количество итераций уравнения " << numOfEq << ":\t" << solve2DStationaryPoissonEquation(SOLUTION_FILE, L1, L2, tau, numOfXIntervals, numOfYIntervals, condsX, condsY, U0, xi, psi, f, eps) << '\n' << '\n';
    writeVectorFile(dataVec, DATA_FILE);
    writeVectorFile(numOfIntervalsVec, INTERVAL_FILE);
}

// Оценка сходимости при разных sigma при известном аналитическом решении
template<typename Type>
void getRealSpeedEstimate(std::size_t numOfEq, Type (*realSol)(Type t, Type x), Type a, Type L, Type timeEnd,
std::size_t numOfXIntervals, std::size_t numOfTimeIntervals, Type(*U0)(Type x), Type(*Ut0)(Type x), Type(*bound1)(Type t), Type(*bound2)(Type t)){ 
    std::string SOLUTION_FILE = "D:\\Calc_Methods_2\\Lab3\\speedEstCrossScheme\\speed" + std::to_string(numOfEq) + ".txt";
    getRealSpeedEstimateWaveEq(SOLUTION_FILE, realSol, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2);
}


template<typename Type>
void temp_main(){
    std::size_t numOfEq;
    Type L1, L2, tau, eps;
    std::size_t numOfXIntervals, numOfYIntervals;
    CONDS_FLAG condsX, condsY;
    Type (*U0)(Type x, Type y) = nullptr;
    Type (*T)(Type x, Type y) = nullptr;
    Type (*Q)(Type x, Type y) = nullptr;
    Type (*f)(Type x, Type y) = nullptr;

    // Первый тест 
    numOfEq = 1;
    L1 = 1.0;
    L2 = 1.0;
    f = f1;
    T = xi1;
    Q = defaultFunc;
    U0 = U01;
    tau = 0.1;
    numOfXIntervals = 20;
    numOfYIntervals = 20;
    condsX = LT_RT;
    condsY = LT_RT;
    eps = 1e-2;
    getPoisson2DEquationSolution(numOfEq, L1, L2, tau, numOfXIntervals, numOfYIntervals, condsX, condsY, U0, T, Q, f, eps);

    // Второй тест
    numOfEq = 2;
    L1 = 1.0;
    L2 = 1.0;
    f = f1;
    T = xi2;
    Q = psi2;
    U0 = U02;
    tau = 0.1;
    numOfXIntervals = 10;
    numOfYIntervals = 10;
    condsX = LT_RT;
    condsY = LQ_RQ;
    eps = 1e-2;
    //getPoisson2DEquationSolution(numOfEq, L1, L2, tau, numOfXIntervals, numOfYIntervals, condsX, condsY, U0, T, Q, f, eps);
}

int main(){
    temp_main<double>();
    
    return 0;
}