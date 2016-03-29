

//CID -- unique chain id [string]
//NID -- nest id [0...N]
//Domain keyword
//dim - number of dimensions in the domain
//lbi - lower bound of dimension i
//ubi - upper bound of dimension i
//#pragma LoopChain CID NID Domain{dim,[(lb1,ub1),(lb2,ub2),...]} 

/*******************************************************************************
\file LCFactory_test.cpp
\autors Cathie Olschanowsky
\purpose
To perform unit testsing on the LCFactory code
\copyright
Copyright 2016 Colorado State University
*******************************************************************************/

#include "gtest/gtest.h"
#include "LC_factory.hpp"
#include <iostream>
#include <utility>

using namespace std;

TEST(PragmaParseTest, justPragmaTags) {

  // this is what would be pulled out of the Rose IR
  string test = "#pragma LoopChain test1 0 Domain{1,[(0,N)]}";

  // This is how we want the factory to be called
  LC_factory factory;
  factory.parse(test);

  // this should have created a single Loop Chain with a single
  // loop nest in it -- verify that that happened
  EXPECT_EQ(1,factory.get_lc_count() );
  string[] cids = factory.get_lc_cids();
  EXPECT_EQ(1,factory.get_lc_depth(cid[0]));
   
}
