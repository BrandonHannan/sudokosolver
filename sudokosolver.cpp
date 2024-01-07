#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<std::vector<int> > CreatePuzzle(){
    std::vector<std::vector<int> > puzzle(9, std::vector<int>(9));
    int value;
    /*for (int i = 0; i<9; i++){
        for (int j = 0; j<9; j++){
            cout << "Enter a value " << i << j << ": ";
            cin >> value;
            puzzle[i][j] = value;
        }
    }*/
    int xy[9][9] = {0, 0, 1,    0, 0, 0,    0, 0, 8,
                    0, 2, 0,    0, 9, 0,    5, 0, 6,
                    9, 0, 0,    4, 0, 0,    0, 0, 0,
                    
                    0, 0, 7,    0, 0, 1,    0, 0, 0,
                    0, 0, 0,    0, 0, 0,    0, 3, 0,
                    0, 6, 0,    0, 4, 0,    2, 0, 9,

                    0, 3, 0,    0, 0, 0,    0, 4, 0,
                    0, 0, 0,    0, 5, 0,    0, 8, 0,
                    0, 0, 6,    7, 0, 0,    3, 0, 5};
    
    for (int i = 0; i<9; i++){
        for (int j = 0; j<9; j++){
            puzzle[i][j] = xy[i][j];
        }
    }
    return puzzle;
}

