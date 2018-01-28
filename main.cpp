#include <iostream>
#include <fstream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

string readFile(string name) {
    ifstream t;
    t.open(&name[0]);
    string buffer;
    string line;
    while(std::getline(t, line)){
        buffer+=line;
    }
    t.close();
    return buffer;
}
bool customerExists(int customer){
    return true;//TODO
}
void beginNewOrder(int customer){
    //Stworz zamowienie z udane = false
}

bool addPizzaToOrder(int pizzaId, int n){
    //dodaj nowe polacznie sprawdz czy starcza, ew usun polaczenie
}

int finishOrder(){
    //tylko zmien skladniki i zrob commit
}

void ingredientsDeliver(list<pair<int,string>> deliver){
    //dodaj skladniki
}



int main(int argc, char *argv[]) {
    string  dbname = "bd";
    string user = "ms383504";
    string password = "x";
    string hostadrr = "10.1.0.5";
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
        work W(C);
        W.exec(readFile("scheme.txt"));
        W.commit();
        C.disconnect();
    }
    catch (const std::exception &e) {
        cerr << e.what() << std::endl;
        return 1;
    }


}