#include "vendor/sciplot.hpp"
using namespace sciplot;

#include <iostream>
#include <cmath>

#include "NodesGenerators.h"
#include "Interpolation.h"
#include "MyFunction.h"


double standardDeviation(vector<double> first, vector<double> second) {
// считает стандратное отклонение
    double intermediateSum = 0;
    for (size_t i = 0; i < first.size(); i++)
    {
        intermediateSum += pow(first[i] - second[i], 2);
    }
    return sqrt(intermediateSum / (first.size() - 1));
}

void runStep(const double step, double a, double b, Plot2D & plot, bool isPrintMyFunction) {
// интерполяция с равномерным шагом
// при выполнении метода строится график интерполяции и, если isPrintMyFunction == true, график исходной функции 
// на вход подаются: 
//                     1) шаг
//                     2) границы изменения переменной x [a,b]
//                     3) объект для создания графика
//                     4) isPrintMyFunction (см.выше)

    cout << endl;

    vector<double> nodesX = nodesStepGenerator(step, a, b); // list of x-coords of nodes
    vector<double> nodesY = getMyFunctionInNodes(nodesX); // list of y-coords of nodes

    vector<double> nodesMediumsX = getMediumsOfInterpolation(nodesX);

    vector<double> myNodesMediumsY = getMyFunctionAtMediums(nodesMediumsX);
    vector<double> interpolatedNodesMediumsY = getInterpolationAtMediums(nodesX, nodesY);

    cout << "Step: " << step << endl;
    cout << "x is in range [" << a << "; " << b << "]" << endl << endl;

    cout << "Calculated nodes coordinates: " << endl << endl;

    for (size_t i = 0; i < nodesX.size(); i++)
    {
        cout << "\t" << i + 1 << ". (" << nodesX[i] << "; " << nodesY[i] << ")" << endl;
    }

    cout << endl << "Calculated mediums of nodes for initial (left) and interpolated (right) functions: " << endl << endl;

    for (size_t i = 0; i < nodesMediumsX.size(); i++)
    {
        cout << "\t" << i + 1 << ". (" << nodesMediumsX[i] << "; " << myNodesMediumsY[i] << ")" << "\t" << "\t(" << nodesMediumsX[i] << "; " << interpolatedNodesMediumsY[i] << ")" << endl;
    }


    Vec x = linspace(a, b, 200);

    vector<double> xVals;
    for (size_t i = 0; i < x.size(); i++)
        xVals.push_back(x[i]);

    vector<double> interpolatedPoints = getInterpolationAtSet(xVals, nodesX, nodesY);
    vector<double> myFunctionPoints = getMyFunctionAtSet(xVals);

    double error = standardDeviation(interpolatedPoints, myFunctionPoints);

    cout << endl << "Standard deviation in step: " << error << endl;

    plot.xlabel("x");
    plot.ylabel("y");
    plot.xrange(a, b);
    plot.yrange(-2, 5);

    plot.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);

    if (isPrintMyFunction)
        plot.drawCurve(x, pow((sin(x - 2)), 5) + pow((cos(x / 10)), 7)).label("original");
    plot.drawCurveWithPoints(xVals, getInterpolationAtSet(xVals, nodesX, nodesY))
        .label(string("uniform interpolation with step = ") + to_string(step) + string("; standardDeviation = ") + to_string(error));
}

void runChebishev(const int n, double a, double b, Plot2D & plot, bool isPrintMyFunction) {
    // интерполяция с узлами Чебышева
    // при выполнении метода строится график интерполяции и, если isPrintMyFunction == true, график исходной функции 
    // на вход подаются: 
    //                     1) параметр n для узлов Чебышева
    //                     2) границы изменения переменной x [a,b]
    //                     3) объект для создания графика
    //                     4) isPrintMyFunction (см.выше)

    cout << endl;

    vector<double> nodesX = nodesChebishevGenerator(n, a, b); // list of x-coords of nodes
    vector<double> nodesY = getMyFunctionInNodes(nodesX); // list of y-coords of nodes

    vector<double> nodesMediumsX = getMediumsOfInterpolation(nodesX);

    vector<double> myNodesMediumsY = getMyFunctionAtMediums(nodesMediumsX);
    vector<double> interpolatedNodesMediumsY = getInterpolationAtMediums(nodesX, nodesY);

    cout << "Amount of nodes: " << n << endl;
    cout << "x is in range [" << a << "; " << b << "]" << endl << endl;

    cout << "Calculated nodes coordinates: " << endl << endl;

    for (size_t i = 0; i < nodesX.size(); i++)
    {
        cout << "\t" << i + 1 << ". (" << nodesX[i] << "; " << nodesY[i] << ")" << endl;
    }

    cout << endl << "Calculated mediums of nodes for initial (left) and interpolated (right) functions: " << endl << endl;

    for (size_t i = 0; i < nodesMediumsX.size(); i++)
    {
        cout << "\t" << i + 1 << ". (" << nodesMediumsX[i] << "; " << myNodesMediumsY[i] << ")" << "\t" << "\t(" << nodesMediumsX[i] << "; " << interpolatedNodesMediumsY[i] << ")" << endl;
    }

    Vec x = linspace(a, b, 200);

    vector<double> xVals;
    for (size_t i = 0; i < x.size(); i++)
        xVals.push_back(x[i]);

    vector<double> interpolatedPoints = getInterpolationAtSet(xVals, nodesX, nodesY);
    vector<double> myFunctionPoints = getMyFunctionAtSet(xVals);

    double error = standardDeviation(interpolatedPoints, myFunctionPoints);

    cout << endl << "Standard deviation in Chebishev: " << error << endl;

    plot.xlabel("x");
    plot.ylabel("y");
    plot.xrange(a, b);
    plot.yrange(-2, 5);

    plot.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);

    if (isPrintMyFunction)
        plot.drawCurve(x, pow((sin(x - 2)), 5) + pow((cos(x / 10)), 7)).label("original");
    plot.drawCurveWithPoints(xVals, getInterpolationAtSet(xVals, nodesX, nodesY))
        .label(string("interpolated (Chebishev) with ") + to_string(n) + string(" nodes") + string("; standardDeviation = ") + to_string(error));
}

int main()
{
    Plot2D plot;

    runStep(2, 0, 10, plot, true); // менять следует 1-й аргумент (меняет шаг между узлами)
    runChebishev(5, 0, 10, plot, false); // менять следует 1-й аргумент (степень n в узлах Чебышева)

    // Create figure to hold plot
    Figure fig = { {plot} };
    // Create canvas to hold figure
    Canvas canvas = { {fig} };
    // Show the plot in a pop-up window
    canvas.show();

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
