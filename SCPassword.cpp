#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

int main()
{
    int N = 20;
    char str[]{ "_0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+,-./|\\\"':;<=>?@[]^`{}~" };
    int strN = 94; // индекс последнего элемента в массиве
    char st[256];
    cout << "Come up with unusual word: "; cin >> st;
    int sum = 0;
    int len = strlen(st);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < strN; j++)
        {
            sum += ((i % 5) + 1);
            if (str[j] == st[i])
                break;
        }
    }
    const int m = (sum << 1) + 18, //при малом модуле повторений будет много, поэтому применим побитовый сдвиг
        a = ((sum + 1) / 2) * 3, // множетели (выбирается случайно 0 <= a,b <= m)
        b = (a * 123) % m;
    int lgc[20];
    lgc[0] = sum;
    for (int i = 1; i < 20; i++)
        lgc[i] = (lgc[i - 1] * a + b) % m;

    char* pass = new char[N + 1]; //выделяем память для строки пароля
    for (int i = 0; i < N; i++)
    {
        pass[i] = str[lgc[i] % strN]; //вставляем случайный символ
    }
    pass[N] = 0; //записываем в конец строки признак конца строки
    cout << "Sir, Your password: " << pass; //выводим пароль на экран
    getch();
    return 0;
}




