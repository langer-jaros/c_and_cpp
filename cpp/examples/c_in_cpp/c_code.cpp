#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

const size_t DB_MAX = 100;

struct Tcar {
	string m_RZ;
	string m_Owner;
	unsigned m_Age;
};

bool AddCar (TCar * db, size_t &dbNr, const char  &rz, const char  & owner, unsigned age){
	for ( size_t i =0; i< dbNr; i++)
		if (db[i] . m_RZ == rz)
			return false;
	db[dbNr]. m_RZ = rz;
	db[dbNr]. m_Owner = owner;
	db[dbNr]. m_Age = age;
	dbNr ++;
	return true;
}

bool DelCar (TCar * db, size_t & dbNr, const char  &rz){
	for ( size_t i =0; i< dbNr; i++)
		if (db[i] . m_RZ == rz){
			db[i] = db[--dbNr];
			return true;
		}
	return false;
}

int carCmp (TCar * a, TCar * b){
	return ( a -> m_Age > b -> m_Age ) - ( b-> m_Age > a -> m_Age ) ; 
}

Sort (TCar * db, size_t dbNr){
	qsort ( db, dbNr, sizeof (*db), carCmp);
}

Print (TCar * db, size_t dbNr){
	for ( size_t i =0; i< dbNr; i++)
		cout << db[i] . m_RZ << " "
			<< db[i] . m_Owner << " "
			<< db[i] . m_Age << endl;
}

int main ( void ) {
	TCar db[DB_MAX]
	size_t dbNr = 0;
	
	
	AddCar ( db, dbNr, "DEF-98-76", "Petra Svobodova", 2);
	AddCar ( db, dbNr, "ABC-12-34", "Jan Novy", 3);
	AddCar ( db, dbNr, "FENOMEN2", "Gotfather", 1);
	Sort(db, dbNr);
	Print(db, dbNr);
	
	DelCar ( db, dbNr, "FENOMEN2" );
	Print(db, dbNr);
	
	
	return 0;
}