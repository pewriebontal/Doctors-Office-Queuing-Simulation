/*
 * doctors_office.h
 * Written by : SENG1120 Staff (c1234567)
 * Modified : 12/04/2024
 *
 * This class represents a doctor's office in a queuing system, mainly a wrapper for a vector of doctor objects.
 * This file should be used in conjunction with Assignment 2 for SENG1120/SENG6120.
 */
#ifndef SENG1120_DOCTORS_OFFICE_H
#define SENG1120_DOCTORS_OFFICE_H

#include <iostream>
#include <string>
#include <vector>
#include "doctor.h"
#include "patient.h"

class doctors_office
{
public:
    /**
     * Constructor for a doctor's office.
     * 
     * Postcondition: A vector of doctors is initialised with size num_docs.
     * Hint: use the resize function for a vector!
    */
    doctors_office(int num_docs = 1);

    /**
     * Destructor for a doctor's office.
     * 
     * Postcondition: The vector of doctors is destroyed.
    */ 
    ~doctors_office();

    /**
     * Search the list of doctors for the first free doctor, if any.
     * 
     * Postcondition: If a free doctor is found, returns its ID. 
	 *                The ID can be taken as its index in the vector, given that a doctor has no explicit ID.
     *                If no doctors are free, returns -1.
    */
    int get_free_doctor_ID() const;

    /**
     * Get the number of doctors that are busy.
     * 
     * Postcondition: The number of busy doctors is returned.
    */
    int get_number_of_busy_doctors() const;

    /**
     * Set a doctor as busy with the specified patient.
     * 
     * Postcondition: The doctor specified by doc_ID (i.e., index) is set as busy, to attend to patient
     *                specified by pat, with the appointment time given by app_time.
    */
    void set_doctor_busy(int doc_ID, const patient& pat, int app_time);

    /**
     * Set a doctor as busy with the specified patient.
     * 
     * Postcondition: The doctor specified by doc_ID (i.e., index) is set as busy, to attend to patient
     *                specified by pat, with the appointment time set as the patient's
     *                appointment time property.
    */
    void set_doctor_busy(int doc_ID, const patient& pat);

    /**
     * Update the status of doctors, checking if they have become free.
     * 
     * Postcondition: The remaining appointment time of each busy doctor is decremented by one unit.
     *                If the remaining appointment time of a busy doctor is reduced to zero, the doctor is set to "free".
     *                A message indicating which patient has been served is printed on the screen, 
     *                together with the patient's departing time (specified by the time variable).
    */
    void update_doctors(int time);

private:
    int num_doctors;              // The number of doctors
    std::vector<doctor> doctors;  // The vector of doctors

    /**
     * Display a message when a doctor has finished an appointment.
     */
    void display_appointment_done(int doc_ID, int pat_id, int time)
    {
        std::cout << "Doctor " 
                  << doc_ID
                  << " (Patient "
                  << pat_id
                  << ") done at time "
                  << time
                  << std::endl;
    }
};

#endif