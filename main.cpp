#include<iostream>
#include "Grid.h"


/*
 * vector[0] = rowNumber
 * vector[1] = colNumber
 * */

std::vector<int> checkNearestNeighbors(std::vector<std::vector<float> > grid, std::vector<int> position){

}

std::vector<int> getLocalMinimum(std::vector<std::vector<float> > grid, std::vector<int> position){
    std::vector<int> currPos = checkNearestNeighbors(grid, position);
    if(currPos[0] == position[0] && currPos[1] == position[1]){
        return currPos;
    } else {
        checkNearestNeighbors(grid, currPos);
    }
}


int main(int argc, char *argv[]){
    Grid grid;
    std::string file = argv[1];
    std::vector <std::vector<float> > fileGrid = grid.parseFile(file);
    for(int i = 0; i < fileGrid.size(); i++){
        for(int j = 0; j < fileGrid[i].size(); j++){
            std::cout << fileGrid[i][j] << " ";
        }
        std::cout << std::endl;

    }
}
