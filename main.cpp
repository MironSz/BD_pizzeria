#include <iostream>
#include <fstream>
#include <pqxx/pqxx>

#define SKLADNIKI "skladnik"
#define PIZZE "pizza"
#DEFINE KLIENCI "klient"
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
bool customerExists(int customer, work W){
    result r = W.exec("SELECT * from "+KLIENCI+" where id_klienta = "+customer+";");
    return r.begin()!=r.end();
}
int beginNewOrder(int customer, work W){
    W.exec("INSERT INTO ZAMOWIENIE (id_klienta,udane) VALUES ("
           +customer+",false);");
    result r = W.exec("SELECT id_klienta from KLIENT WHERE udane = false;");
    return (*r.begin())[0]->as<int>;

    //Stworz zamowienie z udane = false
}

bool addPizzaToOrder(int pizzaId,int orderId, work W){
    W.exec("INSERT INTO PolaczeniaPizzaZamowienie (id_zamowienia,id_pizzy,ilosc)"
                   "VALUES ("+orderId+","+pizzaId+","+ilosc+");");
    result r = W.exec("SELECT sprawdzSkladniki("+orderId+");");
    //TODO sprawdz to
    if(true){
        W.exec("DELETE from PolaczeniePizzaZamowienie WHERE id_zamowienia;");
    }
    return true;
    //dodaj nowe polacznie sprawdz czy starcza, ew usun polaczenie
}

int finishOrder(work W){
    //tylko zmien skladniki i zrob commit
}

void ingredientsDeliver(list<pair<int,string>> deliver, work W){
    //dodaj skladniki
}

void createNewIngredient(string name, work W){
    //stworz nowy skladnik
}
bool ingredientExists(string name, work W){
    result r = W.exec("SELECT * from "+SKLADNIKI+" where nazwa = "+name+";");
    return r.begin()!=r.end();
}

void parse_input(string s, work W){
//    list<string> parsed
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