#include <iostream>
#include <iomanip>
#include "main.h"
using namespace std;

int main()
{    
    int ID = 0;
    double Sy = 0;
    double density = 0;
    double E = 0;
    cout << "Enter ID: ";
    cin >> ID;
    Material material1(ID);
    
    cout << "\nMaterial ID is " << material1.getMaterialID();
    cout << fixed;
    while (ID != 0){
        cout << "\nEnter Sy: ";
        cin >> Sy;
        material1.setYieldStress(Sy);
        
        cout << "\nEnter Density: ";
        cin >> density;
        
        material1.setDensity(density);
        

        
        cout << "\nEnter E: ";
        cin >> E;
        
        material1.setElasticity(E);
        
        material1.calculateMaterial();
        
        cout << "\n\nID\t = " << material1.getMaterialID() <<
            "\nd\t = " << material1.getDiameter() <<
            "\nC\t = " << material1.getCValue() <<
            "\nVol\t = " << material1.getVolume() <<
            "\nMass\t = " << material1.getMass() << endl;
        
        cout << "\nEnter ID: ";
        cin >> ID;
        
        material1.setMaterialID(ID);

    }
}