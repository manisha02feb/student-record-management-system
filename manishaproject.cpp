#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
struct addr
{
    int houseno;
    char street[20];
    char city[20];
    char state[20];
    char country[20];
};
struct student
{
    int rollnumber;
    char studentname[50];
    char Fathersname[50];
    char Mothersname[50];
    int Class;
    int semester;
    char branch[50];
    addr address;
};
student fun()
{
    student s;
    cout << "enter your rollnumber" << endl;
    cin >> s.rollnumber;
    cout << "enter your name" << endl;
    cin.ignore();
    cin.getline(s.studentname, 50);
    cout << "enter your father name" << endl;
    cin.getline(s.Fathersname, 50);
    cout << "enter your mother name" << endl;
    cin.getline(s.Mothersname, 50);
    cout << "enter your class" << endl;
    cin.ignore();
    cin >> s.Class;
    cout << "enter your semester" << endl;
    cin >> s.semester;
    cout << "enter your branch" << endl;
    cin >> s.branch;
    cout << "enter your house number" << endl;
    cin >> s.address.houseno;
    cout << "enter your street name" << endl;
    cin.ignore();
    cin.getline(s.address.street, 30);
    cout << "enter your city" << endl;
    cin >> s.address.city;
    cout << "enter your state name" << endl;
    cin >> s.address.state;
    cout << "enter your country name" << endl;
    cin >> s.address.country;
    cout << "___________________________________________" << endl;
    fstream file("data.txt", ios::app);
    file.write((char *)&s, sizeof(s));
    file.close();
}
student fun1()
{
    student s;
    fstream file("data.txt");
    file.read((char *)&s, sizeof(s));
    file.close();
    cout << "rollnumber:" << s.rollnumber << endl;
    cout << "name:" << s.studentname << endl;
    cout << "fathers name:" << s.Fathersname << endl;
    cout << "mothers name:" << s.Mothersname << endl;
    cout << "Class:" << s.Class << endl;
    cout << "semester:" << s.semester << endl;
    cout << "branch:" << s.branch << endl;
    cout << "house number:" << s.address.houseno << endl;
    cout << "street :" << s.address.street << endl;
    cout << "city:" << s.address.city << endl;
    cout << "state:" << s.address.state << endl;
    cout << "country:" << s.address.country << endl;
}

student fun2()
{
    cout << "enter 1 if you want to display students of particular city" << endl;
    cout << "enter 2 if you want to display students of particular state" << endl;
    cout << "enter 3 if you want to display students of particular country" << endl;

    int option;
    cin >> option;

    if (option == 1)
    {
        cout << "enter the name of city" << endl;
        char city[20];
        cin.ignore();
        cin.getline(city, 20);
        int n;

        student s;

        fstream file("data.txt");
        file.seekg(0, ios::end);
        n = file.tellg() / sizeof(s);
        file.seekg(0, ios ::beg);

        for (int i = 0; i < n; i++)
        {
            file.read((char *)&s, sizeof(s));
            if (strcmp(city, s.address.city) == 0)
            {
                cout << s.studentname << endl;
                cout << s.Fathersname << endl;
                cout << s.address.country << endl;
            }
        }
        file.close();
    }
    else if (option == 2)
    {
        cout << "enter the name of state" << endl;
        char state[20];
        cin.ignore();
        cin.getline(state, 20);
        int n;

        student s;

        fstream file("data.txt");
        file.seekg(0, ios::end);
        n = file.tellg() / sizeof(s);
        file.seekg(0, ios ::beg);

        for (int i = 0; i < n; i++)
        {
            file.read((char *)&s, sizeof(s));
            if (strcmp(state, s.address.state) == 0)
            {
                cout << s.studentname << endl
                     << s.Fathersname << endl
                     << s.address.country << endl;
            }
        }
        file.close();
    }
    else if (option == 3)
    {
        cout << "enter the name of the country" << endl;
        char country[20];
        cin.ignore();
        cin.getline(country, 20);
        int n;

        student s;

        fstream file("data.txt");
        file.seekg(0, ios::end);
        n = file.tellg() / sizeof(s);
        file.seekg(0, ios ::beg);

        for (int i = 0; i < n; i++)
        {
            file.read((char *)&s, sizeof(s));
            if (strcmp(country, s.address.country) == 0)
            {
                cout << s.studentname << endl
                     << s.Fathersname << endl
                     << s.address.country << endl;
            }
        }
        file.close();
    }
}

void fun3()
{
    int r_num;
    cin.ignore();
    cin >> r_num;
    int n;

    student s;

    fstream file("data.txt");
    file.seekg(0, ios::end);
    n = file.tellg() / sizeof(s);
    file.seekg(0, ios ::beg);

    for (int i = 0; i < n; i++)
    {
        file.read((char *)&s, sizeof(s));
        if (r_num == s.rollnumber)
        {
            continue;
        }
        fstream temp("temp.txt", ios::app);
        temp.write((char *)&s, sizeof(s));
        temp.close();
    }
    file.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}

int main()
{
start:
student fun();
student fun1();
student fun2();
void fun3();
cout << "enter 1 if you want to add student data " << endl;
cout << "enter 2 if you want to display student data" << endl;
cout << "enter 3 if you want to search student data" << endl;
cout << "enter 4 if you want to delete student data" << endl;
int k;
cin >> k;
if (k == 1)
{
fun();
}
else if (k == 2)
{
fun1();
}
else if (k == 3)
{
fun2();
}
else if (k == 4)
{
fun3();
}
else
{
cout << "enter any valid option";
}
goto start;
return 0 ;
}