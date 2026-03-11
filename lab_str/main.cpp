#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

using namespace std;
//вариант 3

int getUtf8Char(const string& s, size_t& i) {
    unsigned char c = (unsigned char)s[i];
    if (c < 0x80) {
        i++;
        return c;
    } 
    else if ((c & 0xE0) == 0xC0 && i + 1 < s.size()) {
        int ch = ((c & 0x1F) << 6) | ((unsigned char)s[i+1] & 0x3F);
        i += 2;
        return ch;
    }
    i++;
    return c;
}

bool RusGl(int cp) {
    if (cp >= 0x410 && cp <= 0x42F) {
        cp += 0x20;
    }
    if (cp == 0x401) {
        cp = 0x451;
    }
    
    int gl[] = {0x430, 0x435, 0x451, 0x438, 0x43E, 0x443, 0x44A, 0x44B, 0x44C, 0x44D, 0x44E, 0x44F};

    for (int v : gl) {
        if (cp == v) {
            return true;
        }
    }
    return false;
}

bool RusLetter(int cp) {
    return (cp >= 0x410 && cp <= 0x44F) || cp == 0x401 || cp == 0x451;
}

int RusLower(int cp) {
    if (cp >= 0x410 && cp <= 0x42F) {
        return cp + 0x20;
    }
    if (cp == 0x401) {
        return 0x451;
    }
    return cp;
}

int RusUpper(int cp) {
    cp = RusLower(cp);
    if (cp >= 0x430 && cp <= 0x435) {
        return cp - 0x430;
    }
    if (cp == 0x451) {
        return 6;
    }
    if (cp >= 0x436 && cp <= 0x44F) {
        return cp - 0x436 + 7;
    }
    return -1;
}

void printSymbolTable() {
    cout << "-----п0: таблица символов:-----" << endl;
    cout << "символ | код" << endl;
    
    for (char c = 'A'; c <= 'Z'; c++)
        printf("%c | %3d\n", c, (int)c);
    
    for (char c = 'a'; c <= 'z'; c++)
        printf("%c | %3d\n", c, (int)c);
    
    for (char c = '0'; c <= '9'; c++)
        printf("%c | %3d\n", c, (int)c);
    
    const char* punct = ".,!?;:-()\"'";
    for (int i = 0; punct[i]; i++)
        printf("%c | %3d\n", punct[i], (int)punct[i]);
    
    cout << "-------------------------" << endl;
    cout << "символ | код" << endl;
    
    for (int cp = 0x410; cp <= 0x42F; cp++) {
        char buf[5] = {0};
        buf[0] = (char)(0xD0 | (cp >> 6));
        buf[1] = (char)(0x80 | (cp & 0x3F));
        printf("%s | %5d\n", buf, cp);
    }
    printf("\xD0\x81 | %5d\n", 0x401);
    
    for (int cp = 0x430; cp <= 0x44F; cp++) {
        char buf[5] = {0};
        buf[0] = (char)(0xD0 | (cp >> 6));
        buf[1] = (char)(0x80 | (cp & 0x3F));
        printf("%s | %5d\n", buf, cp);
    }
    printf("\xD1\x91 | %5d\n", 0x451);
}

void task1() {
    cout << "\n-----п1: удаление гласных-----" << endl;
    
    char str[201];
    cout << "введите строку(не более 100 символов): ";
    cin.getline(str, 201);
    
    char result[201];
    int j = 0;
    int len = (int)strlen(str);
    
    for (int i = 0; i < len; ) {
        unsigned char c0 = (unsigned char)str[i];
        if (c0 < 0x80) {
            result[j++] = str[i++];
        } 
        else if ((c0 & 0xE0) == 0xC0 && i + 1 < len) {
            int cp = ((c0 & 0x1F) << 6) | ((unsigned char)str[i+1] & 0x3F);
            if (!RusGl(cp)) {
                result[j++] = str[i];
                result[j++] = str[i+1];
            }
            i += 2;
        } 
        else {
            result[j++] = str[i++];
        }
    }
    result[j] = '\0';
    
    cout << "результат: " << result << endl;
}

