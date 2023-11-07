#include <fstream>
#include <algorithm>
#include "../utils/mas.h"

using namespace std;

struct Lesson 
{
    std::string name;
    float point;
};

const int countLesson = 5;
struct Person
{
    std::string name; // Імя студента
    std::string surname; // Прізвище студента
    std::string group; // група, в якій присутній студент
    Lesson lessons[countLesson]; // успішність
};


float getAvailable(Person data){
    float sum = 0;
    for (int i = 0; i < countLesson; i++)
    {
        sum+=data.lessons[i].point;
    }
    return sum / countLesson;
    
}

bool compare(Person &a, Person &b) {
        return getAvailable(a) > getAvailable(b);

}
// bin
void RD(){
    //  Читання файлу bin з диску та виведення на екран файлу
    const int size = 2;

    Person* data = new Person[size];
    FILE *byteStream = fopen("info.dat", "rb");
    fread(data, sizeof(Person), size, byteStream);
    fclose(byteStream);
    
    int _size = 2;
    cout << viewData(data, _size);

    sort(&data[0], &data[size - 1], compare);
    cout << "Sorted by marks" << endl;
    std::cout << viewData(data, size);
    

};
void RW(Person*& data, int size){
    //  Запис файлу bin
    size = 2;
    FILE *byteStream = fopen("info.dat", "wb");
    fwrite(data, sizeof(Person), size, byteStream);
    fclose(byteStream);
};

// txt
void RD(ifstream &fileStream, std::string fileName){
    //  Читання файлу txt з диску та виведення на екран файлу

    int size = 0;
    Person *data = nullptr;
    Person _data;
    // дописати читання з файлу і аналіз
    fileStream.open(fileName);
    string tmp;
    fileStream >> tmp >> tmp;
    
    while (fileStream >> tmp >> tmp >> tmp >> tmp >> tmp >> _data.name >> tmp >> _data.surname >> tmp >> tmp >> _data.group >> tmp >> tmp >> tmp >> tmp >> tmp >> _data.lessons[0].name >> tmp >> tmp >> _data.lessons[0].point >> tmp >> tmp >> tmp >> tmp >> _data.lessons[1].name >> tmp >> tmp >> _data.lessons[1].point >> tmp >> tmp >> tmp >> tmp >> _data.lessons[2].name >> tmp >> tmp >> _data.lessons[2].point >> tmp >> tmp >> tmp >> tmp >> _data.lessons[3].name >> tmp >> tmp >> _data.lessons[3].point >> tmp >> tmp >> tmp >> tmp >> _data.lessons[4].name >> tmp >> tmp >> _data.lessons[4].point ){
        addItem(data, size, _data);
    };
    cout << viewData(data, size);

    float minPoint = 5;
    int index = 0;
    for (int i = 0; i < size; i++)
    {  
        int avgSum = getAvailable(data[i]);
        if (minPoint > avgSum)
        {
            minPoint = avgSum;
            index = i;
        }
        
    }
    cout << "Студент, який має найнищий бал: " << data[index].surname << endl;


};

void RW(ofstream &fileStream, std::string fileName, Person*& data, int size){
    //  Запис файлу txt 

    fileStream.open(fileName);
    fileStream << viewData(data, size);
    fileStream.close();

};
