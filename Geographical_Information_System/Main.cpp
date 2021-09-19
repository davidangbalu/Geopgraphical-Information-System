#include <string>
#include <iostream>
#include "BST.h"
#include <boost/chrono.hpp>
#include <boost/timer/timer.hpp>



using namespace std;

using namespace boost::timer;

int main() {

	BST bst = BST();

	boost:times

	cpu_timer cityInserts;

	bst.insert(City("Tokyo", make_pair(35.6762, 139.6503), 9273000, 26));
	bst.insert(City("Dublin", make_pair(53.3498, 6.2603), 1388000, 15.5));
	bst.insert(City("Hong Kong", make_pair(22.3193, 114.1694), 7451000, 29));
	bst.insert(City("Toronto", make_pair(43.6532, 79.3832), 2930000, 21));
	bst.insert(City("Johannesburg", make_pair(26.2041, 28.0473), 957441, 21));

	cpu_times cityInsertsElapsed = cityInserts.elapsed();

	bst.withinDistance(1000, make_pair(35.6762, 139.6503));

	cout << "Height: " << bst.height() << "\n";

	//test for duplicate
	bst.insert(City("Tokyo", make_pair(35.6762, 139.6503), 9273000, 26));

	bst.in();

	cout << "Check for Tokyo: " << bst.searchCity("Tokyo") << "\n";

	cout << "Check for Paris: " << bst.searchCity("Paris") << "\n";

	cout << "Check for Coordinate Tokyo: " << bst.searchCoord(make_pair(35.6762, 139.6503)) << "\n";

	cout << "Check for Coordinate Paris: " << bst.searchCoord(make_pair(40.6762, 139.1103)) << "\n";

	cout << "Deleting Dublin " << bst.delCityName("Dublin") << "\n";

	cout << "Deleting Johanesburg " << bst.delCoord(make_pair(26.2041, 28.0473)) << "\n";






	
}