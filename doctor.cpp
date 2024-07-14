/*
 * doctor.cpp
 * Written by : Min Thu Khaing (c3489993)
 * Modified : 14/07/2024
 *
 * This class represents a doctor in a queuing system.
 * This file should be used in conjunction with Assignment 2 for SENG1120/SENG6120.
 */
#include "doctor.h"

/**
 * @brief Construct a new doctor::doctor object
 * 
 * Postcondition: The doctor's status is free (i.e., is_busy is false).
 *                The current_appointment_time is set to 0.
 */
doctor::doctor()
	: remaining_appointment_time(0)
{
	is_busy = false;
}

/**
 * @brief Destroy the doctor::doctor object
 * 
 * Postcondition: The doctor is destroyed.
 */
doctor::~doctor()
{
	remaining_appointment_time = 0;
}

/**
 * @brief Determine if the doctor is free.
 * 
 * Postcondition: Returns true if the doctor is free. Otherwise, returns false.
 * 
 * @return true if the doctor is free
 * @return false if the doctor is busy
 */
bool doctor::is_free() const
{
	return (!is_busy);
}

/**
 * @brief Set the status of the doctor to busy.
 * 
 * Postcondition: The doctor's status is busy.
 */
void doctor::set_busy()
{
	is_busy = true;
}

/**
 * @brief Set the status of the doctor to free.
 * 
 * Postcondition: The doctor's status is free.
 */
void doctor::set_free()
{
	is_busy = false;
}

/**
 * @brief Set the remaining appointment time according to the parameter.
 * 
 * Postcondition: The remaining appointment time is set to the value of t.
 * 
 * @param t The new remaining appointment time.
 */
void doctor::set_remaining_appointment_time(int t)
{
	remaining_appointment_time = t;
}

/**
 * @brief Set the remaining appointment time according to the patient.
 * 
 * Postcondition: The remaining appointment time is set to the patient's appointment length.
 */
void doctor::set_remaining_appointment_time()
{
	remaining_appointment_time = current_patient.get_appointment_length();
}

/**
 * @brief Return the remaining time in the current appointment.
 * 
 * Postcondition: The value of the remaining appointment time is returned.
 * 
 * @return int The remaining appointment time.
 */
int doctor::get_remaining_appointment_time() const
{
	return (remaining_appointment_time);
}

/**
 * @brief Decrement the time remaining in the current appointment by 1 unit.
 * 
 * Postcondition: The remaining appointment time has been reduced by 1.
 */
void doctor::decrement_remaining_appointment_time()
{
	remaining_appointment_time--;
}

/**
 * @brief Set the current patient to the supplied patient.
 * 
 * Postcondition: The current patient is updated.
 * 
 * @param pat The patient object to be set as the current patient.
 */
void doctor::set_current_patient(const patient& pat)
{
	current_patient = pat;
}

/**
 * @brief Return the patient number of the current patient.
 * 
 * Postcondition: The patient number of the current patient is returned.
 * 
 * @return int The patient number of the current patient.
 */
int doctor::get_current_patient_number() const
{
	return (current_patient.get_patient_number());
}

/**
 * @brief Return the arrival time of the current patient.
 * 
 * Postcondition: The arrival time of the current patient is returned.
 * 
 * @return int The arrival time of the current patient.
 */
int doctor::get_current_patient_arrival_time() const
{
	return (current_patient.get_arrival_time());
}

/**
 * @brief Return the waiting time of the current patient.
 * 
 * Postcondition: The waiting time of the current patient is returned.
 * 
 * @return int The waiting time of the current patient.
 */
int doctor::get_current_patient_waiting_time() const
{
	return (current_patient.get_waiting_time());
}

/**
 * @brief Return the appointment time of the current patient.
 * 
 * Postcondition: The appointment length of the current patient is returned.
 * 
 * @return int The appointment length of the current patient.
 */
int doctor::get_current_patient_appointment_length() const
{
	return (current_patient.get_appointment_length());
}
