#include "BST.h"
#include <algorithm>
#include <iostream>
#include <math.h>
#include <cmath> 

using namespace std;

BST::BST() : root(nullptr) {}

BST::~BST()
{
	delete root->leftptr;
	delete root->rightptr;
}

void BST::insert(City city)
{
	if (searchCoord(city.coordinates))
	{
		cout << "Already Exists" << endl;
	}
	else
	{
		TreeNode* newNode = new TreeNode(city);
		if (root == nullptr) {
			root = newNode;
		}
		else {
			insert(newNode, root);
		}
	}
}


void BST::insert(TreeNode* newNode, TreeNode* node)
{
	if (newNode->city < node->city) {
		if (node->leftptr == nullptr) {
			node->leftptr = newNode;
		}
		else {
			insert(newNode, node->leftptr);
		}
	}
	else if (newNode->city > node->city) {
		if (node->rightptr == nullptr) {
			node->rightptr = newNode;
		}
		else {
			insert(newNode, node->rightptr);
		}
	}
}


bool BST::delCityName(string cityName)
{
	return delCityName(root, cityName) != nullptr;
}

TreeNode* BST::delCityName(TreeNode* node, string cityName)
{
	if (node != nullptr)
	{
		if (node->city.cityName.compare(cityName) > 0)
		{
			node->leftptr = delCityName(node->leftptr, cityName);
		}
		else if (node->city.cityName.compare(cityName) < 0)
		{
			node->rightptr = delCityName(node->rightptr, cityName);
		}
		else
		{
			if (node->isLeaf())
			{
				delete node;
				node = nullptr;
			}
			else if (node->leftptr == nullptr)
			{
				TreeNode* temp = node;
				node = node->rightptr;
				delete temp;

			}
			else if (root->rightptr == nullptr)
			{
				TreeNode* temp = node;
				node = node->leftptr;
				delete temp;
			}
			else
			{
				TreeNode* temp = min(node->rightptr);
				node->city = temp->city;
				node->rightptr = delCityName(node->rightptr, temp->city.cityName);
			}
		}
	}
	return node;
}


bool BST::delCoord(pair<double, double> coordinates)
{
	return delCoord(root, coordinates);
}

bool BST::delCoord(TreeNode* node, pair<double, double> coordinates)
{
	if (node != nullptr)
	{
		if (node->city.coordinates.first == coordinates.first && node->city.coordinates.second == coordinates.second)
		{
			return delCityName(root, node->city.cityName) != nullptr;
		}
		return delCoord(node->leftptr, coordinates) || delCoord(node->rightptr, coordinates);
	}
	return false;
}


bool BST::searchCity(string cityName)
{
	return searchCity(root, cityName);
}

bool BST::searchCity(TreeNode* node, string cityName)
{
	if (node == nullptr)
	{
		return false;
	}
	else if (node->city.cityName.compare(cityName) == 0)
	{
		return true;
	}
	else if (node->city.cityName.compare(cityName) > 0)
	{
		return searchCity(node->leftptr, cityName);
	}
	else
	{
		return searchCity(node->rightptr, cityName);
	}
}


bool BST::searchCoord(pair<double, double> coordinates)
{
	return searchCoord(root, coordinates);
}

bool BST::searchCoord(TreeNode* node, pair<double, double> coordinates)
{
	if (node != nullptr)
	{
		if (node->city.coordinates.first == coordinates.first && node->city.coordinates.second == coordinates.second)
		{
			return true;
		}
		return (searchCoord(node->leftptr, coordinates) || searchCoord(node->rightptr, coordinates));
	}
	return false;
}


int BST::height()
{
	return height(root);
}

int BST::height(TreeNode* node)
{
	if (node == nullptr)
	{
		return -1;
	}
	return max(height(node->leftptr), height(node->rightptr)) + 1;

}

void BST::pre()
{
	pre(root);
}

void BST::pre(TreeNode* node)
{
	if (node != nullptr)
	{
		cout << node->city << "\n";
		pre(node->leftptr);
		pre(node->rightptr);

	}
}

void BST::in()
{
	in(root);
}

void BST::in(TreeNode* node)
{
	if (node != nullptr)
	{
		in(node->leftptr);
		cout << node->city << "\n";
		in(node->rightptr);
	}
}

void BST::post()
{
	post(root);
}

void BST::post(TreeNode* node)
{
	if (node != nullptr)
	{
		post(node->leftptr);
		post(node->rightptr);
		cout << node->city << "\n";
	}
}

TreeNode* BST::min(TreeNode* node)
{
	while (node->leftptr != nullptr)
	{
		node = node->leftptr;
	}
	return node;
}

/***************************************************************************************
*    Title: Haversine formula
*    Author: Nik, MrTJ
*    Date:  Apr 18 '12, edited 	Apr 19 '17
*    Code version: 1.0
*    Availability: https://stackoverflow.com/a/10205532/8674939

/**
* Returns the distance between two points on the Earth.
* Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
* @param lat1d Latitude of the first point in degrees
* @param lon1d Longitude of the first point in degrees
* @param lat2d Latitude of the second point in degrees
* @param lon2d Longitude of the second point in degrees
* @return The distance between the two points in kilometers
****************************************************************************************/

const double earthRadiusKm = 6371.0;
const double PI = 3.14;

double deg2rad(double deg) {
	return (deg * PI / 180);
}

double rad2deg(double rad) {
	return (rad * 180 / PI);
}

double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
	double lat1r, lon1r, lat2r, lon2r, u, v;
	lat1r = deg2rad(lat1d);
	lon1r = deg2rad(lon1d);
	lat2r = deg2rad(lat2d);
	lon2r = deg2rad(lon2d);
	u = sin((lat2r - lat1r) / 2);
	v = sin((lon2r - lon1r) / 2);
	return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

void BST::withinDistance(int distance, pair<double, double> coordinates)
{
	withinDistance(root, distance, coordinates);
}

void BST::withinDistance(TreeNode* node, int distance, pair<double, double> coordinates)
{
	if (node != nullptr)
	{
		withinDistance(node->leftptr, distance, coordinates);
		double distance = distanceEarth(node->city.coordinates.first, node->city.coordinates.second, coordinates.first, coordinates.second);
		if (distance < distance)
		{
			cout << "Distance is  " << distance << "\n";
			cout << "The City details are " << "\n";
			cout << node->city << "\n" << "\n";
		}
		withinDistance(node->rightptr, distance, coordinates);
	}
}