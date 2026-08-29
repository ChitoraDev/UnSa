#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <set>
#include "zip_file.hpp" //Thx for Minizip:https://github.com/zlib-ng/minizip-ng
#include <chrono>
#include <iomanip>
#include <sstream>
#include <windows.h>
#include <codecvt>
#include <map>
#include <iomanip>

namespace forf = std::filesystem;
using namespace miniz_cpp;

void zapis(int stroka, std::string znachenie, std::map<std::string, std::string>& settings) {

	char* localAppData = std::getenv("LOCALAPPDATA");
	char* locAppDat = std::getenv("LOCALAPPDATA");
	std::string UndP = std::string(locAppDat) + "\\UNDERTALE\\";

	if (localAppData == nullptr) {

		std::cout << "..[You don't have a save file! Try creating one by launching the game].." << std::endl;
        return;
	}
	
	if (settings["BackupC"] == "true") {
	
	if (locAppDat == nullptr) {

					std::cout << "..[You don't have a save file! Try creating one by launching the game].." << std::endl;
        			return;

	}

	std::string archname = "Undertale_Save.zip";

	try {
						
						zip_file archive;

						if (forf::exists(UndP + "file0")) archive.write(UndP + "file0", "file0");
						if (forf::exists(UndP + "file9")) archive.write(UndP + "file9", "file9");
						if (forf::exists(UndP + "undertale.ini")) archive.write(UndP + "undertale.ini", "undertale.ini");

						archive.save(archname);

						std::cout << "..[" << archname << " been backuped in directory, where exist Unsa].." << std::endl << std::endl;

						} catch (const std::exception& e) {

							std::cout << "..[Unknown error!].." << std::endl << std::endl;

						}

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

void RoomID() {

std::cout << "..[6: Ruins (1), 12: Ruins (7), 18: Cheese Room, 31: Ruins (17), 44: Tundra (1), 46: Tundra (3), 56: Spaghetti, 68: Snowdin (1), 83: Waterfall (2), 92: Waterfall (9), 110: Waterfall (21), 114: Trash Zone (2), 128: Waterfall (Temmie Village), 131: Waterfall (28), 139: Hotland (3), 145: Hotland (6), 155: Hotland (12), 164: Hotland (16), 183: Hotel Lobby, 196: Core (8), 210: Core (22), 216: New Home (1), 219: New Home (4), 231: Last Corridor, 232: New Home (6), 235: Throne Room, 236: Before the Barrier, 246: True Lab (2), 251: True Lab (7)].." << std::endl << std::endl;

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

bool ValidRoomID(int IDORise) {

std::set<int> VN = {

6, 12, 18, 31, 44, 46, 56, 68, 83, 92, 110, 114, 128, 131, 139, 
145, 155, 164, 183, 196, 210, 216, 219, 231, 232, 235, 236, 246, 251

};

return VN.count(IDORise) > 0;

}

std::string WSTOS(const std::wstring& wstr) {
    
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    
	return converter.to_bytes(wstr);

}

void chtenie (std::string Txt, int LinInd) {

	char* localAppData = std::getenv("LOCALAPPDATA");
    				
					if (localAppData == nullptr) {
        			
						std::cout << "..[Error of finding LOCALAPPDATA folder].." << std::endl;
        			
						return;

    				}

					std::string full_path = std::string(localAppData) + "\\UNDERTALE\\file0";
					std::ifstream in(full_path);
					
					if (!in.is_open()) {

						std::cout << "..[Error of reading file0!].." << std::endl << std::endl;

						return;

					}

					std::vector<std::string> lines;
    				std::string line;

					while (std::getline(in, line)) {
        				
						lines.push_back(line);

    				}
    				
					in.close();

					if (LinInd >= 0 && LinInd < lines.size()) {

						std::cout << "..[" << Txt << " = " << lines[LinInd] << "].." << std::endl;

					} else {

						std::cout << "..["<< Txt << "not found!].." << std::endl;

					}

			}

int FromLine(int LinInd) {
    
	char* localAppData = std::getenv("LOCALAPPDATA");
    
	if (localAppData == nullptr) {

		std::cout << "..[Error of finding LOCALAPPDATA folder].." << std::endl;
        			
		return -1;

	} 

    std::string full_path = std::string(localAppData) + "\\UNDERTALE\\file0";
    
	std::ifstream in(full_path);
    
	if (!in.is_open()) return -1;

    std::vector<std::string> lines;
    
	std::string line;
    
	while (std::getline(in, line)) {
        
		lines.push_back(line);
    
	}
    
	in.close();

    if (LinInd >= 0 && LinInd < lines.size()) {
        
		try {
            
            return std::stoi(lines[LinInd]);

        } catch (const std::exception&) {
            
            std::cout << "..[Unknown error!].." << std::endl;
        			
			return -1; 

        }
    
	}
    
	return -1;

}

std::map<std::string, std::string> LodSet() {

std::map<std::string, std::string> settings;
    char* localAppData = std::getenv("LOCALAPPDATA");
    if (localAppData == nullptr) return settings;

    forf::path ConPat = forf::path(localAppData) / "Unsa" / "config.txt";

	std::string line;

    std::ifstream inFile(ConPat);

	while (std::getline(inFile, line)) {
        
		size_t delimiterPos = line.find('=');
        
		if (delimiterPos != std::string::npos) {
            
			std::string key = line.substr(0, delimiterPos);
            
			std::string value = line.substr(delimiterPos + 1);
            
			settings[key] = value;
        
		}
    
	}
    
	return settings;

}

void NewCon(std::map<std::string, std::string>& NewSet) {

    char* localAppData = std::getenv("LOCALAPPDATA");
    if (localAppData == nullptr) {
        
		std::cout << "..[Error of finding LOCALAPPDATA folder!].." << std::endl;
        
		return;

    }

	forf::path ADD = forf::path(localAppData) / "Unsa";
	
	if (!forf::exists(ADD)) {
        
		forf::create_directories(ADD); 
    
	}

	auto settings = LodSet();

	for (const auto& [key, value] : NewSet) {
        
		settings[key] = value;
    
	}
    
    std::ofstream outFile(ADD / "config.txt", std::ios::trunc);
    for (const auto& [key, value] : settings) {
        outFile << key << "=" << value << "\n";
    }
}

void Appl(std::map<std::string, std::string>& settings) {
    
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (settings.count("ColorC")) {
        
		std::string color = settings["ColorC"];
        
		if (color == "1") SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        
		else if (color == "2") SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        
		else if (color == "3") SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        
		else if (color == "4") SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    
	}

	std::string back = settings["BackupC"];

	if (back == "true") {

		bool crbk = true;

	} else {

		bool crbk = false;

	}

}

void Ntime(int SavFilSec) {

char* localAppData = std::getenv("LOCALAPPDATA");
    std::string fio = std::string(localAppData) + "\\UNDERTALE\\file0";
    std::ifstream in(fio);
    std::vector<std::string> lines;
    std::string line;

	while (std::getline(in, line)) lines.push_back(line);

	if (SavFilSec >= 0 && SavFilSec < lines.size()) {
        int totalSeconds = std::stoi(lines[SavFilSec]);
        
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;

		std::cout << "Youve spent " << h << ":" << "0" << m << ":" << "0" << s << "].." << std::endl;

}

}

void exit() {

	std::cout << "..[Press Enter to return to menu].." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

}

int main() {
	
	std::setlocale(LC_ALL, "");
    std::wcin.imbue(std::locale(""));
    std::wcout.imbue(std::locale(""));
	
	forf::path configPath = forf::path(std::getenv("LOCALAPPDATA")) / "Unsa" / "config.txt";
    
	if (!forf::exists(configPath)) {
        
		std::map<std::string, std::string> initMap = {{"ColorC", "1"}, {"BackupC", "false"}};
        
		NewCon(initMap);

    }

	auto CurSet = LodSet();
	Appl(CurSet);
	
	while (true) {
		std::string func = "";

		std::cout << "........[Unsa]........" << std::endl;
		std::cout << "..[Select function].." << std::endl;
		std::cout << "..[Main data - 1. Inventory - 2. Settings - 3. Save file - 4.].." << std::endl;
		
		std::cin >> func;

		if (func == "0") {
			std::cout << "..[You haven't selected a function].." << std::endl;
		}
		else if (func == "1") {
			
			std::string Ma_fu = "";
			
			std::cout << "........[Main data]........" << std::endl;
			std::cout << "..[Select function].." << std::endl;
			std::cout << "..[Change the name of the fallen - 1. Change the level - 2. Change the amount of health - 3. Change the maximum amount of health - 4. Attack - 5. Weapon attack value - 6. Defense value - 7. Armor defense value - 8. The number of the room the person is in - 9. Amount of gold - 10. Number of killed monsters - 11. Equipped weapon - 12. Equipped armor - 13. Amount of time spent in the game - 14. Exit to menu - 15].." << std::endl;
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
				
				zapis(0, name, CurSet);
				
				exit();

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

					zapis(1, std::to_string(lvl), CurSet);

					exit();
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

					zapis(2, std::to_string(uz), CurSet);

					exit();

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

					zapis(3, std::to_string(muz), CurSet);

					exit();
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

					zapis(4, std::to_string(att), CurSet);

					exit();

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

					zapis(5, std::to_string(attwe), CurSet);

					exit();

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

					zapis(6, std::to_string(prot), CurSet);
				}
				else if (prot > 99) {

					std::cout << "..[The number is too large! The maximum is 99].." << std::endl;
				}
				else {

					zapis(6, std::to_string(prot), CurSet);

					exit();

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

						zapis(7, std::to_string(zasbron), CurSet);

						exit();

					}
				
				} else if (Ma_fu == "9") {

					std::string VS;

					std::cout << "..[Enter the list of room ID, or proceed directly to overwritting?].." << std::endl;
					std::cout << "..[View Room ID List - VRIL / Skip directly to overwriting - PDOS].." << std::endl;

					if (!(std::cin >> VS)) {

					std::cout << "..[You entered nothing!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

					} else if (VS == "VRIL") {

						int IDOR;
						
						RoomID();

						std::cout << "..[Enter the ID of room, where will be Frisk].." << std::endl;

						if (!(std::cin >> IDOR)) {

						std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
						continue;

						} else if (IDOR < 0 || IDOR > 251 || !ValidRoomID(IDOR)) {

						std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
						continue;

						} else {

						zapis(547, std::to_string(IDOR), CurSet);

						exit();

						}

					} else if (VS == "PDOS") {

						int IDOR;

						std::cout << "..[Enter the ID of room, where will be Frisk].." << std::endl;

						if (!(std::cin >> IDOR)) {

						std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
						continue;

						} else if (IDOR < 0 || IDOR > 251 || !ValidRoomID(IDOR)) {

						std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
						continue;

						} else {

						zapis(547, std::to_string(IDOR), CurSet);

						exit();

						}

					} else {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
						continue;

					}

				} else if (Ma_fu == "10") {

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

						zapis(10, std::to_string(zolg), CurSet);

						exit();

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

						zapis(12, std::to_string(killmons), CurSet);

						exit();

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

							zapis (28, std::to_string(idobj), CurSet);

							exit();

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

							zapis (28, std::to_string(idobjws), CurSet);

							exit();

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

							zapis(29, std::to_string(arwitidshow), CurSet);

							exit();

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

							zapis(29, std::to_string(aridshow), CurSet);

							exit();

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

			zapis(548, std::to_string(alltime), CurSet);

			exit();
			
			} else { 
				
			zapis(548, std::to_string(alltime), CurSet);

			exit();

			}
		
		} else if (Ma_fu == "15") {

			exit();
		
		}
		
		else {

			std::cout << "..[There is no such function!].." << std::endl << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			continue;

	}

}

		else if (func == "2") {

			std::string MSFI;
			
			std::cout << "........[Inventory]........" << std::endl;
			std::cout << "..[Select function].." << std::endl;
			std::cout << "..[View the list of item IDs, or proceed directly to overwriting the inventory?].." << std::endl;
		
		std::cout << "..[View Item ID List - 1. Skip directly to overwriting inventory - 2. Exit to menu - 3].." << std::endl << std::endl;

			std::cin >> MSFI;

		if (MSFI == "1") {

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

				zapis(nos, std::to_string(II), CurSet);

				exit();

				}

			}

		} else if (MSFI == "2") {

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

				zapis(nos, std::to_string(II), CurSet);

				exit();

				}

			}	

		} else if (MSFI == "3") {

			exit();

		}

	}	else if (func == "3") {

			int setfun;
			
			std::cout << "........[Settings]........" << std::endl;
			std::cout << "..[Select function].." << std::endl;
			std::cout << "..[Color of console - 1. Create a backup before overwritting - 2. Open settings folder - 3. About - 4.].." << std::endl;

			if (!(std::cin >> setfun)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (setfun <= 0) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (setfun > 5) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (setfun == 1) {

					int ColNum;
					
					std::cout << "..[Enter the color number].." << std::endl << "..[White - 1. Red - 2. Green - 3. Yellow - 4]..";

					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

					if (!(std::cin >> ColNum)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (ColNum <= 0) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (ColNum > 4) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (ColNum == 1) {

					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

					CurSet["ColorC"] = "1";
					NewCon(CurSet);

					exit();

				} else if (ColNum == 2) {

					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

					CurSet["ColorC"] = "2";
					NewCon(CurSet);

					exit();

				} else if (ColNum == 3) {

					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

					CurSet["ColorC"] = "3";
					NewCon(CurSet);

					exit();

				} else if (ColNum == 4) {

					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

					CurSet["ColorC"] = "4";
					NewCon(CurSet);

					exit();

				} else {

					std::cout << "..[This color is doesnt exist!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

				} else if (setfun == 2) {

					int BakBefOww;
					
					std::cout << "..[On = 1. Off = 2].." << std::endl;

					if (!(std::cin >> BakBefOww)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (BakBefOww <= 0) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (BakBefOww > 2) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (BakBefOww == 1) {

					CurSet["BackupC"] = "true";
					NewCon(CurSet);

					exit();

				} else if (BakBefOww == 2) {

					CurSet["BackupC"] = "false";
					NewCon(CurSet);

					exit();

				} else {

					std::cout << "..[This function is doesnt exist!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

				} else if (setfun == 3) {

				char* locAppDat = std::getenv("LOCALAPPDATA");
				std::string UndP = std::string(locAppDat) + "\\Unsa\\";
				
				std::string OpnConFol = "explorer " + UndP;
    			system(OpnConFol.c_str());

				exit();
				
				} else if (setfun == 4) {

					std::cout << "....................[UNSA]...................." << std::endl;
					std::cout << "..........[A program for editing Undertale save file].........." << std::endl;
					std::cout << "..........[Version: II].........." << std::endl;
					std::cout << "..........[By Chitora].........." << std::endl;
					std::cout << "..........[Youtube: https://www.youtube.com/@ChitoraMusic, Github: https://github.com/ChitoraDev, Discord: chitoramusic].........." << std::endl;

					exit();

				}

		}
		
		else if (func == "4") {

			int SVF;
			char* locAppDat = std::getenv("LOCALAPPDATA");
			std::string UndP = std::string(locAppDat) + "\\UNDERTALE\\";
			
			std::cout << "........[Save file]........" << std::endl;
			std::cout << "..[Select function].." << std::endl;
			std::cout << "..[Export - 1. Delete - 2. Clear - 3. Fix - 4. 5 - Read].." << std::endl;     //import isnt exist

			if (!(std::cin >> SVF)) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (SVF <= 0) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (SVF > 5) {

					std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				} else if (SVF == 1) {

					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					if (locAppDat == nullptr) {

					std::cout << "..[You don't have a save file! Try creating one by launching the game].." << std::endl;
        			continue;

					}
					
					std::string archname;
					
					std::cout << "..[Enter the name of archive with your save files (Default name: Undertale save)].." << std::endl;

					std::getline(std::cin, archname);

					if (archname.empty()) {

						archname = "Undertale_Save.zip";

					} else if (archname.find(".zip") == std::string::npos){

						archname += ".zip";

					}

					try {
						
						zip_file archive;

						if (forf::exists(UndP + "file0")) archive.write(UndP + "file0", "file0");
						if (forf::exists(UndP + "file9")) archive.write(UndP + "file9", "file9");
						if (forf::exists(UndP + "undertale.ini")) archive.write(UndP + "undertale.ini", "undertale.ini");

						archive.save(archname);

						std::cout << "..[" << archname << " been backuped in directory, where exist Unsa].." << std::endl << std::endl;

						exit();

						} catch (const std::exception& e) {

							std::cout << "..[Unknown error!].." << std::endl << std::endl;

						}

				} else if (SVF == 2) {

					std::string SaveDirDel;
					
					std::cout << "..[This action is unreversible! Are you sure?].." << std::endl << "Yes / No" << std::endl;

					if (!(std::cin >> SaveDirDel)) {

					std::cout << "..[You entered nothing!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

					} else if (SaveDirDel == "Yes") {

						try {

							if (forf::remove_all(UndP) > 0) {

								std::cout << "..[UNDERTALE folder and its content has been deleted!].." << std::endl << std::endl;

								exit();

							} else {

								std::cout << "..[UNDERTALE folder, possible, has been deleted before!].." << std::endl << std::endl;

								exit();

							}

						} catch (const forf::filesystem_error) {

							std::cout << "..[Error of deleting UNDERTALE folder and its content!].." << std::endl << std::endl;

							exit();

						}

					} else if (SaveDirDel == "No") {

						break;

					}

				} else if (SVF == 3) {

					std::string SaveFilClr;
					
					std::cout << "..[This action is unreversible! Are you sure?].." << std::endl << "Yes / No" << std::endl;

					if (!(std::cin >> SaveFilClr)) {

					std::cout << "..[You entered nothing!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

					} else if (SaveFilClr == "Yes") {

						try {

							bool del = false;
							
							for (const auto& entry : forf::directory_iterator(UndP)) {

								if (entry.path().filename() != "undertale.ini") {

									forf::remove_all(entry.path());
									
									del = true;

								}

							} 

							bool clnini = false;

							std::ofstream IniFil(UndP + "undertale.ini", std::ios::trunc);

							if (IniFil.is_open()) {

								IniFil << "[General]" << "\n" << "fun=\"70.000000\"";

								IniFil.close();

								clnini = true;

							}

							if (del == true && clnini == true) {

								std::cout << "..[Save files was been clean!].." << std::endl << std::endl;

								exit();

							} else if (del == false && clnini == true) {

								std::cout << "..[Error of deleting files except undertale.ini!].." << std::endl << std::endl;

								exit();

							} else if (del == true && clnini == false) {

								std::cout << "..[Error of reseting undertale.ini!].." << std::endl << std::endl;

								exit();

							} else {

							std::cout << "..[Unknown error!].." << std::endl << std::endl;	

							exit();

							}

						} catch (const forf::filesystem_error) {

							std::cout << "..[Unknown error!].." << std::endl << std::endl;

							exit();

						}

					} else if (SaveFilClr == "No") {

						break;

					} else {

					std::cout << "..[Just enter Yes or No].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

					}

				} else if (SVF == 4) {

					std::string BackupBeforeFix;
					
					std::cout << "..[Do you need create a backup?].." << std::endl << "Yes / No" << std::endl;

					if (!(std::cin >> BackupBeforeFix)) {

					std::cout << "..[You entered nothing!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

					} else if (BackupBeforeFix == "Yes") {

						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
						if (locAppDat == nullptr) {

							std::cout << "..[You don't have a save file! Try creating one by launching the game].." << std::endl;

        					continue;

						}
					
						std::string archname;
					
						std::cout << "..[Enter the name of archive with your save files (Default name: Undertale save)].." << std::endl;

						std::getline(std::cin, archname);

						if (archname.empty()) {

							archname = "Undertale_Save.zip";

						} else if (archname.find(".zip") == std::string::npos){

							archname += ".zip";

						}

						try {
						
							zip_file archive;

							if (forf::exists(UndP + "file0")) archive.write(UndP + "file0", "file0");
							if (forf::exists(UndP + "file9")) archive.write(UndP + "file9", "file9");
							if (forf::exists(UndP + "undertale.ini")) archive.write(UndP + "undertale.ini", "undertale.ini");

							archive.save(archname);

							std::cout << "..[" << archname << " been backuped in directory, where exist Unsa].." << std::endl << std::endl;

							exit();

							} catch (const std::exception& e) {

								std::cout << "..[Unknown error!].." << std::endl << std::endl;

							}

						int Roomy = FromLine(547);
						
						chtenie("..[Checking of room. Please wait!]..", 547);

						if (Roomy < 0 || Roomy > 251 || !ValidRoomID(Roomy)) {

							std::string FriskHaveProblems;
							
							std::cout << "..[Frisk was found in invalid room! What you want do?].." << std::endl <<"..[Set Frisk on valid room - FTVR, Clear save file - CLRS].." << std::endl;

							if (!(std::cin >> FriskHaveProblems)) {

							std::cout << "..[You entered nothing!].." << std::endl << std::endl;
					
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
							continue;

							} else if (FriskHaveProblems == "FTVR") {

								std::string VS;

								std::cout << "..[Enter the list of room ID, or proceed directly to overwritting?].." << std::endl;
								std::cout << "..[View Room ID List - VRIL / Skip directly to overwriting - PDOS].." << std::endl;

								if (!(std::cin >> VS)) {

									std::cout << "..[You entered nothing!].." << std::endl << std::endl;
					
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
									continue;

								} else if (VS == "VRIL") {

									int IDOR;
						
									RoomID();

									std::cout << "..[Enter the ID of room, where will be Frisk].." << std::endl;

									if (!(std::cin >> IDOR)) {

										std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
										std::cin.clear();
										std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
										continue;

									} else if (IDOR < 0 || IDOR > 251 || !ValidRoomID(IDOR)) {

									std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
									continue;

									} else {

										zapis(547, std::to_string(IDOR), CurSet);

										exit();

									}

								} else if (VS == "PDOS") {

								int IDOR;

								std::cout << "..[Enter the ID of room, where will be Frisk].." << std::endl;

								if (!(std::cin >> IDOR)) {

									std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
									continue;

								} else if (IDOR < 0 || IDOR > 251 || !ValidRoomID(IDOR)) {

									std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
									continue;

								} else {

									zapis(547, std::to_string(IDOR), CurSet);

									exit();

								}

								} else {

									std::cout << "..[You entered an invalid value!].." << std::endl << std::endl;
					
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
									continue;

								}

							} else if (FriskHaveProblems == "CLRS") {

								std::string SaveFilClr;
					
								std::cout << "..[This action is unreversible! Are you sure?].." << std::endl << "Yes / No" << std::endl;

								if (!(std::cin >> SaveFilClr)) {

									std::cout << "..[You entered nothing!].." << std::endl << std::endl;
					
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
									continue;

								} else if (SaveFilClr == "Yes") {

									try {

										bool del = false;
							
										for (const auto& entry : forf::directory_iterator(UndP)) {

										if (entry.path().filename() != "undertale.ini") {

										forf::remove_all(entry.path());
									
										del = true;

									}

								} 

								bool clnini = false;

								std::ofstream IniFil(UndP + "undertale.ini", std::ios::trunc);

								if (IniFil.is_open()) {

									IniFil << "[General]" << "\n" << "fun=\"70.000000\"";

									IniFil.close();

									clnini = true;

								}

								if (del == true && clnini == true) {

									std::cout << "..[Save files was been clean!].." << std::endl << std::endl;

									exit();

								} else if (del == false && clnini == true) {

									std::cout << "..[Error of deleting files except undertale.ini!].." << std::endl << std::endl;

									exit();

								} else if (del == true && clnini == false) {

									std::cout << "..[Error of reseting undertale.ini!].." << std::endl << std::endl;

									exit();

								} else {

									std::cout << "..[Unknown error!].." << std::endl << std::endl;	

									exit();

								}

							} catch (const forf::filesystem_error) {

								std::cout << "..[Unknown error!].." << std::endl << std::endl;

								exit();

							}

						} else if (SaveFilClr == "No") {

							break;

						} else {

							std::cout << "..[Just enter Yes or No].." << std::endl << std::endl;
					
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
							continue;

								}

							}

						}

					}
					
					exit();

				} else if (SVF == 5) {

					std::string WithItID;

					std::cout << "..[Do you need Item ID List?].." << std::endl <<"Yes / No" << std::endl;

					if (!(std::cin >> WithItID)) {

					std::cout << "..[You entered nothing!].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

					} else if (WithItID == "Yes") {
					
					chtenie ("Your name", 0);

					chtenie ("Your level", 1);

					chtenie ("Your HP", 2);

					chtenie ("Your max HP", 3);

					chtenie ("Your value of attack", 4);

					chtenie ("Your value of defeat", 6);

					chtenie ("Your value of experience", 9);

					chtenie ("Your amount of gold", 10);

					chtenie ("How many monsters you kill", 11);

					chtenie ("Your weapon attack value", 5);

					chtenie ("Your armor defense value", 7);

					chtenie ("Your human is located in room at number", 547);

					chtenie ("For attack you use with ID", 28);

					chtenie ("For defeat you use with ID", 29);

					Ntime(548);

					IDItemList;
					
					exit();

				} else if (WithItID == "No") {

					chtenie ("Your name", 0);

					chtenie ("Your level", 1);

					chtenie ("Your HP", 2);

					chtenie ("Your max HP", 3);

					chtenie ("Your value of attack", 4);

					chtenie ("Your value of defeat", 6);

					chtenie ("Your value of experience", 9);

					chtenie ("Your amount of gold", 10);

					chtenie ("How many monsters you kill", 11);

					chtenie ("Your weapon attack value", 5);

					chtenie ("Your armor defense value", 7);

					chtenie ("Your human is located in room at number", 547);

					chtenie ("For attack you use with ID", 28);

					chtenie ("For defeat you use with ID", 29);

					Ntime(548);
					
					exit();

				} else {

					std::cout << "..[Just enter Yes or No].." << std::endl << std::endl;
					
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					
					continue;

				}

			}

		}
		
		else {
			
			std::cout << "..[There is no such function].." << std::endl;

			std::cin.clear();
    		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    		break;

		}

	}

}
