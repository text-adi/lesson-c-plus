
void addItem(Person *&, int&, Person &);

void addItem(Person *&data, int &size, Person &item){
    

    Person* _data = new Person[size + 1];

    for (int i = 0; i < size; i++)
    {
        _data[i] = data[i];
    }
    size++;
    _data[size-1] = item;
    delete[] data;  

    data = _data;
};

std::string viewData(Person *&data, int &size){


    std::string viewText = "";

    if (!size)
    {
        viewText.append("Немає даних!\n");
        return viewText;
    }
    viewText.append("Детальна інформація:\n");

    
    for (int i = 0; i < size; i++)
    {
        viewText.append("Інформація про студента №").append(std::to_string(i + 1)).append("\n");
        viewText.append("Ім'я: ").append(data[i].name).append("\n");
        viewText.append("Прізвище: ").append(data[i].surname).append("\n");
        viewText.append("Назва групи: ").append(data[i].group).append("\n");
        viewText.append("---------------\n");
        for (int indexLesson = 0; indexLesson < countLesson; indexLesson++)
        {
            viewText.append(std::to_string(i + 1)).append(" предмет:\n");
            viewText.append("\tНазва предмет: ").append(data[i].lessons[indexLesson].name).append("\n");
            viewText.append("\tОцінка успішності: ").append(std::to_string(data[i].lessons[indexLesson].point)).append("\n");
            
        }
        
    }
    return viewText;

};

void deleteItem(Person *&data, int &size, int possition){
    
    if (possition < 1 || size < possition )
    {
        std::cout << "Неможливо видалити елемент, так як такого номера елемента немає. Вибери елементи більше 0 та менше " << size << std::endl;
        return;
    }

    Person* _data = new Person[size - 1];
    int _index = 0;

    for (int i = 0; i < size; i++)
    {
        if (i == possition - 1)
        {
            continue;
        }
        
        _data[_index] = data[i];
        _index++;
    }

    size--;
    delete[] data;  

    data = _data;
    std::cout << "Елемент під номером " << possition << " видалений" << std::endl;
};

void deleteItem(Person *&data, int &size){
    
    delete[] data;
    size = 0;
    data = nullptr;

};