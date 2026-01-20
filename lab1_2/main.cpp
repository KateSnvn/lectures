#include <iostream>
#include <string>
using namespace std;

//3 вариант

class Player {
private:
    string name;
    int hp;
    float x;
    float y;
    string actionStatus;
    void checkHp() {
        if (hp <= 0) {
            hp = 0;
            actionStatus = "Мертв";
        } 
        else if (hp > 100) {
            hp = 100;
        }
    }
public:
    //по умолчанию
    Player() {
        name = "Неизвестный";
        x = 0.0;
        y = 0.0;
        hp = 100;
        actionStatus = "Стоит";
    }

    //полного заполнения
    Player(string n, double posX, double posY, int health, string status) {
        name = n;
        x = posX;
        y = posY;
        hp = health;
        actionStatus = status;
        checkHp();
    }

    //копирования
    Player(const Player &other) {         
        name = other.name;
        x = other.x;
        y = other.y;
        hp = other.hp;
        actionStatus = other.actionStatus;
    }

    //деструктор
    ~Player() {}


    //геттеры
    string getName() {
        return name;
    }
    float getX() {
        return x; 
    }
    float getY() { 
        return y; 
    }
    int getHp() {
        return hp; 
    }
    string getStatus() { 
        return actionStatus; 
    }

    //сеттеры
    void setPosition(float posX, float posY) {
        x = posX;
        y = posY;
        cout << "Смена позиции: (" << x << "; " << y << ")" << endl;
    }


    void takeDamage(int dmg) {
        hp -= dmg;
        checkHp();
        cout << name << " получил " << dmg << " урона." << endl;
        cout << "ХП: " << hp << endl;
    }

    void heal(int cnt) {
        if (hp > 0) {
            hp += cnt;
            checkHp();
            cout << name << " вылечился на " << cnt << ". Текущее ХП: " << hp << endl;
            cout << "ХП: " << hp << endl;
        } 
        else {
            cout << "Игрок мертв" << endl;
        }
    }
    void printInfo() {
        cout << "----------------------------" << endl;
        cout << "Информация" << endl;
        cout << "Имя: " << name << endl;
        cout << "Позиция: (" << x << "; " << y << ")" << endl;
        cout << "HP: " << hp << endl;
        cout << "Статус: " << actionStatus << endl;
        cout << "----------------------------" << endl;
    }
};
int main() {

    //cоздание через конструктор по умолчанию
    Player player1;
    player1.printInfo();

    //создание через конструктор полного заполнения
    Player player2("Герой", 10.5, 20.0, 100, "Атака");
    player2.printInfo();

    //создание через конструктор копирования
    Player player3 = player2;
    player3.printInfo();


    player1.setPosition(50.0, 50.0);
    player2.takeDamage(30);
    player2.heal(10);
    player3.takeDamage(150);

    return 0;
    }










// #include <iostream>
// #include <string>

// using namespace std;

// class Player {
// private: 
//     // Данные класса (поля) скрыты от внешнего доступа
//     string name;
//     double posX;
//     double posY;
//     int hp;
//     string actionStatus;

// protected:
//     // protected используется для методов/полей, доступных наследникам.
//     // Для демонстрации добавим сюда служебный метод проверки здоровья.
//     void checkVitality() {
//         if (hp <= 0) {
//             hp = 0;
//             actionStatus = "Мертв";
//         } else if (hp > 100) {
//             hp = 100; // Ограничим макс здоровье
//         }
//     }

// public:
//     // --- Конструкторы ---

//     // 1. Конструктор по умолчанию
//     Player() {
//         name = "Неизвестный";
//         posX = 0.0;
//         posY = 0.0;
//         hp = 100;
//         actionStatus = "Стоит";
//     }
    

//     // 2. Конструктор полного заполнения (с параметрами)
//     Player(string n, double x, double y, int health, string status) {
//         name = n;
//         posX = x;
//         posY = y;
//         hp = health;
//         actionStatus = status;
//         checkVitality(); // Проверяем корректность ХП
//         cout << "Вызван конструктор с параметрами для " << name << endl;
//     }

//     // 3. Конструктор копирования
//     Player(const Player &other) {
//         name = other.name;
//         posX = other.posX;
//         posY = other.posY;
//         hp = other.hp;
//         actionStatus = other.actionStatus;
//         cout << "Вызван конструктор копирования для " << name << endl;
//     }

//     // --- Деструктор ---
//     ~Player() {
//         cout << "Вызван деструктор для игрока " << name << endl;
//     }

//     // --- Геттеры (Getters) ---
//     string getName() { return name; }
//     double getX() { return posX; }
//     double getY() { return posY; }
//     int getHP() { return hp; }
//     string getStatus() { return actionStatus; }

//     // --- Сеттеры (Setters) ---
//     // По заданию сеттеры нужны только на положение
//     void setPosition(double x, double y) {
//         posX = x;
//         posY = y;
//     }

//     // --- Методы действий ---

//     // Получение урона
//     void takeDamage(int dmg) {
//         hp -= dmg;
//         checkVitality(); // Используем protected метод
//         cout << name << " получил " << dmg << " урона. Текущее ХП: " << hp << endl;
//     }

