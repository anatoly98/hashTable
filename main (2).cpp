
#include <windows.h>
#include <iostream>
#include <iomanip>
#include "md5.h"
#include "map.h"

using namespace::std;





int main() {


	MAP map;

	map.add("Paul Di'Anno");
	
	 map.add("Steve Harris");
	
	 map.add("Adrian Smith");
	 map.add("Bruce Dickinson");
	 map.add("Nicko McBrain");
	 map.add("Janick Gers");
	 
	 bool test_one = map.contain("Paul Di'Anno");
	
	 map.del("Paul Di'Anno");

	 bool test_two = map.contain("Bruce Dickinson");
	 bool test_free = map.contain("Paul Di'Anno");
	
	
return 0;
}

