#include "math.h"
#include "iostream"
#include "HelperFunctions.cpp"


class Methods {
public:
    static double TaylorSeriesSinx(double x, double a, int iterationNumber) {

        //a point
        //x is the value of taylor series;
        double res = sin(x);
        double temp = 0;
        for (int i = 1; i < iterationNumber; i++) {
            switch (i % 4)
            {
            case 1:
                temp = cos(x);

            case 2:
                temp = -sin(x);
            case 3:
                temp = -cos(x);
            case 0:
                temp = sin(x);

            default:
                break;
            }
            res = res + (temp * pow((x - a), i) / HelperFunctions::factorial(i));
        }
        return res;
    }
    static double TaylorSeriesCosx(double x, double a, int iterationNumber) {

        //a point
        //x is the value of taylor series;
        double res = cos(x);
        double temp = 0;
        for (int i = 1; i < iterationNumber; i++) {
            switch (i % 4)
            {
            case 1:
                temp = -sin(x);

            case 2:
                temp = -cos(x);
            case 3:
                temp = sin(x);
            case 0:
                temp = cos(x);

            default:
                break;
            }
            res = res + (temp * pow((x - a), i) / HelperFunctions::factorial(i));
        }
        return res;
    }
    static double BisectionMethod(double a, double b, double error, double (*function)(double)) {

        double xLower = a > b ? b : a;
        double xUpper = b >= a ? b : a;
        double middle = (xUpper - xLower) / 2;
        if ((function(a) > 0 && function(b) > 0) || (function(a) < 0 && function(b) < 0)) {
            //Intermediate theorem fails.
            cout << "Unable to apply" << endl;
        }
        else {
            double temp = 0;
            while (true) {

                if (function(middle) < 0) xLower = middle;
                else if (function(middle > 0)) xUpper = middle;
                else if (function(middle == 0)) break;
                if (abs(temp - middle) < error) break;
                temp = middle;
                middle = (xUpper + xLower) / 2;


            }
        }
        return middle;

    }
    static double RegulaFalsiMethod(double x0, double x1, double error, double (*function1)(double)) {

        double c = x1;
        double temp = c;
        while (true) {
            cout << x0 << " " << x1 << endl;
            cout << c << endl;
            temp = c;
            c = x0 - ((x1 - x0) / (function1(x1) - function1(x0))) * function1(x0);
            if (c == 0) break;
            else if (function1(x0) * function1(x1) < 0) x1 = c;
            else x0 = c;
            if (abs(temp - c) < error) break;


        }
        return c;

    }
    static double NewtonMethod(double x0, double error, double (*function1)(double), double (*derivative)(double)) {
        double temp = x0;
        while (true) {
            temp = x0;
            x0 = x0 - function1(x0) / derivative(x0);
            if (abs(temp - x0) < error) break;

        }

        return x0;

    }
    static double SecantMethod(double x0, double x1, double error, double (*function1)(double)) {
        double temp = x1;
        while (true) {
            temp = x1;
            x1 = x1 - function1(x1) * (x1 - x0) / (function1(x1) - function1(x0));
            x0 = temp;
            if (abs(x0 - x1) < error) break;

        }

        return x1;

    }

};