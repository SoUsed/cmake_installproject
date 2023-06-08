#ifndef CONFIGPARSE_HPP
#define CONFIGPARSE_HPP

#include <fstream>
#include <map>
#include <iostream>
#include <algorithm>

std::map<std::string, std::string> confread(std::ifstream& cFile) {
    std::map<std::string, std::string> ret;
    if (cFile.is_open())
    {
        std::string line;
        while(getline(cFile, line))
       {
            line.erase(std::remove_if(line.begin(), line.end(), isspace),
                                 line.end());
            if( line.empty() || line[0] == '#' )
            {
                continue;
            }
            auto delimiterPos = line.find("=");
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);
            ret[name] = value;
        }
    }
    else 
    {
        std::cerr << "Couldn't open config file for reading.\n";
    }
    return ret;
}

#endif // CONFIGPARSE_HPP