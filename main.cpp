/*
 * main.cpp
 * Written by : SENG1120 Staff (c1234567)
 * Modified : 12/04/2024
 *
 * This class represents the main runner for a doctor's office simulation.
 * This file should be used in conjunction with Assignment 2 for SENG1120/SENG6120.
 */

#include <random>
#include <iostream>
#include <iomanip>
#include "simulation.h"

/**
 * Generate some simple statistics about the simulation.
 * 
 * Postcondition: Various statistics are printed to std::cout.
*/
void generate_statistics(simulation &sim)
{
    doctors_office& office = sim.get_office();
    LQueue<patient>& patient_queue = sim.get_patient_queue();
    int total_wait_time = sim.get_total_wait_time();
    int patients_arrived = sim.get_num_patients_arrived();
    int patients_in_queue = 0;

    patient pat;

    while (!patient_queue.empty())
    {
        pat = patient_queue.dequeue();
        total_wait_time = total_wait_time + pat.get_waiting_time();
        patients_in_queue++;
    }

    // Find number of patients still being seen
    int patients_remaining = office.get_number_of_busy_doctors();
    // Find number of patients completely done
    int num_patients_seen = patients_arrived - patients_remaining - patients_in_queue;

    std::cout << "Total waiting time: " << total_wait_time << std::endl;
    std::cout << "Number of patients that completed an appointment: " << num_patients_seen << std::endl;
    std::cout << "Number of patients still being seen by a doctor: " << patients_remaining << std::endl;
    std::cout << "The number of patients left in queue: " << patients_in_queue << std::endl;

    // Compute the average waiting time of all passengers
    double average_wait_time = 0;
    if (patients_arrived > 0) // If number of patients arrived is > 0
    {
        average_wait_time = (double)total_wait_time / patients_arrived;
    }

    // Display only 2 decimal places
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(2);
    std::cout << "Average waiting time: " << average_wait_time << std::endl;
}

/**
 * Parse the arguments and run the simulation.
 * 
 * Postcondition: 0 is returned on a successful run. -1 is returned if an error occurs.
*/
int main(int argc, char *argv[])
{
    if (argc < 6) //quick check that we have 6 arguments passed - the program name is an argument!
    {
        std::cout << "Too few arguments. You must run the program as './Simulation <seed> <sim_time> <num_doctors> <appointment_time> <time_between_arrivals>'" << std::endl;
        return -1;
    }

    try
    {
        //arg[0] is the program name
        int seed = std::atoi(argv[1]);
        int sim_time = std::atoi(argv[2]);
        int num_doctors = std::atoi(argv[3]);
        int appointment_time = std::atoi(argv[4]);
        int time_between_arrival = std::atoi(argv[5]);

        std::srand(seed); // random seed, for reproducibility

        simulation sim(sim_time, num_doctors, appointment_time, time_between_arrival);
        sim.run_simulation();
        generate_statistics(sim);
    }
    catch (std::exception& e) // catch a std::exception
    {
        std::cout << "Standard exception caught: " << e.what() << std::endl;
        return -1;
    }
    catch (...) // catch anything else that may have been thrown
    {
        std::cout << "Unknown error occured." << std::endl;
        return -1;
    }

    return 0;
}
