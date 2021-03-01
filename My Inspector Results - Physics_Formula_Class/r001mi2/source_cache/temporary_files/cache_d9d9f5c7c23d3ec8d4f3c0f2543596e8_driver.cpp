//all tests are examples below are from the open stax college physics textbook.
//this Physics class has a built in long double for storing calculation called val. As well as a vector called vector_values.
// you access them with the dot(.) operator
//example: Physics object;
//         object.val = objects.acceleration_VdT(-15.0, 1.80);  //this now has the result of that calculation stored in val.
//to print out val to the screen use the print method. example: object.print();
//if there are values stored in the vector_values vector use the object.print_vector_values()  method instead.
//most of all have fun exploring and please if there is something I should be doing better let me know. Thanks.
#include "Physics.h"



int main()

{
	Physics car;
	cout << "kg:" << Physics::conversion_gram_to_kilogram(9.88) << endl;
	car._val_ =  car.circularMotion->ideal_angle_banked_curve(835, 35.8);
	car.show_val();
	Physics person;
	Physics ball;
	ball.vector3d->set_coordinates(3, 4, 4);
	Physics vect;
	person._force_ = person.velocity_soccer_kick(-35, 5.5, 75);
	ball._distance_ = ball.circularMotion->centripetal_force_V(ball.vector3d->return_mag(), ball.vertical_velocity_by_Xvelocity_with_angle(23, 35), 22);
	vect.vector2d->set_coordinates(25, 135, 'p');
	vect.vector2d->showAllData();
	ball.circularMotion->conversion_revolutions_min_to_radians_second(ball._distance_);
	person.show_force();
	ball.show_distance();
	cout << "feet to meeters:" << vect.conversion_feet_to_meters(car.displacement(10, 6984.6)) << endl;
	
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
		dragster.val = dragster.displacement_accelerating_object(26.0, 5.56);
		dragster.print();

		dragster.val = dragster.displacement_accelerating_object_PV(0, 0, 26.0, 5.56);
		dragster.print();
	
	
	// Example 2.11 Calculating Final Velocity: no time, dragsters
		Physics dragster;
		double val = dragster.velocity_final_no_time(0,402,26.0);
		std::cout << val << std::endl;
		
	
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
		double val = car.time_by_avgVdA(20.0, 0, 400);
		cout << val << endl;
		
	// Example 2.14 Calculating Position and velocity of a falling object: a rock thrown upward pg62
		Physics rock;
		rock.pos_vel_falling_object_upDown(0, 13.0, -9.80, 2);	
		rock.print_vector_values();	
	
	// Example 2.15 Calculating Velocity of a Falling Object: A Rock Thrown Down pg65
		Physics rock;
		rock.val = rock.velocity_falling_object_down(0, -5.10, -13.0, -9.8);
		rock.print_val();
	
	// Example 2.16 finding gravity from data on a falling object pg68
		Physics marble;
		marble.val = marble.acceleration_dispDtimeSqrd(-1.000, .45173);
		marble.print();

	// Check Your Understanding pg68 Ice breaks off a Glacier how long does it take to fall?
		Physics glacier;
		glacier.val = glacier.time_finalPos_and_acceleration(-30.0, -9.80);
		glacier.print();
	
	
	// Example 2.17 Determining Average Velocity from a graph of Displacement versus time: jetcar
		Physics jetcar;
		jetcar.val = jetcar.slope_formula(2000, 525, 6.4, .50);
		jetcar.print();
	
	// Chapter 2 Problems and Exercises, selected examples
		2.3 Time, Velocity, and Speed
			6.  Physics helicoptorBlades;
				helicoptorBlades.val = helicoptorBlades.rotation_speed_2PIxRdT(5.0, 100, 60);
				helicoptorBlades.print();

			7.8.Physics continent;  PG82
				continent.val = continent.time_by_DisTdV(5.90 * pow(10, 5) * 100, 6);
				continent.print();

			9.	Physics zephyr;
				zephyr.val = zephyr.speed_avg_DdT(1633800, 47098); m/s
				zephyr.print();
				
				Physics zephyr;
				zephyr.val = zephyr.speed_avg_DdT(1633.8*3600, 47098); km/s
				zephyr.print();
		
	
	// Chapter 2b web assign HW #4	
		Physics woodpecker;
		woodpecker.val = woodpecker.acceleration_vStart_vEndDdisplacement(.570, 0, .00415);
		std::cout << std::endl << woodpecker.multiple_of_gravity(woodpecker.val)<< std::endl;
		woodpecker.print();

	// chapter 3, question problem 27 A ball is thrown horizantally off a building
		Physics ball;
		ball.val = ball.air_time_initial_velocity0_y0(66.5);
		ball.print();
		ball.val = ball.velocity_initial_horizontal_component(66.5, 111.3);
		ball.print();
		ball.val = ball.velocity_vertical_component(66.5);
		ball.print();
		ball.final_projectile_velocity_vector(ball.velocity_vertical_component(60), ball.velocity_initial_horizontal_component(54, 123.8));
		//ball.print();

	// Chapter 3 bird with fish
		Physics bird;	
		bird.val = bird.velocity_vertical_component(6);
		bird.print();
		bird.final_projectile_velocity_vector(bird.velocity_vertical_component(6),3.60);

	// chapter 3 soccer kick proble 42 in book
		Physics soccarKick;
		soccarKick.val = soccarKick.velocity_soccer_kick(40, 2.4, 28);
		soccarKick.print();
	

	// chapter 6 problem # 30
		Physics car;
		car._val_ = Physics::conversion_mps_to_kmh(car.circularMotion->ideal_speed_banked_curve(110, 17));
		car.show_val();//part a
		car._val_ = car.circularMotion->coefficient_static_minimum_for_embanked_turn(110, 17, Physics::conversion_kmh_to_mps(30.0));
		car.show_val();//part b
	//

	//

	//
*/

