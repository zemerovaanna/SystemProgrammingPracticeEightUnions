#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

struct Person {
	char name[100];
	int age;
	union {
		struct {
			char fatherName[100];
			char motherName[100];
		} parents;
		int passportNumber;
	};
};

Person people[5];

int main() {

	setlocale(LC_ALL, "ru");
	strcpy(people[0].name, "Денис Евгеньевич Сладков");
	people[0].age = 18;
	//strcpy(people[0].parents.fatherName, "Евгений Витальевич Сладков");
	//strcpy(people[0].parents.motherName, "Анна Викторовна Сладкова");
	people[0].passportNumber = 1;

	strcpy(people[1].name, "Вася Иванович Иванов");
	people[1].age = 5;
	strcpy(people[1].parents.fatherName, "Иван Алексеевич Иванов");
	strcpy(people[1].parents.motherName, "Наталья Петровна Иванова");
	//people[1].passportNumber = 2;

	strcpy(people[2].name, "Василина Петровна Петрова");
	people[2].age = 16;
	//strcpy(people[2].parents.fatherName, "Пётр Петрович Петров");
	//strcpy(people[2].parents.motherName, "Лариса Васильевна Петрова");
	people[2].passportNumber = 3;

	strcpy(people[3].name, "Алёна Александровна Калинова");
	people[3].age = 10;
	strcpy(people[3].parents.fatherName, "Александр Витальевич Калинов");
	strcpy(people[3].parents.motherName, "Камила Игнатьевна Калинова");
	//people[3].passportNumber = 4;

	strcpy(people[4].name, "Игнат Михайлович Серафимов");
	people[4].age = 17;
	//strcpy(people[4].parents.fatherName, "Михаил Алексеевич Серафимов");
	//strcpy(people[4].parents.motherName, "Мария Евгеньевна Серафимова");
	people[4].passportNumber = 2;

	cout << "Список граждан:" << endl;
	for (int i = 0; i < sizeof(people) / sizeof(people[0]); i++)
	{
		cout << "Имя:" << people[i].name << endl;
		cout << "Возраст:" << people[i].age << endl;
		if (people[i].age >= 16)
		{
			cout << "Паспорт:" << people[i].passportNumber << endl;
		}
		else
		{
			cout << "Отец:" << people[i].parents.fatherName << endl;
			cout << "Мать:" << people[i].parents.motherName << endl;
		}
		cout << endl;
	}

	for (int i = 0; i < sizeof(people) / sizeof(people[0]) - 1; i++) {
		for (int j = i + 1; j < sizeof(people) / sizeof(people[0]); j++) {
			if (people[i].passportNumber > people[j].passportNumber) {
				Person temp = people[i];
				people[i] = people[j];
				people[j] = temp;
			}
		}
	}

	cout << "Список граждан не моложе 16 лет, упорядоченный по номеру паспорта:" << endl;
	for (int i = 0; i < sizeof(people) / sizeof(people[0]); i++) {
		if (people[i].age >= 16)
		{
			cout << "Имя: " << people[i].name << endl;
			cout << "Возраст: " << people[i].age << endl;
			cout << "Паспорт: " << people[i].passportNumber << endl;
			cout << "" << endl;
		}
	}

	return 0;
}