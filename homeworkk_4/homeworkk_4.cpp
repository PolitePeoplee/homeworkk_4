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
    }

    // Деструктор для освобождения выделенной памяти
    ~String()
    {
        delete[] str;
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

    // Метод compare, который сравнивает текущую строку с другой строкой и возвращает результат сравнения.
    int compare(const String& otherString) const
    {
        return strcmp(str, otherString.str); // функция возвращает -1, 0, 1
    }

    // Методы toUpper и toLower, которые преобразуют все символы строки в верхний или нижний регистр.
    void toUpper()
    {
        for (size_t i = 0; i < size; i++)
            str[i] = toupper(str[i]); // каждый член заменяем им же, но верхнего регистра
    }

    void toLower()
    {
        for (size_t i = 0; i < size; i++)
            str[i] = tolower(str[i]); // каждый член заменяем им же, но верхнего регистра
    }

    void printttt() const
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
    String concatenatedStr = helloStr.concat(worldStr);
    concatenatedStr.printttt();

    String a("Hello");
    String b("World");
    cout << a.compare(b) << endl;
    a.toUpper();
    a.printttt();
    a.toLower();
    a.printttt();

    return 0;
}
