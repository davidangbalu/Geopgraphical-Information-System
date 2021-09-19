#pragma once
#include "TreeNode.h"

using namespace std;

class BST
{

public:
	BST();
	~BST();

	void insert(City city);

	bool searchCity(string cityName);
	bool searchCoord(pair<double, double> coordinates);

	bool delCityName(string cityName);
	bool delCoord(pair<double, double> coordinates);

	int height();

	void pre();
	void in();
	void post();

	void withinDistance(int distance, pair<double, double> coordinates);

private:
	TreeNode* root;
	void insert(TreeNode* node, TreeNode* newCity);

	bool searchCity(TreeNode* root, string cityName);
	bool searchCoord(TreeNode* root, pair<double, double> coordinates);

	TreeNode* delCityName(TreeNode* root, string cityName);
	bool delCoord(TreeNode* root, pair<double, double> coordinates);

	int height(TreeNode* root);

	void pre(TreeNode* node);
	void in(TreeNode* root);
	void post(TreeNode* node);

	TreeNode* min(TreeNode* node);

	void withinDistance(TreeNode* node, int distance, pair<double, double> coordinate);
};