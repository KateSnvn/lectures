#include <iostream>
#include <string>
using namespace std;

//3 вариант

struct Stop {
    string name;
    Stop* next;
    int price;
};

Stop* route1 = nullptr;
Stop* route2 = nullptr;
Stop* route3 = nullptr;


void showRoute() {
    string from, to;
    cout << "откуда: ";
    cin >> from;
    cout << "куда: ";
    cin >> to;
    
    if (from == to) {
        cout << "вы на месте" << endl;
        return;
    }
    
    Stop* start = nullptr;
    Stop* end = nullptr;
    int startRoute = 0, endRoute = 0;
    
    Stop* cur = route1;
    while (cur != nullptr) {
        if (cur->name == from) {
            start = cur; 
            startRoute = 1; 
        }
        if (cur->name == to) {
            end = cur; 
            endRoute = 1; 
        }
        cur = cur->next;
    }
    
    cur = route2;
    while (cur != nullptr) {
        if (cur->name == from) {
            start = cur; 
            startRoute = 2; 
        }
        if (cur->name == to) {
            end = cur; 
            endRoute = 2; 
        }
        cur = cur->next;
    }
    
    cur = route3;
    while (cur != nullptr) {
        if (cur->name == from) {
            start = cur; 
            startRoute = 3; 
        }
        if (cur->name == to) {
            end = cur; 
            endRoute = 3; 
        }
        cur = cur->next;
    }
    
    if (start == nullptr || end == nullptr) {
        cout << "остановка не найдена" << endl;
        return;
    }
    
    if (startRoute != endRoute) {
        cout << "остановки на разных маршрутах" << endl;
        return;
    }
    
    Stop* current = start;
    int totalprice = 0;
    bool found = false;
    
    cout << "путь: " << current->name << " ";
    
    while (current != nullptr && !found) {
        if (current == end) {
            found = true;
            break;
        }
        
        if (current->next == nullptr) {
            break;
        }
        
        totalprice += current->price;
        current = current->next;
        cout << current->name << " ";
    }
    
    cout << "стоимость:" << totalprice << endl;
    
    if (found && end->next == nullptr) {
        cout << "конечная остановка" << endl;
    }
}

void addStop() {
    string where;
    cout << "куда добавить: ";
    cin >> where;
    
    Stop* target = nullptr;
    
    Stop* cur = route1;
    while (cur != nullptr) {
        if (cur->name == where) {
            target = cur; 
            break;
        }
        cur = cur->next;
    }
    
    if (target == nullptr) {
        cur = route2;
        while (cur != nullptr) {
            if (cur->name == where) {
                target = cur;
                break; 
            }
            cur = cur->next;
        }
    }
    
    if (target == nullptr) {
        cur = route3;
        while (cur != nullptr) {
            if (cur->name == where) {
                target = cur; break;
            }
            cur = cur->next;
        }
    }
    
    if (target == nullptr) {
        cout << "остановка не найдена" << endl;
        return;
    }
    
    Stop* last = target;
    while (last->next != nullptr) {
        last = last->next;
    }
    
    Stop* newStop = new Stop;
    cout << "название новой остановки: ";
    cin >> newStop->name;
    cout << "cтоимость до новой остановки: ";
    cin >> newStop->price;
    newStop->next = nullptr;
    
    last->next = newStop;
    cout << "добавлено" << endl;
}
int main() {
    
    route1 = new Stop{"A", nullptr, 10};
    route1->next = new Stop{"B", nullptr, 15};
    route1->next->next = new Stop{"C", nullptr, 30};
    
    route2 = new Stop{"D", nullptr, 20};
    route2->next = new Stop{"E", nullptr, 25};
    route2->next->next = new Stop{"F", nullptr, 35};
    

    while (true) {
        cout << "меню"<< endl;
        cout << "1. найти путь" << endl;
        cout << "2. добавить остановку" << endl;
        cout << "3. выход" << endl;
        cout << "ваш выбор: ";
        
        int point; 
        cin >> point;

        if (point == 1) {
            showRoute();
        }
        else if (point == 2) {
            addStop();
        }

        else if (point == 3) {
            break;
        }
    }
    return 0;
}

