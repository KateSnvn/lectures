#include "Player.h"
#include <cstdlib>
#include <ctime>

//по умолчанию
Player::Player() {
    name = "Unknown";
    posX = 0;
    posY = 0;
    hp = 100;
}

//с параметрами
Player::Player(string n, int x, int y, int h, vector<char> items) {
    name = n;
    posX = x;
    posY = y;
    hp = h;
    backpack = items;
}

//копирования
Player::Player(const Player& other) {
    name = other.name;
    posX = other.posX;
    posY = other.posY;
    hp = other.hp;
    backpack = other.backpack;
}

//присваивания
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        name = other.name;
        posX = other.posX;
        posY = other.posY;
        hp = other.hp;
        backpack = other.backpack;
    }
    return *this;
}

//деструктор
Player::~Player() {
    cout << "Вызван деструктор для игрока" << endl;
    backpack.clear();
}

//+ 
Player Player::operator+(const Player& other) {
    Player result;
    
    const char* names[] = {"Г1", "Г2", "Г3", "Г4", "Г5", "Г6"};
    int randomIndex = rand() % 6;
    result.name = names[randomIndex];
    
    result.posX = (posX + other.posX) / 2;
    result.posY = (posY + other.posY) / 2;
    result.hp = hp;
    
    result.backpack = backpack;
    
    for (int i = 0; i < other.backpack.size(); i++) {
        char item = other.backpack[i];
        bool found = false;
        
        for (int j = 0; j < result.backpack.size(); j++) {
            if (result.backpack[j] == item) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            result.backpack.push_back(item);
        }
    }
    
    return result;
}

//- 
Player Player::operator-(const Player& other) {
    Player result;

    const char* names[] = {"Г1", "Г2", "Г3", "Г4", "Г5", "Г6"};
    int randomIndex = rand() % 6;
    result.name = names[randomIndex];
    
    result.posX = other.posX;
    result.posY = other.posY;
    result.hp = hp;
    
    for (int i = 0; i < backpack.size(); i++) {
        result.backpack.push_back(backpack[i]);
    }
    
    int removeCount = 1 + rand() % other.backpack.size();
    
    for (int r = 0; r < removeCount; r++) {
        int randomIndex = rand() % other.backpack.size();
        char itemToDelete = other.backpack[randomIndex];
        
        for (int i = 0; i < result.backpack.size(); i++) {
            if (result.backpack[i] == itemToDelete) {
                for (int j = i; j < result.backpack.size() - 1; j++) {
                    result.backpack[j] = result.backpack[j + 1];
                }
                result.backpack.pop_back();
                break;
            }
        }
    }
    
    return result;
}

// / 
Player Player::operator/(const Player& other) {
    Player result;
    
    const char* names[] = {"Г1", "Г2", "Г3", "Г4", "Г5", "Г6"};
    int randomIndex = rand() % 6;
    result.name = names[randomIndex];
    
    result.posX = posX + other.posX + 5;
    result.posY = posY + other.posY - 5;
    result.hp = hp;
    
    int half1 = backpack.size() / 2;
    for (int i = 0; i < half1; i++) {
        result.backpack.push_back(backpack[i]);
    }
    
    int half2 = other.backpack.size() / 2;
    for (int i = half2; i < other.backpack.size(); i++) {
        result.backpack.push_back(other.backpack[i]);
    }
    
    return result;
}


void Player::show() {
    cout << "[" << name << "," << posX << "," << posY << ",(";
    
    for (int i = 0; i < backpack.size(); i++) {
        cout << backpack[i];
        if (i < backpack.size() - 1) {
            cout << ",";
        }
    }
    
    cout << ")]" << endl;
}