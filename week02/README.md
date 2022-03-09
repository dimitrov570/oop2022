# План за упражнението
- Структури продължение
  - член-данни от същия тип

- Структура за рационално число

- ООП парадигма
  - абстракция
  - енкапсулация
  - наследяване
  - полиморфизъм

- Потоци

- Стандартни потоци:
  - за вход
  - за изход
  - за грешка

- Пренасочване на потоци

- Състояния на потоци
  - буфериране (flush)

- Команда cat

- Четене и писане върху текстов файл

# Полезна информация

## Потоци
### Стандартни потоци
- за вход (`stdin`)
- за изход (`stdout`)
- за грешка (`stderr`)

### Функции за проверка за състоянието на потока (връщат `true` ако съответният бит е вдигнат):
- `bool good()`
- `bool eof()`
- `bool fail()`
- `bool bad()`
- `iostate rdstate()`

`clear(iostate state = goodbit)` променя стойността на всички флагове да бъде `state`, което по подрзабиране е `goodbit`, което е 0.

Повече информация [тук](http://www.cplusplus.com/reference/ios/ios/).

### Пренасочване на вход от файл
`./main < input.txt`
### Пренасочване на изход към файл
`./main > output.txt`
### Пренасочване на поток за грешки към файл
`./main 2> err.txt`

## Файлове
- метаданни
- разширения
- ifstream
- ofstream
- fstream

### Методът `open`
Отваря файл с име `filename`.  
- `void open(const char *filename, ios_base::openmode mode);`  

`mode` може да приема следните стойности:
- app
- binary
- in
- out
- trunc
- ate

### ifstream
Поток за четене от файл.  
`open(const char *filename, ios_base::openmode mode = `**ios_base::in**`);`

### ofstream
Поток за писане върху файл.
`open(const char *filename, ios_base::openmode mode = `**ios_base::out**`);`

### fstream
Поток за четене от и писане върху файл.
`open(const char *filename, ios_base::openmode mode = `**ios_base::in** `|` **ios_base::out**`);`

### Повече информация може да намерите на следните адреси
- [istream](https://en.cppreference.com/w/cpp/io/basic_istream)
- [ostream](https://en.cppreference.com/w/cpp/io/basic_ostream)
- [ifstream](https://en.cppreference.com/w/cpp/io/basic_ifstream)
- [ofstream](https://en.cppreference.com/w/cpp/io/basic_ofstream)
- [fstream](https://en.cppreference.com/w/cpp/io/basic_fstream)