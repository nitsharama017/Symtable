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


TEST_CASE("(5) basic symtable test") 
{
	symtable<string, string> table;
	string symbol;
	table.enterScope("Global");
	table.insert("i","int");
    REQUIRE(table.lookup("i",symbol));
	REQUIRE(symbol=="int");
	table.enterScope("main");
	table.insert("j","char");
	table.insert("k","string");
	REQUIRE(table.lookup("j",symbol));
	REQUIRE(symbol=="char");
	REQUIRE(table.lookup("k",symbol));
	REQUIRE(symbol=="string");
	REQUIRE(!(table.lookup("j",symbol,symtable<string,string>::ScopeOption::GLOBAL)));
	//REQUIRE(symbol=="char");
	REQUIRE(!(table.lookup("k",symbol,symtable<string,string>::ScopeOption::GLOBAL)));
	REQUIRE(symbol=="string");
	REQUIRE(table.lookup("j",symbol,symtable<string,string>::ScopeOption::CURRENT));
	REQUIRE(table.lookup("k",symbol,symtable<string,string>::ScopeOption::CURRENT));
	table.exitScope();

	REQUIRE(!table.lookup("j",symbol));
	REQUIRE(table.size() == 1);
    REQUIRE(table.numscopes() == 1);
	
	
}