#include<iostream>
#include "Grid.h"


/*
 * vector[0] = rowNumber
 * vector[1] = colNumber
 * */

std::vector<std::vector<int> > getNearestNeighbors(std::vector<std::vector<float> > grid, std::vector<int> position){
    int rowNumber = position[0];
    int colNumber = position[1];

    int current = grid[rowNumber][colNumber];

    std::vector<std::vector<int> > newGrid;

    if(rowNumber == 0 && colNumber == 0){
        for(int i = rowNumber; i < rowNumber + 2; i++){
            std::vector<int> row;
            for(int j = colNumber; j < colNumber + 2; j++){
                row.push_back(i);
                row.push_back(j);
            }
            newGrid.push_back(row);
        }

    } else if(rowNumber == 0 && colNumber == grid[0].size() - 1){
        for(int i = rowNumber; i < rowNumber + 2; i++){
            std::vector<int> row;
            for(int j = colNumber - 1; j >= colNumber; j--){
                row.push_back(i);
                row.push_back(j);
            }
            newGrid.push_back(row);
        }
    } else if(rowNumber == 0 && colNumber != grid[0].size() - 1){
        for(int i = rowNumber - 1; i < rowNumber + 2; i++){
            std::vector<int> row;
            for(int j = colNumber; j <= colNumber + 1; j++){
                row.push_back(i);
                row.push_back(j);
            }
            newGrid.push_back(row);
        }
    } else if(rowNumber != grid.size() - 1 && colNumber == 0){
        for(int i = rowNumber; i < rowNumber + 2; i++){
            std::vector<int> row;
            for(int j = colNumber - 1; j <= colNumber + 1; j++){
                row.push_back(i);
                row.push_back(j);
            }
            newGrid.push_back(row);
        }
    } else if(rowNumber != grid.size() - 1 && colNumber != grid[0].size() - 1){
        for(int i = rowNumber - 1; i < rowNumber + 2; i++){
            std::vector<int> row;
            for(int j = colNumber - 1; j <= colNumber + 1; j++){
                row.push_back(i);
                row.push_back(j);
            }
            newGrid.push_back(row);
        }
    } else if(rowNumber != grid.size() - 1 && colNumber == grid[0].size() - 1){
        for(int i = rowNumber - 1; i < rowNumber + 2; i++){
            std::vector<int> row;
            for(int j = colNumber - 1; j <= colNumber; j++){
                row.push_back(i);
                row.push_back(j);
            }
            newGrid.push_back(row);
        }
    } else if(rowNumber == grid.size() - 1 && colNumber == 0){
        for(int i = rowNumber - 1; i <= rowNumber; i++){
            std::vector<int> row;
            for(int j = colNumber; j <= colNumber + 1; j++){
                row.push_back(i);
                row.push_back(j);
            }
            newGrid.push_back(row);
        }
    } else if(rowNumber == grid.size() - 1 && colNumber != grid[0].size() - 1){
        for(int i = rowNumber - 1; i < rowNumber + 1; i++){
            std::vector<int> row;
            for(int j = colNumber - 1; j <= colNumber + 1; j++){
                row.push_back(i);
                row.push_back(j);
            }
            newGrid.push_back(row);
        }
    } else if(rowNumber == grid.size() - 1 && colNumber == grid[0].size() - 1){
        for(int i = rowNumber - 1; i < rowNumber + 1; i++){
            std::vector<int> row;
            for(int j = colNumber - 1; j < colNumber + 1; j++){
                row.push_back(i);
                row.push_back(j);
            }
            newGrid.push_back(row);
        }
    }

    return newGrid;
}

std::vector<int> getLowestPoint(std::vector<std::vector<int> > newGrid, std::vector<std::vector<float> > grid){
    std::vector<int> lowest = newGrid[0];

    for(int i = 0; i < newGrid.size(); i++){
        // if the weight on the grid of the newGrid is lower than the currently lowest point
        if(grid[newGrid[i][0]][newGrid[i][1]] < grid[lowest[0]][lowest[1]]){
            lowest[0] = newGrid[i][0];
            lowest[1] = newGrid[i][1];
        }
    }

    return lowest;
}

std::vector<int> checkNearestNeighbors(std::vector<std::vector<float> > grid, std::vector<int> position){
    int rowNumber = position[0];
    int colNumber = position[1];

    int current = grid[rowNumber][colNumber];

    std::vector<int> newPos;

    std::vector<std::vector<int> > newGrid = getNearestNeighbors(grid, position);
    newPos = getLowestPoint(newGrid, grid);
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
