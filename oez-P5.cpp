/* oez-P5
Student name:			Oscar Zavala
Student ID:				0198873
EGR-123-001				Spring 2014
Programing Exercise: Programming Exercise 5
Assigned:				04-08-2014
Due:						05-01-2014
Program Description:	This program uses <Material.h> to find the material that
							will result in a column with the smallest possible mass
							to carry a given load.
Developed on:			04-21-2014
Modified on:			04-27-2014
*/

#include <iostream>
#include <iomanip>
#include "Material.h"
using namespace std;

int main()
{    
	int ID = 0;
	int Sy = 0;
	int density = 0;
	int E = 0;
	cout << "Enter ID             : ";
	cin >> ID;
	Material material1(ID);
	cout << fixed;
	while (ID != 0){
		cout << "Enter Sy        <MPa>: ";
		cin >> Sy;


		cout << "Enter Density<Kg/m^3>: ";
		cin >> density;

		cout << "Enter E         <GPa>: ";
		cin >> E;

		material1.calculateMaterial(ID,Sy,density,E);

		cout << "\nEnter ID: (0 to terminate) ";
		cin >> ID;

	}
}