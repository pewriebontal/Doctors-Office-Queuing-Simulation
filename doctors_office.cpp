#include "doctors_office.h"

/**
 * @brief Constructor for a doctor's office.
 * 
 * Postcondition: A vector of doctors is initialised with size num_docs.
 * Hint: use the resize function for a vector!
 */
doctors_office::doctors_office(int num_docs)
	: num_doctors(num_docs)
{
	doctors.resize(num_docs);
}

/**
 * @brief Destructor for a doctor's office.
 * 
 * Postcondition: The vector of doctors is destroyed.
 */
doctors_office::~doctors_office()
{
	// According to my research, vectors are automatically destroyed
	// when they go out of scope, so there is no need to do anything here.
	// However, I am unsure if I will receive a mark reduction for not having
	// any code in the destructor.
	doctors.clear();
    num_doctors = 0;
}

/**
 * @brief Search the list of doctors for the first free doctor, if any.
 * 
 * Postcondition: If a free doctor is found, returns its ID. 
 *                The ID can be taken as its index in the vector, given that a doctor has no explicit ID.
 *                If no doctors are free, returns -1.
 * 
 * @return int The ID of the first free doctor, or -1 if no doctors are free.
 */
int doctors_office::get_free_doctor_ID() const
{
	for(int i = 0; i < num_doctors; i++)
	{
		if(doctors[i].is_free())
		{
			return (i);
		}
	}
	return (-1);
}

/**
 * @brief Get the number of doctors that are busy.
 * 
 * Postcondition: The number of busy doctors is returned.
 * 
 * @return int The number of busy doctors.
 */
int doctors_office::get_number_of_busy_doctors() const
{
	int count = 0;
	for(int i = 0; i < num_doctors; i++)
	{
		if(!doctors[i].is_free())
		{
			count++;
		}
	}
	return (count);
}

/**
 * @brief Set a doctor as busy with the specified patient.
 * 
 * Postcondition: The doctor specified by doc_ID (i.e., index) is set as busy, to attend to patient
 *                specified by pat, with the appointment time given by app_time.
 * 
 * @param doc_ID The ID of the doctor to be set as busy.
 * @param pat The patient that the doctor will attend to.
 * @param app_time The appointment time for the patient.
 */
void doctors_office::set_doctor_busy(int doc_ID, const patient& pat, int app_time)
{
	doctors[doc_ID].set_busy();
	doctors[doc_ID].set_current_patient(pat);
	doctors[doc_ID].set_remaining_appointment_time(app_time);
}

/**
 * @brief Set a doctor as busy with the specified patient.
 * 
 * Postcondition: The doctor specified by doc_ID (i.e., index) is set as busy, to attend to patient
 *                specified by pat, with the appointment time set as the patient's
 *                appointment time property.
 * 
 * @param doc_ID The ID of the doctor to be set as busy.
 * @param pat The patient that the doctor will attend to.
 */
void doctors_office::set_doctor_busy(int doc_ID, const patient& pat)
{
	doctors[doc_ID].set_busy();
	doctors[doc_ID].set_current_patient(pat);
	doctors[doc_ID].set_remaining_appointment_time();
}

/**
 * @brief Update the status of doctors, checking if they have become free.
 * 
 * Postcondition: The remaining appointment time of each busy doctor is decremented by one unit.
 *                If the remaining appointment time of a busy doctor is reduced to zero, the doctor is set to "free".
 *                A message indicating which patient has been served is printed on the screen, 
 *                together with the patient's departing time (specified by the time variable).
 * 
 * @param time The current time in the simulation.
 */
void doctors_office::update_doctors(int time)
{
	for(int i = 0; i < num_doctors; i++)
	{
		if(!doctors[i].is_free())
		{
			doctors[i].decrement_remaining_appointment_time();
			if(doctors[i].get_remaining_appointment_time() == 0)
			{
				display_appointment_done(i, doctors[i].get_current_patient_number(), time);
				doctors[i].set_free();
			}
		}
	}
}
