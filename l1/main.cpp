#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <iostream>
#include "program/menu.cpp"

#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    // int size = 1;
    // int *mas = new int[size];
    

    // for (int i = 0; i < size; i++)
    // {
    //     mas[i] = i;
    // }
    // cout << "Елементи:" << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << mas[i] << ", ";
    // }

    // int *new_mass = new int[size + 1];
    // for (int i = 0; i < size; i++)
    // {
    //     new_mass[i] = mas[i];   
    // }
    // new_mass[size] = 99;
    // mas = new_mass; 
    // size++;
    
    //  cout << "Елементи:" << endl;
    // for (int i = 0; i < size; i++)
    // {
        
    //      cout << mas[i] << ", ";
    // }

    // ofstream myfile;
    // myfile.open("info.txt");
    // myfile << "test";
    // myfile.close();
    
    // Person *data =  new Person[1];
    // data[0].name = "test";
    // // cout << data[0].name;
    
    // FILE *file = fopen("data", "wb");

    // fwrite(data, sizeof(Person), 1, file);
    // fclose(file);


    // Person *_data =  new Person[1];
    // FILE *_file = fopen("data", "rb");
    // fread(_data, sizeof(Person), 1, _file);

    // fclose(_file);
    // std::cout << " | " << _data[0].name << std::endl;

    mainMenu();
}

