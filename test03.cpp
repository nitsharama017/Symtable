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


TEST_CASE("(3) basic symtable test") 
{
  symtable<string, string>  table;
  string symbol;
	
  REQUIRE(table.size() == 0);
  REQUIRE(table.numscopes() == 0);

  table.enterScope("global");
  
  table.insert("i", "int");
  table.insert("j", "double");
  table.insert("i","cout");
	
  REQUIRE(table.lookup("i", symbol));
//   REQUIRE(symbol == "cout");
//   REQUIRE(!(symbol == "int"));
	
  REQUIRE(table.size() == 2);
  REQUIRE(table.numscopes() == 1);
  
//   table.enterScope("x");
//   table.insert("k", "char");
  
//   REQUIRE(table.size() == 3);
//   REQUIRE(table.numscopes() == 2); 
  
//   //
//   // these lookups should both succeed:
//   //
//   string symbol;
  
//   REQUIRE(table.lookup("k", symbol));
//   REQUIRE(symbol == "char");
  
  
  
//   REQUIRE(table.lookup("j", symbol));
//   REQUIRE(symbol == "double");
  
//   //
//   // this lookup should return false:
//   //
  REQUIRE((!table.lookup("x", symbol)));
}

