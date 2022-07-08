#include<iostream>


using namespace std;

class person {
	string Name;
	int Age;
	char Gender;
public:
	person() {	//Default costructor
		Name = "none";
		Age = 0;
		Gender = 'N';
	}

	

	person(string Name, int Age, char Gender) {	//parametrized constructor
		this->Name = Name;
		this->Age = Age;
		this->Gender = Gender;
	}

	virtual void input() {
		cout << "\n	Enter NAME OF PERSON = ";
		cin >> Name;
		cout << "\n	ENTER AGE OF PERSON IN NUM = ";
		cin >> Age;
		cout << "\n	ENTER GENDER OF PERSON = ";
		cin >> Gender;
	}

	virtual void print() {
		cout << endl << "	Name = " << Name;
		cout << endl << "	Age = " << Age;
		cout << endl << "	Gender = " << Gender;
		
	}

	~person() {
		cout << endl << "~person Called " << endl;
	}

};

////////////////////////////////// A D U L T   C L A S S ////////////////////////////////////////

class Adult :public person {
	string Occupation;
	string Qualification;
	string NIC;

public:

	Adult() :person() {	//Default Constructor
		Occupation = "None";
		Qualification = "None";
		NIC = "0";
	}

	Adult(string n, int a, char g, string occup, string quali, string NIC) :person(n, a, g) {	//Parametrized Constructor
		this->Occupation = occup;
		this->Qualification = quali;
		this->NIC = NIC;
	}

	void input() {
		this->person::input();
		cout << "\n	ENTER OCCUPATION = ";
		cin >> Occupation;
		cout << "\n	ENTER QUALIFICATION = ";
		cin >> Qualification;
		cout << "\n	ENTER NIC number = ";
		cin >> NIC;
	}

	virtual void print() {
		this->person::print();
		cout << endl << "	Occupation = " << Occupation;
		cout << endl << "	Qualification = " << Qualification;
		cout << endl << "	NIC Number = " << NIC;
	}

	~Adult() {
		cout << endl << "~Adult Called " << endl;
	}

};

//////////////////////////////// K I D   C L A S S /////////////////////////////////

class kid :public person {
	string B_form_number;
public:
	kid() :person() {	//Default Constructor
		B_form_number = "None";
	}

	kid(string n, int a, char g, string Bform) :person(n, a, g) {	//parametrized Constructor
		this->B_form_number = Bform;
	}

	void input() {
		this->person::input();
		cout << "\n	ENTER B-FORM NUMBER = ";
		cin >> B_form_number;
	}

	virtual void print() {
		this->person::print();
		cout << endl << "	B form Number = " << B_form_number;
	}

	~kid() {
		cout << endl << "~kid Called " << endl;
	}
};

/////////////////////////////// B O G I E    C L A S S ///////////////////////////////////////////////

class Bogie:public person,kid {
	int Bogie_ID;
	Bogie* next;	//points towards next bogie
	person** Adults;
	person** kids;
	int n[2];	//keeps the number the size of adult and kid
	string familyName;

public:
	Bogie() {		//Default Constructor
		this->kids = NULL;
		this->Adults = NULL;
		this->next = NULL;
		Bogie_ID = 0;
		familyName = "None";
	}

	Bogie(Bogie& obj) {		//Copy Constructor
		this->Bogie_ID = obj.Bogie_ID;
		this->next = obj.next;
		for (int i = 0; i < obj.n[0]; i++) {	//Copies Adults
			this->Adults[i] = obj.Adults[i];
		}
		for (int i = 0; i < obj.n[1]; i++) {	//Copies Kids
			this->kids[i] = obj.kids[i];
		}
		this->familyName = obj.familyName;
	}

	Bogie(int id) {		//Parametrized Constructor
		Bogie_ID = id;
		n[0] = 0; n[1] = 0;
		
		this->kids = 0;
		this->Adults = 0;
		this->next = NULL;
		
		familyName = "None";
	}

	Bogie* getNext() {
		return next;
		
	}

	void setBogie(int id) {
		this->Bogie_ID = id;
		n[0] = 0; n[1] = 0;
		next = NULL;
	}

