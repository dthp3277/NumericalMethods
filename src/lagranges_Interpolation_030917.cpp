#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

double lagrangesInterpolate(vector<pair<double, double>> data, double xP) {
    int n = data.size();
    double product, sum = 0.0f;
    for(int i = 0; i < n; i++) {
        product = 1.0f;
        for(int j = 0; j < n; j++) {
            if(i != j)
            product *= (xP - data[j].first)/(data[i].first - data[j].first);
        }
        product *= data[i].second;
        sum += product;
        cout<<"in iteration "<<i<<" the product is: "<<product<<endl;
    }
    return sum;
}


int main() {
    int n;
    double xP, x, y;
    vector<pair<double, double>> data;
    cout<<"Enter the no of data items: ";
    cin>>n;
    cout<<"Enter the data: ";
    for(int i = 0; i < n; i++) {
        cin>>x>>y;
        data.push_back(pair<double, double>(x, y));
    }
    cout<<"Enter the value at which to find the interpolated value: ";
    cin>>xP;
    cout<<"The interpolated value is: "<<lagrangesInterpolate(data, xP);
    return 0;
}


/*

2nd Degree: y = x^2 - 2 * x + 1
n = 6
Data:
1	0
2	1
3	4
6	25
9	64
10	81
Interpolating Value: 6.5
Interpolated value: 30.25

3rd Degree: y = x^3+x^2+3*x+5
Enter the no of data items: 10
Enter the data: 1 10
3 50
4 97
10 1135
15 3650
60 219785
75 427730
76 444985
80 518645
90 737375
Enter the value at which to find the interpolated value: 20
The interpolated value is: 8465
*/
