#include <iostream>
#include <cctype>
#include <string>

using namespace std;

class Diabetes
{
private:
    string name;
    float age;
    int weight;
    float height;
    char sex;
    string symptoms[10];

public:
    void welcomeScreen();
    void getValue();
    void getLevel1Symptoms();
    void getLevel2Symptoms();
    void getLevel3Symptoms();
    int analyseSymptoms(int level);
    char displayMessage(int level, int result);
};

void Diabetes::welcomeScreen()
{
    cout << "********* WELCOME *********\n";
    cout << " M E D I C A L   D I A G N O S I S   S O F T W A R E\n";
    cout << "DONE BY: Kashish Sharma\n";
    cout << "\nPress Enter to continue...";
    cin.ignore();
}

void Diabetes::getValue()
{
    cout << "\nPERSONAL INFORMATION\n";
    cout << "----------------------\n";
    cout << "NAME: ";
    getline(cin, name);
    cout << "AGE: ";
    cin >> age;
    cout << "WEIGHT (kg): ";
    cin >> weight;
    cout << "HEIGHT (cm): ";
    cin >> height;
    cout << "SEX (M/F): ";
    cin >> sex;
    cin.ignore(); // Ignore remaining newline character
}

void Diabetes::getLevel1Symptoms()
{
    cout << "\nLEVEL 1 SYMPTOMS\n";
    cout << "----------------\n";
    cout << "1. APPETITE (H/L/N): ";
    cin >> symptoms[0];
    cout << "2. FREQUENCY OF THIRST (H/L/N): ";
    cin >> symptoms[1];
    cout << "3. FREQUENCY OF URINATION (H/L/N): ";
    cin >> symptoms[2];
    cout << "4. VISION (I/N): ";
    cin >> symptoms[3];
    cout << "5. URINE SUGAR (P/A): ";
    cin >> symptoms[4];
    cout << "6. KETONUREA (P/A): ";
    cin >> symptoms[5];
    cout << "7. FASTING BLOOD SUGAR (H/L/N): ";
    cin >> symptoms[6];
    cout << "8. RBS (H/L/N): ";
    cin >> symptoms[7];
    cout << "9. FAMILY HISTORY OF DIABETES (P/A): ";
    cin >> symptoms[8];
    cout << "10. OGTT (D/N): ";
    cin >> symptoms[9];
}

void Diabetes::getLevel2Symptoms()
{
    cout << "\nLEVEL 2 SYMPTOMS\n";
    cout << "----------------\n";
    cout << "1. PANCREATITIS (P/A): ";
    cin >> symptoms[0];
    cout << "2. CARCINOMA (P/A): ";
    cin >> symptoms[1];
    cout << "3. CIRRHOSIS (P/A): ";
    cin >> symptoms[2];
    cout << "4. HCTS (H/L/N): ";
    cin >> symptoms[3];
    cout << "5. HEPATITIS (P/A): ";
    cin >> symptoms[4];
    cout << "6. HORMONAL DISORDER (P/A): ";
    cin >> symptoms[5];
    cout << "7. PANCREATECTOMY (P/A): ";
    cin >> symptoms[6];
}

void Diabetes::getLevel3Symptoms()
{
    cout << "\nLEVEL 3 SYMPTOMS\n";
    cout << "----------------\n";
    cout << "1. AGE (Y/M/E): ";
    cin >> symptoms[0];
    cout << "2. BODY WEIGHT (N/A/B/O): ";
    cin >> symptoms[1];
    cout << "3. DURATION (W/M/Y): ";
    cin >> symptoms[2];
    cout << "4. KETONUREA (P/A): ";
    cin >> symptoms[3];
    cout << "5. AUTO ANTIBODIES (P/A): ";
    cin >> symptoms[4];
}

int Diabetes::analyseSymptoms(int level)
{
    int count = 0;
    int result = 0;
    switch(level)
    {
        case 1:
            if (symptoms[9] == "D")
                result = -1;
            else if (symptoms[5] == "P" && symptoms[6] == "P" && symptoms[7] == "H")
                result = -1;
            else
            {
                for(int i = 0; i < 10; ++i)
                {
                    if (symptoms[i] == "H" || symptoms[i] == "P" || symptoms[i] == "D" || symptoms[i] == "I")
                        count++;
                }
                if (count > 5)
                    result = -1;
            }
            break;
        case 2:
            if (symptoms[0] == "P" || symptoms[1] == "P" || symptoms[2] == "P" ||
                symptoms[3] == "H" || symptoms[4] == "P" || symptoms[5] == "P" || symptoms[6] == "P")
                result = -1;
            break;
        case 3:
            if ((symptoms[0] == "Y" && symptoms[1] == "N" && symptoms[2] == "W" && symptoms[3] == "P" && symptoms[4] == "P") ||
                (symptoms[0] == "Y" && symptoms[1] == "B" && symptoms[2] == "W" && symptoms[3] == "P" && symptoms[4] == "P") ||
                (symptoms[0] == "Y" && symptoms[1] == "N" && symptoms[2] == "M" && symptoms[3] == "P" && symptoms[4] == "P") ||
                (symptoms[0] == "Y" && symptoms[1] == "N" && symptoms[2] == "Y" && symptoms[3] == "P" && symptoms[4] == "P"))
                result = 0;
            else
                result = -1;
            break;
        default:
            break;
    }
    return result;
}

char Diabetes::displayMessage(int level, int result)
{
    char choice;
    switch(level)
    {
        case 1:
            switch(result)
            {
                case 0:
                    cout << "\nTHE PERSON IS NOT DIABETIC\n";
                    cout << "Press any key to exit.";
                    cin.ignore();
                    cin.get();
                    exit(0);
                case -1:
                    cout << "\nTHE PERSON IS DIABETIC\n";
                    cout << "Proceed to the next level? (Y/N): ";
                    cin >> choice;
                    break;
            }
            break;
        case 2:
            switch(result)
            {
                case 0:
                    cout << "\nIT IS PRIMARY DIABETES.\n";
                    cout << "Proceed to the next level? (Y/N): ";
                    cin >> choice;
                    break;
                case -1:
                    cout << "\nIT IS SECONDARY DIABETES\n";
                    cout << "Press any key to exit.";
                    cin.ignore();
                    cin.get();
                    break;
            }
            break;
        case 3:
            switch(result)
            {
                case 0:
                    cout << "\nIT IS INSULIN DEPENDENT DIABETES\n";
                    cout << "Press any key to exit.";
                    cin.ignore();
                    cin.get();
                    break;
                case -1:
                    cout << "\nIT IS NON INSULIN DEPENDENT DIABETES\n";
                    cout << "Press any key to exit.";
                    cin.ignore();
                    cin.get();
                    break;
            }
            break;
    }
    return choice;
}

int main()
{
    Diabetes dts;
    dts.welcomeScreen();
    dts.getValue();
    dts.getLevel1Symptoms();
    int result = dts.analyseSymptoms(1);
    char choice = dts.displayMessage(1, result);
    choice = toupper(choice);
    if (choice == 'Y')
    {
        dts.getLevel2Symptoms();
        result = dts.analyseSymptoms(2);
        choice = dts.displayMessage(2, result);
        choice = toupper(choice);
        if (choice == 'Y')
        {
            dts.getLevel3Symptoms();
            result = dts.analyseSymptoms(3);
            dts.displayMessage(3, result);
        }
    }
    return 0;
}
