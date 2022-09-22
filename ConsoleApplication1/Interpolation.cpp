#include <iostream>
#include "Interpolation.h"

double basePolinomial(double x, vector<double> nodes, int i) {

    double res = 1;
    for (int j = 0; j < nodes.size(); j++) {
        if (i != j)
            res *= (x - nodes[j]) / (nodes[i] - nodes[j]);
    }
    return res;
}

double interpolationAtPoint(double x, vector<double> nodesX, vector<double> nodesY) {
    double res = 0;
    for (int i = 0; i < nodesX.size(); ++i) {
        res += nodesY[i] * basePolinomial(x, nodesX, i);
    }
    return res;
}

vector<double> getInterpolationAtSet(vector<double> set, vector<double> nodesX, vector<double> nodesY) {
    vector<double> res;

    for (size_t i = 0; i < set.size(); i++)
    {
        res.push_back(interpolationAtPoint(set[i], nodesX, nodesY));
    }
    return res;
}

vector<double> getMediumsOfInterpolation(vector<double> nodesX) {
    vector<double> mediums;
    for (size_t i = 1; i < nodesX.size(); i++)
    {
        double leftNode = nodesX[i - 1];
        double rightNode = nodesX[i];

        mediums.push_back((rightNode + leftNode) / 2);
    }
    return mediums;
}

vector<double> getInterpolationAtMediums(vector<double> nodesX, vector<double> nodesY) {
    // interpolation at mediums of interpolation nodes

    return getInterpolationAtSet(getMediumsOfInterpolation(nodesX), nodesX, nodesY);
}