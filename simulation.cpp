#include "simulation.h"

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

simulation::~simulation() { }
void simulation::run_simulation()
{
	for(int time = 0; time < sim_time; ++time)
	{
		office.update_doctors(time);

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

		if(has_patient_arrived(time_between_arrival))
		{
			patient new_patient(patients_arrived++, time, 0, appointment_time);
			waiting_queue.enqueue(new_patient);
			display_patient_arrived(new_patient.get_patient_number(), time);
		}

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

doctors_office& simulation::get_office()
{
	return (office);
}

LQueue<patient>& simulation::get_patient_queue()
{
	return (waiting_queue);
}

int simulation::get_total_wait_time()
{
	return (total_wait_time);
}

int simulation::get_num_patients_arrived()
{
	return (patients_arrived);
}
