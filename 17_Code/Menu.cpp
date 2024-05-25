#include "Menu.h"

//moving in the console
void Menu::Coord(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//print error
void Menu::Error() {
    std::cerr << "error, please try one more time: ";
}

//select menu item
void Menu::Choice(int choice) {
    system("cls");
    for (int i = (1 + 1); i <= (110 - 1); i++)
        cout << "\315";
    cout << "\n\n";
    switch (choice) {
    case 1:
        CreateHospital();
        break;
    case 2:
        CreateClinic();
        break;
    case 3:
        if (lst.Empty()) {
            cout << "list is empty\n\n";
            break;
        }
        lst.Output(cout);
        break;
    case 4:
        if (lst.Empty()) {
            cout << "list is empty\n\n";
            break;
        }
        lst.Delete();
        cout << "Medical institutions were deleted\n\n";
        break;
    case 5:
        if (lst.Empty()) {
            cout << "list is empty\n\n";
            break;
        }
        OutputListToFile();
        cout << "Medical institutions were outputed to the file\n\n";
        break;
    case 6:
        InputListFromFile();
        if (lst.Empty()) {
            cout << "list is empty\n\n";
            break;
        }
        cout << "Medical institutions were loaded from the file\n\n";
        break;
    case 7:
        if (lst.Empty()) {
            cout << "list is empty\n\n";
            break;
        }
        lst.Sort();
        cout << "Medical institutions were sorted by city\n\n";
        break;
    case 8:
        if (lst.Empty()) {
            cout << "list is empty\n\n";
            break;
        }
        DoTask();
        break;
    case 9:
        exit(0);
        break;
    }
    for (int i = (1 + 1); i <= (110 - 1); i++)
        cout << "\315";
    cout << "\n\n";
    system("pause");
    Run();
}

//checking a string for numbers
bool Menu::IsDigit(const string value) {
	bool flag = true;
	std::locale loc;
	for (unsigned int i = 0; i < value.size(); i++)
		if (!isdigit(value.at(i), loc)) {
			flag = false;
			break;
		}
	return flag;
}

//start 
void Menu::Begin() {
    Frame(1, 1, 110, 25, 1);
    Run();
}

//returns an integer from a string
int Menu::InputInt() {
    string temp;
    cin >> temp;
    while (!IsDigit(temp)) {
        Error();
        cin >> temp;
    }
    int choice = stoi(temp);
    cout << "\n";
    while (choice < 0) {
        Error();
        cin >> temp;
        while (!IsDigit(temp)) {
            Error();
            cin >> temp;
        }
        choice = stoi(temp);
        cout << "\n";
    }
    return choice;
}

//output list to the file
void Menu::OutputListToFile() {
    std::ofstream out;
    out.open("database_output.txt", std::ios::out);
    if (!out.is_open()) {
        std::cerr << "\nerror output file\n";
        return;
    }
    lst.Output(out);
    out.close();
}

//input list to the file
void Menu::InputListFromFile() {
    std::ifstream in;
    in.open("database_input.txt", std::ios::in);
    if (!in.is_open()) {
        std::cerr << "\nerror input file\n";
        return;
    }
    lst.Input(in);
    in.close();
}

//count doctors by city
void Menu::DoTask() {
    cout << "Reminder: for correct work you need to sort the list\n\n";
    cout << "Input the city where you want to count doctors: ";
    int task = 0;
    string str;
    cin >> str;
    cout << "\n";
    while (str.empty()) {
        Error();
        cin >> str;
        cout << "\n";
    }
    task = lst.Task(str);
    if (task < 0)
        return;
    else {
        cout << "\nThe task was completed\n";
        cout << "The number of doctors is: " << task << "\n\n";
    }
}

//create a Hospital object
void Menu::CreateHospital() {
    string str;
    cout << "Input information about the hospital: \n\n";
    Hospital *hosp = new Hospital;
    cout << "Input the name of the city: ";
    cin >> str;
    cout << "\n";
    while (str.empty()) {
        Error();
        cin >> str;
        cout << "\n";
    }
    hosp->SetCity(str);
    cout << "Input the number of doctors: ";
    hosp->SetDoctors(InputInt());
    cout << "Input the hospital rank: ";
    hosp->SetRank(InputInt());
    cout << "Input the number of hospitalized patients: ";
    hosp->SetHospitalPatients(InputInt());
    cout << "Input the number of free places in the hospital: ";
    hosp->SetFreePlaces(InputInt());
    lst.Push(hosp);
}

//create a Clinic object
void Menu::CreateClinic() {
    string str;
    cout << "Input information about the clinic: \n\n";
    Clinic *cl = new Clinic;
    int temp = 0;
    cout << "Input the name of the city: ";
    cin >> str;
    cout << "\n";
    while (str.empty()) {
        Error();
        cin >> str;
        cout << "\n";
    }
    cl->SetCity(str);
    cout << "Input the number of doctors: ";
    cl->SetDoctors(InputInt());
    cout << "Input the hospital rank: ";
    cl->SetRank(InputInt());
    cout << "Input the number of patients per day: ";
    cl->SetDayPatients(InputInt());
    lst.Push(cl);
}

//input menu item
void Menu::Run() {
    Info();
    string str;
    cin >> str;
    while (!IsDigit(str)) {
        Error();
        cin >> str;
    }
    int choice = stoi(str);
    while (choice < 1 || choice > 9) {
        Error();
        cin >> str;
        while (!IsDigit(str)) {
            Error();
            cin >> str;
        }
        choice = stoi(str);
    }
    Choice(choice);
}

//output frame to console
void Menu::Frame(int x1, int y1, int x2, int y2, int print) {
    int i = 0;
    Coord(x1, y1);
    cout << "\311";
    for (i = (x1 + 1); i <= (x2 - 1); i++) {
        cout << "\315";
        if (print == 1)
            Sleep(1);
    }
    cout << "\273";
    for (i = (y1 + 1); i <= (y2 - 1); i++) {
        Coord(x1, i);
        cout << "\272";
        if (print == 1)
            Sleep(1);
        Coord(x2, i);
        cout << "\272";
        if (print == 1)
            Sleep(1);
    }
    Coord(x1, y2);
    cout << "\310";
    for (i = (x1 + 1); i <= (x2 - 1); i++) {
        cout << "\315";
        if (print == 1)
            Sleep(1);
    }
    cout << "\274";
}

//info about menu items
void Menu::Info() {
    system("cls");
    Frame(1, 1, 110, 25, 0);
    Coord(15, 3);
    cout << "<========================================MENU========================================>";
    Coord(20, 5);
    cout << "<1> Create a hospital\n";
    Coord(20, 7);
    cout << "<2> Create a clinic\n";
    Coord(20, 9);
    cout << "<3> Display medical institutions\n";
    Coord(20, 11);
    cout << "<4> Remove medical institutions\n";
    Coord(20, 13);
    cout << "<5> Save the list to the file\n";
    Coord(20, 15);
    cout << "<6> Load the list from the file\n";
    Coord(20, 17);
    cout << "<7> Sort medical institutions\n";
    Coord(20, 19);
    cout << "<8> Do request\n";
    Coord(20, 21);
    cout << "<9> Exit\n";
    Coord(20, 27);
    cout << "Choice: ";
}