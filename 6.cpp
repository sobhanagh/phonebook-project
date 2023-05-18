#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct PhoneBook {
	string phoneName;
	string phoneNumber;
}p;

struct Contact {
	string name;
	bool favorite;
}contact;


int main() {
	int choose = 0;
	string phoneNameTmp, phoneNumberTmp, name;
	vector<PhoneBook> v;
	map<string,vector<PhoneBook>> person;
	vector<Contact> fav;

	while (choose != 14) {
		//for (auto& a : person) {
		//	for (auto& c : fav) {
		//		if (c.name == a.first) {
		//			cout << "fav " << c.favorite << endl;
		//			break;
		//		}
		//	}
		//	cout << a.first << "   " << endl;
		//	for (auto& b : a.second) {
		//		cout << b.phoneNumber << endl;
		//		
		//	}
		//}
		cout << "--------------\n";
		cout << "1_add contact" << endl;
		cout << "2_delete contact" << endl;
		cout << "3_edit contact" << endl;
		cout << "4_add phoneNumber to contact" << endl;
		cout << "5_delete phoneNumber or phonename of contact" << endl;
		cout << "6_edit phoneNumber or phonename of contact" << endl;
		cout << "7_add contanct to favorite list" << endl;
		cout << "8_delete contanct from favorite list" << endl;
		cout << "9_change order of favorite list" << endl;
		cout << "10_show favorite list" << endl;
		cout << "11_show numbers of contact" << endl;
		cout << "12_show all contacts" << endl;
		cout << "13_search" << endl;
		cout << "14_Exite " << endl;

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
			for (auto& a : person) {
				if (a.first == name) {
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
			for (auto& a : person) {
				if (a.first == name) {
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
			for (auto& a : person) {
				if (a.first == name) {
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
			for (auto& a : person) {
				if (a.first == name) {
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
			for (auto& a : person) {
				if (a.first == name) {
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
			cout << "what is contact name : ";
			cin >> name;
			// check that contact exist
			int c = 0;
			for (auto& a : person) {
				if (a.first == name) {
					c++;
				}
			}
			if (c == 0) {
				cout << "we don't have this name in phonebook" << endl;
			}
			else {
				for (auto& a : person) {
					if (a.first == name) {
						contact.name = name;
						contact.favorite = 1;
						fav.push_back(contact);
						break;
					}
				}
			}
		}

		else if (choose == 8) {
			cout << "what is contact name : ";
			cin >> name;
			// check that contact exist
			int c = 0;
			for (auto& a : person) {
				if (a.first == name) {
					c++;
				}
			}
			if (c == 0) {
				cout << "we don't have this name in phonebook" << endl;
			}
			else {
				for (auto& a : person) {
					if (a.first == name) {
						contact.name = name;
						contact.favorite = 0;
						fav.push_back(contact);
						break;
					}
				}
			}
		}

		else if (choose == 9) {
			string secondName;
			cout << "what is contact name : ";
			cin >> name;
			// check that contact exist
			int c = 0;
			for (auto& a : person) {
				if (a.first == name) {
					c++;
				}
			}
			if (c == 0) {
				cout << "we don't have this name in phonebook" << endl;
			}
			else {
				cout << "what is second contact name : ";
				cin >> secondName;
				// check that contact exist
				c = 0;
				for (auto& a : person) {
					if (a.first == name) {
						c++;
					}
				}
				if (c == 0) {
					cout << "we don't have this name in phonebook" << endl;
				}
				else {
					Contact tmp;
					for (int i = 0; i < fav.size(); i++) {
						if (fav.at(i).name == name) {
							for (int j = 0; j < fav.size(); j++) {
								if (fav.at(j).name == secondName) {
									tmp = fav.at(i);
									fav.at(i) = fav.at(j);
									fav.at(j) = tmp;
									break;
								}
							}
							break;
						}
					}
				}
			}
		}

		else if (choose == 10) {
			for (auto& a : fav) {
				if (a.favorite == 1) {
					cout << a.name << endl;
				}
			}
		}

		else if (choose == 11) {
			cout << "what is contact name : ";
			cin >> name;
			// check that contact exist
			int c = 0;
			for (auto& a : person) {
				if (a.first == name) {
					c++;
				}
			}
			if (c == 0) {
				cout << "we don't have this name in phonebook" << endl;
			}
			else {
				for (auto& a : person) {
					if (a.first == name) {
						cout << "name : " << name << endl;
						for (auto& b : a.second) {
							cout << b.phoneName << ": " << b.phoneNumber << endl;
						}
						break;
					}
				}
			}
		}

		else if (choose == 12) {
			for (auto& a : person) {
				cout << a.first << endl;
			}
		}

		else if (choose == 13) {
			int c = 0;
			cout << "enter name : ";
			cin >> name;
			for (auto& a : person) {
				if (a.first == name) {
					cout << a.first << endl;
					c++;
					break;
				}
			}

			int cTmp = 0;
			for (auto& a : person) {
				for (int i = 0; i < min(a.first.length(), name.length()); i++) {
					if (a.first.at(i) == name[i]) {
						cTmp++;
					}
				}
				if (cTmp == name.length() && a.first != name) {
					cout << a.first << endl;
					c++;
				}
				cTmp = 0;
			}

			if (c == 0) {
				cTmp = 0;
				for (auto& a : person) {
					for (int i = 0; i < name.length(); i++) {
						if (a.first.at(i) == name[i]) {
							cTmp++;
						}
					}
					if (cTmp == name.length()) {
						cout << a.first << endl;
					}
					cTmp = 0;
				}
			}
		}

		else if (choose == 14) {
			break;
		}
	}


	return 0;
}
