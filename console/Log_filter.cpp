#include <iostream>
#include <fstream>
#include <string>

class Line
{
	public:
		std::string pid, thid, date, time, jid, message;
		Line();
};

Line::Line()
{
	pid = "";
	thid = "";
	date = "";
	time = "";
	jid = "";
	message = "";
}

void filter_result(Line log_line[], std::string user_input, int filter_type)
{

	
	std::string x = "";
	if (filter_type == 1)
	{
		int k = 0;
		while (k < 30)
		{
			int flag = 0;
			for (int it = 0; it < user_input.length(); it++)
			{
				if (user_input[it] == log_line[k].pid[it])
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
				std::cout << log_line[k].pid << "  " << log_line[k].thid << "  " << log_line[k].date << "  " << log_line[k].time << "  " << log_line[k].jid << " " << log_line[k].message << std::endl;
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
				if (user_input[it] == log_line[k].thid[it])
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
				std::cout << log_line[k].pid << "  " << log_line[k].thid << "  " << log_line[k].date << "  " << log_line[k].time << "  " << log_line[k].jid << " " << log_line[k].message << std::endl;
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
				if (user_input[it] == log_line[k].date[it])
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
				std::cout << log_line[k].pid << "  " << log_line[k].thid << "  " << log_line[k].date << "  " << log_line[k].time << "  " << log_line[k].jid << " " << log_line[k].message << std::endl;
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
				if (user_input[it] == log_line[k].time[it])
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
				std::cout << log_line[k].pid << "  " << log_line[k].thid << "  " << log_line[k].date << "  " << log_line[k].time << "  " << log_line[k].jid << " " << log_line[k].message << std::endl;
			}
			k++;
		}
	}
	else if (filter_type == 5)
	{
		int k = 0;
		while (k < 30)
		{
			int flag = 0;
			for (int it = 0; it < user_input.length(); it++)
			{
				if (user_input[it] == log_line[k].jid[it])
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
				std::cout << log_line[k].pid << "  " << log_line[k].thid << "  " << log_line[k].date << "  " << log_line[k].time << "  " << log_line[k].jid << " " << log_line[k].message << std::endl;
			}
			k++;
		}
	}
	else if (filter_type == 6)
	{
		int k = 0;
		while (k < 30)
		{
			int flag = 0;
			for (int it = 0; it < user_input.length(); it++)
			{
				if (user_input[it] == log_line[k].message[it])
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
				std::cout << log_line[k].pid << "  " << log_line[k].thid << "  " << log_line[k].date << "  " << log_line[k].time << "  " << log_line[k].jid << " " << log_line[k].message << std::endl;
			}
			k++;
		}
	}
}

int main()
{	
	std::fstream MyReadFile("logfile_try.txt");

	Line log_line[30];
	std::string myText;
	int i = 0;

	while (getline(MyReadFile, myText)) {
		std::string temp_str = myText;
		int j = 0;
		while (temp_str[j] != ' ')
		{
			log_line[i].pid += temp_str[j];
			j++;
		}
		j += 2;

		while (temp_str[j] != ' ')
		{
			log_line[i].thid += temp_str[j];
			j++;
		}
		j += 2;

		while (temp_str[j] != ' ')
		{
			log_line[i].date += temp_str[j];
			j++;
		}
		j += 2;

		while (temp_str[j] != ' ')
		{
			log_line[i].time += temp_str[j];
			j++;
		}
		j += 2;

		while (temp_str[j] != ' ')
		{
			log_line[i].jid += temp_str[j];
			j++;
		}
		j += 2;

		while (temp_str[j] != '\0')
		{
			log_line[i].message += temp_str[j];
			j++;
		}
		//cout << j << endl;
		i++;
	}

	std::string user_input;
	std::cin >> user_input;

	if (user_input.length() == 5 && user_input[0] != 'E' && user_input[2] != '/')
	{
		filter_result(log_line, user_input, 1);
	}
	else if (user_input.length() == 4)
	{
		filter_result(log_line, user_input, 2);
	}
	else if (user_input[2] == '/')
	{
		filter_result(log_line, user_input, 3);
	}
	else if (user_input.length() == 8)
	{
		filter_result(log_line, user_input, 4);
	}
	else if (user_input.length() == 1)
	{
		filter_result(log_line, user_input, 5);
	}
	else if (user_input[0] == 'E' || user_input[0] == 'I' || user_input[0] == 'S')
	{
		filter_result(log_line, user_input, 6);
	}

	MyReadFile.close();

	return 0;
}
