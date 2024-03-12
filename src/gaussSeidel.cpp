//gauss siedel method
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<float> gaussSeidel(vector<vector<float>> coeffs) {
    int n = coeffs.size();
    vector<float> result(n, 0.0f);
    vector<float> temp(n, 0.0f);
    float sum;
    int iterations = 0;
    while(true) {
        for(int i = 0; i < n; i++) {
            sum = 0.0f;
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    sum+=coeffs[i][j]*result[j];
                }
            }
            temp[i] = (coeffs[i][n] - sum) / coeffs[i][i];
        }
    
        iterations++;
            cout<<"Iterations : "<<iterations<<endl;
            for(int i = 0; i < n; i++) {
                cout<<"x"<<i+1<<" = "<<temp[i]<<endl;
            }
        
        if(iterations > 1) {
            float error = 0.0f;
            for(int i = 0; i < n; i++) {
                error+=fabs(temp[i] - result[i]);
            }
            // cout<<"Error : "<<error<<endl;
            if(error < 0.0001) {
                break;
            }
        }
        result = temp;
    }
    return result;
}

int main() {
    int n;
    cout<<"Enter the number of equations : ";
    cin>>n;
    vector<vector<float>> coeffs(n, vector<float>(n+1, 0.0f));
    cout<<"Enter the coefficients of the equations : "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<"Enter a["<<i<<"]["<<j<<"] : ";
            cin>>coeffs[i][j];
        }
        cout<<"Enter the constant of "<<i+1<<"th row : ";
        cin>>coeffs[i][n];
    }
    vector<float> result = gaussSeidel(coeffs);
    cout<<"The solution is : "<<endl;
    for(int i = 0; i < n; i++) {
        cout<<"x"<<i+1<<" = "<<result[i]<<endl;
    }
    return 0;
}

// Output: