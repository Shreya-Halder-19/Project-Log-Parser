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

void filter_result(Line container[], string user_input, int filter_type)
{

	
	string x = "";
	if (filter_type == 1)
	{
		int k = 0;
		while (k < 30)
		{
			int flag = 0;
			for (int it = 0; it < user_input.length(); it++)
			{
				if (user_input[it] == container[k].pid[it])
				{
					flag++;
				}
				else
				{
					break;
				}
			}
			if (flag == user_input.length())
			{
				cout << container[k].pid << "  " << container[k].thid << "  " << container[k].jid << " " << container[k].message << endl;
			}
			k++;
		}
	}
	else if (filter_type == 2)
	{
		int k = 0;
		while (k < 30)
		{
			int flag = 0;
			for (int it = 0; it < user_input.length(); it++)
			{
				if (user_input[it] == container[k].thid[it])
				{
					flag++;
				}
				else
				{
					break;
				}
			}
			if (flag == user_input.length())
			{
				cout << container[k].pid << "  " << container[k].thid << "  " << container[k].jid << " " << container[k].message << endl;
			}
			k++;
		}
	}
	else if (filter_type == 3)
	{
		int k = 0;
		while (k < 30)
		{
			int flag = 0;
			for (int it = 0; it < user_input.length(); it++)
			{
				if (user_input[it] == container[k].jid[it])
				{
					flag++;
				}
				else
				{
					break;
				}
			}
			if (flag == user_input.length())
			{
				cout << container[k].pid << "  " << container[k].thid << "  " << container[k].jid << " " << container[k].message << endl;
			}
			k++;
		}
	}
	else if (filter_type == 4)
	{
		int k = 0;
		while (k < 30)
		{
			int flag = 0;
			for (int it = 0; it < user_input.length(); it++)
			{
				if (user_input[it] == container[k].message[it])
				{
					flag++;
				}
				else
				{
					break;
				}
			}
			if (flag == user_input.length())
			{
				cout << container[k].pid << "  " << container[k].thid << "  " << container[k].jid << " " << container[k].message << endl;
			}
			k++;
		}
	}
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

	string user_input_pid, user_input_thid, user_input_jid, user_input_message;
	cin >> user_input_pid >> user_input_thid >> user_input_jid >> user_input_message;
	
	filter_result(container, user_input_pid, 1);
	filter_result(container, user_input_thid, 2);
	filter_result(container, user_input_jid, 3);
	filter_result(container, user_input_message, 4);

	MyReadFile.close();

	return 0;
}
