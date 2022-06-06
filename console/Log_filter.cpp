#include <iostream>
#include <fstream>
#include <string>

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

void filter_result(Line container[], std::string user_input, int filter_type)
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
				std::cout << container[k].pid << "  " << container[k].thid << "  " << container[k].jid << " " << container[k].message << std::endl;
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
				std::cout << container[k].pid << "  " << container[k].thid << "  " << container[k].jid << " " << container[k].message << std::endl;
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
				std::cout << container[k].pid << "  " << container[k].thid << "  " << container[k].jid << " " << container[k].message << std::endl;
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
				std::cout << container[k].pid << "  " << container[k].thid << "  " << container[k].jid << " " << container[k].message << std::endl;
			}
			k++;
		}
	}
}

int main()
{	
	std::fstream MyReadFile("logfile_try.txt");

	Line container[30];
	std::string myText;
	int i = 0;

	while (getline(MyReadFile, myText)) {
		std::string temp_str = myText;
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

	std::string user_input;
	std::cin >> user_input;

	if (user_input.length() == 5 && user_input[0] != 'E')
	{
		filter_result(container, user_input, 1);
	}
	else if (user_input.length() == 4)
	{
		filter_result(container, user_input, 2);
	}
	else if (user_input.length() == 1)
	{
		filter_result(container, user_input, 3);
	}
	else if (user_input[0] == 'E' || user_input[0] == 'I' || user_input[0] == 'S')
	{
		filter_result(container, user_input, 4);
	}

	MyReadFile.close();

	return 0;
}
