#include <iostream>
#include <string>
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
    std::cout << "Program count number of free outlets.\n";
    std::cout << "Enter number of extension cords:";
    int size = CorrectInput("");

    int* arr = new int[size];
    std::cout << "Enter array of entrances:\n";
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << " extencion cord:";
        arr[i] = CorrectInput("");
        std::cout << std::endl;
    }
    int counter = 0, result = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 1) {
            result += arr[i] - 1;
            counter++;
        }
    }
    std::cout << "Free outlets = " << result;
    delete[] arr;
    return 0;
}
