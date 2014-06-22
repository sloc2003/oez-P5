class Material{
public:
	explicit Material(int);				// default constructor
	// @param: int materialID

	void calculateMaterial(int, int, int, int);			// calculates



private:
	void setMaterialID(int);			// sets materialID
	// @param: int materialID                                    
	void setDensity(int);           // sets density
	// @param: int densitiy

	void setYieldStress(int);       // sets yieldStress
	// @param: int yieldStress

	void setElasticity(int);         // sets elasticity
	// @param: int elasticity

	double getDiameter() const;       // returns diameter
	double getCValue() const;         // returns cValue
	double getVolume() const;         // returns volume
	double getMass() const;           // returns mass
	int getMaterialID () const;    // returns materialID

	void setDiameter();             // sets diameter
	void setCValue();               // sets cValue
	void setVolume();               // sets volume
	void setMass();                 // sets mass

	bool isNewSmallest(double);		// test for new smallest mass
												// @param: double mass

	void displaySmallest() const;

	int materialID;
	double diameter;
	double cValue;
	double volume;
	double mass;

	int smallestID;
	double smallestDiameter;
	double smallestMass;

	int density;
	int yieldStress;
	int elasticity;

	double columnLength;
	double pi;
	double criticalLoad;
};
