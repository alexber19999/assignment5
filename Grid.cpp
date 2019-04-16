#include "Grid.h"

std::vector<std::vector<float> > Grid::parseFile(std::string fileName) {

        std::vector<float> lineParsed;
        std::vector<std::vector<float> > fileParsed;

        std::ifstream infile;
        infile.open(fileName.c_str());
        char ch;

        std::string line;

        if(!infile.fail()){
            while(std::getline(infile, line)){
                std::istringstream ss(line);
                for(std::string s; ss >> s; ) {
                    float temp = std::atof(s.c_str());
                    lineParsed.push_back(temp);
                }
                fileParsed.push_back(lineParsed);
                lineParsed.clear();

            }
        }
        return fileParsed;

}