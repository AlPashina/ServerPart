#pragma once

#include "TQueue.h"
#include <filesystem>
#include <string>
#include <fstream>
#include "Patient.h"
namespace fs = std::filesystem;


class CardWorker
{
private:
	std::string Path;
	int Quantity;
public:
	CardWorker()
	{
		Path = "Patients/";
		Quantity = 10;
	}

	std::string ParseCard()
	{
		setlocale(LC_ALL, "rus");
		Patient pat;
		std::string list_patients;
		for (const auto& entry : fs::directory_iterator(Path))
		{
			std::ifstream fin(entry.path());
			std::string tmp;
			std::getline(fin, tmp);
			list_patients += tmp;
			list_patients += '\n';
			std::getline(fin, tmp);
			list_patients += tmp;
			list_patients += '\n';
			std::getline(fin, tmp);
			list_patients += tmp;
			list_patients += '\n';
			fin.close();
		}
		return list_patients;
	}
};
