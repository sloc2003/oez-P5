#include "Material.h"
#include <iostream>
#include <cmath>

using namespace std;


Material::Material(int ID)
	:materialID( ID )
{
	diameter = 0;
	cValue = 0;
	volume = 0;
	mass = 0;

	density = 0;
	yieldStress = 0;
	elasticity = 0;

	columnLength = 1.219;
	pi = 3.14159;
	criticalLoad = 350;
}

void Material::calculateMaterial(int ID, int userSy, int userDensity, int userElasticity ){
	Material::setMaterialID(ID);
	Material::setYieldStress(userSy);
	Material::setDensity(userDensity);
	Material::setElasticity(userElasticity);
	Material::setCValue();
	Material::setDiameter();
	Material::setVolume();
	Material::setMass();

	cout << "\n\n\tID\t = " << Material::getMaterialID() <<
			"\n\td\t = " << Material::getDiameter() << " m" << 
			"\n\tC\t = " << Material::getCValue() << " m^2" <<
			"\n\tVol\t = " << Material::getVolume() << " m^3" <<
			"\n\tMass\t = " << Material::getMass() << " Kg" << endl;
	if (isNewSmallest(mass))
	{
		smallestDiameter = diameter;
		smallestID = materialID;
		smallestMass = mass;
	}
	
	Material::displaySmallest();

}

void Material::setMaterialID(int ID){
	materialID = ID;
}

void Material::setDensity(int userDensity){
	density = userDensity;
}

void Material::setYieldStress(int userYieldStress){
	yieldStress = userYieldStress;
}

void Material::setElasticity(int userElasticity){
	elasticity = userElasticity;
}

void Material::setCValue(){
	cValue = ((yieldStress*columnLength*columnLength)/(2*pi*pi*elasticity))/1000;
}

void Material::setDiameter(){
	diameter = sqrt((4/(pi*yieldStress*1000))*(criticalLoad+pi*yieldStress*1000*cValue));
}

void Material::setVolume(){
	volume = pi*diameter*diameter*columnLength/4;
}

void Material::setMass(){
	mass = density*volume;
}

bool Material::isNewSmallest(double mass){
	if (materialID == 1){
		return true;
	} else if( mass < smallestMass )
		return true;
	return false;
}

void Material::displaySmallest() const{
	cout << endl;
	cout << "\tID for column with minimum mass\t\t= " << smallestID
		<< "\n\tDiameter for column with minimum mass\t= " << smallestDiameter << " m" 
		<< "\n\tMinimum mass of the column\t\t= " << smallestMass << " Kg" << endl;
}

int Material::getMaterialID() const {
	return materialID;
}

double Material::getDiameter() const {
	return diameter;
}

double Material::getCValue() const {
	return cValue;
}

double Material::getVolume() const {
	return volume;
}

double Material::getMass() const{
	return mass;
}