#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void printTable(vector<vector<double>> values) {   
    for(int i = values.size(), k = 0; i > 0; i--, k++) {

        for(int j = 0; j < i; j++) {
            cout<<values[j][k]<<'\t';
        }
        cout<<endl;
    }
}

vector<vector<double>> differenceTable(vector<pair<double, double>> data) {
    int n = data.size();
    vector<vector<double>> table(n, vector<double>(n, 0));
    for(int i = 0; i < n; i++) table[0][i] = data[i].second;
    for(int j = n-1, c = 1; j > 0; j--, c++) {
        for(int i = 0; i < j; i++) {
            table[c][i] = table[c-1][i+1] - table[c-1][i];
        }
    }
    return table;
}
//newton's forward interpolation
double forwardInterpolation(vector<pair<double, double>> data, double x) {
    auto table = differenceTable(data);
    int i = 0;
    int index = 0;
    double x0 = data[0].first;
    double h = data[1].first - data[0].first;
    int n = data.size();
    for(int i = 1; i < n; i++) {
        if(x < data[i].first) break;   
        x0 = data[i].first;
        index = i;
    }

    double prod = 1, sum = 0, term;
    double p = (x - x0)/h;

    for(int i = 0; i < n - index; i++) {
        term = table[i][index] * prod / tgamma(i + 1);
        sum += term;
        prod *= (p - i);
    }
    return sum;
}

//newton's backward interpolation
double backwardInterpolation(vector<pair<double, double>> data, double x) {
    auto table = differenceTable(data);
    int n = data.size();
    int i = 0;
    int index = n -1;
    double xN = data[n].first;
    double h = data[1].first - data[0].first;
    for(int i = n-1; i > 0; i--) {
        if(x > data[i].first) break;   
        xN = data[i].first;
        index = i;
    }

    double prod = 1, sum = 0, term;
    double p = (x - xN)/h;
    int ind = index;

    for(int i = 0; i < ind + 1; i++, index--) {
        term = table[i][index] * prod / tgamma(i + 1);
        sum += term;
        prod *= (p + i);
    }
    return sum;
}


int main() {
    vector<pair<double, double>> data;
    int n;
    double x, y;
    cout<<"Enter the number of data: ";
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>x>>y;
        data.push_back(pair<double, double>(x, y));
    }
    cout<<"Enter the point at which you'd interpolate: ";
    cin>>x;
    cout<<"The interpolated value is: "<<backwardInterpolation(data, x);
    return 0;
}