#pragma once
#include "CardWorker.h"

class PatientController
{
private:
	CardWorker cw;
	TQueue<Patient> Patients;
public:

	PatientController():Patients(10) {
		Parser();
	}

	void Parser() {
		std::string list = cw.ParseCard();
		Patient pat;
		std::string tmp;
		for (int i = 0; i < list.length(); i++) {
			while (list[i] != '\n')
			{
				tmp += list[i++];
			}
			pat.FIO = tmp;
			tmp = "";
			i++;
			while (list[i] != '\n')
			{
				tmp += list[i++];
			}
			pat.Born_Date = tmp;
			tmp = "";
			i++;
			while (list[i] != '\n')
			{
				tmp += list[i++];
			}
			pat.Gender = tmp;
			tmp = "";
			Patients.push(pat);
		}

	}
	Patient GetPatient(){
		return Patients.pop();
	}


};
