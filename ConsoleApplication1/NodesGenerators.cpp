#include "NodesGenerators.h"

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

//vector<double> nodesUniformGenerator(const int amount, double a, double b) {
//    double length = b - a;
//    double step = length / amount;
//    vector<double> nodes;
//    for (int i = 0; i < amount; ++i) {
//        nodes.push_back(step * i);
//    }
//    return nodes;
//}

vector<double> nodesStepGenerator(double step, double a, double b) {
    vector<double> nodes;
    double node = a;

    while (node <= b) {
        nodes.push_back(node);
        node += step;
    }
    return nodes;
}

vector<double> nodesChebishevGenerator(const int n, double a, double b) {
    vector<double> nodes;

    for (int m = 1; m <= n; ++m) {
        nodes.push_back((a + b) / 2 + (b - a) / 2 * cos(M_PI * (2 * m - 1) / (2 * n)));
    }

    return nodes;
}