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


TEST_CASE("(7) basic symtable test") 
{
	symtable<string, string> table;
	table.enterScope("Global");
	table.insert("i","int");
	table.insert("j", "char");
	table.insert("k","double");
	table.enterScope("main");
	table.insert("a","string");
	table.insert("b", "string");
	table.insert("c", "string");
	table.enterScope("void");
	table.insert("A","char");
	
	
	string symbol;
	REQUIRE(table.lookup("A",symbol,symtable<string,string>::ScopeOption::CURRENT));
	REQUIRE(!table.lookup("a",symbol,symtable<string,string>::ScopeOption::CURRENT));
	REQUIRE(table.lookup("a",symbol,symtable<string,string>::ScopeOption::ALL));
	REQUIRE(table.lookup("i",symbol,symtable<string,string>::ScopeOption::GLOBAL));
	REQUIRE(table.lookup("i",symbol,symtable<string,string>::ScopeOption::ALL));
	REQUIRE(!table.lookup("z",symbol,symtable<string,string>::ScopeOption::ALL));
	
}