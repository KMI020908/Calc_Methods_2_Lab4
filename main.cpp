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
    solve2DStationaryPoissonEquation(SOLUTION_FILE, L1, L2, tau, numOfXIntervals, numOfYIntervals, condsX, condsY, U0, xi, psi, f, eps);
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
    Type (*xi)(Type x, Type y) = nullptr;
    Type (*psi)(Type x, Type y) = nullptr;
    Type (*f)(Type x, Type y) = nullptr;

    // Первый тест 
    numOfEq = 1;
    L1 = 1.0;
    L2 = 1.0;
    f = f1;
    xi = xi1;
    psi = defaultFunc;
    U0 = U01;
    tau = 0.5;
    numOfXIntervals = 10;
    numOfYIntervals = 20;
    condsX = LT_RT;
    condsY = LT_RT;
    eps = 1e-2;
    getPoisson2DEquationSolution(numOfEq, L1, L2, tau, numOfXIntervals, numOfYIntervals, condsX, condsY, U0, xi, psi, f, eps);
}

int main(){
    temp_main<double>();
    /*
    size_t n = 5; 
    size_t m = 8;
    std::vector<std::vector<double>> m1(n);
    std::vector<std::vector<double>> m2(n);

    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m; j++){
            m1[i].push_back(i + j);
            m2[i].push_back(i - j + 10);
        }
    }

    std::cout << m1;
    std::cout << '\n' << '\n';
    std::cout << m2;
    std::cout << '\n' << '\n';
    
    std::cout << normC2Ddiff(m1, m2);
    
   std::vector<double> diag(5), lDiag(4), uDiag(4), fVec(5);
   std::size_t dim = 4;
   diag[0] = 1.0; diag[1] = 2.0; diag[2] = 7.0; diag[3] = 9.0;
   lDiag[0] = 3.0; lDiag[1] = 5.0; lDiag[2] = 4.0;
   uDiag[0] = 3.0; uDiag[1] = 3.0; uDiag[2] = 8.0;
   std::vector<double> solVec(7);
   for (std::size_t i = 0; i < dim; i++){
    fVec[i] = i + 1;
   }
   
   uniDimTridiagonalAlgoritm(diag, lDiag, uDiag, fVec, solVec, dim);
   std::cout << solVec << '\n';
   */

    return 0;
}