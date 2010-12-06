#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 3) {
        std::cout<<"Input format file_in file_out"<<std::endl;
        return 0;
    }

    ifstream in;
    in.open(argv[1]);
    ofstream out;
    out.open(argv[2]);

    if (!in || !out) {
        cout<<"Can't open files!"<<endl;
        return 0;
    }

    string str;
    string meaning;
    string terminator("\r\n");
    while(!in.eof()) {
        getline(in, str);
        while (str.size() > 0 && (str[str.size()-1] == '\r' || str[str.size()-1] == '\n'))
            str.erase(str.end()-1);
        if (str.size() == 0)
            continue;
        int pos = str.find('-');
        if (pos < 0) {
            out<<str<<terminator;
        } else {
            out<<str.substr(0, pos-1)<<terminator;
            out<<'{'<<terminator;
            meaning = str.substr(pos+2);
            out<<meaning<<terminator;
            out<<'}'<<terminator;
        }
    }

    in.close();
    out.close();

    cout<<"Done successfully!"<<endl;

    return 0;
}
