
#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <map>
#include <unordered_map>
#include "Matrix.h"
#include <vector>
#include <algorithm>
#include "A5.cpp"
#include <bitset>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/aes.h>


#define _CRT_SECURE_NO_WARNINGS






using namespace std;

string alf = "абвгдежзийклмнопрстуфхцчшщъыьэюя";              //алфавит 
string alf2 = "-,. ";
vector<string> alf3{ "тире","зпт","тчк","прб"};
vector <string> alf4{ "-",",","."," " };

string mas_alf[32] = {                                         //побитовый алфавит
    "000001", "000010", "000011",
    "000100", "000101", "000110",
    "000111", "001000", "001001",
    "001010", "001011", "001100",
    "001101", "001110", "001111",
    "010000", "010001", "010010",
    "010011", "010100", "010101",
    "010110", "010111", "011000",
    "011001", "011010", "011011",
    "011100", "011101", "011110",
    "011111", "100000" };


int func(char& a)                                   //считает индекс буквы по буквенному значению
{
    for (int i = 0; i < alf.length(); i++)
    {
        if (a == alf[i]) return (i + 1);
    }
    return 0;
}


int mod(int value, int modd)
{
    if (value >= modd) value %= modd;
    if (value < 0) value = modd - (-value) % modd;
    return value;
}

int func1(string a)                                //считает индекс буквы по битовому значению
{
    char c = '0';
    char d = '1';
    int sum = 0;

    if (a[0] == d) sum += 32;
    if (a[1] == d) sum += 16;
    if (a[2] == d) sum += 8;
    if (a[3] == d) sum += 4;
    if (a[4] == d) sum += 2;
    if (a[5] == d) sum += 1;
    if (sum == 0) return 0;
    return (sum - 1) % 32;
}

int func2(int& k1, int& k2, int& k3)
{
    int k = rand() % 3;
    if (!k) return k1;
    if (k == 1) return k2;
    if (k == 2) return k3;
}

void krasiviyvivod(int i, int k)
{
    if (i % k == 0) cout << "\n";
    else cout << "\t";
}

void func3(char& a)                                       //полибий, мать его 
{
    int j = 1;
    int k = 1;    
        for (; j < alf.length()+1; j++)
        {
            if (a == alf[j-1])
            { 
                j = j % 6;
                if (j == 0) j = 6;
                cout << k << j << "\t";
                break;
            } 
            if ((j ) % 6 == 0) k++;
        }
}

int func4(char& a)                                   //считает индекс буквы по буквенному значению (с нуляя)
{
    for (int i = 0; i < alf.length(); i++)
    {
        if (a == alf[i]) return i;
    }
    return 0;
}

string func5(char& a) {
    if (a == '.') return "тчк";
    else if (a == ',') return "зпт";
    else if (a == '-') return "тире";
    else if (a == ' ') return "прб";
}

string func6(string a) {                                                                            //replace ceparators
    string rez = "";
    for (int i = 0; i < a.length(); i++) {
        
            if (a[i] == alf2[0] || a[i] == alf2[1] || a[i] == alf2[2] || a[i] == alf2[3])
                rez += func5(a[i]);
            else 
                rez +=tolower(a[i]);
    }
    return rez;
}

string func7(string& a) {                                                                           // replaceX2 ceparators
    string hh = a;

    for (int i = 0; i < alf3.size(); i++) {
        string new_str = alf4[i];  // на какую строку заменить
        size_t start{ a.find(alf3[i])};            // находим позицию подстроки

        while (start != string::npos) // находим и заменяем все вхождения строки old_str
        {
            a.replace(start, alf3[i].length(), new_str); // Замена old_str на new_str
            start = a.find(alf3[i], start + new_str.length());
        }
    }
    
    return a;
}

string func8(string& key, const string& alphabet)
{
    string newAlphabet = alphabet;

    for (int i = 0; i < key.length(); i++) {
        if (key[i] == 'й')
            key[i] = 'и';

        else if (key[i] == 'ъ')
            key[i] = 'ь';
    }

    for (int i = 0; i < key.length(); i++) {
        for (int l = 0; l < newAlphabet.length(); l++) {
            if (newAlphabet[l] == 'й')
                newAlphabet.erase(l, 1);

            else if (newAlphabet[l] == 'ъ')
                newAlphabet.erase(l, 1);

            if (key[i] == newAlphabet[l])
                newAlphabet.erase(l, 1);
        }
    }
    return key+newAlphabet;
}

