#pragma once
#include <vector>

using namespace std;

vector<double> nodesStepGenerator(double step, double a, double b);
// генератор равномерно отстоящих узлов

vector<double> nodesChebishevGenerator(const int n, double a, double b);
// генератор узлов Чебышева

