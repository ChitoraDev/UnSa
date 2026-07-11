#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <cctype>

namespace forf = std::filesystem;

void zapis(int stroka, std::string znachenie) {

	char* localAppData = std::getenv("LOCALAPPDATA");

	if (localAppData == nullptr) {

		std::cout << "..[You don't have a save file! Try creating one by launching the game].." << std::endl;
        return;
	}

	std::string full_path = std::string(localAppData) + "\\UNDERTALE\\file0";
	forf::path Savef(full_path);

	if (!forf::exists(Savef)) {

		std::cout << "..[You don't have a save file! Try creating one by launching the game].." << std::endl;
		return;

	}

	std::vector<std::string> lines;
	std::string vrem;
	std::ifstream in(Savef);
		
	while (std::getline(in, vrem)) {

			lines.push_back(vrem);
	}
	
	in.close();

	if (stroka < lines.size()) {

		lines[stroka] = znachenie;
	} else {
		
		std::cout << "..[Error reading file! The file is either corrupted or missing a specific line].." << std::endl;
		return;

	}

	std::ofstream out(Savef);

	for (const auto& l : lines) {

		out << l << "\n";

	}

	out.close();

	std::cout << "..[The file has been overwritten!].." << std::endl;

}

void IDItemList() {

std::cout << "..[1: Monster Candy, 2: Croquet Roll, 3: Stick, 4: Bandage, 5: Rock Candy, 6: Pumpkin Rings, 7: Spider Donut, 8: Stoic Onion, 9: Ghost Fruit, 10: Spider Cider, 11: Butterscotch Pie, 12: Faded Ribbon, 13: Toy Knife, 14: Tough Glove, 15: Manly Bandanna, 16: Snowman Piece, 17: Nice Cream, 18: Puppydough Icecream, 19: Bisicle, 20: Unisicle, 21: Cinnamon Bun, 22: Temmie Flakes, 23: Abandoned Quiche, 24: Old Tutu, 25: Ballet Shoes, 26: Punch Card, 27: Annoying Dog, 28: Dog Salad, 29-34: Dog Residue, 35: Astronaut Food, 36: Instant Noodles, 37: Crab Apple, 38: Hot Dog...?, 39: Hot Cat, 40: Glamburger, 41: Sea Tea, 42: Starfait, 43: Legendary Hero, 44: Cloudy Glasses, 45: Torn Notebook, 46: Stained Apron, 47: Burnt Pan, 48: Cowboy Hat, 49: Empty Gun, 50: Heart Locket, 51: Worn Dagger, 52: Real Knife, 53: The Locket, 54: Bad Memory, 55: Last Dream, 56: Undyne's Letter, 57: Undyne's Letter EX, 58: Potato Chips, 59: Junk Food, 60: Mystery Key, 61: Face Steak, 62: Hush Puppy, 63: Snail Pie, 64: Temmie Armo].." << std::endl << std::endl;

}

bool NorNam(const std::string& name) {

if (name.empty() || name.length() > 6) {
        
	std::string Ch;

	while (true) {
	
	std::cout << "..[Non recommended name! You can write this name, but its maybe create a problems with interface. Write down?].." << std::endl << "..[Yes / No].." << std::endl;

    std::cin >> Ch;

	if (Ch == "Yes") {

		break;

	} else if (Ch == "No") {

		return false;

	} else {
	
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "..[Write 'Yes' or 'No'!].." << std::endl;

	}

}

}

for (char c : name) {
        
	if (!std::isalnum(static_cast<unsigned char>(c))) {
            
		std::cout << "..[Name can contain only latin alphabets and numbers!].." << std::endl << std::endl;
		
		return false;

        }
    }
    
	return true;

}

