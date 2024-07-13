/*
 * patient.h
 * Written by : SENG1120 Staff (c1234567)
 * Modified : 12/04/2024
 *
 * This class represents a patient in a queuing system.
 * This file should be used in conjunction with Assignment 2 for SENG1120/SENG6120.
 */

#ifndef SENG1120_PATIENT_H
#define SENG1120_PATIENT_H

class patient
{
public:
	/**
	 * Constructor for a patient. If no values are specified on construction, the default values are used.
	 * 
	 * Postcondition: The patient's information is set, as provided.
	*/
	patient(int pat_num = 0, int arrive_time = 0, int wait_time = 0, int app_length = 0);


    /**
     * Destructor for a patient.
     * 
     * Postcondition: The patient is destroyed - must have been a bad doctor ;)
    */ 
	~patient();

	/**
	 * Update the patient information using the supplied values.
	 * 
	 * Postcondition: The patient's information is updated, as provided. 
	*/
	void set_patient_info(int pat_num = 0, int arrive_time = 0, int wait_time = 0, int app_length = 0);

	/**
	 * Return the waiting time.
	 * 
	 * Postcondition: The value of the waiting time is returned.
	*/
	int get_waiting_time() const;

	/**
	 * Set the waiting time to the specified value.
	 * 
	 * Postcondition: The value of the waiting time is updated.
	*/
	void set_waiting_time(int time);

	/**
	 * Increment the waiting time by 1 unit.
	 * 
	 * Postcondition: The value of the waiting time is incremented by 1.
	*/
	void increment_waiting_time();

	/**
	 * Return the arrival time.
	 * 
	 * Postcondition: The value of the arrival time is returned.
	*/
	int get_arrival_time() const;

	/**
	 * Return the appointment length.
	 * 
	 * Postcondition: The value of the appointment length is returned.
	*/
	int get_appointment_length() const;

	/**
	 * Return the patient number.
	 * 
	 * Postcondition: The value of the patient number is returned.
	*/
	int get_patient_number() const;

private:
	int patient_number;      // The patient number
	int arrival_time;        // The arrival time
	int waiting_time;        // The time spent waiting
	int appointment_length;  // The appointment length 
};

#endif