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

// Оценка порядка сходимости при разных sigma при известном аналитическом решении
template<typename Type>
void getCoverageEstimate(std::size_t numOfEq, Type(*realSol)(Type t, Type x, Type y), std::size_t numOfIt, Type L1, Type L2, Type timeEnd,
std::size_t numOfXIntervals, std::size_t numOfYIntervals, std::size_t numOfTIntervals, CONDS_FLAG condsX, CONDS_FLAG condsY, 
Type(*U0)(Type x, Type y), Type(*T)(Type x, Type y), Type(*Q)(Type x, Type y), Type(*f)(Type t, Type x, Type y)){ 
    std::string SOLUTION_FILE = "D:\\Calc_Methods_2\\Lab4\\coverageEst\\coverage" + std::to_string(numOfEq) + ".txt";
    getRealSolEstimatePoisson2DEq(SOLUTION_FILE, realSol, numOfIt, L1, L2, timeEnd, numOfXIntervals, numOfYIntervals, numOfTIntervals, condsX, condsY, U0, T, Q, f);
}

template<typename Type>
void getCoverageEstimateTau(std::size_t numOfEq, Type L1, Type L2, Type tau0, Type tauEnd, std::size_t tauIntervals,
std::size_t numOfXIntervals, std::size_t numOfYIntervals, CONDS_FLAG condsX, CONDS_FLAG condsY, 
Type(*U0)(Type x, Type y), Type(*T)(Type x, Type y), Type(*Q)(Type x, Type y), Type(*f)(Type x, Type y), Type eps){
    if (tauEnd > tau0){
        std::string SOLUTION_FILE = "D:\\Calc_Methods_2\\Lab4\\coverageTimeEst\\coverage" + std::to_string(numOfEq) + ".txt";
        std::string TAU_FILE = "D:\\Calc_Methods_2\\Lab4\\coverageTimeEst\\tau" + std::to_string(numOfEq) + ".txt";
        std::vector<Type> tauVec;
        std::vector<Type> errVec;
        Type tauStep = (tauEnd - tau0) / tauIntervals;
        for (std::size_t i = 0; i < tauIntervals; i++){
            tauVec.push_back(tau0 + i * tauStep);
            errVec.push_back(solve2DStationaryPoissonEquation(SOLUTION_FILE, L1, L2, tauVec[i], numOfXIntervals, numOfYIntervals, condsX, condsY, U0, T, Q, f, eps));
        }
        writeVectorFile(tauVec, TAU_FILE);
        writeVectorFile(errVec, SOLUTION_FILE);
    }
}

template<typename Type>
void temp_main(){
    std::size_t numOfEq;
    Type L1, L2, tau, eps, timeEnd;
    std::size_t numOfXIntervals, numOfYIntervals, numOfTIntervals;
    CONDS_FLAG condsX, condsY;
    Type (*U0)(Type x, Type y) = nullptr;
    Type (*T)(Type x, Type y) = nullptr;
    Type (*Q)(Type x, Type y) = nullptr;
    Type (*f)(Type x, Type y) = nullptr;
    Type (*F)(Type t, Type x, Type y) = nullptr;

    // Первый тест 
    numOfEq = 1;
    L1 = 1.0;
    L2 = 1.0;
    f = f1;
    T = xi1;
    Q = defaultFunc;
    U0 = U01;
    tau = 0.03;
    numOfXIntervals = 50;
    numOfYIntervals = 50;
    condsX = LT_RT;
    condsY = LT_RT;
    eps = 1e-2;
    //getPoisson2DEquationSolution(numOfEq, L1, L2, tau, numOfXIntervals, numOfYIntervals, condsX, condsY, U0, T, Q, f, eps);

    // Второй тест 
    numOfEq = 2;
    L1 = 1.0;
    L2 = 1.0;
    f = f2;
    T = xi2;
    Q = psi2;
    U0 = U02;
    tau = 0.03;
    numOfXIntervals = 50;
    numOfYIntervals = 50;
    condsX = LQ_RQ;
    condsY = LT_RT;
    eps = 1e-2;
    //getPoisson2DEquationSolution(numOfEq, L1, L2, tau, numOfXIntervals, numOfYIntervals, condsX, condsY, U0, T, Q, f, eps);
    //getCoverageEstimateTau(numOfEq, L1, L2, 0.001, 0.1, 20, numOfXIntervals, numOfYIntervals, condsX, condsY, U0, T, Q, f, eps);

    // Третий тест
    numOfEq = 3;
    L1 = 1.0;
    L2 = 1.0;
    f = f3;
    T = xi3;
    Q = psi3;
    U0 = U03;
    tau = 0.03;
    numOfXIntervals = 50;
    numOfYIntervals = 50;
    condsX = LT_RT;
    condsY = LQ_RQ;
    eps = 1e-2;
    //getPoisson2DEquationSolution(numOfEq, L1, L2, tau, numOfXIntervals, numOfYIntervals, condsX, condsY, U0, T, Q, f, eps);

    // Четвертый тест 
    numOfEq = 4;
    L1 = 1.0;
    L2 = 1.0;
    timeEnd = 1.0;
    F = f4;
    T = xi4;
    Q = defaultFunc;
    U0 = U04;
    numOfXIntervals = 10;
    numOfYIntervals = 10;
    numOfTIntervals = 10;
    condsX = LT_RT;
    condsY = LT_RT;
    eps = 1e-2;
    Type (*realSol)(Type, Type, Type) = [](Type t, Type x, Type y){return std::exp(-t) * std::sin(M_PI * x) * std::sin(M_PI * y);};
    //getCoverageEstimate(numOfEq, realSol, 4, L1, L2, timeEnd, numOfXIntervals, numOfYIntervals, numOfTIntervals, condsX, condsY, U0, T, Q, F);

    // Тест. Вариант 1
    numOfEq = 5;
    L1 = M_PI_2;
    L2 = 1.0;
    f = f5;
    T = xi5;
    Q = psi5;
    U0 = U05;
    tau = 0.03;
    numOfXIntervals = 50;
    numOfYIntervals = 50;
    condsX = LQ_RQ;
    condsY = LT_RT;
    eps = 1e-2;
    //getPoisson2DEquationSolution(numOfEq, L1, L2, tau, numOfXIntervals, numOfYIntervals, condsX, condsY, U0, T, Q, f, eps);

    // Тест. Вариант 9
    numOfEq = 6;
    L1 = 1.0;
    L2 = 1.0;
    f = f6;
    T = xi6;
    Q = psi6;
    U0 = U06;
    tau = 0.03;
    numOfXIntervals = 50;
    numOfYIntervals = 50;
    condsX = LQ_RQ;
    condsY = LT_RT;
    eps = 1e-2;
    //getPoisson2DEquationSolution(numOfEq, L1, L2, tau, numOfXIntervals, numOfYIntervals, condsX, condsY, U0, T, Q, f, eps);

}

int main(){
    temp_main<double>();
    return 0;
}