#include <fstream>
#include <iostream>

void printNthNumberFromBinaryFile(const char* filename, int n)
{
    std::ifstream fi(filename, std::ios::in | std::ios::binary);

    // Преместваме указателя във файла на n-тото число
    // като започваме да броим от 0.
    fi.seekg(n*sizeof(int), std::ios::beg);

    int number;

    // Подаваме указател, който сочи към number от тип char и четем sizeof(int) байта,
    // които ги записваме в number.
    fi.read((char *)&number, sizeof(int));

    std::cout << number;
}

// Записва числава от 0 до numbersCount във файл, чието име е подадено като първ аргумент
void binaryOutput(const char* filename, int numbersCount)
{
    // Отваряме файл за писане в binary mode.
    std::ofstream fo(filename, std::ios::out | std::ios::trunc);
     
    int i;
    for(i = 0; i < numbersCount; ++i)
    {   
        // подаваме указател от тип const char*, който съдържа адреса на i
        // и пишем върху файла sizeof(int) байта от i 
        fo.write((const char*)&i, sizeof(int));
    }

    // Трябва да затворим потока, ако искаме да отворим друг за четене от същия файл.
    fo.close(); 
    
    // При излизане от функцията ще се извикат деструкторите на fi и fo 
    // и ако потоците не са затворени, ще се затворят тогава.
}

void binaryInput(const char* filename, int numbersCount)
{
    std::ifstream fi(filename); // По подразбиране mode = std::ios::in.
    
    int r;
    for (int i = 0; i < numbersCount; ++i)
     {
        // Подаваме указател, който сочи към number от тип char и четем sizeof(int) байта,
        // които ги записваме в number.
        // Т.е. тук на метода read даваме указател, който сочи към мястото в паметта,
        // където се намира r, за да може read да запише sizeof(int) байта на този адрес,
        // т.е. в променливата r.
        fi.read((char *)&r, sizeof(int));
        std::cout << "Read: " << r << '\n';
     }
}

void formattedOutput(const char* filename, int numbersCount)
{

    // Отваряме файл за писане.
    std::ofstream fo(filename, std::ios::out | std::ios::trunc);
     
    int i;
    for(i = 0; i < numbersCount; ++i)
    {   
        // Tук вече ги пишем с operator<<, т.е. форматирано.
        // Във файла няма да са истинските стойности на числата,
        // а ASCII кодовете им.
        fo << i << '\n';
    }

    // Трябва да затворим потока, ако искаме да отворим друг за четене от същия файл.
    fo.close();

    // При излизане от функцията ще се извикат деструкторите на fi и fo 
    // и ако потоците не са затворени, ще се затворят тогава.
}


void formattedInput(const char* filename, int numbersCount)
{
    // По подразбиране mode = std::ios::in.
    std::ifstream fi(filename); 
    
    int r;
    for (int i = 0; i < numbersCount; ++i)
     {
        // Четем с operator>>.
        fi >> r;
        std::cout << "Read: " << r << '\n';
     }
}

int main()
{

    // binaryOutput("file.bin", 10);
    // binaryInput("file.bin", 10);
    // printNthNumberFromBinaryFile("file.bin", 4);
   
    // Забележете, че при текстовите файлове няма смисъл да движим
    // указателя във файла със seekp и seekg, защото примерно числото 12, ще се 
    // запише като последователност от два char-а: '1' и '2' и ще заема 2 байта,
    // а числото 4356 ще се запише като последователност от: '4' '3' '5' '6' и ще заема
    // 4 байта, докато при бинарните файлове всички числа от тип int се записваха в 4 байта.
    formattedOutput("file.txt", 100);
    formattedInput("file.txt", 10);

    return 0;
}