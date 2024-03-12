#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<float> gaussElim(vector<vector<float>> coeffs) {
    float factor;
    int n = coeffs.size();
    vector<float> result(n, 0);
    for(int j = 0; j < n - 1; j++) {
        //cout<<"ma eta aaye hai"<<endl;
        if(fabs(coeffs[j][j]) <= 0.0005) {
            cout<<"Pivot Element is Zero. "<<endl; //naive elimination
            exit(0);
        }
        for(int i = j+1; i < n; i++) {
            cout<<"I'm checking a["<<i<<"]["<<j<<"] = "<<coeffs[i][j]<<endl;
            if(i != j) {
                factor = coeffs[i][j] / coeffs[j][j];
                for(int k = 0; k < n+1; k++) {
                    coeffs[i][k] = coeffs[i][k] - factor * coeffs[j][k];
                }
            }
        }
    }



    //backwards substitution code
    float SOP;
    for(int i = n - 1; i >= 0; i--) {
        SOP = 0.0f;
        for(int j = i + 1; j < n; j++) {
            SOP+=coeffs[i][j]*result[j];
        }
        result[i] = (coeffs[i][n] - SOP)/(coeffs[i][i]);
    }
    return result;
}

void printResult(vector<float> res) {
    for(int i = 0; i < res.size(); i++) {
        cout<<"x"<<i+1<<" = "<<res[i]<<endl;
    }
}

//not to write


int main() {
    int n;
    cin>>n;
    vector<vector<float>> coeffs(n, vector<float>(n+1, 0.0f));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<"Enter a["<<i<<"]["<<j<<"] : ";
            cin>>coeffs[i][j];
        }
        cout<<"Enter the constant of "<<i+1<<"th row : "<<endl;
        cin>>coeffs[i][n];
    }



    vector<float> res = gaussElim(coeffs);

    printResult(res);
    cin.get();
    return 0;
}
