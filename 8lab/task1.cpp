#include <iostream>


using namespace std;

int total = 0;        //количество структур

struct Product {
    char name[12];    //наименование
    int amount;       //количество выпущенной продукции 
    int number;       //номер цеха
    float revenue;    //прибыль  
    char day[12];     //день недели
};

int inputInt(const char message[] = "")   //ввод положительных чисел
{
    char number[15];
    bool isNumber = true;
    do {
        isNumber = true;
        printf("%s", message);
        scanf_s("%s", &number, sizeof(number));
        for (unsigned i = 0; i < strlen(number); i++) {
            if (!isdigit(number[i]) || i > 9) {
                printf("Invalid input2\n");
                isNumber = false;
                break;
            }
        }
    } while (!isNumber);
    return atoi(number);
}

float inputFloat(const char message[] = "")     //ввод дробных чисел
{
    char number[15];
    bool isNumber = true;
    do {
        isNumber = true;
        printf("%s", message);
        scanf_s("%s", &number, sizeof(number));
        unsigned counter = 0;
        int point = -1;
        while (counter < strlen(number)) {        
            if (number[counter] == '.') {
                point = counter;            //находим местоположение точки
                break;
            }
            counter++;
        }
        for (unsigned i = 0; i < strlen(number); i++) {
            if ((!isdigit(number[i]) && i != point && i != 0) || (number[i] == '.' && i != point) || (number[i] == '-' && i != 0)) {
                printf("Invalid input1\n");
                isNumber = false;
                break;
            } 
        }
    } while (!isNumber);
    return atof(number);
}

Product* eraseStruct(Product* Obj, const int& number)   
{
    if (total == 1) {
        Obj = nullptr;
        total--;
    }
    else if (total == 0) {
        printf("You have no one struct.\n");
    }
    else if (number >= total || number < 0) {
        printf("Incorrect number.\n");
    }
    else {
        Product* tempObj = new Product[total - 1];
        int counter = 0;
        for (int i = 0; i < total; i++) {
            if (i != number) {
                tempObj[counter] = Obj[i];  //копируем во временный объект
                counter++;
            }
        }
        total--;    //уменьшаем размер структуры
        delete[] Obj;
        Obj = new Product[total];
        for (int i = 0; i < total; i++) {
            Obj[i] = tempObj[i];    //возвращаем все значения, кроме выбранной
        }
        delete[] tempObj;
    }
    return Obj;
}

Product* addStruct(Product* Obj)
{
    if (total == 0) {
        Obj = new Product[1];
        total++;
    }
    else {
        Product* tempObj = new Product[total];     
        for (int i = 0; i < total; i++) {
            tempObj[i] = Obj[i];        //копируем во временный объект
        }
        delete[] Obj;
        total++;     //увеличиваем размер структуры
        Obj = new Product[total];
        for (int i = 0; i < total - 1; i++) {
            Obj[i] = tempObj[i];       //возвращаем все значения
        }
        delete[] tempObj;
    }  
    return Obj;
}

void setData(Product* Obj, const int& number)      //устанавливает значение заданной структуре
{
    if (number < total) {
        printf("\n\nEnter name of product:");
        scanf_s("%s", Obj[number].name, sizeof(Obj[number].name));
        Obj[number].amount = inputInt("\nEnter amount of product:");
        printf("\nEnter day of the week:");
        scanf_s("%s", Obj[number].day, sizeof(Obj[number].day));
        Obj[number].number = inputInt("\nEnter factory number:");
        Obj[number].revenue = inputFloat("\nEnter revenue per this day($):"); 
    }
    else printf("\nIncorrect number\n");
}

void separator()
{
    printf("\n");
    for (int i = 0; i < 140; i++) printf("#");
    printf("\n");
}

void changeStruct(Product* Obj, const int& number)
{
    if (total == 0) {
        printf("You have nothing to change.\n");
    }
    else if (number > total || number < 0) {
        printf("Incorrect number.\n");
    }
    else {
        setData(Obj, number);
    }
}

int findStruct(Product* Obj)
{
    if (total != 0) {
        int choice = 0;
        printf("Enter field You want to find(1 - name, 2 - amount, 3 - number of factory, 4 - revenue, 5 - day of the week)\n");
        scanf_s("%d", &choice);
        printf("Enter value of field: ");
        float num = 0;
        int result = 0;
        char word[12];
        if (choice == 1 || choice == 5) scanf_s("%12s", word, sizeof(word));    //день или наименование(т.е. если это слово)
        else scanf_s("%f", &num);
        for (int i = 0; i < total; i++) {
            switch (choice) {
            case 1:
                if (!strcmp(word, Obj[i].name)) {   //сравнение строк
                    return i;   //возвращаем номер искомой структуры
                }
                break;
            case 2:
                if ((int)num == Obj[i].amount) {
                    return i;
                }
                break;
            case 3:
                if ((int)num == Obj[i].number) {
                    return i;
                }
                break;
            case 4:
                if (num == Obj[i].revenue) {
                    return i;
                }
                break;
            case 5:
                if (!strcmp(word, Obj[i].day)) {
                    return i;
                }
            }
        } 
    }
    else printf("You have no one struct.\n");
    return -1;
}

