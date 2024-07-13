/*
 * simulation.h
 * Written by : SENG1120 Staff (c1234567)
 * Modified : 12/04/2024
 *
 * This class represents the main simulation in a doctor's office queuing system.
 * This file should be used in conjunction with Assignment 2 for SENG1120/SENG6120.
 */

#ifndef SENG1120_SIMULATION_H
#define SENG1120_SIMULATION_H

#include <iostream>
#include <random>
#include "doctors_office.h"
#include "patient.h"
#include "lqueue.h"

class simulation
{
public:
    /**
     * Create the simulation using the provided parameters.
     * 
     * Postcondition: The simulations parameters are set, as provided.
     *                A doctors_office with the specified number of doctors has been created.
	 *                The total_wait_time is set to 0.
     *                The patients_arrived is set to 0.
     */
    simulation(int sim_time, int num_doctors, int appointment_time, int time_between_arrival);

    /**
     * Destructor for a simulation.
     * 
     * Postcondition: The simulation is destroyed.
    */ 
    ~simulation();

    /**
     * Run the simulation.
     * 
     * Postcondition: The simulation object has been updated as per the simulation.
     */
    void run_simulation();

    /**
     * Return a reference to the doctor's office used in the simulation.
     * 
     * Postcondition: A reference to the doctor's office is returned.
     */
    doctors_office& get_office();

    /**
     * Return a reference to the patient queue used in the simulation.
     * 
     * Postcondition: A reference to the patient queue is returned.
     */
    LQueue<patient>& get_patient_queue();

    /**
     * Return the total time patients spent waiting during the simulation.
     * 
     * Postcondition: The value of the total waiting time is returned.
     */
    int get_total_wait_time();

    /**
     * Return the numer of patients that arrived throughout the simulation.
     * 
     * Postcondition: The number of patients that arrived is returned.
     */
    int get_num_patients_arrived();

private:
    int sim_time;             // The simulation time, as the number of time steps
    int num_doctors;          // The number of doctors
    int appointment_time;     // The length of an appointment
    int time_between_arrival; // The average time between patient arrivals

    int patients_arrived;     // The number of patients that have arrived
    int total_wait_time;      // The total wait time of all patients 

    LQueue<patient> waiting_queue;   // The queue of patients waiting to be seen
    doctors_office office;           // The doctor's office, containing the doctors

    /**
     * Determine if a patient has arrived at this time step.
     * 
     * Note: the argument passed is the time_between_arrival, NOT the current time.
     * 
     * Postcondition: Returns true if a patient has arrived.
     */
    bool has_patient_arrived(double time_between_arrival)
    {
        double value = rand() / (double)RAND_MAX;
        return value > std::exp(-1.0 / time_between_arrival);
    }

    /**
     * Display a message when a patient has arrived.
     * 
     * Postcondition: A message is printed to std::cout.
     */
    void display_patient_arrived(int pat_num, int time)
    {
        std::cout << "Patient " 
                  << pat_num
                  << " arrived at time " 
                  << time 
                  << std::endl;
    }

    /**
     * Display a message when a patient is first being seen, i.e., they have been allocated to a doctor.
     *
     * Postcondition: A message is printed to std::cout.
     */
    void display_patient_seen(int doc_id, int pat_num, int time)
    {
        std::cout << "Doctor " 
                  << doc_id
                  << " seeing Patient "
                  << pat_num
                  << " at time "
                  << time
                  << std::endl;
    }
};

#endif