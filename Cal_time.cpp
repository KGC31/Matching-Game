#include"Cal_time.h"

void write_file(string filename, point t)
{
	ofstream os(filename,ios::app);
	if (!os)
	{
		cout << "Can't open file" << endl;
	}
	os << t.name << "-" << t.num << "\n";
	os.close();
}

vector<point> read_file(string filename)// vector<point>& arr)
{
	ifstream is;
	
	is.open(filename);
	if (!is.is_open())
		cout << "Can't open file" << endl;
	vector<point> arr;
	string name = "";
	string p = "";
	point temp;
	while (!is.eof())
	{
		getline(is, name, '-');
		getline(is, p, '\n');
		temp.name = name;
		temp.num = stof(p);
		//float n;
		//is >> n;
		arr.push_back(temp);
	}
	
	is.close();
	arr.pop_back();
	vector<point> arr1 = sorted(arr);
	return arr1;
}

vector<point> sorted(vector<point> arr)
{
	for(int i = 0; i < arr.size();i++)
		for(int j = i+ 1; j <arr.size();j++)
			if (arr[j].num < arr[i].num)
			{
				point temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	return arr;
}

void leaderboard(vector<point> arr)
{
	color(2);
	Gotoxy(15, 0);
	cout << " _____                  __                  ______                      __ " << endl;
	Gotoxy(15, 1);
	cout << "|     |_.-----.---.-.--|  |.-----.----.    |   __  .-----.---.-.----.--|  |" << endl;
	Gotoxy(15, 2);
	cout << "|       |  -__|  _  |  _  ||  -__|   _|    |   __ <|  _  |  _  |   _|  _  |" << endl;
	Gotoxy(15, 3);
	cout << "|_______|_____|___._|_____||_____|__|      |______/|_____|___._|__| |_____|" << endl;
	
	for (int i = 0; i < 5; i++) {
		Gotoxy(42, 5 + i);
		cout << i + 1 << ". " << arr[i].name<<" - "<<arr[i].num << endl;
	}
}


void printleaderboard()
{
	system("cls");
	vector<point> a = read_file("time.txt");
	leaderboard(a);
	system("pause");
	system("cls");
	boardview();
}