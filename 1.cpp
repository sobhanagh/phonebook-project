#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct PhoneBook {
	string phoneName;
	string phoneNumber;
	bool favorite;  // true == favorit   false == not favorite
}p;


int main() {
	int choose = 0;
	string phoneNameTmp, phoneNumberTmp, name;
	bool favoriteTmp;
	vector<PhoneBook> v;
	map<string, vector<PhoneBook>> person;
	map<string, vector<PhoneBook>>::iterator it;

	while (choose != 7) {
		// for (auto& a : person) {
		// 	cout << a.first << "   " << endl;
		// 	for (auto& b : a.second) {
		// 		cout << b.phoneNumber << endl;
		// 	}

		// }
		// cout << "--------------\n";
		cout << "1_add contact" << endl;
		cout << "2_delete contact" << endl;
		cout << "3_edit contact" << endl;
		cout << "4_Exite " << endl;

		cin >> choose;

		if (choose == 1) {
			cout << "what is contact name : ";
			cin >> name;
			person.insert(make_pair(name, v));
		}

		else if (choose == 2) {
			int c = 0;
			cout << "what is contact name : ";
			cin >> name;
			it = person.begin();
			if (it != person.end()) {
				if (it->first == name) {
					c++;
				}
			}
			if (c == 0) {
				cout << "we don't have this name in phonebook" << endl;
			}
			else {
				person.erase(name);
			}
			
		}

		else if (choose == 3) {
			string nameTmp;
			cout << "what is contact name : ";
			cin >> name;
			// check that contact exist
			int c = 0;
			it = person.begin();
			if (it != person.end()) {
				if (it->first == name) {
					c++;
				}
			}
			if (c == 0) {
				cout << "we don't have this name in phonebook" << endl;
			}
			else {
				cout << "what is the new name : ";
				cin >> nameTmp;

				for (auto& n : person) {
					if (n.first == name) {
						v = n.second;
						person.erase(name);
						person.insert(make_pair(nameTmp, v));
						v.clear();
						break;
					}
				}
			}

		}

		else if (choose == 4) {
			break;
		}
	}


	return 0;
}