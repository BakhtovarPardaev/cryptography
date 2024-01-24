
#include <iostream>
#include <cstring>
#include <math.h>
#include <ctime>
#include <map>

using namespace std;

string alf = "абвгдежзийклмнопрстуфхцчшщъыьэюя";              //алфавит 

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

void krasiviyvivod(int i)
{
    if (i % 5 == 0) cout << "\n";
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


int main()
{
    srand(time(NULL));
    system("chcp 1251");
    //setlocale(LC_ALL, "Russian");
    string word2 = "ктобоитсякаждогокустазптникогданедолженходитьналовлюптицтчк";
  
    int c = 0;

    cout << endl << "vvedite variant: \n1-вывести индексы букв \n2-вывести буквы по их индексу \n3-отобразить букы в побитовом виде \n4-отобразить биты в буквенном виде \n5-Атбаш \n6-Полибия \n7-Цезарь \n8-Виженера \n9-Белазо \n10-Тритемия \n11-Кардано \n12-Виженера 2 \n13-Маршрутной перестановки \n14-Вертикальной перестановки \n15-Матричный \n16-Плейфера \n17-Битовый \n 18-блокнот Шеннона \n 19-RSA(вроде) \n 20-Elgamal" << endl;
    cin >> c;

    switch (c)
    {
    case 1:                                                  //выводит индексы букв фразы
    {
        string phrase = "";
        cout << "Введите фразу" << endl;
        cin >> phrase;

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
    case 5:
    {
        int c;
        string phrase = "";
        cout << "Введите фразу" << endl;
        cin >> phrase;

        cout << "1-enc \t 2-dec \n";
        cin >> c;

        switch (c)
        {
        case 1:
        {
            for (int i = 0; i < phrase.length(); i++)
            {
                cout << alf[(31 - func(phrase[i])) + 1];
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < phrase.length(); i++)
            {
                cout << alf[(31 - func(phrase[i])) + 1];
            }
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
        cin >> phrase;

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
        cin >> phrase;

        cout << "1-enc \t 2-dec \n";
        cin >> c;
        cout << "Vvedite kluch\n";
        cin >> q;

        switch (c)
        {
        case 1:
        {
            for (int i = 0; i < phrase.length(); i++)
            {
                cout << alf[((func4(phrase[i]) + q) % alf.length())];
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < phrase.length(); i++)
            {
                cout << alf[((func4(phrase[i]) - q) % alf.length())];
            }
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
        cin >> phrase;

        cout << "1-enc \t 2-dec \n";
        cin >> c;
        cout << "Vvedite kluch\n";
        cin >> q;
      
        switch (c)
        {
        case 1:
        {
            for (int i = 0; i < phrase.length(); i++)
            {
                cout << alf[((func4(phrase[i]) + func(q[i])) % alf.length())];
            }
            
            break;
        }
        case 2:
        {
            for (int i = 0; i < phrase.length(); i++)
            {
                cout << alf[((func4(phrase[i]) - func(q[i])) % alf.length())];                    /////исправить
            }
            
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
        cin >> phrase;

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
            for (int i = 0; i < phrase.length(); i++)
            {
               cout<<alf[((func(parol[i]) + func(phrase[i]))-2) % alf.length()];
            }
            cout << "\n";

            break;
        }
        case 2:
        {
            
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
        cin >> phrase;

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
            for (int i = 0; i < phrase.length(); i++)
            {
                cout << alf[mod(((func(phrase[i]) - i)-1), 32)];
            }
            cout << "\n";

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
    case 12:
    {
        break;
    }
    case 13:
    {
        break;
    }
    case 14:
    {
        break;
    }
    case 15:
    {
        break;
    }
    case 16:
    {
        break;
    }
    case 17:
    {
        break;
    }
    case 18:                                                              //блокнот Шеннона-шифровка
    {
        int kl = 0;
        cout << " case 18 vvedite variant: \n 1--шифровка \n 2--расшифровка" << endl;
        cin >> kl;

        switch (kl)
        {
        case 1:
        {
            string phrase = "";
            cout << "Введите фразу" << endl;
            cin >> phrase;

            int a;
            int c;
            unsigned long long t;
            cout << "Введите коэффициенты: a, c, t" << endl;
            cin >> a >> c >> t;
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
            cin >> phrase;

            int a;
            int c;
            unsigned long long t;
            cout << "Введите коэффициенты: a, c, t" << endl;
            cin >> a >> c >> t;
            int d;
            int k;
            int f;
            for (int i = 0; i < phrase.length(); i++)
            {

                k = func(phrase[i]);

                t = (a * t + c) % 32;

                d = (k - t) - 1;

                if (k == 1 && d < 0) d += 31;

                if (d < 0) d += 32;

                cout << alf[d];
            }
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
            cin >> phrase;
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
        cin >> phrase;
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
            krasiviyvivod(i);
            cout << "k= " << k << " C= " << a << b;

        }
        break;
    }
    case 21:                                                             //hash_code
    {
        string phrase = "";
        cout << "Введите фразу" << endl;
        cin >> phrase;
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
        int** mas = new int* [60];
        for (int i = 0; i < 60; i++)
        {
            mas[i] = new int[60];
            for (int k = 0; k < 60; k++)
            {
                for (int q = 0; q < 60; q++)
                {
                    mas[k][q] = 0;
                }
            }
        }

        for (int ii = 0; ii < 60; ii++)
        {
            for (int kk = 0; kk < 60; kk++)
            {

                cin >> mas[ii][kk];
            }
        }



        for (int g = 0; g < 60; g++)
        {
            delete[] mas[g];
        }

        break;
    }
    default:
        break;
    }
}
