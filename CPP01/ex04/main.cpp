#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}

	std::ifstream	infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return (1);
	}

	std::string	content;
	std::string	line;

	while (std::getline(infile, line))
	{
		content += line;
		if (!infile.eof())
			content += "\n";
	}
	infile.close();

	std::string	outfilename = filename + ".replace";
	std::size_t	pos = 0;

	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}

	std::ofstream	outfile(outfilename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: Cannot create file " << outfilename << std::endl;
		return (1);
	}

	outfile << content;
	outfile.close();

	return (0);
}