Product* shakerSort(Product* Obj)   //сортировка шейкера по убыванию по полю "amount"
{
    int left = 0, right = total - 1;
    Product temp;
    bool isSwapped = true;
    while ((left < right) && isSwapped) {
        isSwapped = false;
        for (int i = left; i < right; i++) {
            if (Obj[i].amount < Obj[i + 1].amount) {
                temp = Obj[i];
                Obj[i] = Obj[i + 1];
                Obj[i + 1] = temp;
                isSwapped = true;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if (Obj[i - 1].amount < Obj[i].amount) {
                temp = Obj[i];
                Obj[i] = Obj[i - 1];
                Obj[i - 1] = temp;
                isSwapped = true;
            }
        }
        left++;
    }
    return Obj;
}

void showData(Product* Obj, int number)     //показывает содержимое заданной структуры
{
    if (number < total && number >= 0) {
        separator();
        printf("\n\nName of product:%s\n", Obj[number].name);
        printf("Amount of product:%d\n", Obj[number].amount);
        printf("Day of the week:%s\n", Obj[number].day);
        printf("Factory number:%d\n", Obj[number].number);
        printf("Revenue per this day($):%.2lf\n\n", Obj[number].revenue);
        separator();
    }
    else printf("\nIncorrect number\n");
}
void showAllStructs(Product* Obj)
{
    if (total > 0) {
        separator();

        printf("\n%10s","Name:");
        for (int i = 0; i < total; i++) printf("%20s", Obj[i].name);

        printf("\n%10s", "Amount:");
        for (int i = 0; i < total; i++) printf("%20d", Obj[i].amount);

        printf("\n%10s", "Number:");
        for (int i = 0; i < total; i++) printf("%20d", Obj[i].number);

        printf("\n%10s", "Revenue:");
        for (int i = 0; i < total; i++) printf("%20.2f$", Obj[i].revenue);

        printf("\n%10s", "Day:");
        for (int i = 0; i < total; i++) printf("%20s", Obj[i].day);

        separator();
    }
    else printf("You have no one struct\n");
}


Product* givenNumber(Product* data)      //ввод до заранее заданного числа
{
    printf("Enter number of data sets:");
    int count = 0;
    scanf_s("%d", &count);
    for (int i = 0; i < count; i++) {
        data = addStruct(data);
        setData(data, total - 1);
    }
    return data;

}
Product* zeros(Product* data)   //ввод, пока пользователь не введет 0 0 0 0 0 
{
    do {
        data = addStruct(data);
        setData(data, total - 1);
    } while (!(data[total - 1].amount == 0 && data[total - 1].day[0] == '0' && data[total - 1].name[0] == '0' && data[total - 1].number == 0 && data[total - 1].revenue == 0.0));
    data = eraseStruct(data, total - 1);
    return data;
}
Product* chooseInput(Product* Obj)    //выбор формы ввода значений
{
    int choice;
    do {
        choice = inputInt("\nHow You want to enter values?\n1.Early given amount\n\n2. Until You enter 0 0 0 0 0\n\n3. Dialog\n");
    } while (choice < 1 || choice > 3);
    
    switch (choice) {
    case 1:
        Obj = givenNumber(Obj);
        break;
    case 2:
        Obj = zeros(Obj);
        break;

    case 3:
        int out = 0;
        do {
            Obj = addStruct(Obj);
            setData(Obj, total - 1);
            printf("Do You want to continue input?(1 - YES, 0 - NO)");
            scanf_s("%d", &out);
        } while(out);
        break;
    }
    return Obj;
}

int choose()        //чтобы пользователь не мог ввести числа < 0 и > 6
{
    bool isCorrect;
    int choice;
    do {
        isCorrect = true;
        choice = inputInt("\nWhat You want to do ? \n1 - add struct; \n2 - show all structs; \n3 - delete struct; \n4 - change struct; \n5 - find struct; \n6 - sort array of structs with shaker sort; \n0 - exit; \n");
        if (choice < 0 || choice > 6) {
            isCorrect = false;
            printf("Only 0, 1,..., 6\n");
        }
    } while (!isCorrect);
    return choice;
}


//тестовые входные данные
/* 
doors 283 thuesday 7 15.8
toys 2031 friday 19 1574.90             
mirrors 189 monday 3 -123.7
burgers 20312 wednesday 17 -91261.5
computers 94 thursday 190 840789.1
*/
/*
smth 18921 sunday 156 123123
keys 1234 friday 45 1238912.54
sadflsf 6210 saturday 51 -784562.12
sweets 12834812 monday 12 -8476202.12
books 1378 thursday 1415 840789.1
*/



int main()
{

    Product* Obj = 0;
    printf("Hello. This program can store information about products of factory.\n");
    int choice = 0;
    int temp = total;
    int out = 0;
    do {
        separator();
        choice = choose();
        switch (choice) {
        case 0:          //выход
            break;
        case 1:          //добавление структур по желанию пользователя
            Obj = chooseInput(Obj);
            break;
        case 2:
            showAllStructs(Obj);
            break;
        case 3:
            printf("Enter number of struct You want delete:"); //удаление выбранной структуры
            scanf_s("%d", &temp);
            Obj = eraseStruct(Obj, temp - 1);  //начиная с 1
            break;
        case 4:
            printf("Enter number of struct You want change:");
            scanf_s("%d", &temp);
            changeStruct(Obj, temp - 1);  //начиная с 1
            break;
        case 5:
            temp = findStruct(Obj);
            if (temp != -1) {
                showData(Obj, temp);
            }
            else printf("This struct not found.\n");
            break;
        case 6:
            Obj = shakerSort(Obj);
            break;
        }
        if (choice == 0) break;    //выход из диалога
    } while (true);
    delete[] Obj;
    
    return 0;
}

