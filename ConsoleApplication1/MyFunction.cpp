#include "MyFunction.h"
#include <iostream>

double myFunction(double x) {
// 2nd variant
    return pow((sin(x - 2)), 5) + pow((cos(x / 10)), 7);
}

vector<double> getMyFunctionAtSet(vector<double> set) {
    vector<double> res;

    for (size_t i = 0; i < set.size(); i++)
    {
        res.push_back(myFunction(set[i]));
    }
    return res;
}

vector<double> getMyFunctionInNodes(vector<double> nodesX) {
    return getMyFunctionAtSet(nodesX);
}

vector<double> getMyFunctionAtMediums(vector<double> nodesMediums) {
    return getMyFunctionAtSet(nodesMediums);
}