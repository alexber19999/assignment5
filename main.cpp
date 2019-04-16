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

    if(rowNumber == 0 && colNumber == 0){
        //getNearestNeighbors
        //findLowestPoint

    } else if(rowNumber == 0 && colNumber == grid[0].size() - 1){
        int left = grid[rowNumber][colNumber  - 1];
        int below = grid[rowNumber + 1][colNumber];
        int diag = grid[rowNumber + 1][colNumber - 1];

        int minimum = std::min({left, below, diag, current});

        if(minimum == left){
            newPos.push_back(rowNumber);
            newPos.push_back(colNumber - 1);
        } else if(minimum == below){
            newPos.push_back(rowNumber + 1);
            newPos.push_back(colNumber);
        } else if(minimum = diag){
            newPos.push_back(rowNumber + 1);
            newPos.push_back(colNumber - 1);
        } else {
            return position;
        }

    } else if(rowNumber == 0 && colNumber != grid[0].size() - 1){

    } else if(rowNumber != grid.size() - 1 && colNumber == 0){

    } else if(rowNumber != grid.size() - 1 && colNumber != grid[0].size() - 1){
        int upperLeft = grid[rowNumber - 1][colNumber - 1];
        int upperMid = grid[rowNumber - 1][colNumber];
        int upperRight = grid[rowNumber - 1][colNumber + 1];
        int left = grid[rowNumber][colNumber - 1];
        int
    } else if(rowNumber != grid.size() - 1 && colNumber == grid[0].size() - 1){

    } else if(rowNumber == grid.size() - 1 && colNumber == 0){
        int right = grid[rowNumber][colNumber + 1];
        int above = grid[rowNumber - 1][colNumber];
        int diag = grid[rowNumber - 1][colNumber + 1];

        int minimum = std::min({right, below, diag, current});

        if(minimum == right){
            newPos.push_back(rowNumber);
            newPos.push_back(colNumber + 1);
        } else if(minimum == above){
            newPos.push_back(rowNumber - 1);
            newPos.push_back(colNumber);
        } else if(minimum == diag){
            newPos.push_back(rowNumber - 1);
            newPos.push_back(colNumber + 1);
        } else {
            return position;
        }
    } else if(rowNumber == grid.size() - 1 && colNumber != grid[0].size() - 1){

    } else if(rowNumber == grid.size() - 1 && colNumber == grid[0].size() - 1){
        int left = grid[rowNumber][colNumber  - 1];
        int above = grid[rowNumber - 1][colNumber];
        int diag = grid[rowNumber - 1][colNumber - 1];

        int minimum = std::min({left, above, diag, current});

        if(minimum == left){
            newPos.push_back(rowNumber);
            newPos.push_back(colNumber - 1);
        } else if(minimum == above){
            newPos.push_back(rowNumber - 1);
            newPos.push_back(colNumber);
        } else if(minimum == diag){
            newPos.push_back(rowNumber - 1);
            newPos.push_back(colNumber - 1);
        } else {
            return positon;
        }
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
