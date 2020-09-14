#include "Physics.h"
//all tests are examples from the open stax college physics textbook.
int main()
{

	Physics car;
	double val = car.time_using_VdA(20.0, 0, 400);
	cout << val << endl;

	
	return 0;
}
/*_______________________________________________________________________________
	Testing functions
	
	// check your understanding pg 40 finding average speed with a avg velocity of 0	
	// converting 80 miles in 105 minutes to base units of m/s 
		Physics train;
		double val = train.velocity_avg_DdT(80.0*5280, 105*3.28 * 60);
		cout << val << endl;
	
	// check your understanding part a, page 34
		Physics cyclist;
		double val = cyclist.displacement_start_finish(0, -3+2);
		cout << val << endl;
	
	// Example 2.1 Calculating Acceleration: a racehorse leaves the gate
		Physics racehorse;
		double val = racehorse.acceleration_VdT(-15.0, 1.80);
		cout << val << endl;
			
	// Example 2.2 Calculating Displacement: A Subway Train  pg42
		Physics train;
		double val = train.displacement_start_finish(4.70, 6.70);
		cout << val << endl;
		
		val = train.displacement_start_finish(5.25, 3.75);
		cout << val << endl;
	
	// Example 2.3
		Distance traveled is just the absolute value of the displacment   pg45
	
	// Example 2.4 Calculating Acceleration a subway train speeding up  pg45
		Physics train;
		double val = train.acceleration_VdT(30.0*1000, 20 * 3600);
		cout << val << endl;
	
	// Example 2.5 Calculate Acceleration: A Subway train slowing down pg46
		Physics train;
		double val = train.acceleration_VdT(-30.0*1000, 8 * 3600);
		cout << val << endl;
	
	
	// Example 2.6 calculating average velocity  pg47
		Physics test1;
		double val = test1.velocity_avg_DdT(test1.displacement_start_finish(5.25, 3.75)*60,5.0);
		cout << val << endl;
	
	// Example 2.7 Calculating Deceleration: the subway train
		Physics train;
		double val = train.acceleration_VdT(-20.0*1000, 10 * 3600);
		cout << val << endl;	
	
	// Example 2.8 Calculating Displacement: how far does the jogger run pg50
		Physics runner;
		double val = runner.displacement_VxT(4.0, 120);
		cout << val << endl;
		
	// Example 2.9 Calculating final velocity: an airplain slowing down
		Physics plain;
		double val = plain.final_velocity(70.0, -1.50, 40.0);
		cout << val << endl;
	
	// Example 2.10 Calculating Displacement of an accelerating object: Dragsters
		Physics dragster;
		double val = dragster.displacement_accelerating_object(26.0, 5.56);
		cout << val << endl;
	
	
	// Example 2.11 Calculating Final Velocity: no time, dragsters
		Physics dragster;
		double val = dragster.final_velocity_no_time(0, 26.0, 402);
		cout << val << endl;
		Physics test;
		val = test.final_velocity_no_time(2.5, 26.0, 402);
		cout << val << endl;
	
	// Example 2.12 Calculating Displacement: How far does a car go when coming to a halt
		//a:
		Physics car;
		double val = car.displacement_halting_VdA(0, 30.0, 0, -7.0);
		cout << val << endl;
		//b:
		Physics car;
		double val = car.displacement_halting_VdA(0, 30.0, 0, -5.0);
		cout << val << endl;
		//c:  incorperating reaction time
		a)
			Physics car;
			double val = car.displacement_halting_VdA(car.displacement_VxT(30.0, .50), 30.0, 0, -7.0);
			cout << val << endl;		
		b)
			Physics car;
			double val = car.displacement_halting_VdA(car.displacement_VxT(30.0, .50), 30.0, 0, -5.0);
			cout << val << endl;
	
	// Example 2.13 Calculating time: A car merges into traffic
		Physics car;
		vector<double> val;
		val = car.time_using_quadratic(1, 10, -200);
		for (int i = 0; i < 2; i++){
			cout << val[i] << endl;
		}
	
	// check your understanding pg59
	Physics car;
	double val = car.time_using_VdA(20.0, 0, 400);
	cout << val << endl;
		
	// Example 2.14
	
	//
	
	//
	
	//
	
	//
	
	//
	
*/
/*
	Physics test;
	double val = test.velocity_avg_DdT(80.0*5280, 105*3.28 * 60);
	cout << val << endl;
	



	val = test.final_velocity(70.0, -1.50, 40.0);
	cout << val << endl;
	
	val = test.displacement_Vstart_Vend(70.0, -1.50);
	cout << val << endl;
*/