string cleanWord(const string& word) {
    string result;
    size_t i = 0;
    while (i < word.size()) {
        unsigned char c0 = (unsigned char)word[i];
        if (c0 < 0x80) {
            if (isalpha(c0)) {
                result += (char)tolower(c0);
            }
            i++;
        } 
        else if ((c0 & 0xE0) == 0xC0 && i + 1 < word.size()) {
            int cp = ((c0 & 0x1F) << 6) | ((unsigned char)word[i+1] & 0x3F);
            if (RusLetter(cp)) {
                int lcp = RusLower(cp);
                result += (char)(0xD0 | (lcp >> 6));
                result += (char)(0x80 | (lcp & 0x3F));
            }
            i += 2;
        } 
        else {
            i++;
        }
    }
    return result;
}

bool isAlphabetical(const string& word) {
    vector<int> indices;
    size_t i = 0;
    while (i < word.size()) {
        unsigned char c0 = (unsigned char)word[i];
        if (c0 < 0x80) {
            indices.push_back((int)tolower(c0));
            i++;
        } 
        else if ((c0 & 0xE0) == 0xC0 && i + 1 < word.size()) {
            int cp = ((c0 & 0x1F) << 6) | ((unsigned char)word[i+1] & 0x3F);
            int idx = RusUpper(cp);
            if (idx >= 0) indices.push_back(idx);
            i += 2;
        } 
        else {
            i++;
        }
    }
    for (size_t k = 0; k + 1 < indices.size(); k++) {
        if (indices[k+1] < indices[k]) {
            return false;
        }
    }
    return true;
}

int letterCount(const string& word) {
    int cnt = 0;
    for (size_t i = 0; i < word.size(); ) {
        unsigned char c = (unsigned char)word[i];
        if (c < 0x80) { 
            cnt++; i++; 
        }
        else if ((c & 0xE0) == 0xC0) {
            cnt++; i += 2; 
            }
        else { 
            i++; 
        }
    }
    return cnt;
}

void task2() {
    cout << "\n-----п2: поиск слов, в которых все буквы упорядочены по алфавиту-----" << endl;
    
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "не удалось открыть файл input.txt" << endl;
        return;
    }
    int N;
    inputFile >> N;
    inputFile.close();
    
    if (N <= 0) {
        cout << "N должно быть положительным числом" << endl;
        return;
    }
    
    ifstream textFile("text.txt");
    if (!textFile) {
        cout << "не удалось открыть файл text.txt" << endl;
        return;
    }
    vector<string> biggest_words;
    string word;
    
    while (textFile >> word) {
        string cleaned = cleanWord(word);
        if (cleaned.empty()) {
            continue;
        }

        if (!isAlphabetical(cleaned)) {
            continue;
        }
        
        bool found = false;
        for (size_t k = 0; k < biggest_words.size(); k++)
            if (biggest_words[k] == cleaned) { 
                found = true; break; 
            }
        if (found) {
            continue;
        }

        if ((int)biggest_words.size() < N || letterCount(cleaned) > letterCount(biggest_words.back())) {
            int pos = (int)biggest_words.size();
            for (int k = 0; k < (int)biggest_words.size(); k++) {
                if (letterCount(cleaned) > letterCount(biggest_words[k])) {
                    pos = k;
                    break;
                }
            }
            biggest_words.insert(biggest_words.begin() + pos, cleaned);

            if ((int)biggest_words.size() > N) {
                biggest_words.pop_back();
            }
        }
    }
    textFile.close();

    cout << "Подходящих слов найдено: " << biggest_words.size() << endl;

    if (biggest_words.empty()) {
        cout << "Нет подходящих слов" << endl;
        return;
    }

    ofstream resultFile("result.txt");
    if (!resultFile) {
        cout << "Ошибка: не удалось создать файл result.txt" << endl;
        return;
    }

    resultFile << "Самые длинные слова с буквами по алфавиту:" << endl;
    for (int i = 0; i < (int)biggest_words.size(); i++) {
        resultFile << i + 1 << ". " << biggest_words[i] << " (длина: " << letterCount(biggest_words[i]) << ")" << endl;
    }
    resultFile.close();

    cout << "\nРезультат:" << endl;
    for (int i = 0; i < (int)biggest_words.size(); i++) {
        cout << i + 1 << ". " << biggest_words[i] << " (длина: " << letterCount(biggest_words[i]) << ")" << endl;
    }
    cout << "Результаты сохранены в result.txt" << endl;
}

int main() {
    printSymbolTable();
    task1();
    task2();
    return 0;
}