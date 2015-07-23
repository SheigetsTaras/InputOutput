#include <fstream>
#include <iostream>
#include <ctime>

int main()
{
	/*srand(time(0));
	std::ofstream inTXT("INPUT.TXT");

	for(int i = 0 ; i < 100 ; i++)
	inTXT << rand() % 2;

	inTXT.close();*/


	std::ifstream in("INPUT.TXT", std::ifstream::binary);

	if (!in.is_open())
	{
		std::cout << "Can not open file!" << std::endl;
	}
	else
	{
		in.seekg(0, in.end);	//переходим в конец файда
		int length = in.tellg();	//получаем количесво символов в файле
		in.seekg(0, in.beg);	// возвращаемся на начало

		char *buff = new char[length];
		int current_zero = 0;
		int max_zero = 0;

		in.read(buff, length);
		if (in)
		{
			for (int i = 0; i < length; i++)
			{
				if (buff[i] == '0')
				{
					current_zero++;
				}
				else
				{
					if (max_zero < current_zero)
						max_zero = current_zero;
					current_zero = 0;
				}

			}
		}
		else
		{
			std::cout << "Error read file" << std::endl;
		}
		in.close();

		std::cout << max_zero;

		std::ofstream out("OUTPUT.txt");
		if (out)
		{
			for (int i = 0; i < max_zero; i++)
				out << '0';
		}
		out.close(); 

		delete []buff;
	}
}