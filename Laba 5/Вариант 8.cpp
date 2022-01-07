#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct scan_info {
	string model; // наименование модели 
	int price; // цена
	double x_size; // горизонтальный размер области сканирования
	double y_size; // вертикальный размер области сканирования 
	int optr; // оптическое разрешение
	int grey; // число градаций серого
};



std::ostream& operator <<(std::ostream& scan_fyle, const vector<scan_info>& records)
{
	size_t l = records.size();
	for (size_t i = 0; i<l; i++)
	cout << "Model: " << records[i].model
		 << "\nPrice: " << records[i].price
		 << "\nx_size: " << records[i].x_size
		 << "\ny_size: " << records[i].y_size
		 << "\noptr: " << records[i].optr
		 << "\ngrey: " << records[i].grey << "\n";
	return scan_fyle;
}

std::ofstream& operator <<(std::ofstream& scan_fyle, vector<scan_info>& records)
{
	scan_fyle.seekp(0, ios::beg);
	size_t l = records.size();
	scan_fyle.write(reinterpret_cast<char*>(&l), sizeof(int));
	for (auto& rec : records) {
		size_t len = rec.model.size();
		scan_fyle.write(reinterpret_cast<char*>(&len), sizeof(size_t));
		scan_fyle.write(rec.model.c_str(), len);
		scan_fyle.write(reinterpret_cast<char*>(&rec.price), sizeof(rec.price));
		scan_fyle.write(reinterpret_cast<char*>(&rec.x_size), sizeof(rec.x_size));
		scan_fyle.write(reinterpret_cast<char*>(&rec.y_size), sizeof(rec.y_size));
		scan_fyle.write(reinterpret_cast<char*>(&rec.optr), sizeof(rec.optr));
		scan_fyle.write(reinterpret_cast<char*>(&rec.grey), sizeof(rec.grey));	}
	return scan_fyle;
}

void add_to_vectorScan(scan_info &rec)
{
	cout << "Введите данные о сканере:";
	cin >> rec.model >> rec.price >> rec.x_size >> rec.y_size >> rec.optr >> rec.grey;
	while (cin.fail())
	{
		cin >> rec.model >> rec.price >> rec.x_size >> rec.y_size >> rec.optr >> rec.grey;
	}
}

void add_record(std::ofstream& scan_fyle, vector<scan_info>& records) //функция добавления новых записей
{
	
	size_t l = records.size();
	scan_info empty{ "",0,0,0,0,0 };
	if (records.size() != 0)
	{
		records.push_back(records[l - 1]);
		for (int i = l; i > 0; i--)
		{
			records[i] = records[i - 1];
		}
		add_to_vectorScan(records[0]);
	}
	else
	{
		records.push_back(empty);
		add_to_vectorScan(records[0]);
	}
	scan_fyle << records;
}

int main()
{
	setlocale(LC_ALL, "Rus");
    int numRecord;

	ofstream fout("C:\\Users\\mrgam\\source\\repos\\newoutput.bin", ios_base::binary | ios_base::out);
	vector<scan_info> records
	{   
		{"Scaner1", 1000 ,2.5 ,3.4 ,20 ,500},
		{"Scaner2", 1210 ,2.5 ,4.4 ,20 ,600},
		{"Scaner3", 800 ,5.5 ,6.4 ,30 ,800}
	};
	fout << records;
	
	cout << "Введите количество записей, которые хотите добавить: ";
	cin >> numRecord;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введены некоректные данные. Введите заного: ";
		cin >> numRecord;
	}
	
	for (size_t i = 0; i < numRecord; i++)
	{
		add_record(fout, records);
	}

	fout.close();
	return 0;
}
