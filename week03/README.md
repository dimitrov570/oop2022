# План за упражнението
- Четене и писане върху текстов файл
  - Ascii таблица
  - hexdump

- Файлове
  - метаданни
  - разширения
  - примери с различни формати на файлове

- Метод за писане на структурата за рационални числа в поток

- Метод за сериализация на структурата за рационални числа в поток

- Подравняване и padding

# Полезна информация

При отваряна не поток към бинарен файл се подава и флагът `std::ios::binary`. Пример: `std::ofstream output_stream("output.bin", std::ios::out | std::ios::binary);`.

## Методи

### `read( char_type* s, std::streamsize count );`

Чете `count` (втори аргумент) на брой байтове от поток и ги записва в паметта на адрес, сочен от `s` (първи аргумент).

Повече информация може да намерите [тук](https://en.cppreference.com/w/cpp/io/basic_istream/read).

### `write( const char_type* s, std::streamsize count );`

Записва в поток `count` (втори аргумент) на брой байтове, които се намират в паметта на адрес сочен от `s` (първи аргумент).

Повече информация може да намерите [тук](https://en.cppreference.com/w/cpp/io/basic_ostream/write).

### `put( char_type ch );`

Записва байта `ch` в поток.

Повече информация може да намерите [тук](https://en.cppreference.com/w/cpp/io/basic_ostream/put).

### `get`

`get` има няколко overload-а, един от които е `get( char_type& ch );`, който записва в `ch` един байт, прочетен от потока.

Другите overload-и и повече информация може да намерите [тук](https://en.cppreference.com/w/cpp/io/basic_istream/get).

### `seekg`

Два overload-a:

- `seekg( pos_type pos );`  
Премества позицията за четене от поток на `pos`, спрямо началото му.

- `seekg( off_type off, std::ios_base::seekdir dir);`  
Премества позицията за четене от поток на `pos` (първи аргумент), спрямо `dir` (втори аргумент). `dir` може да бъде `std::ios_base::beg` (начало), `std::ios_base::cur` (текущата позиция) и `std::ios_base::end` (край на потока).

Повече информация може да намерите [тук](https://en.cppreference.com/w/cpp/io/basic_istream/seekg).

### `seekp`

Същото като `seekg`, само се отнася за позицията за писане.

Повече информация може да намерите [тук](https://en.cppreference.com/w/cpp/io/basic_ostream/seekp).