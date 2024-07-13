/*
 * doctor.h
 * Written by : SENG1120 Staff (c1234567)
 * Modified : 12/04/2024
 *
 * This class represents a doctor in a queuing system.
 * This file should be used in conjunction with Assignment 2 for SENG1120/SENG6120.
 */

#ifndef SENG1120_DOCTOR_H
#define SENG1120_DOCTOR_H

#include <string>
#include "patient.h"

class doctor
{
public:
	/**
	 * Constructor for a doctor.
	 * 
	 * Postcondition: The doctor's status is free (i.e., is_busy is false).
	 *                The current_appointment_time is set to 0.
	*/
	doctor();

    /**
     * Destructor for a doctor.
     * 
     * Postcondition: The doctor is destroyed.
    */ 
	~doctor();

	/**
	 * Determine if the doctor is free.
	 * 
	 * Postcondition: Returns true if the doctor is free. Otherwise, returns false.
	*/
	bool is_free() const;

	/**
	 * Set the status of the doctor to busy.
	 * 
	 * Postcondition: The doctor's status is busy.
	*/
	void set_busy();

	/**
	 * Set the status of the doctor to free.
	 * 
	 * Postcondition: The doctor's status is free.
	*/
	void set_free();

	/**
	 * Set the remaining appointment time according to the parameter.
	 * 
	 * Postcondition: the remaining appointment time is set to the value of t.
	*/
	void set_remaining_appointment_time(int t);

	/**
	 * Set the remaining appointment time according to the patient.
	 * 
	 * Postcondition: the remaining appointment time is set to the patient's appointment length.
	*/
	void set_remaining_appointment_time();

	/**
	 * Return the remaining time in the current appointment.
	 * 
	 * Postcondition: The value of the remaining appointment time is returned.
	*/
	int get_remaining_appointment_time() const;

	/**
	 * Decrement the time remaining in the current appointment by 1 unit.
	 * 
	 * Postcondition: The remaining appointment time has been reduced by 1.
	*/
	void decrement_remaining_appointment_time();

	/**
	 * Set the current patient to the supplied patient.
	 * 
	 * Postcondition: the current patient is updated.
	*/
	void set_current_patient(const patient& pat);

	/**
	 * Return the patient number of the current patient.
	 * 
	 * Postcondition: The patient number of the current patient is returned.
	*/
	int get_current_patient_number() const;

	/**
	 * Return the arrival time of the current patient.
	 * 
	 * Postcondition: The arrival time of the current patient is returned.
	*/
	int get_current_patient_arrival_time() const;

	/**
	 * Return the waiting time of the current patient.
	 * 
	 * Postcondition: The waiting time of the current patient is returned.
	*/
	int get_current_patient_waiting_time() const;

	/**
	 * Return the appointment time of the current patient.
	 * 
	 * Postcondition: The appointment length of the current patient is returned.
	*/
	int get_current_patient_appointment_length() const;

private:
	patient current_patient;        // The current patient being seen
	bool is_busy;                   // The status of the doctor. is_busy is true if the doctor is busy and false if free
	int remaining_appointment_time; // The remaining time for the current appointment
};

#endif