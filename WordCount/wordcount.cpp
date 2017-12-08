/*
Samuel J. Grenon
Cameron K. Titus
Jim A. Samson
wordcount.cpp
This program counts and stores strings in an unordered map from a txt file.
*/

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

/*
main()
The main function prompts a user for a filename. If the filename can't open or
dosen't exist the program will ask you to try again. If the ifstream can open the file
we use the stream insertion operator to insert the contents into a string. We store its contents
in an unordered_map. We increment the count if we have repeated keys.
*/
int main()
{
	std::string _name, buffer;
	std::ifstream _inputFile;
	std::unordered_map<std::string, size_t> hashmap;

	std::cout << "Please enter your file name." << std::endl;
	while (std::getline(std::cin, _name))
	{		
		_inputFile.open(_name);

		if (!_inputFile)
		{
			std::cerr << "Unable to open filename please try again. " << _name << std::endl;
			continue;
		}
		break;
	}

	while (_inputFile >> buffer)
	{
		hashmap[buffer]++;
	}

	for (const auto &s : hashmap) {
		std::cout << s.first << " " << s.second << std::endl;
		
	}

	std::cout << "Press ENTER to quit ";
	while (std::cin.get() != '\n');
	
}



	

	

	
	
	

	

	
	




			

