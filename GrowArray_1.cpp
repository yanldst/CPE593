/*
 * Title: GrowArray
 * Author: Lei Yan
 *
 */

#include<fstream>
#include<sstream>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class GrowArray {
private:
    int *  p;
    int used;
    int size;

    void grow(int r) {

        size = size * 2;

        int * temp = p;
        p = new int[size];

        for (int i = 0; i < used; ++i) {
            p[i + r] = temp[i];
        }
        delete [] temp;
    }

    void grow() {
        grow(0);
    }
public:
    GrowArray(int initialSize) {
        used = 0;
        size = initialSize;
        p = new int[size];

    }
    GrowArray() {
        used = 0;
        size = 1;
        p = new int[size];
    }

    ~GrowArray() {
        delete [] p;
    }

    void ADD_BACK(int v) {
        if (used + 1 > size) {
            grow();
        }
        p[used] = v;
        ++used;
    }

    void ADD_FRONT(int v) {
        if (used + 1 > size) {
            grow(1);
        }
        else {
            for (int i = used - 1; i >= 0; --i) {  // O(n)
                p[i + 1] = p[i];
            }
        }

        p[0] = v;
        ++used;
    }

    void REMOVE_FRONT() {
        for (int i = 0; i < used - 1; ++i) {  // O(n)
            p[i] = p[i + 1];
        }

        --used;
    }

    void REMOVE_BACK() {
        p[used - 1] = 0;
        --used;
    }

    int length() const {
        return used;
    }

    friend ostream& operator << (ostream& s, const GrowArray& list) {
        for (int i = 0; i < list.length(); i++) {
            s << list.p[i] << " ";
        }
        return s;
    }
};

int main() {

    GrowArray a;

    string line_temp, choice;
    int input, i = 0;

    ifstream infile;
    infile.open("HW4a.txt");

    if (infile) {
        while (getline(infile, line_temp)) {
            istringstream line(line_temp);
            line >> choice;

            if (choice == "ADD_FRONT") {
                string stringLength, tempString;
                stringLength = line_temp.substr(line_temp.find(" ")+1);
                //store inputing integers to be string, used to reverse the order of inputing numbers
                for(int i=stringLength.length()-1; i>=0; i--){
                    if(stringLength[i]==' '){
                          continue;
                    } else{
                    tempString = stringLength[i];
                    input = atoi(tempString.c_str());
                    a.ADD_FRONT(input);
                    continue;
                    }
                }

            }

            else if (choice ==  "ADD_BACK") {
                while (line >> input) {
                    a.ADD_BACK(input);
                }
            }
            else if (choice == "REMOVE_FRONT") {
                line >> input;
                for (i = 0; i < input; ++i) {
                    a.REMOVE_FRONT();
                }
            }
            else if (choice == "REMOVE_BACK") {
                line >> input;
                for (i = 0; i < input; ++i) {
                    a.REMOVE_BACK();
                }
            }
            else if (choice == "OUTPUT") {
                cout << a << endl;
            }
            else {
                cout << "BAD INPUT";
                break;
            }
        }
    }
}
