#include<vector>
#include"methods.cpp"
#include"ioData.cpp"
#include<iomanip>
#include"testFuncs.h"
#include<algorithm>
#include<cstdio>

// Процедура для заполнения названий файла
void getFileNames(std::size_t numOfEq, std::string &SOLUTION_FILE, std::string &DATA_FILE, std::string &INTERVAL_FILE){
    SOLUTION_FILE = "D:\\Calc_Methods_2\\Lab3\\CrossScheme\\solution" + std::to_string(numOfEq) + ".txt";
    DATA_FILE = "D:\\Calc_Methods_2\\Lab3\\CrossScheme\\data" + std::to_string(numOfEq) + ".txt";
    INTERVAL_FILE = "D:\\Calc_Methods_2\\Lab3\\CrossScheme\\interval" + std::to_string(numOfEq) + ".txt";
}

// Решенние уравнений при разных sigma
template<typename Type>
void getWaveEquationSolution(std::size_t numOfEq, Type a, Type L, Type timeEnd,
std::size_t numOfXIntervals, std::size_t numOfTimeIntervals,  Type(*U0)(Type x), Type(*Ut0)(Type x), Type(*bound1)(Type t), Type(*bound2)(Type t), Type x0 = 0.0){ 
    std::string SOLUTION_FILE;
    std::string DATA_FILE;
    std::string INTERVAL_FILE;
    std::vector<Type> dataVec = {a, L, timeEnd, x0};
    std::vector<std::size_t> numOfIntervalsVec = {numOfXIntervals, numOfTimeIntervals};
    
    getFileNames(numOfEq, SOLUTION_FILE, DATA_FILE, INTERVAL_FILE);
    solveWaveEquation(SOLUTION_FILE, a, L, timeEnd, numOfXIntervals, numOfTimeIntervals, U0, Ut0, bound1, bound2, x0);
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
    Type a, L, timeEnd;
    std::size_t numOfXIntervals, numOfTimeIntervals;
    Type (*U0)(Type x) = nullptr;
    Type (*Ut0)(Type t) = nullptr;
    Type (*bound1)(Type t) = nullptr;
    Type (*bound2)(Type t) = nullptr;
}

int main(){
    temp_main<double>();
    return 0;
}