//     // Лечение
//     void heal(int amount) {
//         if (hp > 0) { // Лечим только живых
//             hp += amount;
//             checkVitality();
//             cout << name << " вылечился на " << amount << ". Текущее ХП: " << hp << endl;
//         } else {
//             cout << "Нельзя вылечить мертвого игрока." << endl;
//         }
//     }

//     // Вывод всей информации
//     void printInfo() {
//         cout << "--- Информация об игроке ---" << endl;
//         cout << "Имя: " << name << endl;
//         cout << "Позиция: (" << posX << ", " << posY << ")" << endl;
//         cout << "HP: " << hp << endl;
//         cout << "Статус: " << actionStatus << endl;
//         cout << "----------------------------" << endl;
//     }
// };

// int main() {
//     // Тестирование
//     setlocale(LC_ALL, "Russian"); // Для корректного вывода кириллицы

//     // 1. Создание через конструктор с параметрами
//     Player player1("Hero", 10.5, 20.0, 100, "Attack");
//     player1.printInfo();

//     // 2. Создание через конструктор по умолчанию
//     Player player2;
//     player2.printInfo();

//     // 3. Создание через конструктор копирования
//     Player player3 = player1;
//     player3.setPosition(50.0, 50.0); // Меняем позицию копии
//     player3.printInfo();

//     // Проверка методов
//     player1.takeDamage(30);
//     player1.heal(10);
//     player1.takeDamage(150); // Убийство персонажа

//     return 0;
// }









// #include <iostream>
// #include <string>

// //3 вариант

// class Character {
// private:
//     // Приватные поля: доступны только внутри класса
//     std::string name;
//     int health;

// protected:
//     // Защищенные поля: доступны в этом классе и классах-наследниках
//     float x;
//     float y;

// public:
//     // Публичные поля: доступны отовсюду (обычно поля делают приватными, но для задания добавим статус сюда)
//     std::string actionStatus;

//     // 1. Конструктор по умолчанию
//     Character() {
//         name = "Unknown";
//         x = 0.0;
//         y = 0.0;
//         health = 100;
//         actionStatus = "Idle";
//         std::cout << "[Log]: Вызван конструктор по умолчанию для " << name << std::endl;
//     }

//     // 2. Конструктор полного заполнения
//     Character(std::string n, float posX, float posY, int hp, std::string status) 
//         : name(n), x(posX), y(posY), health(hp), actionStatus(status) {
//         std::cout << "[Log]: Вызван конструктор заполнения для " << name << std::endl;
//     }

//     // 3. Конструктор копирования
//     Character(const Character &other) {
//         name = other.name + " (Copy)";
//         x = other.x;
//         y = other.y;
//         health = other.health;
//         actionStatus = other.actionStatus;
//         std::cout << "[Log]: Вызван конструктор копирования для " << name << std::endl;
//     }

//     // 4. Деструктор
//     ~Character() {
//         std::cout << "[Log]: Персонаж " << name << " удален из памяти." << std::endl;
//     }

//     // --- ГЕТТЕРЫ ---
//     std::string getName() const { return name; }
//     float getX() const { return x; }
//     float getY() const { return y; }
//     int getHealth() const { return health; }
//     std::string getStatus() const { return actionStatus; }

//     // --- СЕТТЕРЫ ---
//     void setPosition(float newX, float newY) {
//         x = newX;
//         y = newY;
//     }

//     // --- МЕТОДЫ ЛОГИКИ ---

//     // Вывод всей информации
//     void displayInfo() const {
//         std::cout << "\n--- Информация о герое ---" << std::endl;
//         std::cout << "Имя: " << name << " | Статус: " << actionStatus << std::endl;
//         std::cout << "Координаты: (" << x << ", " << y << ")" << std::endl;
//         std::cout << "Здоровье (HP): " << health << std::endl;
//         std::cout << "--------------------------\n" << std::endl;
//     }

//     // Получение урона
//     void takeDamage(int damage) {
//         health -= damage;
//         if (health < 0) health = 0;
//         std::cout << name << " получил " << damage << " урона!" << std::endl;
//     }

//     // Лечение
//     void heal(int amount) {
//         health += amount;
//         if (health > 100) health = 100; // Ограничим максимум
//         std::cout << name << " восстановил " << amount << " HP." << std::endl;
//     }
// };

// int main() {
//     // Демонстрация работы
//     setlocale(LC_ALL, "Russian"); // Для корректного вывода кириллицы в консоли Windows

//     // Создаем персонажа (полное заполнение)
//     Character hero("Воин", 10.5, 20.0, 100, "Ожидание");
//     hero.displayInfo();

//     // Двигаем и раним
//     hero.setPosition(15.0, 30.2);
//     hero.takeDamage(30);
//     hero.actionStatus = "В бою";
//     hero.displayInfo();

//     // Копируем персонажа
//     Character clone = hero;
//     clone.heal(10);
//     clone.displayInfo();

//     return 0;
// }

