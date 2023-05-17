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
		for (auto& a : person) {
			cout << a.first << "   " << endl;
			for (auto& b : a.second) {
				cout << b.phoneNumber << endl;
			}

		}
		cout << "--------------\n";
		cout << "1_add contact" << endl;
		cout << "2_delete contact" << endl;
		cout << "3_edit contact" << endl;
		cout << "4_add phoneNumber to contact" << endl;
		cout << "5_delete phoneNumber of contact" << endl;
		cout << "6_edit phoneNumber of contact" << endl;
		cout << "7_Exite " << endl;

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
				cout << "enter phone name : ";
				cin >> phoneNameTmp;
				cout << "\nenter phone number :";
				cin >> phoneNumberTmp;

				p.phoneName = phoneNameTmp;
				p.phoneNumber = phoneNumberTmp;
				p.favorite = 0;

				for (auto& n : person) {
					if (n.first == name) {
						v = n.second;
						v.push_back(p);
						person.erase(name);
						person.insert(make_pair(name, v));
						v.clear();
						break;
					}
				}

			}
		}

		else if (choose == 5) {
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
				cout << "which number do you want to delete ?" << endl;
				c = 0;
				for (auto& a : person) {
					if (a.first == name) {
						for (auto& b : a.second) {
							cout << c << "_" << b.phoneNumber << endl;
							c++;
						}
						break;
					}
				}
				int deleteNumber;
				cin >> deleteNumber;
				int i = 0;
				for (auto& a : person) {
					if (a.first == name) {
						for (auto& b : a.second) {
							if (i == deleteNumber) {
								a.second.erase(a.second.begin() + i);
								break;
							}
							i++;
						}
						break;
					}
				}
			}


		}

		else if (choose == 6) {
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
				int n;
				int i = 0;
				int j = 0;
				int itmp;
				string newParam;
				cout << "which one do you want to edit ?" << endl;
				cout << "1_phoneName" << endl;
				cout << "2_phoneNumber" << endl;
				cin >> n;
				if (n == 1) {
					cout << "which name ? " << endl;
					for (auto& a : person) {
						if (a.first == name) {
							for (auto& b : a.second) {
								cout << i << "_" << b.phoneNumber << endl;
								i++;
							}
						}
					}
					cin >> itmp;
					cout << "enter the new name : ";
					cin >> newParam;
					for (auto& a : person) {
						if (a.first == name) {
							for (auto& b : a.second) {
								cout << "yes\n";
								if (j == itmp) {
									b.phoneName = newParam;
									v = a.second;
									person.erase(name);
									person.insert(make_pair(name, v));
									v.clear();
								}
								j++;
							}

						}
					}
				}
				else if (n == 2) {
					cout << "which number ? " << endl;
					for (auto& a : person) {
						if (a.first == name) {
							for (auto& b : a.second) {
								cout << i << "-" << b.phoneNumber << endl;
								i++;
							}
						}
					}
					cin >> itmp;
					cout << "enter the new number : ";
					cin >> newParam;
					for (auto& a : person){
						if (a.first == name) {
							for (auto& b : a.second) {
								if (j == itmp) {
									b.phoneNumber = newParam;
									v = a.second;
									person.erase(name);
									person.insert(make_pair(name, v));
									v.clear();
									break;
								}
								j++;
							}
							break;
						}
					}
				}

			}
		}

		else if (choose == 7) {
			break;
		}
	}


	return 0;
}