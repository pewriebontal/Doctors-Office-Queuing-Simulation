#include "simulation.h"

/**
 * @brief Create the simulation using the provided parameters.
 * 
 * Postcondition: The simulations parameters are set, as provided.
 *                A doctors_office with the specified number of doctors has been created.
 *                The total_wait_time is set to 0.
 *                The patients_arrived is set to 0.
 * 
 * @param sim_time The simulation time, as the number of time steps.
 * @param num_doctors The number of doctors.
 * @param appointment_time The length of an appointment.
 * @param time_between_arrival The average time between patient arrivals.
 */
simulation::simulation(int sim_time,
					   int num_doctors,
					   int appointment_time,
					   int time_between_arrival)
	: sim_time(sim_time)
	, num_doctors(num_doctors)
	, appointment_time(appointment_time)
	, time_between_arrival(time_between_arrival)
	, patients_arrived(0)
	, total_wait_time(0)
	, office(num_doctors)
{ }

/**
 * @brief Destructor for a simulation.
 * 
 * Postcondition: The simulation is destroyed.
 */
simulation::~simulation()
{
	sim_time = 0;
	num_doctors = 0;
	appointment_time = 0;
	time_between_arrival = 0;
	patients_arrived = 0;
	total_wait_time = 0;
}

/**
 * @brief Run the simulation.
 * 
 * Postcondition: The simulation object has been updated as per the simulation.
 * 
 * Steps:
 * 1. Update the doctors_office to decrement the remaining appointment time of each busy doctor by one time unit.
 * 2. If the patient queue is non-empty, increment the waiting time of each patient by one time unit.
 *    Note: You'll have to get clever here since you don't have access to the individual entries in the queue!
 * 3. If a patient arrives (i.e., has_patient_arrived(...) returns true), display a message (using display_patient_arrived(...)),
 *    increment the number of patients by 1, add the new patient to the queue.
 * 4. If there is a free doctor and the patient queue is non-empty, remove a patient from the front of the queue,
 *    increment the total waiting time, and send the patient to the free doctor. Display an appropriate message (using display_patient_seen(...)).
 */
void simulation::run_simulation()
{
	for(int time = 0; time < sim_time; ++time)
	{
		// 1. Update the status of doctors
		office.update_doctors(time);

		// 2. Increment waiting time for each patient in the queue
		if(!waiting_queue.empty())
		{
			int queue_size = waiting_queue.size();
			for(int i = 0; i < queue_size; ++i)
			{
				patient pat = waiting_queue.dequeue();
				pat.increment_waiting_time();
				waiting_queue.enqueue(pat);
			}
		}

		// 3. Check if a new patient has arrived
		if(has_patient_arrived(time_between_arrival))
		{
			patient new_patient(patients_arrived++, time, 0, appointment_time);
			waiting_queue.enqueue(new_patient);
			display_patient_arrived(new_patient.get_patient_number(), time);
		}

		// 4. Assign patients to free doctors
		while(!waiting_queue.empty() && office.get_free_doctor_ID() != -1)
		{
			int free_doctor_id = office.get_free_doctor_ID();
			patient current_patient = waiting_queue.dequeue();
			total_wait_time += current_patient.get_waiting_time();
			office.set_doctor_busy(free_doctor_id, current_patient);
			display_patient_seen(free_doctor_id, current_patient.get_patient_number(), time);
		}
	}
}

/**
 * @brief Return a reference to the doctor's office used in the simulation.
 * 
 * Postcondition: A reference to the doctor's office is returned.
 * 
 * @return doctors_office& A reference to the doctor's office.
 */
doctors_office& simulation::get_office()
{
	return (office);
}

/**
 * @brief Return a reference to the patient queue used in the simulation.
 * 
 * Postcondition: A reference to the patient queue is returned.
 * 
 * @return LQueue<patient>& A reference to the patient queue.
 */
LQueue<patient>& simulation::get_patient_queue()
{
	return (waiting_queue);
}

/**
 * @brief Return the total time patients spent waiting during the simulation.
 * 
 * Postcondition: The value of the total waiting time is returned.
 * 
 * @return int The total waiting time of all patients.
 */
int simulation::get_total_wait_time()
{
	return (total_wait_time);
}

/**
 * @brief Return the number of patients that arrived throughout the simulation.
 * 
 * Postcondition: The number of patients that arrived is returned.
 * 
 * @return int The number of patients that arrived.
 */
int simulation::get_num_patients_arrived()
{
	return (patients_arrived);
}
