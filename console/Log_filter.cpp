#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Line
{
public:
	std::string pid, thid, jid, message;
	Line();
};

Line::Line()
{
	pid = "";
	thid = "";
	jid = "";
	message = "";
}

int main()
{	
	fstream MyReadFile("logfile_try.txt");

	Line container[30];
	string myText;
	int i = 0;

	while (getline(MyReadFile, myText)) {
		string temp_str = myText;
		int j = 0;
		while (temp_str[j] != ' ')
		{
			container[i].pid += temp_str[j];
			j++;
		}
		j += 2;

		while (temp_str[j] != ' ')
		{
			container[i].thid += temp_str[j];
			j++;
		}
		j += 19;

		while (temp_str[j] != ' ')
		{
			container[i].jid += temp_str[j];
			j++;
		}
		j += 2;

		while (temp_str[j] != '\0')
		{
			container[i].message += temp_str[j];
			j++;
		}
		//cout << j << endl;
		i++;
	}

	/*
	for (int k = 0; k < 30; k++)
	{
		cout << container[k].pid << "  " << container[k].thid << "  " << container[k].jid << " " << container[k].message << endl;
	}
	*/

	string user_input_pid, user_input_thid, user_input_jid;
	cin >> user_input_pid >> user_input_thid >> user_input_jid;

	int k = 0;

	while(k<30)
	{
		//cout << k << endl;
		int flag = 0;
		for (int it = 0; it < 5; it++)
		{
			if (user_input_pid[it] == container[k].pid[it])
			{
				flag++;
			}
			else
			{
				break;
			}
		}
		if (flag == 5)
		{
			cout << container[k].pid << "  " << container[k].thid << "  " << container[k].jid << " " << container[k].message << endl;
		}
		k++;
	}
	k = 0;

	while (k < 30)
	{
		//cout << k << endl;
		int flag = 0;
		for (int it = 0; it < 4; it++)
		{
			if (user_input_thid[it] == container[k].thid[it])
			{
				flag++;
			}
			else
			{
				break;
			}
		}
		if (flag == 4)
		{
			cout << container[k].pid << "  " << container[k].thid << "  " << container[k].jid << " " << container[k].message << endl;
		}
		k++;
	}
	k = 0;

	while (k < 30)
	{
		//cout << k << endl;
		int flag = 0;
		if (user_input_jid[0] == container[k].jid[0])
		{
			flag++;
		}
		if (flag == 1)
		{
			cout << container[k].pid << "  " << container[k].thid << "  " << container[k].jid << " " << container[k].message << endl;
		}
		k++;
	}
	k = 0;

	while (k < 30)
	{
		//cout << k << endl;
		int flag = 0;
		for (int it = 0; it < user_input_message.length(); it++)
		{
			if (user_input_message[it] == container[k].message[it])
			{
				flag++;
			}
			else
			{
				break;
			}
		}
		if (flag == user_input_message.length())
		{
			cout << container[k].pid << "  " << container[k].thid << "  " << container[k].jid << " " << container[k].message << endl;
		}
		k++;
	}

	MyReadFile.close();

	return 0;
}
