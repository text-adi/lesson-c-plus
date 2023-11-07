#include "func.cpp"
#include "../utils/mas.cpp"
#include <fstream>

void dataManagmentMainMenu(Person*&, int &);
void dataManagmentBinMainMenu(Person*&, int &);
void dataManagmentTxtMainMenu(Person*&, int &);

void collectData(Person*&, int &);


int getMenuChoice(){
    int choice = 0;
    std::cout << std::endl;
    std::cout << "Ваш вибір: ";
    std::cin >> choice;
    
    return choice;
}




void mainMenu(){
    int size = 0;
    Person *data = nullptr;
    system("clear");
    
    while (true)
    {
        std::cout << "-------------" << std::endl;
        std::cout << "Головне меню" << std::endl;
        std::cout << "Виберіть пункт меню:" << std::endl;
        std::cout << "1. Управління даними" << std::endl;
        std::cout << "2. Запис та читання даних в форматі Bin" << std::endl;
        std::cout << "3. Запис та читання даних в форматі Txt" << std::endl;
        std::cout << "9. Вихід з програми" << std::endl;

        int menuChoice = getMenuChoice();

        switch (menuChoice)
        {
        case 1:
            system("clear");
            dataManagmentMainMenu(data,size);
            break;
        case 2:
            system("clear");
            dataManagmentBinMainMenu(data, size);
            break;
        case 3:
            system("clear");
            dataManagmentTxtMainMenu(data, size);
            break;
        case 9:
            system("clear");
            std::cout << "Ще побачимося :) Вихід з програми..." << std::endl;
            return;
        
        default:
            system("clear");
            std::cout << "Пункт не вірний. Вибери інший пункт!" << std::endl;
            break;
        }

    }

}



void dataManagmentMainMenu(Person*& data, int &size){
    system("clear");
    while (true)
    {
        std::cout << "-------------" << std::endl;
        std::cout << "Головне меню - управління даними" << std::endl;
        std::cout << "Виберіть пункт меню:" << std::endl;
        std::cout << "1. Переглянути усі дані" << std::endl;
        std::cout << "2. Додати запис" << std::endl;
        std::cout << "3. Видалити запис" << std::endl;
        std::cout << "4. Очистити усі дані" << std::endl;

        std::cout << "9. Повернутися назад" << std::endl;

        int menuChoice = getMenuChoice();

        switch (menuChoice)
        {
        case 1:
            system("clear");
            std::cout << viewData(data, size);
            break;
        case 2:
            system("clear");
            collectData(data, size);
            break;
        case 3:
            system("clear");
            if (!size )
            {
                std::cout << "Не можливо видалити елемент, так як даних немає" << std::endl;
                break;
            }
            std::cout << "Вкажіть, номер елементу, який плануєте видалити:" << std::endl;
            deleteItem(data, size, getMenuChoice());
            break;
        case 4:
            system("clear");
            std::cout << "Очищені усі дані очищені" << std::endl;
            deleteItem(data, size);
            break;
        case 9:
            system("clear");
            return;
        
        default:
            system("clear");
            std::cout << "Пункт не вірний. Вибери інший пункт!" << std::endl;
            break;
        }

    }

}

void collectData(Person*& data, int &size){
    system("clear");
    std::cout << "Заповність наступну інформацію про студента:" << std::endl;
    
    Person _data;

    std::cout << "Ім'я: "; std::cin >> _data.name;
    std::cout << "Прізвище: "; std::cin >> _data.surname;
    std::cout << "Назва групи: "; std::cin >> _data.group;
    
    std::cout << "А тепер заповніть " << countLesson << " предмета:" << std::endl;
    
    for (int i = 0; i < countLesson; i++)
    {
        std::cout << "Предмет №" << i + 1 << std::endl; 
        std::cout << "Назва предмета: "; std::cin >> _data.lessons[i].name;
        std::cout << "Успішність: "; std::cin >> _data.lessons[i].point;
        
    }

    std::cout << "Додавання елемента в загальний список..." << std::endl;
    addItem(data, size, _data);
    std::cout << "Елемент доданий. Загальний розмір даних: " << size << std::endl;
}

//
void dataManagmentBinMainMenu(Person*& data, int &size){
    system("clear");
    while (true)
    {
        std::cout << "-------------" << std::endl;
        std::cout << "Головне меню - Запис та читання даних в форматі Bin" << std::endl;
        std::cout << "Виберіть пункт меню:" << std::endl;
        std::cout << "1. Прочитати дані з файлу" << std::endl;
        std::cout << "2. Записати усі дані в файл" << std::endl;

        std::cout << "9. Повернутися назад" << std::endl;

        int menuChoice = getMenuChoice();

        switch (menuChoice)
        {
        case 1:
            cout << "123";
            RD();
            break;
        case 2:
            system("clear");
            RW(data, size);
            break;

        case 9:
            system("clear");
            return;
        
        default:
            system("clear");
            std::cout << "Пункт не вірний. Вибери інший пункт!" << std::endl;
            break;
        }

    }

}

void dataManagmentTxtMainMenu(Person*& data, int &size){
    string fileName = "info.txt";
    ifstream ifileStream;
    ofstream ofileStream;


    system("clear");
    while (true)
    {
        std::cout << "-------------" << std::endl;
        std::cout << "Головне меню - Запис та читання даних в форматі Txt" << std::endl;
        std::cout << "Виберіть пункт меню:" << std::endl;
        std::cout << "1. Прочитати дані з файлу" << std::endl;
        std::cout << "2. Записати усі дані в файл" << std::endl;
        std::cout << "3. Записати елемент вибірково по індексу" << std::endl;

        std::cout << "9. Повернутися назад" << std::endl;

        int menuChoice = getMenuChoice();

        switch (menuChoice)
        {
        case 1:
            system("clear");
            RD(ifileStream, fileName);
            break;
        case 2:
            system("clear");
            RW(ofileStream, fileName, data, size);
            break;

        case 9:
            system("clear");
            return;
        
        default:
            system("clear");
            std::cout << "Пункт не вірний. Вибери інший пункт!" << std::endl;
            break;
        }

    }
}