	int getBogieID() {
		return Bogie_ID;
	}

	bool matchID(int id) {	//used in finding a bogie of a particular id
		if (this->Bogie_ID != id) {
			return false;
		}
	}

	void setNext(Bogie* a) {
		next = a;
	}

	void updateNext(Bogie& obj) {	//recives the next object 
		*next = obj;
	}

	void setFamilyName() {
		cout << endl << "ENTER FAMILY NAME = ";
		cin >> familyName;
	}

	void AddPassengers() {	// should add adults and kids information etc
		cout << "\nENTER THE NUMBER OF ADULTS = "; int numA;
		cin >> numA;
		while (numA > 4) {
			cout << "\nONLY FOUR ADULTS CAN SIT IN A BOGIE ! ";
			cout << "\nPLEASE ENTER AGAIN = ";
			cin >> numA;
		}
		person** temp = new person*[n[0]];	//intializing temporary adult array
		for (int i = 0; i < n[0]; i++) {
			temp[i] = Adults[i];	//copying in temporary array
		}
		Adults = new person*[n[0] + numA];	//intializing adult array after increasin  number of adult
		//for (int i = 0; i < n[0]; i++) {
		//	Adults[i] = temp[i];	//pasting adults from temp to original adult array
		//}
		int count = 1;
		for (int i = n[0]; i < n[0] + numA; i++) {
			Adult a[1];		//making adult object
			a[0].input();
			this->Adults[i] = &a[0]; //Adding the current Object
		
			/*person* g;
			g = &a;
			g->print();*/
			/*Adults++;
			count++;
			Adults = &a[0];*/
			/*Adults[i] = *g;*/
			this->Adults[i]->print();
		}
		
		n[0] = n[0] + numA;	//incresing number of adults	

		cout << "\nENTER NUMBER OF KIDS = "; int numK;
		cin >> numK;
		while (numK > 6) {
			cout << "\nONLY SIX KIDS IN A BOGIE ! ";
			cout << "\nPLEASE ENTER AGAIN = ";
			cin >> numK;
		}
		temp = new person*[n[1]];	//
		for (int i = 0; i < n[1]; i++) {
			temp[i] = kids[i];
		}
		kids = new person*[n[1] + numK];
		for (int i = 0; i < n[1]; i++) {
			kids[i] = temp[i];	//pasting adults from temp to original adult array
		}
		for (int i = 0; i < n[1] + numK; i++) {
			kid k;
			k.input();
			kids[i] = &k;
		}
		n[1] = n[1] + numK;		//increases the number of kids
	}

	void Print() {
		cout << endl << "ADULTS IN BOGIE " << endl;
		for (int i = 0; i < n[0]; i++) {
			Adults[i]->print();
		}
		cout << endl << "KIDS IN BOGIE " << endl;
		for (int i = 0; i < n[1]; i++) {
			kids[i]->print();
		}
	}

	~Bogie() {
		
		//next = NULL;
		delete[] Adults;
		delete[] kids;
		// iam the dumebesr 
		//if you find that precious thing, Never Loose it
		//Kuch Khushiyan Bant Kar hi ham Yuhin Sakun Mehsus Kar lia Krte hein
		//Is Sakun ki talash mei apna ham Yuhin buhat sa nuksan kr bethte hein

		//Haste Haste Bhi Dil Tod Dena Koi Tumse Seekhe
		//Rote  Rote  Bhi Muskura Dena Koi Hamse Seekhe

	}
};

////////////////////////////// T R A I N ///////////////////////////////////////////////////

class train :public Bogie{
	Bogie* engine;
	Bogie* current;
	Bogie* temp;
	int n; //Number of Bogies in Train
	Bogie e1[15];

public:

