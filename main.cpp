#include<iostream>
#include "Grid.h"


/*
 * vector[0] = rowNumber
 * vector[1] = colNumber
 * */

std::vector<int> checkNearestNeighbors(std::vector<std::vector<float> > grid, std::vector<int> position){
    int rowNumber = position[0];
    int colNumber = position[1];

    std::vector<int> newPos;

    if(rowNumber == 0 && colNumber == 0){
        int right = grid[rowNumber][colNumber + 1];
        int below = grid[rowNumber + 1][colNumber];
        int diag = grid[rowNumber + 1][colNumber + 1];

        int minimum = std::min({right, below, diag});

        if(minimum == right){
            newPos.push_back(rowNumber);
            newPos.push_back(colNumber + 1);
        } else if(minimum == below){
            newPos.push_back(rowNumber + 1);
            newPos.push_back(colNumber);
        } else{
            newPos.push_back(rowNumber + 1);
            newPos.push_back(colNumber + 1);
        }

    } else if(rowNumber == 0 && colNumber == grid[0].size() - 1){
        int left = grid[rowNumber][colNumber  - 1];
        int below = grid[rowNumber + 1][colNumber];
        int diag = grid[rowNumber + 1][colNumber - 1];

        int minimum = std::min({left, below, diag});

        if(minimum == left){
            newPos.push_back(rowNumber);
            newPos.push_back(colNumber - 1);
        } else if(minimum == below){
            newPos.push_back(rowNumber + 1);
            newPos.push_back(colNumber);
        } else{
            newPos.push_back(rowNumber + 1);
            newPos.push_back(colNumber - 1);
        }

    } else if(rowNumber == 0 && colNumber != grid[0].size() - 1){

    } else if(rowNumber != grid.size() - 1 && colNumber == 0){

    } else if(rowNumber != grid.size() - 1 && colNumber != grid[0].size() - 1){

    } else if(rowNumber != grid.size() - 1 && colNumber == grid[0].size() - 1){

    } else if(rowNumber == grid.size() - 1 && colNumber == 0){

    } else if(rowNumber == grid.size() - 1 && colNumber != grid[0].size() - 1){

    } else if(rowNumber == grid.size() - 1 && colNumber == grid[0].size() - 1){

    }

    return newPos;
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
