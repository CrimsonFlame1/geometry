//
//  main.cpp
//  practice2
//
//  Created by Crimson_Flame on 26/11/2020.
//  Copyright © 2020 Lee Zheng Shieng. All rights reserved.
//

#include <iostream>
using namespace std;

string option;
string shape;
double height;
double radius;
const double pi = 3.142857143;
double results;
double slength;
double base;


class io{
public:
    void printResults(float results) {
        if (option == "Area"){
            cout << "The area of the " << shape << ": " << results << endl;
        } else if (option == "Volume"){
            cout << "The volume of the " << shape << ": " << results << endl;
        }
    }
    
    void enterHeight() {
        cout << "Please enter height: " << flush;
        cin >> height;
    }
    void enterRadius() {
        cout << "Please enter radius: " << flush;
        cin >> radius;
    }
    
    void enterBase() {
        cout << "Please enter length of base: " << flush;
        cin >> base;
    }
    void cylinder() {
        enterHeight();
        enterRadius();
    }
    
    void cone() {
        enterRadius();
        cout << "Please enter slant length: " << flush;
        cin >> slength;
    }
    
    void sphere() {
        enterRadius();
    }
    
    void vCylinder() {
        enterRadius();
        enterHeight();
    }
    
    void vCone() {
        enterRadius();
        enterHeight();
    }
    
    void vSphere() {
        enterRadius();
    }
};


class findArea{
public:
    float areaCylinder() {
        double areaOfCrossSection = (2)*(pi)*(radius * radius);
        double middleArea = (2) * (pi) * (radius) * (height);
        double results = areaOfCrossSection + middleArea;
        return results;
    }
    
    float areaCone() {
        double baseArea = (pi) * (radius * radius);
        double surface = (pi) * (radius) * (slength);
        double results = baseArea + surface;
        return results;
    }
    
    float areaSphere() {
        double results = (4) * (pi) * (radius * radius);
        return results;
    }
};


class findVolume{
public:
    float volumeCylinder() {
        double areaBase = (pi) * (radius * radius);
        double results = areaBase * height;
        return results;
    }
    
    float volumeCone() {
        double results = (0.33333333333333) * (pi) * (radius * radius) * (height);
        return results;
    }
    
    float volumeSphere() {
        double results = (1.33333333333333) * (pi) * (radius * radius * radius);
        return results;
    }
};


class geometrySolver: public io, public findArea, public findVolume {
public:
    geometrySolver() {
        cout << "What would you like to find? Area or Volume: " << flush;
        cin >> option;
        cout << "Choose: Cylinder  Cone  Sphere --> " << flush;
        cin >> shape;
        if (option == "Area"){
            if (shape == "Cylinder") {
                cylinder();
                printResults(areaCylinder());
            }
            else if (shape == "Cone"){
                cone();
                printResults(areaCone());
            }
            else if (shape == "Sphere"){
                sphere();
                printResults(areaSphere());
            }
        } else if (option == "Volume") {
            if (shape == "Cylinder") {
                vCylinder();
                printResults(volumeCylinder());
            }
            else if (shape == "Cone") {
                vCone();
                printResults(volumeCone());
            }
            else if (shape == "Sphere") {
                vSphere();
                printResults(volumeSphere());
            }
        }
    }
};


int main(){
    
    bool con = 1;
    string decision;
    while (con) {
        geometrySolver q1;
        cout << "Do you wish to continue? no or yes >> " << flush;
        cin >> decision;
        if (decision == "no") {
            cout << "End of program.." << endl;
            con = 0;
        } else{
            continue;
        }
    }
    
    return 0;
}
