#include <iostream>

double productCalculation(double** data, unsigned int n, double x, unsigned int i,unsigned int j){
    if(j >= n) return 1;
    if(i == j) return productCalculation(data,n, x, i, j+1);
    return (x - data[j][0]) / (data[i][0] - data[j][0]) * productCalculation(data,n, x, i, ++j);
}

double lagrangesInterpolate(double** data, unsigned int n, double x, unsigned int i){
    if(i >= n) return 0;
    return productCalculation(data,n, x, i,0) * data[i][1] + lagrangesInterpolate(data,n, x, ++i);
}
int main(){
    double x;
    unsigned int n;
    std::cout<<"Enter number of data: ";
    std::cin>>n;

    double** data = new double*[n];
    std::cout<<"Enter data points: "<<std::endl;
    for (size_t i = 0; i < n; i++)
    {
        data[i] = new double[2];
        for (size_t j = 0; j < 2; j++)
        {
            std::cin>>data[i][j];  
        }
    }
    std::cout<<"Enter the point at which you want to interpolate: ";
    std::cin>>x;

    double result = lagrangesInterpolate(data, n, x, 0);
    std::cout<<"The interpolated value is: "<<result<<std::endl;

    for (size_t i = 0; i < n; i++)
    {
        delete[] data[i];
    }
    delete[] data;
    
}