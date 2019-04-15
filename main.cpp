#include<iostream>
#include "Grid.h"

int main(int argc, char *argv[]){
    Grid grid;
    std::string file = argv[1];
    std::vector <std::vector<double> > fileGrid = grid.parseFile(file);
    std::cout << fileGrid.size() << std::endl;
    for(int i = 0; i < fileGrid.size(); i++){
        for(int j = 0; j < fileGrid[i].size(); j++){
            std::cout << fileGrid[i][j] << " ";
        }
        std::cout << std::endl;

    }
}
