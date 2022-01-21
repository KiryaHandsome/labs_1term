#include <iostream>
#include <string>

int odd_magic_square(int N)
{
    int odd_size = 2 * N - 1;
    int** odd_square = new int* [odd_size];
    for (int i = 0; i < odd_size; i++) {
        odd_square[i] = new int[odd_size];
    }
    //fill 0
    for (int i = 0; i < odd_size; i++) {
        for (int j = 0; j < odd_size; j++) {
            odd_square[i][j] = (int)0;
        }
    }
    //fill from 1 to N * N
    int count = 1;
    for (int tmp = 0; tmp < N; tmp++) {
        int j = 0;
        for (int i = odd_size / 2; i >= 0; i--) {
            odd_square[tmp + i][tmp + j] = count;
            count++;
            j++;
        }
    }
    //from left to right
    for (int tmp = 0; tmp <= (N - 3) / 2; tmp++) {
        int j = 0;
        for (int i = odd_size / 2; j < (N - 1) / 2; i--) {
            odd_square[tmp + i][tmp + j + N] = odd_square[tmp + i][tmp + j];
            j++;
        }
    }
    //from the top down
    for (int tmp = 0; tmp <= (N - 3) / 2; tmp++) {
        int j = odd_size / 2;
        for (int i = 0; i <= (N - 3) / 2; i++) {
            odd_square[tmp + i + N][tmp + j] = odd_square[tmp + i][tmp + j];
            j--;
        }
    }
    //from the down up
    for (int tmp = 0; tmp <= (N - 3) / 2; tmp++) {
        int j = (odd_size - 1) / 2;
        for (int i = odd_size - 1; i > (3 * N - 3) / 2; i--) {
            odd_square[i - N - tmp][j - tmp] = odd_square[i - tmp][j - tmp];
            j++;
        }
    }
    //from right to left
    for (int tmp = 0; tmp <= (N - 3) / 2; tmp++) {
        int j = odd_size - 1;
        for (int i = odd_size / 2; j > (3 * N - 3) / 2; i++) {
            odd_square[i - tmp][j - N - tmp] = odd_square[i - tmp][j - tmp];
            j--;
        }
    }
    //output magic square
    for (int i = (N - 3) / 2 + 1; i <= (3 * N - 3) / 2; i++) {
        for (int j = (N - 3) / 2 + 1; j <= (3 * N - 3) / 2; j++) {
            printf("%6d", odd_square[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < odd_size; i++) {
        delete[] odd_square[i];
    }
    return N;

}
int CorrectInput(std::string massege)
{
    std::string input;
    bool isNotNumber;
    do {

        isNotNumber = false;
        std::cout << massege;
        std::cin >> input;
        for (int i = 0; i < input.length(); i++) {
            if (!isdigit(input[i])) {
                std::cout << "\nIts not correct number. Try again.\n";
                isNotNumber = true;
                break;
            }
        }
    } while (isNotNumber);

    return std::stoi(input);
}

int main()
{
    int N;
    std::cout << "Program make magic square any size.\nEnter size of square.\n";
    N = CorrectInput("N = ");


    if (N % 4 == 0) {
        int** square = new int* [N];
        for (int i = 0; i < N; i++) {
            square[i] = new int[N];
        }
        int counter = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((i % 4 == 0 || i % 4 == 3) && (j % 4 == 1 || j % 4 == 2)) {
                    square[i][j] = counter;
                    counter++;
                }
                else if ((i % 4 == 1 || i % 4 == 2) && (j % 4 == 0 || j % 4 == 3)) {
                    square[i][j] = counter;
                    counter++;
                }
                else {
                    counter++;
                }
            }
        }
        counter--;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((i % 4 == 0 || i % 4 == 3) && (j % 4 == 0 || j % 4 == 3)) {
                    square[i][j] = counter;
                    counter--;
                }
                else if ((i % 4 == 1 || i % 4 == 2) && (j % 4 == 1 || j % 4 == 2)) {
                    square[i][j] = counter;
                    counter--;
                }
                else {
                    counter--;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << square[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        for (int i = 0; i < N; i++) {
            delete[] square[i];
        }
    }
    else if (N % 2 == 1) {
        odd_magic_square(N);
    }
    else if (N % 4 == 2) {
        int odd_size = N - 1;
        int** even_odd_square = new int* [N];
        for (int i = 0; i < N; i++) {
            even_odd_square[i] = new int[N];
        }
        int** even_odd_square_help = new int* [odd_size];
        for (int i = 0; i < odd_size; i++) {
            even_odd_square_help[i] = new int[odd_size];
        }

        //fill 0
        for (int i = 0; i < odd_size; i++) {
            for (int j = 0; j < odd_size; j++) {
                even_odd_square_help[i][j] = 0;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                even_odd_square[i][j] = 0;
            }
        }
        //fill from 1 to N * N
        int count = 1;
        for (int tmp = 0; tmp < N / 2; tmp++) {
            int j = 0;
            for (int i = odd_size / 2; i >= 0; i--) {
                even_odd_square_help[tmp + i][tmp + j] = count;
                count++;
                j++;
            }
        }

        //from left to right
        for (int tmp = 0; tmp <= (N / 2 - 3) / 2; tmp++) {
            int j = 0;
            for (int i = odd_size / 2; j < (N / 2 - 1) / 2; i--) {
                even_odd_square_help[tmp + i][tmp + j + N / 2] = even_odd_square_help[tmp + i][tmp + j];
                j++;
            }
        }
        //from the top down
        for (int tmp = 0; tmp <= (N / 2 - 3) / 2; tmp++) {
            int j = odd_size / 2;
            for (int i = 0; i <= (N / 2 - 3) / 2; i++) {
                even_odd_square_help[tmp + i + N / 2][tmp + j] = even_odd_square_help[tmp + i][tmp + j];
                j--;
            }
        }
        //from the down up
        for (int tmp = 0; tmp <= (N / 2 - 3) / 2; tmp++) {
            int j = (odd_size - 1) / 2;
            for (int i = odd_size - 1; i > (3 * N / 2 - 3) / 2; i--) {
                even_odd_square_help[i - N / 2 - tmp][j - tmp] = even_odd_square_help[i - tmp][j - tmp];
                j++;
            }
        }
        //from right to left
        for (int tmp = 0; tmp <= (N / 2 - 3) / 2; tmp++) {
            int j = odd_size - 1;
            for (int i = odd_size / 2; j > (3 * N / 2 - 3) / 2; i++) {
                even_odd_square_help[i - tmp][j - N / 2 - tmp] = even_odd_square_help[i - tmp][j - tmp];
                j--;
            }
        }
        //even_odd_square = 4 * even_odd_square_help
        int i_odd, j_odd;

        i_odd = (odd_size - N / 2) / 2;
        for (int i = 0; i < N / 2; i++) {
            j_odd = (odd_size - N / 2) / 2;;
            for (int j = 0; j < N / 2; j++) {
                even_odd_square[i][j] = even_odd_square_help[i_odd][j_odd];
                j_odd++;
            }
            i_odd++;
        }
        i_odd = (odd_size - N / 2) / 2;;
        for (int i = 0; i < N / 2; i++) {
            j_odd = (odd_size - N / 2) / 2;;
            for (int j = N / 2; j < N; j++) {
                even_odd_square[i][j] = even_odd_square_help[i_odd][j_odd] + N * N / 2;
                j_odd++;
            }
            i_odd++;
        }
        i_odd = (odd_size - N / 2) / 2;
        for (int i = N / 2; i < N; i++) {
            j_odd = (odd_size - N / 2) / 2;;
            for (int j = 0; j < N / 2; j++) {
                even_odd_square[i][j] = even_odd_square_help[i_odd][j_odd] + N * N * 3 / 4;
                j_odd++;
            }
            i_odd++;
        }
        i_odd = (odd_size - N / 2) / 2;
        for (int i = N / 2; i < N; i++) {
            j_odd = (odd_size - N / 2) / 2;;
            for (int j = N / 2; j < N; j++) {
                even_odd_square[i][j] = even_odd_square_help[i_odd][j_odd] + N * N / 4;
                j_odd++;
            }
            i_odd++;
        }
        int place = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N / 2 + 1; j++) {
                if ((i == 0 && j == 0) || (i == N / 2 - 1 && j == 0) || (j == 1 && (i > 0 && i < N / 2 - 1))) {
                    place = even_odd_square[i][j];
                    even_odd_square[i][j] = even_odd_square[i + N / 2][j];
                    even_odd_square[i + N / 2][j] = place;
                }

            }
        }
        int place1 = 0;
        int place2 = 0;
        for (int i = 0; i < N / 2; i++) {
            for (int diff = 0; diff < (N / 2 - 3) / 2; diff++) {
                place1 = even_odd_square[i][N / 2 + diff];
                even_odd_square[i][N / 2 + diff] = even_odd_square[i + N / 2][N / 2 + diff];
                even_odd_square[i + N / 2][N / 2 + diff] = place1;
                place2 = even_odd_square[i][N / 2 - 1 - diff];
                even_odd_square[i][N / 2 - 1 - diff] = even_odd_square[i + N / 2][N / 2 - 1 - diff];
                even_odd_square[i + N / 2][N / 2 - 1 - diff] = place2;
            }
        }

        int sum1 = 0, sum2 = 0, sum3 = 0;
        for (int i = 0; i < N; i++) {
            sum1 += even_odd_square[i][0];
        }
        for (int j = 0; j < N; j++) {
            sum2 += even_odd_square[0][j];
        }
        for (int i = 0; i < N; i++) {
            sum3 += even_odd_square[i][i];
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%5d", even_odd_square[i][j]);
            }
            printf("\n");
        }
        std::cout << "Sum1 = " << sum1 << " sum2 = " << sum2 << " sum3 = " << sum3;


        for (int i = 0; i < N; i++) {
            delete[] even_odd_square[i];
        }
        for (int i = 0; i < N / 2; i++) {
            delete[] even_odd_square_help[i];
        }
    }

    return 0;
}