string func9(vector<vector<char>>& matr, int  column, int row) {
    string rez = "";
        for (int i = 0; i < row; i++) 
            rez += matr[i][column];

        
    return rez;
}

void hexStringToBytes(const std::string& hex, unsigned char* bytes) {
    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        unsigned char byte = (unsigned char)std::strtoul(byteString.c_str(), nullptr, 16);
        bytes[i / 2] = byte;
    }
}

std::string bytesToHexString(const unsigned char* bytes, size_t length) {
    std::string hexString;
    for (size_t i = 0; i < length; ++i) {
        char buf[3];
        sprintf_s(buf, sizeof(buf), "%02x", bytes[i]);
        hexString.append(buf);
    }
    return hexString;
}

string encryptVtransposition(const string& plaintext, const vector<int>& key);

string decryptVtransposition(const string& ciphertext, const string& key);

string decryptPlayfair(const std::string& ciphertext,  std::string& key);

int main()
{
    srand(time(NULL));
    system("chcp 1251");

    string word2 = "ктобоитсякаждогокуста,никогданедолженходитьналовлюптиц.";

    int c = 0;

    cout << endl << "vvedite variant: \n1-вывести индексы букв \n2-вывести буквы по их индексу \n3-отобразить букы в побитовом виде \n4-отобразить биты в буквенном виде \n5-Атбаш \n6-Полибия \n7-Цезарь \n8-Виженера \n9-Белазо \n10-Тритемия \n11-Кардано \n12-Виженера 2 \n13-Маршрутной перестановки \n14-Вертикальной перестановки \n15-Матричный \n16-Плейфера \n17-Битовый \n 18-блокнот Шеннона \n 19-RSA(вроде) \n 20-Elgamal \n 24-AES" << endl;
    cin >> c;

    switch (c)
    {
    case 1:                                                  //выводит индексы букв фразы
    {
        string phrase = "";
        cout << "Введите фразу" << endl;
        getline(cin, phrase);

        for (int k = 0; k < phrase.length();)
        {
            for (int i = 0; i < 10; i++)
            {
                cout << func(phrase[k]) << "\t";
                k++;
            }
            cout << endl;
        }
        break;
    }
    case 2:                                                  //выводит буквы по их индексу
    {
        int* mas = new int[255];
        int i = 0;
        int g = 0;
        while (true)
        {
            cin >> g;
            if (g == 666)
            {
                for (int k = 0; k < i; k++)
                {
                    cout << alf[mas[k] - 1];
                }
                break;
            }
            mas[i] = g;
            i++;
        }
        delete[] mas;
        break;
    }
    case 3:                                               //отображает букы в побитовом виде. вводить одной строкой без пробелов
    {
        string g;

        string key;
        int i = 0;
        while (true)
        {
            cin >> g;
            cin >> key;
            if (key == "666")
            {
                for (int k = 0; k < g.length(); k++)
                {
                    for (int q = 0; q < 32; q++)
                    {
                        if (g[k] == alf[q])
                        {
                            cout << mas_alf[q] << "\t";
                        }
                    }
                }
                break;
            }
        }
        break;
    }
    case 4:                                                    //отображает биты в буквенном виде 6-и битовый вид
    {

        string* mas_bit = new string[255];
        string g;
        int i = 0;

        while (true)
        {
            cin >> g;
            if (g == "666")
            {
                for (int a = 0; a < i; a++)
                {
                    cout << alf[func1(mas_bit[a])];
                }
                break;
            }

            mas_bit[i] = g;
            i++;
        }
        delete[] mas_bit;
        break;
    }
    case 5:                                                            //Атбаш
    {

        int c;
        cout << "Введите фразу" << endl;
        string phrase = "";
        cin.ignore();
        getline(cin, phrase);

        phrase = func6(phrase);

        cout << "1-enc \t 2-dec \n";
        cin >> c;

        switch (c)
        {
        case 1:
        {
            string rez = "";
            for (int i = 0; i < phrase.length(); i++)
            {
                rez+= alf[(31 - func(phrase[i])) + 1];
            }
            cout <<rez<< "\n\n";
            break;
        }
        case 2:
        {
            string rez = "";
            for (int i = 0; i < phrase.length(); i++)
            {
                rez+= alf[(31 - func(phrase[i])) + 1];
            }
            cout <<func7(rez)<< "\n\n";
            break;
        }
        default:
            break;
        }
        break;
    }
    case 6:
    {
        int c;
        string phrase = "";
        cout << "Введите фразу" << endl;
        cin.ignore();
        getline(cin, phrase);
        phrase = func6(phrase);

        cout << "1-enc \t 2-dec \n";
        cin >> c;

        switch (c)
        {
        case 1:
        {
            for (int i = 0; i < phrase.length(); i++)
            {
                func3(phrase[i]);
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < phrase.length(); i++)
            {
                cout << "errrrrrrrrrrrrrrrrrrrrrrrror\n";
            }
            break;
        }
        default:
            break;
        }


        break;
    }
    case 7:
    {
        int c=0;
        int q = 0;
        string phrase = "";
        cout << "Введите фразу" << endl;
        cin.ignore();
        getline(cin, phrase);
        phrase = func6(phrase);

        cout << "1-enc \t 2-dec \n";
        cin >> c;
        cout << "Vvedite kluch\n";
        cin >> q;

        if (q > alf.length()) {
            cout << "Ключ вышел за пределы \n";
            break;
        }
        else if (q == 0) {
            cout << "Ключ равен нулю \n";
            break;
        }

        switch (c)
        {
        case 1:
        {
            string rez = "";
            for (int i = 0; i < phrase.length(); i++)
            {
                rez+= alf[((func4(phrase[i]) + q) % alf.length())];
            }
            cout << rez << "\n\n";
            break;
        }
        case 2:
        {
            string rez = "";
            for (int i = 0; i < phrase.length(); i++)
            {
                rez+= alf[((func4(phrase[i]) - q) % alf.length())];
            }
            cout << func7(rez) << "\n\n";
            break;
        }
        default:
            break;
        }
        break;
    }
    case 8:
    {
        int c = 0;
        string q = "";
        string phrase = "";
        cout << "Введите фразу" << endl;
        cin.ignore();

        getline(cin, phrase);
        phrase = func6(phrase);

        cout << "1-enc \t 2-dec \n";
        cin >> c;
        cout << "Vvedite kluch\n";
        cin >> q;
        
        switch (c)
        {
        case 1:
        {
            q += phrase;
            string rez = "";
            for (int i = 0; i < phrase.length(); i++)
            {
                rez+= alf[((func4(phrase[i]) + func4(q[i])) % alf.length())];
            }
            cout << rez << "\n\n";
   
            break;
        }
        case 2:
        {
           string rez = "";
            for (int i = 0; i < phrase.length(); i++)
            {
                rez+= alf[((func4(phrase[i]) - func4(q[i])) % alf.length())];  
                q += rez[i];
            } 
            cout << func7(rez) << "\n\n";
            break;
        }
        default:
            break;
        }
        break;
    }
    case 9:                                                                            
    {
        int c = 0;
        string q = "";
        string parol = "";
        string phrase = "";
        cout << "Введите фразу" << endl;
        cin.ignore();

        getline(cin, phrase);
        phrase = func6(phrase);

        cout << "1-enc \t 2-dec \n";
        cin >> c;
        cout << "Vvedite parol\n";
        cin >> q;

        for (; parol.length() < phrase.length();)
        {
            parol += q;
        }
        
        switch (c)
        {
        case 1:                                                                                  //enc  = alf [parol [key] + phrase [i]]  
        {            
            string rez = "";
            for (int i = 0; i < phrase.length(); i++)
            {
               rez+= alf[((func(parol[i]) + func(phrase[i]))-2) % alf.length()];
            }
            cout << rez<<"\n\n";

            break;
        }
        case 2:
        {
            string rez = "";
            for (int i = 0; i < phrase.length(); i++)
            {
                rez += alf[((func(parol[i]) - func(phrase[i]))) % alf.length()];
            }
            cout << rez << "\n\n";
            break;
        }
        default:
            break;
        }
        break;
    }
    case 10:
    {

        int c;
        string phrase = "";
        cout << "Введите фразу" << endl;
        cin.ignore();

        getline(cin, phrase);
        phrase = func6(phrase);

        cout << "1-enc \t 2-dec \n";
        cin >> c;

        switch (c)
        {
        case 1:
        {
            for (int i = 0; i < phrase.length(); i++)
            {
                cout << alf[mod(((func(phrase[i]) + i) - 1), 32)];
            }
            cout << "\n";
            break;
        }
        case 2:
        {            
           string rez = "";
            for (int i = 0; i < phrase.length(); i++)
            {
                rez+= alf[mod(((func(phrase[i]) - i)-1), 32)];
            }

            cout << func7(rez) << "\n\n";
            break;
        }
        default:
            break;
        }

        break;
    }
    case 11:
    {

        break;
    }
    case 12:                                                       //Виженер 2
    {

        break;
    }
    case 13:                                                       //Маршрутной перестановки
    {

        int c = 0;
        int q = 0;
        string phrase = "";
        cout << "Введите фразу" << endl;
        cin.ignore();

        getline(cin, phrase);
        phrase = func6(phrase);

        cout << "1-enc \t 2-dec \n";
        cin >> c;

        switch (c)
        {
        case 1:
        {
            int a = 0, b = 0;
            cout << "Введите длину решетки\n";   cin >> a;
            b = phrase.length() / a;
           
            if (phrase.length() % a != 0) {
                cout << "\n ERROR: \t Длина фразы не кратна кол-ву строк\n\n";
            }
            else{
                int phraseDlina = phrase.length() - 1;

                for (int i = 0; i < (phrase.length()/b); i++){
                    if (i%2 != 0) {
                        for (int k = 0; k < b; k++) {
                            cout << phrase[(((a-1)-i)+(a*k))];
                        }
                    }
                    else {
                        for (int k = 0; k < b; k++) {
                            cout << phrase[((phraseDlina - i) - (a*k))];
                        }  
                    }
                }
            }
            break;
        }
        case 2:
        {
            int a = 0, b = 0;
            cout << "Введите длину решетки\n";   cin >> a;
            b = phrase.length() / a;

            if (phrase.length() % a != 0) {
                cout << "\n ERROR: \t Длина фразы не кратна кол-ву строк\n\n";
            }
            else {
                int phraseDlina = phrase.length() - 1;

                for (int i = 0; i < (phrase.length() / b); i++) {
                    if (i % 2 != 0) {
                        for (int k = 0; k < b; k++) {
                            cout << phrase[(((a - 1) - i) + (a * k))];
                        }
                    }
                    else {
                        for (int k = 0; k < b; k++) {
                            cout << phrase[((phraseDlina - i) - (a * k))];
                        }
                    }
                }
            }
            break;
        }
        default:
            break;
        }
        break;
    }
    case 14:                                                       //Вертикальной перестановки
    {
        int c = 0;
        string phrase = "";
        string key = "";

        cout << "Введите фразу" << endl;
        cin.ignore();
        getline(cin, phrase);
        phrase = func6(phrase);

        cout << "Введите ключ\n";
        cin >> key;

        while (true) {
            if (phrase.length() % key.length())
                phrase += '0';
            else
                break;
        }
        

        cout << "1-enc \t 2-dec \n";
        cin >> c;

        switch (c)
        {
        case 1:
        {
            vector <int> intKey;

            for (int i = 0; i < key.length(); i++)  
                intKey.push_back(func(key[i]));

            string ciphertext = encryptVtransposition(phrase, intKey);
            cout << "\nCiphertext: " << ciphertext << endl;

            break;
        }
        case 2:
        { 
            string decryptedText = decryptVtransposition(phrase, key);
            decryptedText = func7(decryptedText);
 
            size_t pos;
            while ((pos = decryptedText.find('0')) != std::string::npos) {
                decryptedText.erase(pos, 1);
            }
            cout << "\nDecrypted text:  "<<decryptedText<<"\n";
            
            break; 
        }
        default:
            break;
        }

        break;
    }
    case 15:                                                       //Матричной перестановки
    {

        int c;
        string phrase = "";
        cout << "Введите фразу" << endl;
        cin.ignore();

        getline(cin, phrase);
        phrase = func6(phrase);
        if (phrase.length() % 3 != 0) {
            cout << "\nДлина фразы не кратна трем\nТеккущая длина = "<< phrase.length()<<"\n";
            break;
        }
        cout << "1-enc \t 2-dec \n";
        cin >> c;

        switch (c)
        {
        case 1:
        {
            matrix alfa(3, 3);
            matrix beta(3, 1);
            int size = phrase.length() / 3;
            cout << "size= "<<size;
            vector <int> masRez;
            int **bukvi = new int* [size];

            for (int k = 0; k < size; k++) {

                bukvi[k] = new int[3];
            }

            for (int count = 0; count < phrase.length();) {

                for (int row = 0; row < size; row++) {

                    for (int column = 0; column < 3; column++) {
                        bukvi[row][column] = func(phrase[count]);
                        count++;
                    }
                }
            }

            cout << "\nВведите матрицу-ключ\n";
            alfa.fini();
            matrix perem(3, 1);

            for (int i = 0; i < size; i++) {

                beta.fini(bukvi[i]);
                perem = alfa* beta;
                for (int i = 0; i < perem.size; i++) {
                    masRez.push_back(perem.mas[i]);
                }
            }

            for (int i = 0; i < masRez.size(); i++) {
                krasiviyvivod(i, 19);
                cout << masRez[i];
            }

            for (int count = 0; count < size; count++)
                delete[] bukvi[count];
            
            break;
        }
        case 2:
        {
            string rez = "";
            
            break;
        }
        default:
            break;
        }
        break;
    }
    case 16:                                                               //Pleyfer
    {
        int c;
        string phrase = "";
        string key = "";
        cout << "Введите фразу" << endl;
        cin.ignore();

        getline(cin, phrase);
        phrase = func6(phrase);

        cout << "Введите ключ без повторяющихся букв\n";
        cin >> key;
        cout << "1-enc \t 2-dec \n";
        cin >> c;

        switch (c)
        {
        case 1:
        { 
            string rez = "";
            string forTable = func8(key, alf);
            cout << "KEY= " << key<<"\n";
            vector <vector<char>> table(5, vector<char>(6));

            for (int i = 0, j=0; i < 5; i++) {
                for (int k = 0; k < 6; k++) {
                    table[i][k] = forTable[j];
                    j++;
                } 
            }

            for (int i = 0; i < phrase.length(); i += 2) {
                        char a = phrase[i];
                        char b = phrase[i + 1];
                        int row1=0, col1=0, row2=0, col2=0;
                       
                        for (int r = 0; r < 5; ++r) {                     // координаты символов
                            for (int c = 0; c < 6; ++c) {
                                if (table[r][c] == a) {
                                    row1 = r;
                                    col1 = c;
                                }
                                if (table[r][c] == b) {
                                    row2 = r;
                                    col2 = c;
                                }
                            }
                        }
                                                                         //for replace pare
                        if (row1 == row2) {
                            rez += table[row1][(col1 + 1) % 6];
                            rez += table[row2][(col2 + 1) % 6];
                        }
                        
                        else if (col1 == col2) {
                            rez += table[(row1 + 1) % 5][col1];
                            rez += table[(row2 + 1) % 5][col2];
                        }
                       
                        else {
                            rez += table[row1][col2];
                            rez += table[row2][col1];
                        }
            }

            cout << "Шифртекст:\t" << rez << "\n\n";

            break;
        }
        case 2:
        {
            string rez = decryptPlayfair(phrase, key);


            cout << func7(rez) << "\n\n";
            break;
        }
        default:
            break;
        }
        break;

    }
    case 17:
    { 
        break;
    }
    case 18:                                                              //блокнот Шеннона-шифровка
    {
        int kl = 0;
        cout << "vvedite variant: \n 1--шифровка \n 2--расшифровка" << endl;
        cin >> kl;

        switch (kl)
        {
        case 1:
        {
            string phrase = "";
            cout << "Введите фразу" << endl;
            cin.ignore();

            getline(cin, phrase);
            phrase = func6(phrase);

            int a;
            int c;
            unsigned long long t;
            cout << "Введите коэффициенты: a, c, t\nУсловия:\n   c - нечетное число\n   a mod 4 = 1 и а<32 и >1" << endl;

            cin >> a >> c >> t;

            if (c % 2 == 0 || a % 4 != 1 || a==1 || c==0 || c<32 || a<32 || t<32 || t==0) {
                cout << "\t\tОбратите внимание на условия коэффициентов\n\n";
                break;
            }

            int d;
            for (int i = 0; i < phrase.length(); i++)
            {
                t = (a * t + c) % 32;

                d = ((t + func(phrase[i])) % 32) - 1;

                d != -1 ? cout << alf[d] : cout << alf[d + 1];
            }

            break;
        }

        case 2:
        {
            string phrase = "";
            cout << "Введите фразу" << endl;
            cin.ignore();

            getline(cin, phrase);
            phrase = func6(phrase);

            int a;
            int c;
            unsigned long long t;
            cout << "Введите коэффициенты: a, c, t" << endl;
            cin >> a >> c >> t;
            int d;
            int k;
            int f;            
            string rez = "";
            for (int i = 0; i < phrase.length(); i++)
            {

                k = func(phrase[i]);

                t = (a * t + c) % 32;

                d = (k - t) - 1;

                if (k == 1 && d < 0) d += 31;

                if (d < 0) d += 32;

                rez+= alf[d];
            }

            cout << func7(rez) << "\n\n";
            break;
        }

        default:
            break;
        }
        break;
    }
    case 19:                                                              //проверить название
    {
        int kl = 0;
        cout << " case 19 vvedite variant: \n 1--шифровка \n 2--расшифровка" << endl;
        cin >> kl;
        switch (kl)
        {
        case 1:
        {
            string phrase = "";
            cout << "Введите фразу" << endl;
            cin.ignore();

            getline(cin, phrase);
            phrase = func6(phrase);

            int a = 0;
            int n = 0;
            cout << "Введите E: " << endl;
            cin >> a;
            cout << "Введите N: " << endl;
            cin >> n;
            int rez = 0;

            for (int k = 0; k < phrase.length(); k++)
            {
                rez = func(phrase[k]);
                for (int i = 0; i < a - 1; i++)
                {
                    rez = (rez * func(phrase[k])) % n;
                    if (rez == 0) rez = n;
                }
                cout << rez << " ";
            }

            break;
        }
        case 2:
        {
            int a = 0;
            int n = 0;
            cout << "Введите D: " << endl;
            cin >> a;
            cout << "Введите N: " << endl;
            cin >> n;
            int rez = 0;
            cout << "Введите шифровку" << endl;

            string* phrase = new string[255];
            string g;
            int ind = 0;

            while (true)
            {
                cin >> g;
                if (g == "стоп")
                {
                    for (int k = 0; k < ind; k++)
                    {
                        rez = atoi(phrase[k].c_str());
                        for (int i = 0; i < a - 1; i++)
                        {
                            rez = (rez * atoi(phrase[k].c_str())) % n;
                            if (rez == 0) rez = n;
                        }
                        cout << rez << "\t";
                    }
                    break;
                }

                phrase[ind] = g;
                ind++;
            }
            delete[] phrase;

            break;
        }
        default:
            break;
        }
        break;
    }
    case 20:                                                              //Elgamal
    {
        string phrase = "";
        cout << "Введите фразу" << endl;
        cin.ignore();

        getline(cin, phrase);
        phrase = func6(phrase);

        int a = 0;
        int b = 0;
        int p = 0;
        int x = 0;
        int g = 0;
        int y = 0;
        int k = 0;
        int k1 = 0;
        int k2 = 0;
        int k3 = 0;

        cin >> p >> x >> g >> y >> k1 >> k2 >> k3;
        for (int i = 0; i < phrase.length(); i++)
        {
            k = func2(k1, k2, k3);
            a = int(pow(g, k)) % p;
            if (!a) a = p;
            b = int(pow(y, k)) * func(phrase[i]) % p;
            if (!b) b = p;
            krasiviyvivod(i, 5);
            cout << "k= " << k << " C= " << a << b;

        }
        break;
    }
    case 21:                                                             //hash_code
    {
        string phrase = "";
        cout << "Введите фразу" << endl;
        cin.ignore();

        getline(cin, phrase);
        phrase = func6(phrase);

        int h = 0;
        int hh = 0;

        for (int i = 0; i < phrase.length(); i++)
        {
            hh = (h + func(phrase[i]));
            h = int(pow(hh, 2)) % 11;
            if (!h) h = 11;
            cout << "hash_code =" << h << endl;
        }
    }
    case 22:                                                             //заьыл
    {
        string phrase = "";
        cout << "Введите фразу" << endl;
        cin >> phrase;
        map <char, int> Lis;
        for (int i = 0; i < alf.length(); i++)
        {
            Lis.emplace(alf[i], 0);
        }

        for (int i = 0; i < phrase.length(); i++)
        {
            auto it = Lis.find(phrase[i]);
            if (it != Lis.end())
            {
                // Lis[phrase[i]] = Lis.;
            }
        }

        break;
    }
    case 23:                                                              //забыл
    {
        
        
    }
    case 24: {

        std::string plaintextHex = "";                                      //   00112233445566778899aabbccddeeff
        std::string keyHex = "";                                               //   000102030405060708090a0b0c0d0e0f

        if ((plaintextHex.length() && keyHex.length()) == 0)
        {
            cout << "Введите текст в шестнадцатеричном формате\n";
            cin >> plaintextHex;
            cout << "\nВведите ключь в шестнадцатеричном формате\n";
            cin >> keyHex;
        }


        unsigned char plaintext[AES_BLOCK_SIZE];
        unsigned char key[AES_BLOCK_SIZE];

        hexStringToBytes(plaintextHex, plaintext);
        hexStringToBytes(keyHex, key);

        // Шифрование
        EVP_CIPHER_CTX* encryptCtx = EVP_CIPHER_CTX_new();
        if (!encryptCtx) {
            std::cerr << "Ошибка создания контекста шифрования." << std::endl;
            return 1;
        }

        if (EVP_EncryptInit_ex(encryptCtx, EVP_aes_128_ecb(), nullptr, key, nullptr) != 1) {
            std::cerr << "Ошибка инициализации шифрования." << std::endl;
            EVP_CIPHER_CTX_free(encryptCtx);
            return 1;
        }

        int outLen;

        unsigned char* ciphertext = new unsigned char[AES_BLOCK_SIZE + EVP_CIPHER_CTX_block_size(encryptCtx)];

        if (EVP_EncryptUpdate(encryptCtx, ciphertext, &outLen, plaintext, AES_BLOCK_SIZE) != 1) {
            std::cerr << "Ошибка шифрования." << std::endl;
            EVP_CIPHER_CTX_free(encryptCtx);
            return 1;
        }

        int finalLen;

        if (EVP_EncryptFinal_ex(encryptCtx, ciphertext + outLen, &finalLen) != 1) {
            std::cerr << "Ошибка завершения шифрования." << std::endl;
            EVP_CIPHER_CTX_free(encryptCtx);
            return 1;
        }


        outLen += finalLen;

        std::cout << "Зашифрованный текст: " << bytesToHexString(ciphertext, finalLen) << std::endl;

        EVP_CIPHER_CTX_free(encryptCtx);

        // Расшифрование
        EVP_CIPHER_CTX* decryptCtx = EVP_CIPHER_CTX_new();
        if (!decryptCtx) {
            std::cerr << "Ошибка создания контекста расшифрования." << std::endl;
            return 1;
        }

        if (EVP_DecryptInit_ex(decryptCtx, EVP_aes_128_ecb(), nullptr, key, nullptr) != 1) {
            std::cerr << "Ошибка инициализации расшифрования." << std::endl;
            EVP_CIPHER_CTX_free(decryptCtx);
            return 1;
        }

        unsigned char* decryptedtext = new unsigned char[AES_BLOCK_SIZE];

        if (EVP_DecryptUpdate(decryptCtx, decryptedtext, &outLen, ciphertext, outLen) != 1) {
            std::cerr << "Ошибка расшифрования." << std::endl;
            EVP_CIPHER_CTX_free(decryptCtx);
            return 1;
        }

        if (EVP_DecryptFinal_ex(decryptCtx, decryptedtext + outLen, &finalLen) != 1) {
            std::cerr << "Ошибка завершения расшифрования." << std::endl;
            EVP_CIPHER_CTX_free(decryptCtx);
            return 1;
        }

        outLen += finalLen;

        std::cout << "Расшифрованный текст: " << bytesToHexString(decryptedtext, outLen) << std::endl;

        EVP_CIPHER_CTX_free(decryptCtx);

        delete[] ciphertext;
        delete[] decryptedtext;
    }
    default:
        break;
    }
}



