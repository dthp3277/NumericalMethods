#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<float>> inverse(vector<vector<float>> mat) {
    int n = mat.size();
    float factor;
    //creating augmented matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) mat[i].push_back(1);
            else mat[i].push_back(0);
        }
    }

    for(int j = 0; j < n; j++) {
        if(fabs(mat[j][j]) <= 0.00005) {
            cout<<"Pivot Element is Zero. "<<endl;
            exit(0);
        }
        for(int i = 0; i < n; i++) {

            if(i != j) {
                    factor = mat[i][j] / mat[j][j];
                    for(int k = 0; k < 2*n; k++) {
                        mat[i][k] = mat[i][k] - factor * mat[j][k];
                    }
            }
        }
    }

    vector<vector<float>> result(n, vector<float>(n, 0.0f));
    for(int i = 0; i < n; i++) {
        for(int j = n; j < 2*n; j++) {
            mat[i][j] = mat[i][j] / mat[i][i];
            //cout<<mat[i][j];
            result[i][j - n] = mat[i][j];
        }
        //cout<<endl;
    }

    return result;
}

void printResult(vector<vector<float>> result) {
    cout<<"The inverse is: "<<endl;
    int n = result.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
                cout<<result[i][j]<<'\t';
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<vector<float>> mat(n, vector<float>(n, 0.0f));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>mat[i][j];
        }
    }
    printResult(inverse(mat));
    return 0;
}
