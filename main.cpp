#include<iostream>
#include<cstdlib>
#include<ctime>
#include <fstream>
#include <unistd.h>
#include "Grid.h"


/*
 * vector[0] = rowNumber
 * vector[1] = colNumber
 * */

//returns a grid of neighbors along with the current node
//gets a grid corresponding to the elevation map grid
//position is a row column vector
std::vector<std::vector<int> > getNearestNeighbors(std::vector<std::vector<float> > grid, std::vector<int> position){
    int rowNumber = position[0];
    int colNumber = position[1];

    int current = grid[rowNumber][colNumber];

    std::vector<std::vector<int> > newGrid;

    if(rowNumber == 0 && colNumber == 0){
//        int numElems = 0;
        for(int i = rowNumber; i < rowNumber + 2; i++){
            std::vector<int> row;
            for(int j = colNumber; j < colNumber + 2; j++){
                row.push_back(i);
                row.push_back(j);
                newGrid.push_back(row);
                row.clear();
//                numElems += 2;
            }

        }

//        std::cout << "NUMBER OF ELEMENTS: " << numElems << std::endl;

    } else if(rowNumber == 0 && colNumber == grid[0].size() - 1){
        for(int i = rowNumber; i < rowNumber + 2; i++){
            std::vector<int> row;
            for(int j = colNumber - 1; j >= colNumber; j--){
                row.push_back(i);
                row.push_back(j);
                newGrid.push_back(row);
                row.clear();
            }

        }
    } else if(rowNumber == 0 && colNumber != grid[0].size() - 1){
        for(int i = rowNumber ; i < rowNumber + 2; i++){
            std::vector<int> row;
            for(int j = colNumber - 1; j <= colNumber + 1; j++){
                row.push_back(i);
                row.push_back(j);
                newGrid.push_back(row);
                row.clear();
            }

        }
    } else if(rowNumber != grid.size() - 1 && colNumber == 0){
        for(int i = rowNumber - 1; i < rowNumber + 2; i++){
            std::vector<int> row;
            for(int j = colNumber; j <= colNumber + 1; j++){
                row.push_back(i);
                row.push_back(j);
                newGrid.push_back(row);
                row.clear();
            }

        }
    } else if(rowNumber != grid.size() - 1 && colNumber != grid[0].size() - 1){
        for(int i = rowNumber - 1; i < rowNumber + 2; i++){
            std::vector<int> row;
            for(int j = colNumber - 1; j <= colNumber + 1; j++){
                row.push_back(i);
                row.push_back(j);
                newGrid.push_back(row);
                row.clear();
            }

        }
    } else if(rowNumber != grid.size() - 1 && colNumber == grid[0].size() - 1){
        for(int i = rowNumber - 1; i < rowNumber + 2; i++){
            std::vector<int> row;
            for(int j = colNumber - 1; j <= colNumber; j++){
                row.push_back(i);
                row.push_back(j);
                newGrid.push_back(row);
                row.clear();
            }

        }
    } else if(rowNumber == grid.size() - 1 && colNumber == 0){
        for(int i = rowNumber - 1; i <= rowNumber; i++){
            std::vector<int> row;
            for(int j = colNumber; j <= colNumber + 1; j++){
                row.push_back(i);
                row.push_back(j);
                newGrid.push_back(row);
                row.clear();
            }

        }
    } else if(rowNumber == grid.size() - 1 && colNumber != grid[0].size() - 1){
        for(int i = rowNumber - 1; i < rowNumber + 1; i++){
            std::vector<int> row;
            for(int j = colNumber - 1; j <= colNumber + 1; j++){
                row.push_back(i);
                row.push_back(j);
                newGrid.push_back(row);
                row.clear();
            }

        }
    } else if(rowNumber == grid.size() - 1 && colNumber == grid[0].size() - 1){
        for(int i = rowNumber - 1; i < rowNumber + 1; i++){
            std::vector<int> row;
            for(int j = colNumber - 1; j < colNumber + 1; j++){
                row.push_back(i);
                row.push_back(j);
                newGrid.push_back(row);
                row.clear();
            }

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

//
//    std::cout << position[0] << " : " << position[1] << std::endl;
//    std::cout << newGrid.size() << std::endl;
//    std::cout << newGrid[0].size() << std::endl;
//    std::cout << newGrid[1].size() << std::endl;
//    std::cout << std::endl;

    newPos = getLowestPoint(newGrid, grid);

    return newPos;
}

std::vector<int> getLocalMinimum(std::vector<std::vector<float> > grid, std::vector<int> position){
    std::vector<int> currPos = checkNearestNeighbors(grid, position);
    if(currPos[0] == position[0] && currPos[1] == position[1]){
        return currPos;
    } else {
        getLocalMinimum(grid, currPos);
    }
}


int main(int argc, char *argv[]){
    if(argc != 5){
        std::cout << "Invalid number of arguments" << std::endl;
        exit(-1);
    }
    std::ofstream outfile("results.txt");
    int PPID = getpid();
    srand(time(NULL));
    Grid grid;
    std::string file = argv[1];
    int numSkiers = std::atoi(argv[2]);
    int numRuns = std::atoi(argv[3]);
    bool traceMode = argv[4];
    std::vector <std::vector<float> > fileGrid = grid.parseFile(file);
//    for(int i = 0; i < fileGrid.size(); i++){
//        for(int j = 0; j < fileGrid[i].size(); j++){
//            std::cout << fileGrid[i][j] << " ";
//        }
//        std::cout << std::endl;
//
//    }
//    std::vector<int> testPos;
//    testPos.push_back(3);
//    testPos.push_back(1);
//
////    std::vector<int> minimum = getLocalMinimum(fileGrid, testPos);
////
////    std::cout << minimum[0] << std::endl;
////    std::cout << minimum[1] << std::endl;
////    std::cout << fileGrid[minimum[0]][minimum[1]] << std::endl;
//
//    std::vector<std::vector<int> > smallGrid = getNearestNeighbors(fileGrid, minimum);
////
////    std::cout << std::endl;
////
////    for(int i = 0; i < smallGrid.size(); i++){
////        for(int j = 0; j < smallGrid[i].size(); j++){
////            std::cout << smallGrid[i][j] << " " << std::endl;
////        }
////        std::cout << std::endl;
////    }
////

    int numChildren = 0;
    int p = PPID;
    for(int i = 0; i < numSkiers && getpid() == PPID; i++){
        int randomRow = rand() % fileGrid.size();
        int randomCol = rand() % fileGrid[0].size();
        numChildren++;
        p = fork();
        if(p == 0){
            std::vector<int> start = {randomRow, randomCol};
            std::vector<int> min = getLocalMinimum(fileGrid, start);
            outfile << "Local Minimum: ";
            outfile << min[0] << ", ";
            outfile << min[1] << "\n";
            sleep(1);
        }else if(p < 0){
            std::cout << "Creation Failed" << std::endl;
            exit(-1);
        }
    }

    if(p != 0){
        outfile.close();
        std::cout << "CHILDREN: " << numChildren << std::endl;
    }





}