string encryptVtransposition(const string& plaintext, const vector<int>& key) { 
    string ciphertext = "";
    int numRows = plaintext.length() / key.size();

    multimap <int, string> mapMas;

    vector<vector<char>> matrix(numRows, vector<char>(key.size()));

    for (int i = 0, j = 0; i < numRows; i++) {
        for (int k = 0; k < key.size(); k++) {
            matrix[i][k] = plaintext[j];
            j++;
        }
    }

    for (int i = 0; i < key.size(); i++) {
        mapMas.insert({ key[i], func9(matrix, i, numRows)});
    }

    for (const auto& pairr : mapMas) {
        ciphertext+= pairr.second;
    }

    return ciphertext;
}


string decryptVtransposition(const string& ciphertext, const string& key) {
    string plaintext="";
    string newKey = key;
    int numRows = ciphertext.length() / key.length();

    multimap <char, string> mapMas;
    unordered_multimap <int, string> masMap;
    vector<string> phrase_piace; 
    vector<vector<char>> matrix(numRows, vector<char>(key.length()));

    for (int i = 0; i < ciphertext.length(); i+=numRows) {
        phrase_piace.push_back(ciphertext.substr(i, numRows));
    }

    sort(newKey.begin(), newKey.end());


    for (int i = 0; i < key.length(); i++) {
        mapMas.insert({newKey[i], phrase_piace[i]});
    }

        for (int i = 0; i < key.length(); i++) {
            auto it = mapMas.find(key[i]);
            masMap.insert({ i, it->second });
            mapMas.erase(it);
        }

    for (auto it = masMap.begin(); it != masMap.end() ;)
    {
        for (int i = 0; i < key.size(); i++, it++) {
            for (int k = 0; k < numRows; k++) {
                matrix[k][i] = it->second[k];

            }
        }
    }

    for (int i = 0; i < numRows; i++) {
        cout << "\n";
        for (int k = 0; k < key.size(); k++) {
            cout << matrix[i][k] << " ";
            plaintext += matrix[i][k];
        }
        
    }
   
    return plaintext;
}

