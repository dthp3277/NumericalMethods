#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>

using namespace std;

vector<double> fitCurves(vector<pair<float, float>> data) {

    double Sy = 0, Sx = 0, Sxy = 0, Sx2 = 0;
    int n = data.size();
    for(int i = 0; i < data.size(); i++) {
        Sy += data[i].second;
        Sx += data[i].first;
        Sxy += data[i].first * data[i].second;
        Sx2 += pow(data[i].first, 2);
    }

    double det = (n * Sx2 - Sx * Sx);
    if(fabs(det) <= 0.000005)
        throw string("Determinant is Zero lol.");

    double a, b;
    a = (Sy * Sx2 - Sxy * Sx) / det;
    b = (n * Sxy - Sx * Sy) / det;

    vector<double> a_and_b;
    a_and_b.push_back(a);
    a_and_b.push_back(b);

    return a_and_b;
}

vector<double> fitCurvesExp(vector<pair<float, float>> data) {
    double Sy = 0, Sx = 0, Sxy = 0, Sx2 = 0;
    int n = data.size();
    for(int i = 0; i < data.size(); i++) {
        data[i].second = log(data[i].second);
        Sy += data[i].second;
        Sx += data[i].first;
        Sxy += data[i].first * data[i].second;
        Sx2 += pow(data[i].first, 2);
    }

    double det = (n * Sx2 - Sx * Sx);
    if(fabs(det) <= 0.000005)
        throw string("Determinant is Zero lol.");

    double a, b;
    a = (Sy * Sx2 - Sxy * Sx) / det;
    b = (n * Sxy - Sx * Sy) / det;
    a = exp(a);
    vector<double> a_and_b;
    a_and_b.push_back(a);
    a_and_b.push_back(b);

    return a_and_b;
}

void printData(vector<pair<float, float>> data) {
    for(int i = 0; i < data.size(); i++) {
        cout<<data[i].first<<" "<<data[i].second<<endl;
    }
}

int main() {
    vector<pair<float, float>> data;
    float x, y;
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    for(int i = 0; i < n; i++) {
        cout<<"Enter x"<<i+1<<": ";
        cin>>x;
        cout<<"Enter y"<<i+1<<": ";
        cin>>y;
        data.push_back(pair<float, float>(x, y));
    }

    try {
        vector<double> answer = fitCurves(data);
        cout<<"Linear: y = "<<answer[0]<<" + "<<answer[1]<<"x"<<endl;
        answer = fitCurvesExp(data);
        cout<<"Exponential: y = "<<answer[0]<<" ^ "<<answer[1]<<"x"<<endl;
    } catch(std::string error) {
        cout<<error;
        exit(0);
    }
    return 0;
}
