#include <bits/stdc++.h>
using namespace std;
string gov[30];
void GEVORNRATE(){
    gov[1]  = "Cairo";
    gov[2]  = "Alexandria";
    gov[3]  = "Port Said";
    gov[4]  = "Suez";
    gov[11] = "Damietta";
    gov[12] = "Dakahlia";
    gov[13] = "Sharqia";
    gov[14] = "Qalyubia";
    gov[15] = "Kafr El-Sheikh";
    gov[16] = "Gharbia";
    gov[17] = "Monufia";
    gov[18] = "Beheira";
    gov[19] = "Ismailia";
    gov[21] = "Giza";
    gov[22] = "Beni Suef";
    gov[23] = "Fayoum";
    gov[24] = "Minya";
    gov[25] = "Assiut";
    gov[26] = "Sohag";
    gov[27] = "Qena";
    gov[28] = "Aswan";
    gov[29] = "Luxor";
}
string getGovernorate(int code) {
    return gov[code];
}
bool allDigits(string id) {
    for (int i = 0; i < id.size(); i++) {
        if (!isdigit(id[i])) {
            return false;
        }
    }
    return true;
}
void NATIONALID(string id) {
    int year;
    if (id[0] == '3')
        year = 2000 + (id[1]-'0')*10 + (id[2]-'0');
    else if (id[0] == '2')
        year = 1900 + (id[1]-'0')*10 + (id[2]-'0');
    else {
        cout << "Status : Invalid\n";
        return;
    }

int month = (id[3]-'0')*10 + (id[4]-'0');
int day   = (id[5]-'0')*10 + (id[6]-'0');
int age = 2026 - year;
int code = (id[7]-'0')*10 + (id[8]-'0');
string gender;
if ( (id[13] - '0') % 2 == 0 ) {
    gender = "Female";
}
else {
    gender = "Male";
}
    cout << "=============================\n";
    cout << "National ID Analysis\n";
    cout << "=============================\n";

    cout << "Birth Date : " << year << " / " << month << " / " << day << endl;
    cout << "Age        : " << age << endl;
    cout << "Gender     : " << gender << endl;
    cout << "Status     : Valid" << endl;
    cout << "Gevornrate : " << getGovernorate(code); 
    cout << "=============================\n";
}

int main() {
    string id;
while (true) 
{
cout << "Enter National ID (14 digits): ";
cin >> id;
if (id.length() == 14 && allDigits(id))
{
     break;
}
NATIONALID(id);
}
}