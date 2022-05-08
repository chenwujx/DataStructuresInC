#include <iostream>
#include <string>

using namespace std;

int seqListDebug();
int linkListDebug();

int main() {
    int iChoice = 0, iMenuItems = 3;

    while (1) {
        std::cout << "======================================" << endl;
        std::cout << "0.Quit." << endl;
        std::cout << "1.sequence Linear List." << endl;
        std::cout << "2.link Linear List." << endl;
        std::cout << "======================================" << endl;
        std::cin >> iChoice;
        if (iChoice > -1 || iChoice < iMenuItems) {
            switch (iChoice) {
                case 0:
                    return 0;
                    break;
                case 1:
                    seqListDebug();
                    break;
                case 2:
                    linkListDebug();
                    break;
                default:
                    return 0;
                    break;
            } 
        }
    }

}
