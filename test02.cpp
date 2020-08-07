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


TEST_CASE("(2) basic symtable test") 
{
  symtable<string, string>  table;
  
  REQUIRE(table.size() == 0);
  REQUIRE(table.numscopes() == 0);

  table.enterScope("global");
  
  table.insert("i", "int");
  table.insert("j", "double");
  
	
//   REQUIRE(table.size() == 2);
//   REQUIRE(table.numscopes() == 1);
  
  
  table.enterScope("x");
  table.insert("k", "char");
  
//   REQUIRE(table.size() == 1);
//   REQUIRE(table.numscopes() == 1); 
  
  //
  // these lookups should both succeed:
  //
  string symbol;
  table.exitScope();	
  REQUIRE((!table.lookup("k", symbol)));
  //REQUIRE(symbol == "char");
  
  REQUIRE(table.lookup("i", symbol));
  REQUIRE(symbol == "int");
  
  REQUIRE(table.lookup("j", symbol));
  REQUIRE(symbol == "double");
  
  //
  // this lookup should return false:
  //
  REQUIRE((!table.lookup("x", symbol)));
}

