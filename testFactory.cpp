﻿#include "Physics_World.h"
#include "RunTimer.h"


int main()
{
	//starting time do not edit code between solid comment lines
	//_________________________________________________________________________
	RunTimer timer;
	timer.start();
	//_________________________________________________________________________
	//add test code between starred areas
	//*************************************************************************
	/*
	Vector2D x_o(-2, -2);
	Vector2D x_1(-2, 1);
	Vector2D x_2(2, -2);

	Vector2D l_0 = x_1 - x_o;
	Vector2D l_1 = x_2 - x_1;
	Vector2D l_2 = x_o - x_2;

	l_0.displayAllData("l0");
	l_1.displayAllData("l1");
	l_2.displayAllData("l2");
	l_0.normalize_Vector2D();
	l_0.displayAllData("l0");

	double M[3][4] = { {  1, 2, -1,  -4 },
	                   {  2, 3, -1, -11 },
	                   { -2, 0, -3,  22 } };

	to_reduced_row_echelon_form(M);
	print_matrix(M, 3, 4);
	*/


	TriangleSolver t(2, 3, 3);
	t.displayTriangleData();

	TriangleSolver t1(3, 2, 3);
	t1.displayTriangleData();

	t1.congruentBy(t);
	t1.similarBy(t);

	//setVal(QP::powerCarriedAwayByElectrons(1.00e-3, 500e-9, 1.30e3,2.28));
	//show_val("N/t", "elec/sec");


	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	//return EXIT_SUCCESS;

}
