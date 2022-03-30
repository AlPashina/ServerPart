
#include "ServerController.h"
int main()
{
	setlocale(LC_CTYPE, "rus");
	ServerController s = ServerController();
	s.Run();
}



//
//#include <iostream>
//#include<fstream>
//#include <Windows.h>
//#include<string>
//#include"PatientController.h"
//
//int main()
//{
//	setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
//	//patient_card PC = patient_card(10);
//	TQueue<int> s = TQueue<int>(10);
//	s.Push(1);
//	s.Print();
//	std::fstream fin;
//	std::string _path = "Patients/patient_";
//	bool fileCheck = true;
//	for (int i = 0;; i++) {
//		std::string fullpath = _path + std::to_string(i) + ".txt";
//		fin.open(fullpath);
//		if (fin.is_open()) {
//			Patient p;
//			fin >> p.Name >> p.Surname >> p.Patronimic;
//			fin >> p.Year >> p.Gender;
//			std::cout << p.Name << p.Surname << p.Patronimic;//
//			std::cout << p.Year << p.Gender;//
//			_pQueuePatient->Push(p);
//
//			fin.close();
//		}
//		else {
//			break;
//		}
//	}
//}



/*
int main() {
	setlocale(LC_ALL, "Russian");
//	TStack<char> vstack = TStack<char>(10);
//	vstack.Push('d');
	/*	TQueue<char>vq = TQueue<char>(10);
		vq.Push('a');
		vq.Push('b');
		vq.Push('c');
		cout << vq.Pop();
		*/
//	CardWorker a= CardWorker();
//	a.ParseCards();
	//a.GetPatient();
//	return 0;
//}

/*
	int main(){
		Doctor d=Doctor();
		while(true){
			string command="" ;
			std::cin>>command;
			if (command=="get"){
				d.GetNextP();
				d.PrintCurrPat();
			}
			else{break;}
		}
	
	}

*/