#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

string passwordGenerator(int length){
    string password;
    const string allowedCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";

    for (int i = 0; i < length; i++){
        int index = rand() % allowedCharacters.size();
        password += allowedCharacters[index];
    }
    
    return password;
}


void programTitle(){
    cout << "___  ____ ____ ____ _ _ _ ____ ____ ___    " << endl;
    cout << "|__] |__| [__  [__  | | | |  | |__/ |  \\   " << endl;
    cout << "|    |  | ___] ___] |_|_| |__| |  \\ |__/   " << endl;
    cout << "____ ____ _  _ ____ ____ ____ ___ ____ ____" << endl;
    cout << "| __ |___ |\\ | |___ |__/ |__|  |  |  | |__/" << endl;
    cout << "|__] |___ | \\| |___ |  \\ |  |  |  |__| |  \\" << endl;
    cout << "" << endl;
}

int main(){
    int input;
    string password;

    srand(time(0));

    while (true)
    {
        cout << "" << endl;
        programTitle();
        //cout << "password generator" << endl;
        cout << "Enter desired password length: ";
        cin >> input;
        if (input >= 8 && input <= 24){
            string password = passwordGenerator(input);
            cout << "Generated password: " << password << endl;
            cout << "Enter \"0\" to exit." << endl;
        }
        else if (input == 0 )
        {
            cout << "Exiting program..." << endl;
            break;
        }
        
        else{
            cout << "Error. Password length should be between 8 and 24." << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(3000));
    }

    return 0;
}