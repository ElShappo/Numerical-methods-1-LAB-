#pragma once

#include <vector>
using namespace std;

double basePolinomial(double x, vector<double> nodes, int i);
// считает i-й базисный полином в точке x, на вход кроме того поступают x-координаты узлов

double interpolationAtPoint(double x, vector<double> nodesX, vector<double> nodesY);
// считает интерполяцию в точке x, на вход дополнительно поступают x- и y-координаты узлов, по которым определяется сама интерполированная функция

vector<double> getInterpolationAtSet(vector<double> set, vector<double> nodesX, vector<double> nodesY);
// считает интерполяцию на множестве точек set, на вход дополнительно поступают x- и y-координаты узлов, по которым определяется сама интерполированная функция

vector<double> getMediumsOfInterpolation(vector<double> nodesX);
// получить список "серединных" координат (между (Xi+Xi+1)/2 )

vector<double> getInterpolationAtMediums(vector<double> nodesX, vector<double> nodesY);
// вычислить значение интерполированной функции в "серединных" точках
