#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>

using namespace std;

deque<char> createdeque(int length) {
    deque<char> d;
    char symbols[] = { '@', '#', '$', '%', '^', '&', '*' };
    srand(time(NULL)); 

    for (int i = 0; i < length; i++) {
        d.push_back(symbols[rand() % 7]);
    }

    return d;
}

void printdeque(deque<char> d) {
    for (char c : d) {
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    deque<char> d = createdeque(5);
    printdeque(d);

    char input;
    int position;

    while (!d.empty()) {
        cout << "enter a symbol to insert: ";
        cin >> input;

        cout << "enter position to insert (1 - left, 2 - right): ";
        cin >> position;

        if (position == 1) {
            d.push_front(input);
        }
        else {
            d.push_back(input);
        }

        printdeque(d);

        for (int i = 0; i < d.size() - 2; i++) {
            if (d[i] == d[i + 1] && d[i] == d[i + 2]) {
                d.erase(d.begin() + i, d.begin() + i + 3);
                cout << "three consecutive symbols erased!" << endl;
                printdeque(d);
            }
        }
    }

    cout << "Deque is now empty. Program is ending." << endl;

    return 0;
}