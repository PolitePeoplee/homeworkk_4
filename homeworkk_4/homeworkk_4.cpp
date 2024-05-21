#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    char* str;  // Указатель на C-строку
    size_t size;  // Размер строки (без учета завершающего нулевого символа)

public:
    // Конструктор
    String(const char* c_str)
    {
        size = strlen(c_str);
        str = new char[size + 1];
        strcpy(str, c_str);
        str[size] = '\0';
    }

    // Деструктор для освобождения выделенной памяти
    ~String()
    {
        delete[] str;
        size = 0;
    }

    // Функция для добавления строки
    void append(const char* other_str)
    {
        size_t other_size = strlen(other_str);
        char* tmp = new char[size + 1];
        strcpy(tmp, str);
        delete[] str;
        str = new char[size + other_size + 1];
        strcpy(str, tmp);
        strcat(str, other_str);
        size += other_size;
        delete[] tmp;
    }

    // Функция для объединения двух строк
    String concat(const String& otherString) const
    {
        size_t newLength = size + otherString.size;
        char* newData = new char[newLength + 1];
        strcpy(newData, str);
        strcat(newData, otherString.str);
        String newString(newData);
        delete[] newData;
        return newString;
    }

    //метод  compare, который сравнивает текущую строку с другой строкой и возвращает результат сравнения.
    int compare(const String& otherString)
    {
        return strcmp(str, otherString.str);//функция возвращает -1, 0, 1
    }

    //методы toUpper и toLower(, которые преобразуют все символы строки в верхний или нижний регистр.
    void toUpper()
    {
        for (int i = 0; i < strlen(str); i++)
            str[i] = toupper(str[i]);//каждый член заменяем им же, но верхнего регистра
    }
    void toLower()
    {
        for (int i = 0; i < strlen(str); i++)
            str[i] = tolower(str[i]);//каждый член заменяем им же, но верхнего регистра
    }
    void printttt()
    {
        cout << str << endl;
    }
};

int main()
{
    const char* initial_str = "Hello ";
    const char* append_str = "World!";
    String myString(initial_str);
    myString.append(append_str);
    myString.printttt();

    const char* hello = "Hello";
    const char* world = "World";

    String helloStr(hello);
    String worldStr(world);
    helloStr.concat(worldStr);
    helloStr.printttt();

    String a("Hello");
    String b("World");
    cout << a.compare(b) << endl;
    a.toUpper();
    a.printttt();
    a.toLower();
    a.printttt();
    return 0;
}
