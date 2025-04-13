#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Task {
private:
    string text;
    bool doneYet;

public:
    Task(const string& t) : text(t), doneYet(false) {}

    string getText() const { return text; }
    bool isDone() const { return doneYet; }
    void markIt() { doneYet = true; }
};

class MyList {
private:
    vector<Task> list;

public:
    void addSomething(const string& t) {
        list.push_back(Task(t));
        cout << "ok added --> " << t << endl;
    }

    void showAll() const {
        if (list.empty()) {
            cout << "(Your list is empty)\n";
            return;
        }

        cout << "\n* these are something which I have to do *\n";
        for (int i = 0; i < list.size(); ++i) {
            cout << i+1 << ". [" << (list[i].isDone() ? "Already complete" : "Incomplete") << "] " << list[i].getText() << endl;
        }
        cout << "--------------\n\n";
    }

    void done(int index) {
        if (index >= 1 && index <= (int)list.size()) {
            list[index - 1].markIt();
            cout << " Task done by user: " << list[index - 1].getText() << "\n";
        } else {
            cout << "hmm... wrong number?\n";
        }
    }

    void deleteIt(int index) {
        if (index >= 1 && index <= (int)list.size()) {
            string removed = list[index - 1].getText();
            list.erase(list.begin() + index - 1);
            cout << "deleted -> " << removed << "\n";
        } else {
            cout << "nah, that's not a thing.\n";
        }
    }
};

// simple number input
int getNum() {
    int num;
    cin >> num;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "yo type a number pls: ";
        cin >> num;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return num;
}

// gets a line (text) input
string getTxt() {
    string s;
    getline(cin, s);
    return s;
}

int main() {
    MyList l;
    int pick;

    while (true) {
        cout << "\n~ TODO List ~\n";
        cout << "1. Add task\n";
        cout << "2. See tasks\n";
        cout << "3. Mark as done\n";
        cout << "4. Delete task\n";
        cout << "5. Quit\n";

        cout << "choose between (1-5): ";
        pick = getNum();

        switch (pick) {
        case 1:
            cout << "what is in your mind type here: ";
            l.addSomething(getTxt());
            break;

        case 2:
            l.showAll();
            break;

        case 3:
            l.showAll();
            cout << "Which task you want to mark as done? ---> ";
            l.done(getNum());
            break;

        case 4:
            l.showAll();
            cout << "Which task you want to delete? --->";
            l.deleteIt(getNum());
            break;

        case 5:
            cout << "bye bye!! Thanks again for using Todo List\n";
            return 0;

        default:
            cout << "invalid... try 1-5?\n";
        }
    }

    return 0;
}
