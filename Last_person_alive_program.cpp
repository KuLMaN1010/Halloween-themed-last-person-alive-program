#include "Simulation.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    char choice = '1';
    while (choice == '1') {
        
        int numPeople;
        cout << "How many are you?: ";
        cin >> numPeople;

        vector<string> people(numPeople);
        for (int i = 0; i < numPeople; ++i) {
            cout << "Enter Person #" << i + 1 << "'s name: ";
            cin >> people[i];
        }

        int skipNum;
        cout << "Give me a number: ";
        cin >> skipNum;
        cout << "Now we begin......";
        cout << "" << endl;
        
        Simulation sim(people, skipNum);

        
        vector<string> eliminated = sim.GetEliminationList();
        cout << "\nKill List:\n";
        for (int i = 0; i < eliminated.size(); ++i) {
            cout <<"        "<< i + 1 << ". " << eliminated[i] << endl;
        }

        cout << "" << endl;
        cout << "" << endl;
        cout << "********************************************";
        cout << "\nSurvivor: " << sim.GetSurvivor() << endl;
        cout << "********************************************";
        cout << "" << endl;
        cout << "" << endl;

        cout << "\nWant to run another round?\nFor Yes, enter 1.\nFor No, enter any other number.\n";
        cin >> choice;
    }

    return 0;
}
