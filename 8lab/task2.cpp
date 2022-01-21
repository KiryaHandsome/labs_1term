#include <string>
#include <iostream>
#include <fstream>

using namespace std;


struct Library {
    int number;        //номер книги
    char author[30];   //автор
    char name[15];     //название
    int year;          //год издания 
    char publisher[30];//издательство
    int pages;         //количество страниц
};

int total = 0;  //количество структур(каждый раз обновляется при чтении файла)

int inputInt(const char message[] = "")   //ввод положительных чисел
{
    char number[15];
    number[14] = '\0';
    bool isNumber = true;
    do {
        isNumber = true;
        printf("%s", message);
        scanf_s("%s", &number, sizeof(number));
        for (unsigned i = 0; i < strlen(number); i++) {
            if (!isdigit(number[i]) || i > 9) {
                printf("Invalid input\n");
                isNumber = false;
                break;
            }
        }
    } while (!isNumber);
    return atoi(number);
}

void writeData(Library* Obj, string path = "memory.txt")   //записывает данные в файл(по умолчанию в memory.txt)
{
    ofstream fout;
    fout.open(path);
    if (fout.is_open()) {
        fout << total << "\n";      //первое число в файле - количество созданных структур
        for (int i = 0; i < total; i++){
            fout << Obj[i].number << "\n" 
                 << Obj[i].author << "\n"
                 << Obj[i].name << "\n" 
                 << Obj[i].year << "\n"
                 << Obj[i].publisher << "\n"
                 << Obj[i].pages << "\n";
        }
    }
    fout.close();
    free(Obj);          //очищает память после использования, после вызова метода не писать free
}



Library* readData(string path = "memory.txt")   //чтение данных из файла(по умолчанию из memory.txt)
{
    ifstream fin;
    Library* Obj = 0;
    fin.open(path);
    if (fin.is_open()) {
        fin >> total;
        Obj = (Library*)calloc(total, sizeof(Library));
        for (int i = 0; i < total; i++) {
            for (int s = 0; s < 6; s++) {
                switch (s % 6) {
                case 0:
                    fin >> Obj[i].number;
                    break;
                case 1:
                    fin >> Obj[i].author;
                    break;
                case 2:
                    fin >> Obj[i].name;
                    break;
                case 3:
                    fin >> Obj[i].year;
                    break;
                case 4:
                    fin >> Obj[i].publisher;
                    break;
                case 5:
                    fin >> Obj[i].pages;
                    break;
                }
            }
        }
    }
    fin.close();
    return Obj;
}
void separator()
{
    printf("\n");
    for (int i = 0; i < 140; i++) printf("#");
    printf("\n");
}

void showDataFromFile(string path = "memory.txt")     //вывод данных из файла в консоль
{
    Library* Obj = readData(path);
    if (total > 0) {
        separator();
        printf("\n"); printf("%10s", "Number:");
        for (int i = 0; i < total; i++) printf("%20d", Obj[i].number);
        printf("\n"); printf("%10s", "Author:");
        for (int i = 0; i < total; i++) printf("%20s", Obj[i].author);
        printf("\n"); printf("%10s", "Name:");
        for (int i = 0; i < total; i++) printf("%20s", Obj[i].name);
        printf("\n"); printf("%10s", "Year:");
        for (int i = 0; i < total; i++) printf("%20d", Obj[i].year);
        printf("\n"); printf("%10s", "Publisher:");
        for (int i = 0; i < total; i++) printf("%20s", Obj[i].publisher);
        printf("\n"); printf("%10s", "Pages:");
        for (int i = 0; i < total; i++) printf("%20d", Obj[i].pages);
        separator();
    }
    else printf("You have no one struct\n");
    free(Obj);
}

void addStructs(const int addNum = 0)       //добавление структур с консоли
{
    Library* Obj = readData(); 
    int prevTotal = total;
    total += addNum;
    if (total == 0) {
        Obj = (Library*)calloc(total, sizeof(Library));   
    }
    else {
        Library* tempObj = (Library*)calloc(prevTotal, sizeof(Library));
        for (int i = 0; i < prevTotal; i++) {
            tempObj[i] = Obj[i];        //копируем во временный объект
        }
        free(Obj);
        Obj = (Library*)calloc(total, sizeof(Library));
        for (int i = 0; i < total; i++) {
            Obj[i] = tempObj[i];    //возвращаем значения обратно
        }
        free(tempObj);
    }
    for (int i = prevTotal; i < total; i++) {
        cout << "Input struct #" << i + 1 <<"\n";
        Obj[i].number = inputInt("Number: ");
        cout << "Author: ";
        cin >> Obj[i].author;
        cout << "Name: ";
        cin >> Obj[i].name;
        Obj[i].year = inputInt("Year: ");
        cout << "Publisher: ";
        cin >> Obj[i].publisher;
        Obj[i].pages = inputInt("Pages: ");
        cout << "\n";
    }
    writeData(Obj);
}


