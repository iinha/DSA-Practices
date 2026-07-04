#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


struct Student {
    string code;
    string name;
    double gpa;
    string klass;
};

class Registry {
public:
    void add(const Student& s);
    const Student* find(const string& code) const;
    vector<string> list(const string& klass) const;
    const Student* top(const string& klass) const;

private:
    unordered_map<string, Student> byCode;
    unordered_map<string, vector<string>> byClass;
};

// Implement all Registry methods below (use Registry::<method> syntax):
//   add(s)        - register a student
//   find(code)    - pointer to student, or nullptr if not found
//   list(klass)   - codes in a class, sorted ascending by code; empty if class unknown
//   top(klass)    - pointer to top-gpa student in a class (tie => smallest code); nullptr if empty




int main() {
    int n;
    cin >> n;

    Registry reg;
    for (int i = 0; i < n; i++) {
        Student s;
        cin >> s.code >> s.name >> s.gpa >> s.klass;
        reg.add(s);
    }

    int q;
    cin >> q;
    while (q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "FIND") {
            string code; cin >> code;
            const Student* s = reg.find(code);
            if (!s) {
                cout << "NOT_FOUND\n";
            }
            else {
                cout << s->code << " " << s->name << " "
                    << fixed << setprecision(2) << s->gpa
                    << " " << s->klass << "\n";
            }
        }
        else if (cmd == "LIST") {
            string klass; cin >> klass;
            vector<string> codes = reg.list(klass);
            if (codes.empty()) {
                cout << "EMPTY\n";
            }
            else {
                for (size_t i = 0; i < codes.size(); i++) {
                    if (i) cout << " ";
                    cout << codes[i];
                }
                cout << "\n";
            }
        }
        else if (cmd == "TOP") {
            string klass; cin >> klass;
            const Student* s = reg.top(klass);
            if (!s) {
                cout << "EMPTY\n";
            }
            else {
                cout << s->code << " " << s->name << " "
                    << fixed << setprecision(2) << s->gpa << "\n";
            }
        }
    }
    return 0;
}
