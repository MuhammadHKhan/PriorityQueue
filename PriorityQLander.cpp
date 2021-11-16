#include <iostream>
#include <fstream>
#include <sstream>
#include "lander.h"
#include "priorityQ.h"

//Muhammad Khan, CS 302 1001, Assignment 8
//This program will use a priorityQ for its heapArray
//to store lander objects that contain various fields 
//that can be changed by the lander class functions
//The priorityQ will keep the array updated by using
//its functions. The program will output the rocket
//stats and its other various fields
//The user will enter two files, one for the rocket stats
//and the other for the change functions for each rocket

using namespace std;

int main()
{
	//use for opening files
	string inputFile;
	ifstream infile;
	bool check = true;

	//use for lander objects
	double mass = 0.0;
	double max_thrust = 0.0;
	double max_fuel = 0.0;
	double altitude = 0.0;
	double fuel = 0.0;
	int id = 1;

	//use for the sim file
	double sim = 0.0;

	//try to open file that has lander stats
	while (check)
	{
		cout << "Enter lander file: ";
		cin >> inputFile;
		infile.open(inputFile);
		if (infile)
		{
			check = false;
		}
	}

	check = true;

	//make a priorityQ object and insert
	//lander objects
	priorityQ<lander> heap;

		infile >> mass;
		infile >> max_thrust;
		infile >> max_fuel;
		infile >> altitude;
		infile >> fuel;
		infile >> id;
		lander A(mass, max_thrust, max_fuel, altitude, fuel, id);
		heap.insert(A);
		//cout << A.get_id() << endl;
		infile >> mass;
		infile >> max_thrust;
		infile >> max_fuel;
		infile >> altitude;
		infile >> fuel;
		infile >> id;
		lander B(mass, max_thrust, max_fuel, altitude, fuel, id);
		heap.insert(B);
		//cout << B.get_id() << endl;
		infile >> mass;
		infile >> max_thrust;
		infile >> max_fuel;
		infile >> altitude;
		infile >> fuel;
		infile >> id;
		lander C(mass, max_thrust, max_fuel, altitude, fuel, id);
		heap.insert(C);
		//cout << C.get_id() << endl;
		infile >> mass;
		infile >> max_thrust;
		infile >> max_fuel;
		infile >> altitude;
		infile >> fuel;
		infile >> id;
		lander D(mass, max_thrust, max_fuel, altitude, fuel, id);
		heap.insert(D);
		//cout << D.get_id() << endl;
		infile >> mass;
		infile >> max_thrust;
		infile >> max_fuel;
		infile >> altitude;
		infile >> fuel;
		infile >> id;
		lander E(mass, max_thrust, max_fuel, altitude, fuel, id);
		heap.insert(E);
		//cout << E.get_id() << endl;
		infile >> mass;
		infile >> max_thrust;
		infile >> max_fuel;
		infile >> altitude;
		infile >> fuel;
		infile >> id;
		lander F(mass, max_thrust, max_fuel, altitude, fuel, id);
		heap.insert(F);
		//cout << F.get_id() << endl;
		infile >> mass;
		infile >> max_thrust;
		infile >> max_fuel;
		infile >> altitude;
		infile >> fuel;
		infile >> id;
		lander G(mass, max_thrust, max_fuel, altitude, fuel, id);
		heap.insert(G);
		//cout << G.get_id() << endl;
		infile >> mass;
		infile >> max_thrust;
		infile >> max_fuel;
		infile >> altitude;
		infile >> fuel;
		infile >> id;
		lander H(mass, max_thrust, max_fuel, altitude, fuel, id);
		heap.insert(H);
		//cout << H.get_id() << endl;
		infile >> mass;
		infile >> max_thrust;
		infile >> max_fuel;
		infile >> altitude;
		infile >> fuel;
		infile >> id;
		lander I(mass, max_thrust, max_fuel, altitude, fuel, id);
		heap.insert(I);
		//cout << I.get_id() << endl;
		infile >> mass;
		infile >> max_thrust;
		infile >> max_fuel;
		infile >> altitude;
		infile >> fuel;
		infile >> id;
		lander J(mass, max_thrust, max_fuel, altitude, fuel, id);
		heap.insert(J);
		//cout << J.get_id() << endl;

		//cout << "Size of queue " << heap.getSize() << endl;
	lander temp;
	infile.close();	//close the file stream
	string read = " ";
	double x = 0;
	char a = ' ';
	int i = 0;
	
	while (check)
	{
		cout << "Enter simulation file: ";
		cin >> inputFile;
		infile.open(inputFile);
		if (infile)
		{
			check = false;
		}
	}
	
	//read in from the file and print out the stats of each rocket
	/*this function will read in the stats from the file, determine 
	if the number read was valid, and insert it for the landers change flow
	rate function, then output its stats and insert it back if the following
	cases are met, if not, keep looping and doing the same thing.*/
	while (infile >> read)
	{
		if (!(read[0] >= 48 && read[0] <= 57))
		{
			continue;
		}
		else
		{
			stringstream convert(read);
			convert >> x;
			if (x <= 1.0 && x >= 0.0)
			{
				temp = heap.getHighestPriority();
				heap.deleteHighestPriority();

				cout << "Rocket " << temp.get_id() << endl;
				cout << "Fuel: " << temp.get_fuel_amount() << endl;
				cout << "Altitude: " << temp.get_altitude() << endl;
				cout << "Velocity: " << temp.get_velocity() << endl;
				cout << endl;
				temp.change_flow_rate(x);
				temp.simulate();

				if (temp.get_altitude() < 0 && temp.get_velocity() <= -2)
				{
					cout << "Rocket ID: " << temp.get_id() << " has crashed. At least nobody was on board" << endl;
				}
				else
				{
					heap.insert(temp);
				}
				
			}
		}
	}

	return 0;
}

