#include <iostream>
#include <vector>
using namespace std;

//print2d matrix
void print2d(vector<vector<double>> values) {
    for(int i = 0; i < values.size(); i++) {
        for(int j = 0; j < values[i].size(); j++) {
            cout<<values[i][j]<<" ";
        }
        cout<<endl;
    }
}

//print1d matrix
void print1d(vector<double> values) {
    for(int i = 0; i < values.size(); i++) {
        cout<<values[i]<<" ";
    }
    cout<<endl;
}


vector<double> doLittles(vector<vector<double>> values) {
    int n = values.size();
    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U(n, vector<double>(n, 0));
    double sum;

    //calculating L and U matrices
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i <= j) {
                sum = 0;
                for(int k = 0; k < i; k++) {
                    sum += L[i][k] * U[k][j];
                }
                U[i][j] = values[i][j] - sum;
                if(i == j) L[i][j] = 1; 
                else L[i][j] = 0;
            } else {
                sum = 0;
                for(int k = 0; k < j; k++) {
                    sum += L[i][k] * U[k][j];
                }
                L[i][j] = (values[i][j] - sum) / U[j][j];
                U[i][j] = 0;
            }
        }
    }

    //calculating V matrix
    vector<double> V(n, 0);
    for(int i = 0; i < n; i++) {
        sum = 0;
        for(int j = 0; j < i; j++) {
            sum += V[j] * L[i][j];
        }
        V[i] = (values[i][n] - sum)/L[i][i];
    }

    vector<double> result(n, 0);
    for(int i = n - 1; i >= 0; i--) {
        sum = 0;
        for(int j = i + 1; j < n; j++) {
            sum += result[j] * U[i][j];
        }
        result[i] = (V[i] - sum) / U[i][i];
    }
    return result;
}


int main() {
    int n;
    cout<<"Enter the order n: ";
    cin>>n;
    vector<vector<double>> values;
    for(int i = 0; i < n; i++) {
        vector<double> temp;
        for(int j = 0; j < n+1; j++) {
            double x;
            cout<<"Enter the value of a["<<i<<"]["<<j<<"] : ";
            cin>>x;
            temp.push_back(x);
        }
        values.push_back(temp);
    }

    vector<double> result = doLittles(values);
    cout<<"The result is: "<<endl;
    for(int i = 0; i < result.size(); i++) {
        cout<<"x_"<<i+1<<" = "<<result[i]<<endl;
    }
}