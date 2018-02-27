/* Udacity SDC Project 4: PID Controler
 * Submited by: Omer Waseem
 * Submitted on: Feb 27, 2018
*/

#include "PID.hpp"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;
	total_cte = 0.0;
	previous_cte = 0.0;
}

void PID::UpdateError(double cte) {
	p_error = -1 * Kp * cte;
	d_error = -1 * Kd * (cte - previous_cte);
	
	// keep track of cte integral (total_cte) and previous_cte for differential
	total_cte += cte;
	previous_cte = cte;
	
	i_error = -1 * Ki * total_cte;
}

double PID::TotalError() {
	return p_error + i_error + d_error;
}


