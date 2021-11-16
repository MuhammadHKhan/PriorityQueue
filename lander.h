#include <iostream>
#include <cmath>

using namespace std;

class lander
{
public:
	lander(double = 0, double = 0, double = 0, double = 0, double = 0, int = 0);
	double get_velocity() const;
	double get_altitude() const;
	double get_fuel_amount() const;
	int get_id() const;
	double get_mass() const;
	char get_status() const;
	bool change_flow_rate(double);
	void simulate();
	bool operator<(const lander&) const;
private:
	double flow_rate;
	double velocity;
	double altitude;
	double fuel_amount;
	bool stillLanding;
	int id;
	int timesSimulated;
	double LANDER_MASS;
	double MAX_FUEL_CONSUMPTION_RATE;
	double MAX_THRUST;
};

lander::lander(double mass, double max_thrust, double max_fuel, double alt, double fuel, int idd)
{
	LANDER_MASS = mass;
	MAX_THRUST = max_thrust;
	MAX_FUEL_CONSUMPTION_RATE = max_fuel;
	altitude = alt;
	fuel_amount = fuel;
	id = idd;
	velocity = 0;
	flow_rate = 0;
	timesSimulated = 0;
	if (altitude > 0)
	{
		stillLanding = true;
	}
	else
		stillLanding = false;
}

//returns the velocity
double lander::get_velocity() const
{
	return velocity;
}

//returns the altitude
double lander::get_altitude() const
{
	return altitude;
}

//returns the mass
double lander::get_mass() const
{
	return LANDER_MASS;
}

//returns the fuel amount
double lander::get_fuel_amount() const
{
	return fuel_amount;
}

//returns the id
int lander::get_id() const
{
	return id;
}

//function will return a char if any of the cases below match
char lander::get_status() const
{
	//return a if airborne
	if (altitude > 0)
	{
		return 'a';
	}
	//return c if at surface and velocity is less than or equal to two
	else if (altitude == 0 && velocity <= -2)
	{
		return 'c';
	}
	//return l if none of the above cases match
	else
	{
		return 'l';
	}
}

//this function will set the flow rate to r if it is in between 0 and 1
//otherwise, the function will return false
bool lander::change_flow_rate(double r)
{
	if (r >= 0 && r <= 1)
	{
		if (fuel_amount > 0)
		{
			flow_rate = r;
			return true;
		}
	}
	else
	{
		return false;
	}
	
}

void lander::simulate()
{
	if (altitude > 0)
	{
		//this will calculate the instantaneous velocity
		//and will update the velocity field with the value
		double getVel = 0.0;
		double fr = flow_rate;
		double mt = get_mass();
		double fa = get_fuel_amount();
		getVel = ((fr * MAX_THRUST) / (mt + fa)) - 1.62;
		velocity += getVel;

		altitude += velocity;

		//update the stillLanding field if necessary
		if (altitude > 0.0)
		{
			stillLanding = true;
		}
		else if (altitude <= 0)
		{
			stillLanding = false;
		}

		fuel_amount -= MAX_FUEL_CONSUMPTION_RATE * abs(velocity) * 1;

		//set fuel amount to 0 if the fuel amount is a negative value
		if (fuel_amount < 0.0)
		{
			fuel_amount = 0;
		}

		//increment/update timesSimulated by 1
		timesSimulated++;
	}
}

//sereis of test cases for the operator < overload
bool lander::operator<(const lander& rhs) const
{
	if (this->timesSimulated == rhs.timesSimulated)
	{
		if (this->get_altitude() < rhs.get_altitude())
		{
			return true;
		}
		else if (this->get_altitude() == rhs.get_altitude())
		{
			if (this->get_fuel_amount() < rhs.get_fuel_amount())
			{
				return true;
			}
			else if (this->get_fuel_amount() == rhs.get_fuel_amount())
			{
				if (rhs.get_mass() < this->get_mass())
				{
					return true;
				}
				else if (rhs.get_mass() == this->get_mass())
				{
					if (this->get_id() < rhs.get_id())
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (this->timesSimulated < rhs.timesSimulated)
	{
		return true;
	}
	else
	{
		return false;
	}
}
