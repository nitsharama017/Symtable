#include <iostream>
#include <string>
#include "symtable.h"

using namespace std;

TEST_CASE("(0)initially empty")
{
	symtable<string, string> table;
	
	REQUIRE(table.size() == 0);
	REQUIRE(table.numscopes() == 0);
}
