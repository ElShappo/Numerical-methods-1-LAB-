#pragma once

#include <vector>

using namespace std;

double myFunction(double x);
// вычислить значение исходной функции

vector<double> getMyFunctionAtSet(vector<double> set);
// вычислить значения исходной функции на заданном множестве

vector<double> getMyFunctionInNodes(vector<double> nodesX);
// вычислить значения исходной функции в узлах интерполяции

vector<double> getMyFunctionAtMediums(vector<double> nodesMediums);
// вычислить значения исходной функции в "серединных" точках (между узлами)