std::vector<std::vector<std::vector<int> > > PossibleSolutions(std::vector<std::vector<int> > puzzle){
    std::vector<std::vector<std::vector<int> > > possible_solutions(9, std::vector<std::vector<int> >(9, std::vector<int>(9)));
    for (int i = 0; i<9; i++){
        for (int j = 0; j<9; j++){
            std::fill(possible_solutions[i][j].begin(), possible_solutions[i][j].end(), 0);
            if (puzzle[i][j] == 0){
                for (int k = 0; k<9; k++){
                    if (puzzle[i][k] != 0){
                        possible_solutions[i][j][puzzle[i][k] - 1] = 1;
                    }
                    if (puzzle[k][j] != 0){
                        possible_solutions[i][j][puzzle[k][j] - 1] = 1;
                    }
                }
            }
            else{
                for (int k = 0; k<9; k++){
                    possible_solutions[i][j][k] = 1;
                }
            }
        }
    }

    for (int i = 0; i<9; i++){
        for (int j = 0; j<9; j++){
            if (puzzle[i][j] == 0){
                if (j == 0 || j == 1 || j == 2){
                    if (i == 0 || i == 1 || i == 2){
                        for (int x = 0; x<3; x++){
                            for (int y = 0; y<3; y++){
                                if (puzzle[x][y] != 0){
                                    possible_solutions[i][j][puzzle[x][y] - 1] = 1;
                                }
                            }
                        }
                    }
                    if (i == 3 || i == 4 || i == 5){
                        for (int x = 3; x<6; x++){
                            for (int y = 0; y<3; y++){
                                if (puzzle[x][y] != 0){
                                    possible_solutions[i][j][puzzle[x][y] - 1] = 1;
                                }
                            }
                        }
                    }
                    if (i == 6 || i == 7 || i == 8){
                        for (int x = 6; x<9; x++){
                            for (int y = 0; y<3; y++){
                                if (puzzle[x][y] != 0){
                                    possible_solutions[i][j][puzzle[x][y] - 1] = 1;
                                }
                            }
                        }
                    }
                }
                if (j == 3 || j == 4 || j == 5){
                    if (i == 0 || i == 1 || i == 2){
                        for (int x = 0; x<3; x++){
                            for (int y = 3; y<6; y++){
                                if (puzzle[x][y] != 0){
                                    possible_solutions[i][j][puzzle[x][y] - 1] = 1;
                                }
                            }
                        }
                    }
                    if (i == 3 || i == 4 || i == 5){
                        for (int x = 3; x<6; x++){
                            for (int y = 3; y<6; y++){
                                if (puzzle[x][y] != 0){
                                    possible_solutions[i][j][puzzle[x][y] - 1] = 1;
                                }
                            }
                        }
                    }
                    if (i == 6 || i == 7 || i == 8){
                        for (int x = 6; x<9; x++){
                            for (int y = 3; y<6; y++){
                                if (puzzle[x][y] != 0){
                                    possible_solutions[i][j][puzzle[x][y] - 1] = 1;
                                }
                            }
                        }
                    }
                }
                if (j == 6 || j == 7 || j == 8){
                    if (i == 0 || i == 1 || i == 2){
                        for (int x = 0; x<3; x++){
                            for (int y = 6; y<9; y++){
                                if (puzzle[x][y] != 0){
                                    possible_solutions[i][j][puzzle[x][y] - 1] = 1;
                                }
                            }
                        }
                    }
                    if (i == 3 || i == 4 || i == 5){
                        for (int x = 3; x<6; x++){
                            for (int y = 6; y<9; y++){
                                if (puzzle[x][y] != 0){
                                    possible_solutions[i][j][puzzle[x][y] - 1] = 1;
                                }
                            }
                        }
                    }
                    if (i == 6 || i == 7 || i == 8){
                        for (int x = 6; x<9; x++){
                            for (int y = 6; y<9; y++){
                                if (puzzle[x][y] != 0){
                                    possible_solutions[i][j][puzzle[x][y] - 1] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    std::vector<int> counter(9);
    std::fill(counter.begin(), counter.end(), 0);

    for (int i = 0; i<9; i++){
        for (int j = 0; j<9; j++){
            if (puzzle[i][j] == 0){
                if (j == 0 || j == 1 || j == 2){
                    if (i == 0 || i == 1 || i == 2){
                        for (int x = 0; x<3; x++){
                            for (int y = 0; y<3; y++){
                                for (int z = 0; z<9; z++){
                                    if (possible_solutions[x][y][z] == 1){
                                        counter[z]++;
                                    }
                                }
                            }
                        }
                        
                        for (int x = 0; x<9; x++){
                            if (counter[x] == 8 && possible_solutions[i][j][x] == 0){
                                for (int y = 0; y<9; y++){
                                    if (y != x){
                                        possible_solutions[i][j][y] = 1;
                                    }
                                }
                                break;
                            }
                        }

                        for (int x = 0; x<9; x++){
                            counter[x] = 0;
                        }
                    }
                    if (i == 3 || i == 4 || i == 5){
                        for (int x = 3; x<6; x++){
                            for (int y = 0; y<3; y++){
                                for (int z = 0; z<9; z++){
                                    if (possible_solutions[x][y][z] == 1){
                                        counter[z]++;
                                    }
                                }
                            }
                        }
                        
                        for (int x = 0; x<9; x++){
                            if (counter[x] == 8 && possible_solutions[i][j][x] == 0){
                                for (int y = 0; y<9; y++){
                                    if (y != x){
                                        possible_solutions[i][j][y] = 1;
                                    }
                                }
                                break;
                            }
                        }

                        for (int x = 0; x<9; x++){
                            counter[x] = 0;
                        }
                    }
                    if (i == 6 || i == 7 || i == 8){
                        for (int x = 6; x<9; x++){
                            for (int y = 0; y<3; y++){
                                for (int z = 0; z<9; z++){
                                    if (possible_solutions[x][y][z] == 1){
                                        counter[z]++;
                                    }
                                }
                            }
                        }
                        
                        for (int x = 0; x<9; x++){
                            if (counter[x] == 8 && possible_solutions[i][j][x] == 0){
                                for (int y = 0; y<9; y++){
                                    if (y != x){
                                        possible_solutions[i][j][y] = 1;
                                    }
                                }
                                break;
                            }
                        }

                        for (int x = 0; x<9; x++){
                            counter[x] = 0;
                        }
                    }
                }
                if (j == 3 || j == 4 || j == 5){
                    if (i == 0 || i == 1 || i == 2){
                        for (int x = 0; x<3; x++){
                            for (int y = 3; y<6; y++){
                                for (int z = 0; z<9; z++){
                                    if (possible_solutions[x][y][z] == 1){
                                        counter[z]++;
                                    }
                                }
                            }
                        }
                        
                        for (int x = 0; x<9; x++){
                            if (counter[x] == 8 && possible_solutions[i][j][x] == 0){
                                for (int y = 0; y<9; y++){
                                    if (y != x){
                                        possible_solutions[i][j][y] = 1;
                                    }
                                }
                                break;
                            }
                        }

                        for (int x = 0; x<9; x++){
                            counter[x] = 0;
                        }
                    }
                    if (i == 3 || i == 4 || i == 5){
                        for (int x = 3; x<6; x++){
                            for (int y = 3; y<6; y++){
                                for (int z = 0; z<9; z++){
                                    if (possible_solutions[x][y][z] == 1){
                                        counter[z]++;
                                    }
                                }
                            }
                        }
                        
                        for (int x = 0; x<9; x++){
                            if (counter[x] == 8 && possible_solutions[i][j][x] == 0){
                                for (int y = 0; y<9; y++){
                                    if (y != x){
                                        possible_solutions[i][j][y] = 1;
                                    }
                                }
                                break;
                            }
                        }

                        for (int x = 0; x<9; x++){
                            counter[x] = 0;
                        }
                    }
                    if (i == 6 || i == 7 || i == 8){
                        for (int x = 6; x<9; x++){
                            for (int y = 3; y<6; y++){
                                for (int z = 0; z<9; z++){
                                    if (possible_solutions[x][y][z] == 1){
                                        counter[z]++;
                                    }
                                }
                            }
                        }
                        
                        for (int x = 0; x<9; x++){
                            if (counter[x] == 8 && possible_solutions[i][j][x] == 0){
                                for (int y = 0; y<9; y++){
                                    if (y != x){
                                        possible_solutions[i][j][y] = 1;
                                    }
                                }
                                break;
                            }
                        }

                        for (int x = 0; x<9; x++){
                            counter[x] = 0;
                        }
                    }
                }
                if (j == 6 || j == 7 || j == 8){
                    if (i == 0 || i == 1 || i == 2){
                        for (int x = 0; x<3; x++){
                            for (int y = 6; y<9; y++){
                                for (int z = 0; z<9; z++){
                                    if (possible_solutions[x][y][z] == 1){
                                        counter[z]++;
                                    }
                                }
                            }
                        }
                        
                        for (int x = 0; x<9; x++){
                            if (counter[x] == 8 && possible_solutions[i][j][x] == 0){
                                for (int y = 0; y<9; y++){
                                    if (y != x){
                                        possible_solutions[i][j][y] = 1;
                                    }
                                }
                                break;
                            }
                        }

                        for (int x = 0; x<9; x++){
                            counter[x] = 0;
                        }
                    }
                    if (i == 3 || i == 4 || i == 5){
                        for (int x = 3; x<6; x++){
                            for (int y = 6; y<9; y++){
                                for (int z = 0; z<9; z++){
                                    if (possible_solutions[x][y][z] == 1){
                                        counter[z]++;
                                    }
                                }
                            }
                        }
                        
                        for (int x = 0; x<9; x++){
                            if (counter[x] == 8 && possible_solutions[i][j][x] == 0){
                                for (int y = 0; y<9; y++){
                                    if (y != x){
                                        possible_solutions[i][j][y] = 1;
                                    }
                                }
                                break;
                            }
                        }

                        for (int x = 0; x<9; x++){
                            counter[x] = 0;
                        }
                    }
                    if (i == 6 || i == 7 || i == 8){
                        for (int x = 6; x<9; x++){
                            for (int y = 6; y<9; y++){
                                for (int z = 0; z<9; z++){
                                    if (possible_solutions[x][y][z] == 1){
                                        counter[z]++;
                                    }
                                }
                            }
                        }
                        
                        for (int x = 0; x<9; x++){
                            if (counter[x] == 8 && possible_solutions[i][j][x] == 0){
                                for (int y = 0; y<9; y++){
                                    if (y != x){
                                        possible_solutions[i][j][y] = 1;
                                    }
                                }
                                break;
                            }
                        }

                        for (int x = 0; x<9; x++){
                            counter[x] = 0;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i<9; i++){
        for (int j = 0; j<9; j++){
            if (puzzle[i][j] == 0){
                for (int x = 0; x<9; x++){
                    for (int y = 0; y<9; y++){
                        if (possible_solutions[x][j][y] == 1){
                            counter[y]++;
                        }
                    }
                }

                for (int x = 0; x<9; x++){
                    if (counter[x] == 8 && possible_solutions[i][j][x] == 0){
                        for (int y = 0; y<9; y++){
                            if (y != x){
                                possible_solutions[i][j][y] = 1;
                            }
                        }
                        break;
                    }
                }

                for (int x = 0; x<9; x++){
                    counter[x] = 0;
                }

                for (int x = 0; x<9; x++){
                    for (int y = 0; y<9; y++){
                        if (possible_solutions[i][x][y] == 1){
                            counter[y]++;
                        }
                    }
                }

                for (int x = 0; x<9; x++){
                    if (counter[x] == 8 && possible_solutions[i][j][x] == 0){
                        for (int y = 0; y<9; y++){
                            if (y != x){
                                possible_solutions[i][j][y] = 1;
                            }
                        }
                        break;
                    }
                }

                for (int x = 0; x<9; x++){
                    counter[x] = 0;
                }
            }
        }
    }
    return possible_solutions;
}

void PrintPuzzle(std::vector<std::vector<int> > puzzle){
    for (int i = 0; i<9; i++){
        for (int j = 0; j<9; j++){
            std::cout << puzzle[i][j] << " ";
            if (j == 2 || j == 5){
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
        if (i == 2 || i == 5){
            std::cout << "______________________";
            std::cout << endl;
        }
    }
}

void SolutionFinder(std::vector<std::vector<int> > puzzle, std::vector<std::vector<std::vector<int> > > possible_solutions){
    int count = 0; 
    for (int i = 0; i<9; i++){
        for (int j = 0; j<9; j++){
            if (puzzle[i][j] == 0){
                count++;
            }
        }
    }

    for (int i = 0; i<count; i++){
        
        int index_1 = 0;
        int index_2 = 0;
        int index_3 = 0;
        int counter = 0;
        int signal = 0;
        for (int x = 0; x<9; x++){
            for (int y = 0; y<9; y++){
                if (puzzle[x][y] == 0){
                    index_1 = x;
                    index_2 = y;
                    counter = 0;
                    for (int z = 0; z<9; z++){
                        if (possible_solutions[x][y][z] == 0){
                            counter++;
                            index_3 = z;
                        }
                    }
                    if (counter == 1){
                        signal++;
                        break;
                    }
                }
            }
            if (signal>0){
                break;
            }
        }

        puzzle[index_1][index_2] = index_3 + 1;

        possible_solutions = PossibleSolutions(puzzle);
        
    }
    PrintPuzzle(puzzle);
}

int main(){
    std::vector<std::vector<int> > puzzle = CreatePuzzle();
    std::vector<std::vector<std::vector<int> > > possible_solutions = PossibleSolutions(puzzle);
    SolutionFinder(puzzle, possible_solutions);
    return 0;
}