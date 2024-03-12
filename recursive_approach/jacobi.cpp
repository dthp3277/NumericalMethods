#include <iostream>
#include <cmath>

double getAbsError(double* A, double* B, unsigned int size){
    double max_difference = 0.0;
    for (size_t i = 0; i < size; i++)
    {
        double d = std::abs(A[i] - B[i]);
        if(max_difference <d) max_difference = d;
    }
    return max_difference;
}

double* jacobi(double** aug, unsigned int n, double* x = nullptr){
     if (x == nullptr) {
        x = new double[n]();
    }

    double* x_n = new double[n];
    
    for (size_t i = 0; i < n; i++)
    {
        double s =0;
        for (size_t j = 0; j < n; j++)
        {
            if (i==j) continue;
            s+=aug[i][j]*x[j];
        }
        x_n[i] = (aug[i][n] - s)/aug[i][i];
    }
    double error = getAbsError(x, x_n, n);
    delete[] x;
    if (error < 0.0005){
        return x_n;
    }
    return jacobi(aug, n, x_n);
}

int main(){
    unsigned int n;
    std::cout << "Enter the number of equations: ";
    std::cin >> n;
    double** aug = new double*[n];
    for (size_t i = 0; i < n; i++)
    {
        aug[i] = new double[n+1];
        for (size_t j = 0; j < n+1; j++)
        {
            std::cin >> aug[i][j];
        }
    }
    double* result = jacobi(aug, n);
    std::cout << "The solution is: "<<std::endl;
    for (size_t i = 0; i < n; i++)
    {
        std::cout << result[i] << " "<<std::endl;
    }
    std::cout << std::endl;
    
    for (size_t i = 0; i < n; i++)
    {
        delete[] aug[i];
    }
    delete[] aug;
    delete[] result;
    return 0;
}