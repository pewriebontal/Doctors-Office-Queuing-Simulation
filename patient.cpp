/*
 * patient.cpp
 * Written by : Min Thu Khaing (c3489993)
 * Modified : 14/07/2024
 *
 * This class represents a patient in a queuing system.
 * This file should be used in conjunction with Assignment 2 for SENG1120/SENG6120.
 */
/*
 *                       _oo0oo_
 *                      o8888888o
 *                      88" . "88
 *                      (| -_- |)
 *                      0\  =  /0
 *                    ___/`---'\___
 *                  .' \\|     |// '.
 *                 / \\|||  :  |||// \
 *                / _||||| -:- |||||- \
 *               |   | \\\  -  /// |   |
 *               | \_|  ''\---/''  |_/ |
 *               \  .-\__  '-'  ___/-. /
 *             ___'. .'  /--.--\  `. .'___
 *          ."" '<  `.___\_<|>_/___.' >' "".
 *         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *         \  \ `_.   \_ __\ /__ _/   .-` /  /
 *     =====`-.____`.___ \_____/___.-`___.-'=====
 *                       `=---='
 *
 *
 *     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *               佛祖保佑         永无BUG
 */
#include "patient.h"

/**
 * @brief Constructor for a patient. If no values are specified on construction, the default values are used.
 * 
 * Postcondition: The patient's information is set, as provided.
 * 
 * @param pat_num The patient number.
 * @param arrive_time The arrival time of the patient.
 * @param wait_time The initial waiting time of the patient.
 * @param app_length The appointment length of the patient.
 */
patient::patient(int pat_num, int arrive_time, int wait_time, int app_length)
	: patient_number(pat_num)
	, arrival_time(arrive_time)
	, waiting_time(wait_time)
	, appointment_length(app_length)
{ }

/**
 * @brief Destructor for a patient.
 * 
 * Postcondition: The patient is destroyed - must have been a bad doctor ;)
 */
patient::~patient()
{
	// I wonder who is behind this funny comments

	// Setting the default values to 0
	// because I want High Distinction pls pls
	patient_number = 0;
	arrival_time = 0;
	waiting_time = 0;
	appointment_length = 0;
}

/**
 * @brief Update the patient information using the supplied values.
 * 
 * Postcondition: The patient's information is updated, as provided.
 * 
 * @param pat_num The patient number.
 * @param arrive_time The arrival time of the patient.
 * @param wait_time The waiting time of the patient.
 * @param app_length The appointment length of the patient.
 */
void patient::set_patient_info(int pat_num, int arrive_time, int wait_time, int app_length)
{
	patient_number = pat_num;
	arrival_time = arrive_time;
	waiting_time = wait_time;
	appointment_length = app_length;
}

/**
 * @brief Return the waiting time.
 * 
 * Postcondition: The value of the waiting time is returned.
 * 
 * @return int The waiting time of the patient.
 */
int patient::get_waiting_time() const
{
	return (waiting_time);
}

/**
 * @brief Set the waiting time to the specified value.
 * 
 * Postcondition: The value of the waiting time is updated.
 * 
 * @param time The new waiting time.
 */
void patient::set_waiting_time(int time)
{
	waiting_time = time;
}

/**
 * @brief Increment the waiting time by 1 unit.
 * 
 * Postcondition: The value of the waiting time is incremented by 1.
 */
void patient::increment_waiting_time()
{
	waiting_time++;
}

/**
 * @brief Return the arrival time.
 * 
 * Postcondition: The value of the arrival time is returned.
 * 
 * @return int The arrival time of the patient.
 */
int patient::get_arrival_time() const
{
	return (arrival_time);
}

/**
 * @brief Return the appointment length.
 * 
 * Postcondition: The value of the appointment length is returned.
 * 
 * @return int The appointment length of the patient.
 */
int patient::get_appointment_length() const
{
	return (appointment_length);
}

/**
 * @brief Return the patient number.
 * 
 * Postcondition: The value of the patient number is returned.
 * 
 * @return int The patient number.
 */
int patient::get_patient_number() const
{
	return (patient_number);
}
