#include <QDebug>

int main() {
   
   // Создаем строку типа QString
   QString a = "love";
   
   // Добавляем текст в конец строки
   a.append(" chess");
 
   // Добавляем текст в начало строки
   a.prepend("I ");
   
   // Выводим строку
   qInfo() << a << "\n"; //std::endl;
 
   // Выводим количество символов строки
   qInfo() << "The a string has " << a.count() << " characters" << "\n"; //Qt::endl;
   
   // Выводим всю строку в верхнем регистре
   qInfo() << a.toUpper()<< "\n"; //std::endl;    
 
   // Выводим всю строку в нижнем регистре
   qInfo() << a.toLower() << "\n"; //Qt::endl;
   
   return 0;
}

