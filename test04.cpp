//
// A symtable unit test based on Catch framework
//
// << Akshaj Uppala >>
// U. of Illinois, Chicago
// CS 251, Spring 2020
// Project #03: symtable
//

#include <iostream>

#include "symtable.h"

#include "catch.hpp"

using namespace std;


TEST_CASE("(4) basic symtable test") 
{
	symtable<string, string> table;
	table.enterScope("Global");
	table.insert("i","int");
	table.exitScope();
	
	REQUIRE(table.size() == 0);
    REQUIRE(table.numscopes() == 0);
	
	
}