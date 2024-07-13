#include "doctor.h"

doctor::doctor()
	: remaining_appointment_time(0)
{
	is_busy = false;
}

doctor::~doctor() { }

bool doctor::is_free() const
{
	return (!is_busy);
}

void doctor::set_busy()
{
	is_busy = true;
}

void doctor::set_free()
{
	is_busy = false;
}

void doctor::set_remaining_appointment_time(int t)
{
	remaining_appointment_time = t;
}

void doctor::set_remaining_appointment_time()
{
	remaining_appointment_time = current_patient.get_appointment_length();
}

int doctor::get_remaining_appointment_time() const
{
	return (remaining_appointment_time);
}

void doctor::decrement_remaining_appointment_time()
{
	remaining_appointment_time--;
}

void doctor::set_current_patient(const patient& pat)
{
	current_patient = pat;
}

int doctor::get_current_patient_number() const
{
	return (current_patient.get_patient_number());
}
int doctor::get_current_patient_arrival_time() const
{
	return (current_patient.get_arrival_time());
}

int doctor::get_current_patient_waiting_time() const
{
	return (current_patient.get_waiting_time());
}

int doctor::get_current_patient_appointment_length() const
{
	return (current_patient.get_appointment_length());
}
