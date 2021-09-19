#include "City.h"
#include <iostream>

using namespace std;

City::City(string city, pair<double, double> coordinates, int population, double yearAvgTemp)
{
	this->cityName = city;
	this->coordinates = coordinates;
	this->population = population;
	this->yearAvgTemp = yearAvgTemp;
}

City::~City()
{
}

bool City::operator<(City city) const
{
	return cityName.compare(city.cityName);
}

bool City::operator>(City city) const
{
	return cityName.compare(city.cityName);
}


ostream& operator<<(ostream& os, const City& city)
{
	os << "City: " + city.cityName << "\n";
	os << "Coordinates: " << city.coordinates.first << "  " << city.coordinates.second << "\n";
	os << "Population: " << city.population << "\n";
	os << "Average Yearly Temperature: " << city.yearAvgTemp << "\n";
	return os;
}