int main() {

	while (true) {
		std::string func = "";

		std::cout << "........[Unsa]........" << std::endl;
		std::cout << "..[Select function].." << std::endl;
		std::cout << "..[Main data - 1. Inventory - 2. Characters - 3. Settings - 4. Save file - 5.].." << std::endl;
		
		std::cin >> func;

		if (func == "0") {
			std::cout << "..[You haven't selected a function].." << std::endl;
		}
		else if (func == "1") {
			std::string Ma_fu = "";
			
			std::cout << "..[Select function].." << std::endl;
			std::cout << "..[Change the name of the fallen - 1. Change the level - 2. Change the amount of health - 3. Change the maximum amount of health - 4. Attack - 5. Weapon attack value - 6. Defense value - 7. Armor defense value - 8. The number of the room the person is in - 9. Amount of gold - 10. Number of killed monsters - 11. Equipped weapon - 12. Equipped armor - 13. Amount of time spent in the game - 14.].." << std::endl;
			std::cin >> Ma_fu;

			if (Ma_fu == "0") {

				std::cout << "..[You haven't selected a function].." << std::endl;

			}
			else if (Ma_fu == "1") {
				std::string name;
				
				while (true) {
				
				std::cout << "..[Enter a new name].." << std::endl;
				std::cin >> name;
				
				if (NorNam(name)) {
				
				zapis(0, name);
				break;

				}

			}

			}
			else if (Ma_fu == "2") {

				int lvl;

				std::cout << "..[Enter the desired level value].." << std::endl;
				
				if (!(std::cin >> lvl)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}
				
				if (lvl == 0) {

					std::cout << "..[The number cannot be equal to zero!].." << std::endl;


				}
				else if (lvl > 20) {

					std::cout << "..[The number is too large! The maximum is 20].." << std::endl;

				}
				else {

					zapis(1, std::to_string(lvl));
				}
				
				
			}
			else if (Ma_fu == "3") {

				int uz = 0;

				std::cout << "..[Enter the amount of health].." << std::endl;
				
				if (!(std::cin >> uz)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

				if (uz == 0) {

					std::cout << "..[The number cannot be equal to zero!].." << std::endl;
				}
				else if (uz > 99) {

					std::cout << "..[The number is too large! The maximum is 99].." << std::endl;
				}
				else {

					zapis(2, std::to_string(uz));


				}

			}
			
			else if (Ma_fu == "4") {

				int muz = 0;

				std::cout << "..[Enter your maximum health].." << std::endl;
				
				if (!(std::cin >> muz)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

				if (muz == 0) {

					std::cout << "..[The number cannot be equal to zero!].." << std::endl;
				}
				else if (muz > 99) {

					std::cout << "..[The number is too large! The maximum is 99].." << std::endl;
				}
				else {

					zapis(3, std::to_string(muz));
				}


			}

			else if (Ma_fu == "5") {

				int att = 0;

				std::cout << "..[Enter attack value].." << std::endl;
				
				if (!(std::cin >> att)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

				if (att == 0) {

					std::cout << "..[The number cannot be equal to zero!].." << std::endl;
				}
				else if (att > 99) {

					std::cout << "..[The number is too large! The maximum is 99].." << std::endl;
				}
				else {

					zapis(4, std::to_string(att));

				}

			}
				
			else if (Ma_fu == "6") {

				int attwe = 0;

				std::cout << "..[Enter the attack value of the weapon the person is equipped with].." << std::endl;
				
				if (!(std::cin >> attwe)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

				if (attwe == 0) {

					std::cout << "..[The number cannot be equal to zero!].." << std::endl;
				}
				else if (attwe > 99) {

					std::cout << "..[The number is too large! The maximum is 99].." << std::endl;
				}
				else {

					zapis(5, std::to_string(attwe));

				}

			}

			else if (Ma_fu == "7") {

				int prot = 0;

				std::cout << "..[Enter protection value].." << std::endl;
				
				if (!(std::cin >> prot)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

				if (prot == 0) {

					zapis(6, std::to_string(prot));
				}
				else if (prot > 99) {

					std::cout << "..[The number is too large! The maximum is 99].." << std::endl;
				}
				else {

					zapis(6, std::to_string(prot));

				}
				
				}

				else if (Ma_fu == "8") {

					int zasbron = 0;

					std::cout << "..[Enter the armor protection value].." << std::endl;
					
					if (!(std::cin >> zasbron)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

					if (zasbron == 0) {

						std::cout << "..[The number cannot be equal to zero!].." << std::endl;
					} else if (zasbron > 99) {

						std::cout << "..[The number is too large! The maximum is 99].." << std::endl;
					} else {

						zapis(7, std::to_string(zasbron));
					}
				} else if (Ma_fu == "10") {              //десять потому, что ты хочешь реализовать перемещение по комнатам позже

					int zolg;

					std::cout << "..[Enter the desired amount of gold].." << std::endl;
					
					if (!(std::cin >> zolg)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

					if (zolg == 0) {

						std::cout << "..[The number cannot be equal to zero!].." << std::endl;

					} else if (zolg > 9999) {

						std::cout << "..[The number is too large! The maximum is 9999].." << std::endl;

					} else {

						zapis(10, std::to_string(zolg));

					}



				} else if (Ma_fu == "11") {

					int killmons;

					std::cout << "..[Enter the number of monsters killed].." << std::endl;
					
					if (!(std::cin >> killmons)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

					if (killmons == 0) {

						std::cout << "..[The number cannot be equal to zero!].." << std::endl;

					} else if (killmons > 9999) {

						std::cout << "..[The number is too large! The maximum is 9999].." << std::endl;

					} else {

						zapis(12, std::to_string(killmons));

					}

				} else if (Ma_fu == "12") {

					std::string shorhi;

					std::cout << "..[Show list of all item IDs?].." << std::endl;
					std::cout << "..[Yes / No].." << std::endl;

					std::cin >> shorhi;
					
					if (shorhi == "No") {

						int idobj;
						
						std::cout << "..[Enter the ID for the item to be used as a weapon].." << std::endl;
						
						if (!(std::cin >> idobj)) {

						std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						
						continue;

						}
						
						if (idobj > 64) {

							std::cout << "..[You have entered an item ID that doesnt exist!].." << std::endl << std::endl;
							
							continue;

						} else if (idobj < 0) {

							std::cout << "..[You have entered an incorrect item ID!].." << std::endl << std::endl;
							
							continue;

						} else {

							zapis (28, std::to_string(idobj));

						}

					} else if (shorhi == "Yes") {
						
						int idobjws;
						
						IDItemList();

						std::cout << "..[Enter the ID for the item to be used as a weapon].." << std::endl;
						
						if (!(std::cin >> idobjws)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}
						
						if (idobjws > 64) {

							std::cout << "..[You have entered an item ID that doesnt exist!].." << std::endl << std::endl;
							
							continue;

						} else if (idobjws < 0) {

							std::cout << "..[You have entered an incorrect item ID!].." << std::endl << std::endl;
							
							continue;

						} else {

							zapis (28, std::to_string(idobjws));

						}
					}

				} else if (Ma_fu == "13") {

					std::string showitid;

					std::cout << "..[Show list of all item IDs?].." << std::endl;
					std::cout << "..[Yes / No].." << std::endl;

					std::cin >> showitid;

					if (showitid == "No") {

						int arwitidshow;

						std::cout << "..[Enter the ID of the item to be used as armor].." << std::endl;

						if (!(std::cin >> arwitidshow)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

						if (arwitidshow > 64) {

							std::cout << "..[You have entered an item ID that doesnt exist!].." << std::endl << std::endl;
							
							continue;

						} else if (arwitidshow < 0) {

							std::cout << "..[You have entered an incorrect item ID!].." << std::endl << std::endl;
							
							continue;

						} else {

							zapis(29, std::to_string(arwitidshow));

					}

				

				} else if (showitid == "Yes") {

					IDItemList();

					int aridshow;

						std::cout << "..[Enter the ID of the item to be used as armor].." << std::endl;

						if (!(std::cin >> aridshow)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

						if (aridshow > 64) {

							std::cout << "..[You have entered an item ID that doesnt exist!].." << std::endl << std::endl;
							
							continue;

						} else if (aridshow < 0) {

							std::cout << "..[You have entered an incorrect item ID!].." << std::endl << std::endl;
							
							continue;

						} else {

							zapis(29, std::to_string(aridshow));

				}

			}

			} else if (Ma_fu == "14") {

			int alltime;
			
			std::cout << "..[Enter the value for time played in seconds].." << std::endl;

			if (!(std::cin >> alltime)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

			if (alltime > 3236) {
			
			std::cout << "..[You should try speedrunning].." << std::endl << std::endl;

			zapis(548, std::to_string(alltime));
			
			} else { 
				
			zapis(548, std::to_string(alltime));

			}

		} else {

			std::cout << "..[There is no such function!].." << std::endl << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			continue;

		}

	}

		else if (func == "2") {

			std::string MSFI;
			
			std::cout << "..[View the list of item IDs, or proceed directly to overwriting the inventory?].." << std::endl;
		
		std::cout << "..[View Item ID List - VIIL / Skip directly to overwriting inventory - PDOI].." << std::endl << std::endl;

			std::cin >> MSFI;

		if (MSFI == "VIIL") {

		int Isn;
		
			std::cout << "..[Enter the inventory slot number].." << std::endl << std::endl;

		if (!(std::cin >> Isn)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (Isn <= 0) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (Isn > 8) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else {

				int nos = 10 + (Isn * 2);      //I couldnt think of this formula myself
				int II;
				
				IDItemList();
				
				std::cout << "..[Enter the ID of the item].." << std::endl;
				
				if (!(std::cin >> II)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (II < 0) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (II > 64) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else {



				zapis(nos, std::to_string(II));

				}

			}

		} else if (MSFI == "PDOI") {

		int Isn;
		
			std::cout << "..[Enter the inventory slot number].." << std::endl << std::endl;

		if (!(std::cin >> Isn)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (Isn <= 0) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (Isn > 8) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else {

				int nos = 10 + (Isn * 2);      //I couldnt think of this formula myself
				int II;
				
				std::cout << "..[Enter the ID of the item].." << std::endl;
				
				if (!(std::cin >> II)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (II < 0) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (II > 64) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else {

				zapis(nos, std::to_string(II));

				}

			}	

		}

	}
		
		else if (func == "3") {

			std::cout << "CHARActers (In development)" << std::endl;

		}
		
		else if (func == "4") {

			std::cout << "settings (In development)" << std::endl;

		}
		
		else if (func == "5") {

			std::cout << "save file (In development)" << std::endl;
		}
		
		else if (func == "6") {

			std::cout << "Unsa V2 Beta 1" << std::endl;

			std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

		}
		
		else {
			
			std::cout << "..[There is no such function].." << std::endl;

		}

	}

}