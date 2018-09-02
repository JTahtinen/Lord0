#pragma once
#include <fstream>
#include <string>
#include <iostream>

namespace lord 
{

	inline std::string load_text_file(std::string path)
	{
		std::string output = "";
		std::string line;

		std::ifstream file(path);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				output.append(line + "\n");
			}
			file.close();
		}
		else
		{
			std::cout << "[ERROR] Could not load file: " << path << std::endl;
		}
		return output;
	}

}