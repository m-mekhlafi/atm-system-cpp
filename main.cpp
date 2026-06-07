#include <iostream>
#include <string>
using namespace std;

struct Language {
    string header, askAccount, loginHint, registerHint, wrongInput, createAcc, dep, with, show, exit, error, bala, success, namePrompt, pinPrompt;
};

Language En = { "AL-MEKHLAFI ATM", "Do you have an account?", "9: Login", "8: Register", "Wrong Input!", "Create Account", " Deposit ", " Withdraw ", "Show Account", "Logout", "Error!", "Balance: ", "Success!", "Name: ", "PIN: " };
Language Ar = { "صراف المخلافي الآلي", "هل لديك حساب؟", "9: دخول", "8: تسجيل", "إدخال خاطئ!", "إنشاء حساب", " إيداع ", " سحب ", "عرض الحساب", "خروج", "خطأ!", "رصيدك: ", "تمت العملية!", "الاسم: ", "الرمز: " };
Language cur;

string Names[10];
int Pins[10];
int userCount = 0;
double Balances[10];

void CreateAccount();
void Deposit(int userID);
int Login();
void Withdraw(int userID);
void ShowAccount(int userID);

int main() {
    int langChoice;
    cout << "1- English | 2- العربية: ";
    cin >> langChoice;
    cin.ignore();
    cur = (langChoice == 2) ? Ar : En; // this is the most important things onit
    //if the choice was 2 it will get to Arabic if it's not it well chose else

    while (true) { // A loop that cuz infinity uintel the 0
        int currentID = -1;
        int action;

        cout << "\n ~~~~~~~~~~ " << cur.header << " ~~~~~~~~~~ " << endl;
        cout << cur.askAccount << "\n" << cur.loginHint << " | " << cur.registerHint << " | 0: Shutdown" << endl;
        cin >> action;
        cin.ignore();

        if (action == 0) break; // when you press the zero it show

        if (action == 9) {
            currentID = Login();
        } else if (action == 8) {
            CreateAccount();
            continue;
        } else {
            cout << cur.wrongInput << endl;
            continue;
        }

        if (currentID != -1) {
            char choice;
            bool loggedIn = true;
            while (loggedIn) {
                cout << "\n ~~~~~~~~~~ " << cur.header << " ~~~~~~~~~~ " << endl;
                cout << "1- " << cur.dep << " 2- " << cur.with << " 3- " << cur.show << " 4- " << cur.exit << endl;
                cout << "> ";
                cin >> choice;
                cin.ignore();

                switch (choice) {
                    case '1': Deposit(currentID); break;
                    case '2': Withdraw(currentID); break;
                    case '3': ShowAccount(currentID); break;
                    case '4': loggedIn = false; break;
                    default: cout << cur.wrongInput << endl;
                }
            }
        }
    }
    return 0;
}

void CreateAccount() {

    if (userCount >= 10) {
        cout << cur.error << " System full! (Max 10 users)" << endl;
        return;
    }

    cout << "\n --- " << cur.createAcc << " ---" << endl;
    cout << cur.namePrompt;
    getline(cin, Names[userCount]);

    int p1, p2;
    do {
        cout << cur.pinPrompt;
        cin >> p1;
        cin.ignore();
        cout << cur.pinPrompt << " (Confirm): ";
        cin >> p2;
        cin.ignore();
        if (p1 != p2) cout << cur.error << " PIN mismatch!" << endl;
    } while (p1 != p2);

    Pins[userCount] = p1;
    Balances[userCount] = 0;
    userCount++;
    cout << cur.success << endl;
}

void Deposit(int userID) {
    double Amount;
    cout << "\n" << cur.dep << ": ";
    cin >> Amount;
    cin.ignore();
    if (Amount > 0) {
        Balances[userID] += Amount;
        cout << cur.success << " New " << cur.bala << Balances[userID] << endl;
    } else {
        cout << cur.error << " Invalid Amount!" << endl;
    }
}

int Login() {
    string name1;
    int pass1;
    cout << "\n --- Login ---" << endl;
    cout << cur.namePrompt;
    getline(cin, name1);
    cout << cur.pinPrompt;
    cin >> pass1;
    cin.ignore();

    for (int i = 0; i < userCount; i++) {
        if (name1 == Names[i] && pass1 == Pins[i]) {
            cout << cur.success << " Welcome Back, " << name1 << endl;
            return i;
        }
    }
    cout << cur.error << " Invalid Name or PIN!" << endl;
    return -1;
}

void Withdraw(int userID) {
    double amount;
    cout << "\n" << cur.with << ": ";
    cin >> amount;
    cin.ignore();

    if (amount > 0 && amount <= Balances[userID]) {
        Balances[userID] -= amount;
        cout << cur.success << " Take your cash. " << cur.bala << Balances[userID] << endl;
    } else {
        cout << cur.error << " Insufficient balance or invalid amount!" << endl;
    }
}

void ShowAccount(int userID) {
    cout << "\n --- " << cur.show << " ---" << endl;
    cout << "Name: " << Names[userID] << "\nID: " << userID << "\n" << cur.bala << Balances[userID] << " $" << endl;
}
