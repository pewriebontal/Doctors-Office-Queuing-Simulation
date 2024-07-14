#include "doctors_office.h"

doctors_office::doctors_office(int num_docs)
	: num_doctors(num_docs)
{
	doctors.resize(num_docs);
}

doctors_office::~doctors_office() { }

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

void doctors_office::set_doctor_busy(int doc_ID, const patient& pat, int app_time)
{
	doctors[doc_ID].set_busy();
	doctors[doc_ID].set_current_patient(pat);
	doctors[doc_ID].set_remaining_appointment_time(app_time);
}

void doctors_office::set_doctor_busy(int doc_ID, const patient& pat)
{
	doctors[doc_ID].set_busy();
	doctors[doc_ID].set_current_patient(pat);
	doctors[doc_ID].set_remaining_appointment_time();
}

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
