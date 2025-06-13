#include <iostream>
using namespace std;

int main() {
    const int FRAME_SIZE = 3;
    int frames[FRAME_SIZE];
    int pageString[100];
    int pageCount = 0;
    int pointer = 0;
    int pageFaults = 0;

    for (int i = 0; i < FRAME_SIZE; i++) {
        frames[i] = -1;
    }

    cout << "Enter pages one by one (end with -1): ";
   int input;
cout << "Enter pages (end with -1): ";
cin >> input;

while (input != -1) {
    pageString[pageCount] = input;
    pageCount++;
    cin >> input;
}

    cout << "\nStep\tPage\tFrame1\tFrame2\tFrame3\tPage Fault\n";

    for (int i = 0; i < pageCount; i++) {
        int currentPage = pageString[i];
        bool found = false;

        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] == currentPage) {
                found = true;
                break;
            }
        }

        if (!found) {
            frames[pointer] = currentPage;
            pointer = (pointer + 1) % FRAME_SIZE;
            pageFaults++;
        }

        cout << i + 1 << "\t" << currentPage << "\t";
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (frames[j] == -1)
                cout << "-\t";
            else
                cout << frames[j] << "\t";
        }
        cout << (found ? "No" : "Yes") << "\n";
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;

    return 0;
}