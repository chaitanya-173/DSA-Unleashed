#include <iostream>
using namespace std;

class Batsman {

    //properties
    private:
    int ducks;

    public:
    int runs;
    int innings;
    int centuries;
    int fifties;
    int iccAwards;
    char quality;

    void setDucks(int d){  //setter
        ducks = d;
    } 

    int getDucks(){  //getter
        return ducks;
    }

    Batsman(){  //default constructor
        cout << "Default Constructor called" << endl;
    }

    Batsman(int runs, char quality){  //parameterised constructor
        cout << "Parameterised Constructor called" << endl;
        this -> runs = runs;  //object ke runs ke andar input wale runs ko copy krdiya
        this -> quality = quality;
        /*cout << "Value of this: " << this << endl; */ 
    }

    Batsman(Batsman& temp){  //copy constructor 
        cout << "Copy Constrcutor called" << endl;
        this->runs = temp.runs;
        this->quality = temp.quality;
    }

    void print(){
        cout << "Runs: " << runs << endl;
        cout << "Quality: " << quality << endl;
    }

    ~Batsman(){  //Destructor
        cout << "Destructor called" << endl;
    }

    static int matchesWon;  //static data member - common for all batsman

    static int random(){
        return matchesWon;
    }

};

int Batsman::matchesWon = 5000;

int main() {

    //creation of object (statically)
    Batsman Kohli;

    Kohli.runs = 27000;
    Kohli.innings = 591;
    Kohli.centuries = 80;
    Kohli.fifties = 140;
    Kohli.iccAwards = 10;
    Kohli.quality = 'A';
    Kohli.setDucks(37); //setter to set private properties

    //creation of object (dynamically)
    Batsman *Rohit = new Batsman;

    (*Rohit).runs = 19000;
    (*Rohit).innings = 483;
    (*Rohit).centuries = 48;
    Rohit->fifties = 106;
    Rohit->iccAwards = 2;
    Rohit->quality = 'B';
    Rohit->setDucks(33);

    cout << "Kohli runs: " << Kohli.runs << endl;
    cout << "Kohli innings: " << Kohli.innings << endl;
    cout << "Kohli centuires: " << Kohli.centuries << endl;
    cout << "Kohli fifties: " << Kohli.fifties << endl;
    cout << "Kohli ICC awards: " << Kohli.iccAwards << endl;
    cout << "Quality of Kohli: " << Kohli.quality << endl;
    cout << "Ducks of Kohli: " << Kohli.getDucks() << endl; //getter to get(fetch) private properties
    cout << endl;
    cout << "Rohit runs: " << (*Rohit).runs << endl;
    cout << "Rohit innings: " << (*Rohit).innings << endl;
    cout << "Rohit centuires: " << (*Rohit).centuries << endl;
    cout << "Rohit fifties: " << (*Rohit).fifties << endl;
    cout << "Rohit ICC awards: " << (*Rohit).iccAwards << endl;
    cout << "Quality of Rohit: " << (*Rohit).quality << endl;
    cout << "Ducks of Rohit: " << (*Rohit).getDucks() << endl;
    cout << endl;

    Batsman Chaitanya;  //object created statically (Default Constructor)
    Batsman *c = new Batsman;  //object created dynamically
    cout << endl;

    Batsman Aryan(30, 'C');  //object created (Parameterised Constructor)
    cout << "Address of Aryan: " << &Aryan << endl;
    cout << endl;

    Aryan.print();
    Batsman Sarthak(Aryan);  //object created (Copy Constructor)
    Sarthak.print();
    cout << endl;

    Batsman Om(10, 'D');
    Batsman Ac(20, 'E');
    Om.print();
    Ac.print();
    //Copy Assignment Operator
    Om = Ac;          //Om.runs = Ac.runs
    Om.print();       //Om.quality = Ac.quality
    Ac.print();
    cout << endl;
    //6 times destructor called(Kohli, Chaitanya, Aryan, Sarthak, Om, Ac)
    //Rohit not called cuz of dynamic allocation
    delete Rohit;  //manual destructor call
    cout << endl;

    cout << "Matches won: " << Batsman::matchesWon << endl;  //no need of object for access
    cout << "Matches won: " << Batsman::random() << endl;
    cout << endl;
    
}