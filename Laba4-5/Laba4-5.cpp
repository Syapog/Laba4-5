#include <iostream>
#include <fstream>
using namespace std;

class Kv
{
private:
	int nom_n = 1;
	int etaj_n = 1;
	int S_n = 30;
	int komn_n = 2;
	int stoim_n = 90;
public:
	Kv(int nom, int etaj, int S, int komn, int stoim)
	{
		nom_n = nom;
		etaj_n = etaj;
		S_n = S;
		komn_n = komn;
		stoim_n = stoim;
	}
	void Vivod()
	{
		setlocale(LC_ALL, "ru");
		cout << "Номер квартиры: " << nom_n << ", Этаж: " << etaj_n << ", Площать: " << S_n << ", Кол-во комнат: " << komn_n << ", Стоимость Т/Р: " << stoim_n << endl;
	}
	int GetStoim()
	{
		return stoim_n;
	}
	void Dannie()
	{
		ofstream fout;
		fout.open("Данные.txt", ofstream::app);
		if (!fout.is_open())
		{
			cout << "Ошибка открытия" << endl;
		}
		else
		{
			fout << "Номер квартиры: " << nom_n << ", Этаж: " << etaj_n << ", Площать: " << S_n << ", Кол-во комнат: " << komn_n << ", Стоимость Т/Р: " << stoim_n << endl;

		}
		fout.close();
	}
};

void main()
{
	setlocale(LC_ALL, "ru");

	const int SIZE = 5;
	Kv arry[SIZE] { Kv(1, 1, 30, 2, 90), Kv(3, 1, 25, 2, 65), Kv(7, 3, 40, 3, 120), Kv(10, 4, 35, 3, 100), Kv(16, 5, 60, 4, 150) };
	arry[0].Vivod();
	arry[1].Vivod();
	arry[2].Vivod();
	arry[3].Vivod();
	arry[4].Vivod();

	arry[0].Dannie();
	arry[1].Dannie();
	arry[2].Dannie();
	arry[3].Dannie();
	arry[4].Dannie();

	cout << "Введите ваше кол-во денег: ";
	int a;
	cin >> a;

	for (int i = 0; i < SIZE; i++)
	{
		if (arry[i].GetStoim() <= a)
		{
			arry[i].Vivod();
			arry[i].Dannie();
		}
	}

	ifstream ifs;
	ifs.open("Данные.txt");

	if (!ifs.is_open())
	{
		cout << "Ошибка открытия" << endl;
	}
	else
	{
		cout << "Файл открыт" << endl;
		string str;

		while (!ifs.eof())
		{
			ifs >> str;
			cout << str << " ";
		}
	}
	ifs.close();
}

