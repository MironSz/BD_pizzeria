#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

string readFile(string name) {
    std::ifstream t;
    t.open(name);
    std::string buffer;
    std::string line;
    while(line){
        std::getline(t, line);
        buffer+=line;
    }
    t.close();
    return buffer;
}

int main(int argc, char *argv[]) {
    string  dbname = "bd";
    string user = "ms383504";
    string password = "x";
    string hostadrr = "127.0.0.1";
    string port = "5432";
    try {
        connection C("dbname = " + dbname + " user = " + user + " password = " + password + " hostaddr = " + hostadrr +
                     " port = " + port);
        if (C.is_open()) {
            cout << "Opened database successfully: " << C.dbname() << endl;
        } else {
            cout << "Can't open database" << endl;
            return 1;
        }
    }
    catch (const std::exception &e) {
        cerr << e.what() << std::endl;
        return 1;
    }

    work W(C);
    W.exec(readFile("drop_tables.txt"));
    W.commit();
    C.disconnect();
}