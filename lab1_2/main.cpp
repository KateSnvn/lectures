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