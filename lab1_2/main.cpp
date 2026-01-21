#include <iostream>
#include <string>
using namespace std;

//3 вариант

class Player {
private:
    string name;
    int hp;
    void checkHp() {
        if (hp <= 0) {
            hp = 0;
            actionStatus = "Мертв";
        } 
        else if (hp > 100) {
            hp = 100;
        }
    }
    float x;
    float y;
    string actionStatus;
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
        checkHp();
        actionStatus = status;
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
    ~Player() {
        cout << "Run_Destructor" << endl;
    }


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
    void setPositionX(float posX) {
        x = posX;
        cout << "Перемещение на X: " << posX << endl;
    }
    void setPositionY(float posY) {
        y = posY;
        cout << "Перемещение на Y: " << posY << endl;
    }


    void damage(int dmg) {
        if (dmg > 0) {
            hp -= dmg;
            checkHp();
            cout << name << " получил " << dmg << " урона." << endl;
            cout << "ХП: " << hp << endl;
        }
    }

    void heal(int cnt) {
        if (cnt > 0) {
            if (hp > 0) {
                hp += cnt;
                checkHp();
                cout << name << " вылечился на " << cnt << ". Текущее ХП: " << hp << endl;
                cout << "ХП: " << hp << endl;
            } 
            else {
                cout << "Игрок мертв и не может лечиться" << endl;
            }
        }
    }
    void info() {
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
    player1.info();

    //создание через конструктор полного заполнения
    Player player2("Герой", 10.5, 20.0, 100, "Атака");
    player2.info();

    //создание через конструктор копирования
    Player player3 = player2;
    player3.info();


    player1.setPositionX(50.0);
    player1.setPositionY(50.0);
    player2.damage(30);
    player2.heal(10);
    player3.damage(150);

    return 0;
    }