void eraseStruct(const int num = 0)
{
    Library* Obj = readData();
    int prevTotal = total;
    total--;
    if (prevTotal == 1) {
        Obj = nullptr;
    }
    else {
        Library* tempObj = (Library*)calloc(total, sizeof(Library));
        int counter = 0;
        for (int i = 0; i < prevTotal; i++) {
            if (i != num) {
                tempObj[counter] = Obj[i];
                counter++;
            }
        }
        free(Obj);
        Obj = (Library*)calloc(total, sizeof(Library));
        for (int i = 0; i < total; i++) {
            Obj[i] = tempObj[i];
        }
        free(tempObj);
    }
    writeData(Obj);         //записываем в файл
}


void changeStruct(int num)
{
    Library* Obj = readData();
    Obj[num].number = inputInt("Number: ");
    cout << "Author: ";
    cin >> Obj[num].author;
    cout << "Name: ";
    cin >> Obj[num].name;
    Obj[num].year = inputInt("Year: ");
    cout << "Publisher: ";
    cin >> Obj[num].publisher;
    Obj[num].pages = inputInt("Pages: ");
    writeData(Obj);
}

void clear()       
{
    ofstream fout;
    fout.open("memory.txt");
    if (fout.is_open()) {    
        fout << 0;          //очищаем данные файла и записываем 0
    }
    fout.close(); 
}

string saveAlphabetizedList()       
{
    Library* Obj = readData();
    int temp = inputInt("Enter year: ");
    Library* tempObj = (Library*)calloc(1, sizeof(Library));;
    for (int i = 0; i < total - 1; i++) {       //сортировка пузырьком
        for (int j = 0; j < total - i - 1; j++) {
            if (strcmp(Obj[j].name, Obj[j + 1].name) == 1) {
                *tempObj = Obj[j];
                Obj[j] = Obj[j + 1];
                Obj[j + 1] = *tempObj;
            }
        } 
    }
    int c = 0;
    for (int i = 0; i < total; i++) {
        if (Obj[i].year > temp) c++;    //счетчик для будущего массива отсортированных в алфавитном порядке книг после заданного года 
    }
    tempObj = (Library*)calloc(c, sizeof(Library)); 
    c = 0;
    for (int i = 0; i < total; i++) {
        if (Obj[i].year > temp) {
            tempObj[c] = Obj[i];
            c++;
        }
    }
    total = c;
    string path = "sortedlist.txt";
    writeData(tempObj, path);   //записываем в файл sortedlist.txt отсортированную структуру
    return path;
}

int dialog()
{
    int choice;
    do {
        choice = inputInt("\nEnter what You want to do?\n1 - add struct;\n2 - show data;\n3 - delete struct;\n4 - change struct;\n5 - alphabetize(sort) by name and show books after year(without saving)\n6 - save data in file\n0 - exit\n");
        if (choice < 0 || choice > 6) cout << "Only 0..5";
    } while (choice < 0 || choice > 6);
    return choice;
}


int main()
{
    clear();
    writeData(readData("input.txt"));   //чтение входных данных из файла input.txt
    int choice, num;
    do {

        choice = dialog();
        switch (choice) {
        case 0:
            break;
        case 1:
            num = inputInt("Add structs, enter count: ");
            addStructs(num);
            break;
        case 2:
            showDataFromFile();
            break;
        case 3:
            num = inputInt("Erase struct, number: ");
            if (total == 0) printf("You have no one struct.\n");
            else if (num > total || num < 0) printf("Incorrect num.\n");
            else eraseStruct(--num);
            break;
        case 4:
            num = inputInt("Change struct, number: ");
            if (total == 0) printf("You have no one struct.\n");
            else if (num > total || num < 0) printf("Incorrect num.\n");
            else changeStruct(--num);
            break;
        case 5:
            showDataFromFile(saveAlphabetizedList());
            break;
        case 6:
            writeData(readData(), "output.txt");
            showDataFromFile();
        }
        if (choice == 0) break;
    } while (true);
    clear();
    return 0;
}
