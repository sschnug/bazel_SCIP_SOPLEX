/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                           */
/*                  This file is part of the examples to                     */
/*                         An introduction to SCIP                           */
/*                                                                           */
/*    Copyright (C) 2007 Cornelius Schwarz                                   */
/*                                                                           */
/*                  2007 University of Bayreuth                              */
/*                                                                           */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/**@file queens_main.cpp
 * @brief main file for the queens example
 * @author Cornelius Schwarz
 */

#include "queens.h"
#include <cstdlib>
#include <iostream>
#include "scip_exception.h"

using namespace std;
using namespace scipexamples;


/** main function for queens example */
int
main(
     int args,
     char ** argv
     )
{
   cout << "********************************************" << endl;
   cout << "* n-queens solver based on SCIP            *" << endl;
   cout << "*                                          *" << endl;
   cout << "* (c) Cornelius Schwarz (2007)             *" << endl;
   cout << "********************************************" << endl << endl;

   if (args < 2)
   {
      cerr << "call " << argv[0] << " <number of queens>" << endl;
      exit(1);
   }

   // get the number of queens for commandline
   size_t n = abs(atoi(argv[1])); /*lint !e732*/

   try
   {
      // initialize the queens solver
      QueensSolver solver(n);

      // solve the queens problem
      solver.solve();

      // display the solution on stdout
      solver.disp();

   } catch(const SCIPException& exc)
   {
      cerr << exc.what() << endl;
      exit((int) exc.getRetcode());
   }
   return EXIT_SUCCESS;
}