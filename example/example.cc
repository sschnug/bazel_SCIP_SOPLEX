/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 /*                                                                           */
 /*                  This file is part of the class library                   */
 /*       SoPlex --- the Sequential object-oriented simPlex.                  */
 /*                                                                           */
 /*  Copyright 1996-2022 Zuse Institute Berlin                                */
 /*                                                                           */
 /*  Licensed under the Apache License, Version 2.0 (the "License");          */
 /*  you may not use this file except in compliance with the License.         */
 /*  You may obtain a copy of the License at                                  */
 /*                                                                           */
 /*      http://www.apache.org/licenses/LICENSE-2.0                           */
 /*                                                                           */
 /*  Unless required by applicable law or agreed to in writing, software      */
 /*  distributed under the License is distributed on an "AS IS" BASIS,        */
 /*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. */
 /*  See the License for the specific language governing permissions and      */
 /*  limitations under the License.                                           */
 /*                                                                           */
 /*  You should have received a copy of the Apache-2.0 license                */
 /*  along with SoPlex; see the file LICENSE. If not email to soplex@zib.de.  */
 /*                                                                           */
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
 /**@file   example.cpp
  * @brief  simple example of how to build up and solve an lp using the SoPlex callable library
  *
  * @author Ambros Gleixner
  */
 
 #include <iostream>
 #include "soplex.h"
 
 using namespace soplex; 
 
 void test_real()
 {
    SoPlex mysoplex;
 
    /* set the objective sense */
    mysoplex.setIntParam(SoPlex::OBJSENSE, SoPlex::OBJSENSE_MINIMIZE);
 
    /* we first add variables */
    DSVector dummycol(0);
    mysoplex.addColReal(LPCol(3.0, dummycol, infinity, 1.0));
    mysoplex.addColReal(LPCol(2.0, dummycol, infinity, 1.0));
 
    /* then constraints one by one */
    DSVector row1(2);
    row1.add(0, 0.2);
    row1.add(1, 1.0);
    mysoplex.addRowReal(LPRow(2.0, row1, infinity));
 
    /* NOTE: alternatively, we could have added the matrix nonzeros in dummycol already; nonexisting rows are then
     * created automatically. */
 
    /* write LP in .lp format */
    mysoplex.writeFileReal("dump_real.lp", NULL, NULL, NULL);
 
    /* solve LP */
    SPxSolver::Status stat;
    DVector prim(2);
    DVector dual(1);
    stat = mysoplex.optimize();
 
    /* get solution */
    if(stat == SPxSolver::OPTIMAL)
    {
       mysoplex.getPrimal(prim);
       mysoplex.getDual(dual);
       std::cout << "LP solved to optimality.\n";
       std::cout << "Objective value is " << mysoplex.objValueReal() << ".\n";
       std::cout << "Primal solution is [" << prim[0] << ", " << prim[1] << "].\n";
       std::cout << "Dual solution is [" << dual[0] << "].\n";
    }
    else
    {
       std::cout << "Error: SoPlex returned with status " << stat << ".\n";
    }
 }

int main() {
  std::cout << "Testing SoPlex as floating-point LP solver:\n\n";
  test_real();

  return 0;
}