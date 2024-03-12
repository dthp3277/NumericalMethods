#include <iostream>

void eliminate(double** aug, unsigned int n, unsigned int curr, unsigned int i = 0) {
    if (i == n) return;
    if (i != curr) {
        double ratio = aug[i][curr] / aug[curr][curr];
        for (size_t j = 0; j < n + 1; j++) {
            aug[i][j] -= ratio * aug[curr][j];
        }
    }
    eliminate(aug, n, curr, i + 1);
}

// welp couldn't make it purely functional, the aug matrix gets mutated
// making it purely functional would require a lot of copying and memory allocation
double* gaussJordan_rec(double**aug, unsigned int n, unsigned int curr=0){
    if(curr==n){
        double* result = new double[n];
        for (size_t i = 0; i < n; i++)
        {
            result[i] = aug[i][n]/aug[i][i];
        }
        return result;
    }

    eliminate(aug, n, curr);
    return gaussJordan_rec(aug, n, ++curr);
}

int main(){
    unsigned int n;
    std::cout<<"Enter the number of equations: ";
    std::cin>>n;
    double** aug = new double*[n];
    for (size_t i = 0; i < n; i++)
    {
        aug[i] = new double[n+1];
        for (size_t j = 0; j < n+1; j++)
        {
            std::cin>>aug[i][j];
        }
    }
    double* result = gaussJordan_rec(aug, n);
    for (size_t i = 0; i < n; i++)
    {
        std::cout<<"x"<<i+1<<" = "<<result[i]<<std::endl;
        delete[] aug[i];
    }
    delete[] aug;
    delete[] result;
    return 0;
}