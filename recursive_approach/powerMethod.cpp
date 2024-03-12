#include <iostream>
#include <cmath>
const double TOLERANCE = 0.00005;

double findAbsLargest(double* mat, unsigned int size){
    double largest = mat[0];
    for (size_t i = 0; i < size; i++)
    {
        if(std::abs(largest)<std::abs(mat[i])) largest = mat[i];
    }
    return largest;
}

double getAbsError(double* A, double* B, unsigned int size){
    double max_difference = 0.0;
    for (size_t i = 0; i < size; i++)
    {
        double d = std::abs(A[i] - B[i]);
        if(max_difference <d) max_difference = d;
    }
    return max_difference;
}


double powerMethod(double** A, unsigned int size, double* X = nullptr){
    if(X == nullptr){
        X = new double[size];
        for (size_t i = 0; i < size; i++)
        {
            X[i] = 1;
        }
    }

    double* matMul = new double[size];
    for (size_t i = 0; i < size; i++)
    {
        double sum = 0;
        for (size_t j = 0; j < size; j++)
        {
            sum += A[i][j] * X[j];
        }
        matMul[i] = sum;
    }

    double lambda = findAbsLargest(matMul, size);
    for (size_t i = 0; i < size; i++)
    {
        matMul[i] = matMul[i] / lambda;
    }
    
    double error = getAbsError(matMul, X, size);
    if (error < TOLERANCE) {
        delete[] matMul; 
        return lambda;
    }

    double result = powerMethod(A, size, matMul);
    delete[] matMul;
    return result;
}


int main(){
    double** matrix;
    unsigned int size;
    std::cout<<"Enter size of matrix: "<<std::endl;
    std::cin>>size;

    matrix = new double*[size];
    std::cout<<"Enter matrix: "<<std::endl;
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = new double[size];
        for (size_t j = 0; j < size; j++)
        {
            std::cin>>matrix[i][j];
        }   
    }

    std::cout<<"Largest eigenValue is: "<<powerMethod(matrix, size);

    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}