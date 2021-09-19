#pragma once
#include <string>

using namespace std;

class City
{
	
	friend class TreeNode;
	friend class BST;
	friend ostream& operator<<(std::ostream& str, const City& cityIn);

public:
	City(string city, pair <double, double> coordinates, int population, double yearAvgTemp);
	~City();
	bool operator<(City city) const;
	bool operator>(City city) const;

private:
	string cityName;
	pair <double, double> coordinates;
	int population;
	double yearAvgTemp;
};
