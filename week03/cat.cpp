#include <iostream>
#include <fstream>

const int BUFF_SIZE = 1024;

void catBuffered(std::istream& is, std::ostream& os)
{
  char buffer[BUFF_SIZE];
  is.read(buffer, BUFF_SIZE); // Четем от входния поток.
  while(is.gcount() > 0){ // gcount() връща колко байта са прочетени при последното четене от потока
    os.write(buffer, is.gcount()); // Записваме го в изходния поток.
    is.read(buffer, BUFF_SIZE); // Четем отново.
  }
}

void catByteByByte(std::istream& is, std::ostream& os)
{
  // get чете един байт от потока
  // put записва един байт в потока
  char c;
  while(is.get(c)) // Четем един байт от входния поток.
  {
    os.put(c); // Записваме прочетения байт в изходния поток.
  }
    
}

int main(int argc, char* argv[])
{
  // std::cout << argc << '\n';
  // for (int i = 0; i < argc; ++i)
  // {
  //   std::cout << argv[i] << '\n';
  // }
  
  // Нямаме подадени аргументи на програмата, тогава четем от stdin и пишем върху stdout.
  if (argc == 1) 
  {
    catBuffered(std::cin, std::cout);
    // catByteByByte(std::cin, std::cout);
  }
  
    // Ако имаме подадени файлове като аргументи, четем от всички последователно 
    // и ги извеждаме на stdout.
    for (int i = 1; i < argc; ++i)
    {
      // Отваряме поток към файла.
      std::ifstream fi(argv[i], std::ios::in);
      catByteByByte(fi, std::cout);

      // Затваряме потока.
      fi.close(); // И да не го направим, при излизане от scope-а, когато се извика деструктора на fi, ще се затвори.
    }

  return 0;
}