std::string decryptPlayfair(const std::string& ciphertext,  std::string& key) {
    std::vector<std::vector<char>> table(5, std::vector<char>(6));
    std::string decryptedText = "";
    string forTable = func8(key, alf);

            for (int i = 0, j=0; i < 5; i++) {
                for (int k = 0; k < 6; k++) {
                    table[i][k] = forTable[j];
                    j++;
                }
            }

            cout << "table+++++++\n\n";

            for (int i = 0, j = 0; i < 5; i++) {
                for (int k = 0; k < 6; k++) {
                    cout<<table[i][k]<<" ";
                    j++;
                }
                cout << "\n";
            }
            cout << "\n\n";

    for (int i = 0; i < ciphertext.length(); i += 2) {
        char a = ciphertext[i];
        char b = ciphertext[i + 1];
        int row1 = 0, col1 = 0, row2 = 0, col2 = 0;

        for (int r = 0; r < 5; ++r) {
            for (int c = 0; c < 6; ++c) {
                if (table[r][c] == a) {
                    row1 = r;
                    col1 = c;
                }
                if (table[r][c] == b) {
                    row2 = r;
                    col2 = c;
                }
            }
        }

        if (row1 == row2) {
            decryptedText += table[row1][(col1 + 5) % 6]; 
            decryptedText += table[row2][(col2 + 5) % 6];
        }
        else if (col1 == col2) {
            decryptedText += table[(row1 + 4) % 5][col1]; 
            decryptedText += table[(row2 + 4) % 5][col2];
        }
        else {
            decryptedText += table[row1][col2];
            decryptedText += table[row2][col1];
        }
    }

    return decryptedText;
}