	train() {
		n = 1;
		engine = NULL;	//Engine will point towards First Bogie
		temp = NULL;
		current = NULL;
		
	}
	void AddBogie(int ID) {
		while (engine != NULL && this->SearchBogie(ID) == true) {
			cout << "THIS ID ALREADY EXISTS !! ";
			cout << "ENTER NEW ID = ";
			cin >> ID;
		}
		Bogie* a = new Bogie(ID);
		a->setFamilyName();
		a->AddPassengers();
		if (engine != NULL) {
			current = engine;
			while (current->getNext() != NULL) {

				current = current->getNext();
			}
			current->setNext(a);
			n++;
		}
		else {
			engine=a;	//CAse when itss a first Bogie
			n++;
		}
	}
	
	void RemoveBogie(int ID) {
		Bogie* delBogie = new Bogie(0);
		temp = engine;
		current = engine;

		while (current->getNext() != NULL && current->getBogieID() != ID) {	//traverse until it find the matching id
			temp = current;	//stores current in temp bogie before the bogie that is to be removed 
			current = current->getNext();	//updates the next
		}
		if (current->getNext() == NULL) {	//when id not found
			delBogie->setNext(NULL);
		}
		else {	//case when id iz found
			
			delBogie = current;				//seperating the matched id bogie
			current = current->getNext();	//re connecting the previous bogie stored in temp bogie
			temp->setNext(current);
			if (delBogie == engine) {
				engine = engine->getNext();
				temp = NULL;
			}
			delBogie->setNext(NULL);
			n--;
		}
	
	}

	void removeBogie(int ID) {	//search the bogie and delete it
		cout << "\nDELETING BOGIE OF ID " << ID << endl;
		for (int i = 1, j = 1; i < n; i++) {	// j is to skip deleted object
			if ((engine[i].getBogieID()) != ID) {
				e1[j] = engine[i];
				j++;
			}
		}

		n--;	//decreasing the number of bogies after removing a bogie 
		engine = new Bogie[n];
		for (int i = 1; i < n; i++) {	//paste in original
			engine[i] = e1[i];
		}
	}

	void PrintTrain() {
		current =engine;
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << " ------ ";
		}
		cout << endl;
		bool loop = true;
		if (engine != NULL && engine->getNext() == NULL ) {
			cout << "|  ";
			cout << engine->getBogieID() << "  |-";
			current->Print();
		}
		while(engine != NULL && current->getNext() != NULL && loop == true  ) {
			cout << "|  ";
			cout << current->getBogieID() << "  |-";
			current->Print();
			current = current->getNext();
			if (current->getNext() == NULL) {
				cout << "|  ";
				cout << current->getBogieID() << "  |-";
				current->Print();
				loop = false;
			}
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << " ------ ";
		}
		cout << endl;
	}

	void printTrain() {	//print only the Bogie_ID of all bogies
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << " ------ ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << "|  ";
			cout << engine[i].getBogieID() << "  |-";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << " ------ ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << "\n\nBogie ID = " << engine[i].getBogieID() << endl;
			engine[i].Print();
		}
		cout << endl;
	}

	bool SearchBogie(int ID) {	////search the particular bogie	
		current = engine;
		bool loop = true;
		while (current->getNext() != NULL && loop == true) {
			
			if (current->getBogieID() == ID) {
				cout << "\nBOGIE FOUND !! " << endl;
				return true;
			}
			current = current->getNext();	//current updates
			if (current->getNext() == NULL) {
				if (current->getBogieID() == ID) {
					cout << "\nBOGIE FOUND !! " << endl;
					return true;
				}
				loop = false;
			}
		}
		cout << "\nBOGIE NOT FOUND !! " << endl;
		return false;
	}


	~train() {
		
		temp = engine;
		current = engine;
		Bogie* a = engine;
		while (a->getNext() != NULL) {
			Bogie* t = a->getNext();
			delete a;
			a = t;
		}	
		delete engine;

	}
};

////////////////////////////////////////  MAIN  //////////////////////////////////////////////////////
int main() {

	train a;
	a.PrintTrain();
	a.AddBogie(2);
	//a.AddBogie(3);
	//a.AddBogie(1);
	//a.AddBogie(6);
	a.PrintTrain();
	//a.RemoveBogie(2);	//done
	a.SearchBogie(0);
	a.PrintTrain();

	return 0;
}