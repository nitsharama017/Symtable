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


TEST_CASE("(8) basic symtable test") 
{
	symtable<string, string> table;
	table.enterScope("Global");
	table.insert("i","int");

	table.enterScope("main");
	table.insert("j","char");
	table.insert("k","string");
	
	REQUIRE(table.curScope().Name == "main");
	string symbol;
	REQUIRE(table.lookup("j",symbol));
	REQUIRE(table.size() == 3);
    REQUIRE(table.numscopes() == 2);
	
	
}