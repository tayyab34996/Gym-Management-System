#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <conio.h>
#define RESET   "\033[0m"
#define RED     "\033[91m"    // Light Red
#define GREEN   "\033[92m"    // Light Green
#define YELLOW  "\033[93m"    // Light Yellow
#define BLUE    "\033[94m"    // Light Blue
#define BLUE    "\033[94m"    // Light Blue
#define MAGENTA "\033[95m"    // Light Magenta
#define CYAN    "\033[96m"    // Light Cyan
using namespace std;
string memType[5] = { "BRONZE","SILVER","GOLD","PLATINUM","DIAMOND"};
bool checkmemType(string type) {
    for (int i = 0; type[i] != '\0'; i++) {
        type[i] = toupper(type[i]);
    }
    for(int i=0;i<5;i++) {
        if (type == memType[i]) { return true; }
    }
    return false;
}
string datetostring(int d, int m, int y) {
    if (d < 0 || d>31 || m < 0 || m>12 || y < 0 || y>2030) {return ""; }
    else { stringstream ss;
        ss << d << "-" << m << "-" << y;
        return ss.str();
    }
}
bool comparedate(int d, int m, int y, int d1, int m1, int y1) {
    if ((d < d1)||(m<m1)||(y<y1)) { return true; }
    else { return false; }
}

class Attendance {
private:
    string membertype, date; int memberId; bool present;
public:
    void markattendance(int memberId, const string& date, string membertype, bool present) {
        ofstream att("attendence1.txt", ios::app); // Open file in append mode
        if (att.is_open()) {
            att << memberId << " " << date << " " << (present ? "Present" : "Absent") << endl;//if present then mark present otherwise absent
            att.close();
            cout << "Attendance marked successfully for Member ID: " << memberId << endl;
        }
        else
            cout << "Unable to open file for writing attendance." << endl;
    }
    void displayAttendance() {
        ifstream attFile("attendence1.txt");
        if (attFile.is_open()) {
            string line;
            while (getline(attFile, line)) {
                cout << line << endl;
            }
            attFile.close();
        }
        else
            cout << "Unable to open the attendance file." << endl;
    }
    void markstaffattendance(string name, const string& date, bool present) {
        ofstream att("attendence2.txt", ios::app); // Open file in append mode
        if (att.is_open()) {
            att << name << " " << date << " " << (present ? "Present" : "Absent") << endl; att.close();
            cout << "Attendance marked successfully for : " << name << endl;
        }
        else
            cout << "Unable to open file for writing attendance." << endl;
    }
    void displaystaffAttendance() {
        ifstream attFile("attendence2.txt");
        if (attFile.is_open()) {
            string line;
            while (getline(attFile, line)) {
                cout << line << endl;
            } attFile.close();
        }
        else
            cout << "Unable to open the attendance file." << endl;
    }
};
class gymtiming {
    string maletimings, femaletimings, coedtimings;
public:
    gymtiming() {
        maletimings = "8:00 PM - 11:59 PM"; femaletimings = "8:00 AM - 11:59 AM"; coedtimings = "1:00 PM - 4:00 PM";
        saveTimings();
    }
    void setTimings() {
        cin.ignore();
        cout << "Enter Male timings: "; getline(cin, maletimings);
        cout << "Enter Female timings: "; getline(cin, femaletimings);
        cout << "Enter Co-ed timings: "; getline(cin, coedtimings);
        cout << "Timings updated successfully" << endl; saveTimings();
    }
    void displayTimings() const {
        cout << "Gym Timings:\n" << "Male Only: " << maletimings << endl << "Female Only: " << femaletimings << endl << "Co-ed: " << coedtimings << endl;
    }
    void saveTimings() const {
        ofstream outfile("timings.txt");
        if (outfile.is_open()) {
            outfile << maletimings << endl; outfile << femaletimings << endl; outfile << coedtimings << endl;
            outfile.close();
        }
        else
            cout << "Error: Unable to save timings to file." << endl;
    }
};
class Feestructure {
private:
    int Trainerfees, yogafees, mmafees, zumbafees, aerobicsfees, swimmingfees;
public:
    Feestructure() {
        cout << BLUE;
        Trainerfees = 5000; yogafees = 10000;  mmafees = 10000; zumbafees = 5000; aerobicsfees = 10000; swimmingfees = 5000;
        saveFeestructure();
    }
    void setfees() {
        bool running = true;
        int newfees, choice = 0;
        while (running) {
            choice = 0;
            cout << "\nEdit Fees Structure:\n1.Trainer\n2.Yoga\n3.MMA\n4.Zumba\n5.Aerobics\n6.Swimming\n";
            cout << "Enter Activity you want to change Fees of: ";
            cin >> choice;
            switch (choice) {
            case 1: {
                cout << "Enter new Fees: "; cin >> newfees;
                Trainerfees = newfees;
                break;
            }
            case 2: {
                cout << "Enter new Fees: "; cin >> newfees;
                yogafees = newfees;
                break;
            }
            case 3: {
                cout << "Enter new Fees: "; cin >> newfees;
                mmafees = newfees;
                break;
            }
            case 4: {
                cout << "Enter new Fees: "; cin >> newfees;
                zumbafees = newfees;
                break;
            }
            case 5: {
                cout << "Enter new Fees: "; cin >> newfees;
                aerobicsfees = newfees;
                break;
            }
            case 6: {
                cout << "Enter new Fees: "; cin >> newfees;
                swimmingfees = newfees;
                break;
            }
            default: {
                cout << "Invalid choice!\n";
                break;
            }
            }
            if (running) {
                char continueChoice;
                cout << "\nDo you want to continue? (Y/N): "; cin >> continueChoice;
                if (continueChoice != 'Y' && continueChoice != 'y') {
                    saveFeestructure();
                    running = false;
                }
            }
        }
    }
    void saveFeestructure() const {
        ofstream outfile("fees.txt");
        if (outfile.is_open()) {
            outfile << Trainerfees << endl; outfile << yogafees << endl; outfile << mmafees << endl; outfile << zumbafees << endl; outfile << aerobicsfees << endl;
            outfile << swimmingfees << endl;
            outfile.close();
        }
        else
            cout << "Error: Unable to save timings to file." << endl;
    }
    void displayfees() {
        cout << "Fees Structure: \n" << "Trainer Fees: " << Trainerfees << endl << "Yoga Fees: " << yogafees << endl << "MMA Fees: " << mmafees << endl;
        cout << "Zumba Fees: " << zumbafees << endl << "Aerobics Fees: " << aerobicsfees << endl << "Swimming Fees: " << swimmingfees << endl;
    }
};
class Person {
protected:
    string name;
    int age;
public:
    Person(string name, int age) : name(name), age(age) {}
    virtual void display() const = 0;  // Making display a pure virtual function
    string getName() const { return name; }
    int getAge() const { return age; }
};
class Member : public Person {
private:
    int memberId;
    string membershipType, joiningDate, expiryDate;
public:
    void setName(const string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    void setMembershipType(const string& newType) { membershipType = newType; }
    void setJoiningDate(const string& newDate) { joiningDate = newDate; }
    void setExpiryDate(const string& newDate) { expiryDate = newDate; }
    Member(string name, int age, int memberId, string membershipType, string joiningDate, string expiryDate)
        : Person(name, age), memberId(memberId), membershipType(membershipType), joiningDate(joiningDate), expiryDate(expiryDate) {
    }
    void display() const override {
        cout << "Name: " << name << ", Age: " << age << endl;
        cout << "Member ID: " << memberId << ", Membership Type: " << membershipType << ", Joining Date: " << joiningDate << ", Expiry Date: " << expiryDate << endl;
    }
    int getId() const { return memberId; }
    string getMembershipType() const { return membershipType; }
    string getJoiningDate() const { return joiningDate; }
    string getExpiryDate() const { return expiryDate; }
};
class Trainer : public Person {
private:
    int trainerId;
public:
    Trainer(string name, int age, int trainerId) : Person(name, age), trainerId(trainerId) {}
    void setName(const string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    void display() const override { //overriding display function
        cout << "Name: " << name << ", Age: " << age << endl;
        cout << "Trainer ID: " << trainerId << endl;
    }
    int getTrainerId() const { return trainerId; }
};
class Staff : public Person {
private:
    int id; // Ensure this member is present if you wish to use getId() method
    string job;
    double fees;
public:
    Staff(string name, int id, string job, int age, double fees) : Person(name, age), id(id), job(job), fees(fees) {}
    int getId() const { return id; }  // Define getId method
    string getJob() const { return job; }
    double getFees() const { return fees; }
    void setId(int newId) { id = newId; } // If needed, setter for ID
    void setName(const string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    void setJob(const string& newJob) { job = newJob; }
    void setFees(double newFees) { fees = newFees; }
    void display() const override { //again overriding 
        cout << "Name: " << name << ", ID: " << id << endl << "Job: " << job << "Age : " << age << ", Fees: $" << fees << endl;
    }
};
class Equipment {
private:
    string equipmentName;
    int equipmentId;
public:
    Equipment(string equipmentName, int equipmentId) : equipmentName(equipmentName), equipmentId(equipmentId) {}
    void display() const {
        cout << "Equipment Name: " << equipmentName << ", Equipment ID: " << equipmentId << endl;
    }
    void setEquipmentName(string name) { equipmentName = name; }
    string getEquipmentName() const { return equipmentName; }
    int getEquipmentId() const { return equipmentId; }
};
class Session {
private:
    int sessionId; string sessionType, dateTime;
public:
    Session(int sessionId, string sessionType, string dateTime) : sessionId(sessionId), sessionType(sessionType), dateTime(dateTime) {}
    void display() const { cout << "Session ID: " << sessionId << ", Type: " << sessionType << ", Date/Time: " << dateTime << endl; }
    int getSessionId() const { return sessionId; }
    string getSessionType() const { return sessionType; }
    string getDateTime() const { return dateTime; }
};
class Payment {
private:
    int paymentId; double amount; string date;
public:
    Payment(int paymentId, double amount, string date) : paymentId(paymentId), amount(amount), date(date) {}
    void display() const { cout << "Payment ID: " << paymentId << ", Amount: $" << amount << ", Date: " << date << endl; }
    int getPaymentId() const { return paymentId; }
    double getAmount() const { return amount; }
    string getDate() const { return date; }
};
class GymManagement {
private:
    Feestructure r;
    static const int maxMembers = 100, maxTrainers = 50, maxStaff = 10, maxEquipments = 100, maxSessions = 200, maxPayments = 300;
    Member* members[maxMembers]; Trainer* trainers[maxTrainers]; Staff* staff[maxStaff]; Equipment* equipments[maxEquipments];
    Session* sessions[maxSessions]; Payment* payments[maxPayments];
    int numMembers = 0, numTrainers = 0, numStaff = 0, numEquipments = 0, numSessions = 0, numPayments = 0;
    gymtiming g1; Attendance a1;
public:
    GymManagement() { loadAllData(); }
    ~GymManagement() {
        saveAllData();
        clearAllData();
    }
    void attendance(int id) {
        string type, date;
        cout << "Enter todays date :"; cin >> date;
        a1.markattendance(id, date, type, true);
    }
    void loadAllData() { loadMembers(); loadTrainers(); loadStaff(); loadEquipments(); loadSessions(); loadPayments(); }
    void saveAllData() { saveMembers(); saveTrainers(); saveStaff(); saveEquipments(); saveSessions(); savePayments(); }
    void clearAllData() {
        for (int i = 0; i < numMembers; i++) delete members[i];
        for (int i = 0; i < numTrainers; i++) delete trainers[i];
        for (int i = 0; i < numStaff; i++) delete staff[i];
        for (int i = 0; i < numEquipments; i++) delete equipments[i];
        for (int i = 0; i < numSessions; i++) delete sessions[i];
        for (int i = 0; i < numPayments; i++) delete payments[i];
        numMembers = numTrainers = numStaff = numEquipments = numSessions = numPayments = 0;
    }
    //TRAINER                     TRAINER
    void addTrainer(Trainer* t) {
        if (numTrainers < maxTrainers) {
            trainers[numTrainers++] = t;
            saveTrainers();
        }
    }
    void saveTrainers() {
        ofstream outFile("trainer.txt", ios::app);
        outFile << trainers[numTrainers - 1]->getName() << " " << trainers[numTrainers - 1]->getAge() << " " << trainers[numTrainers - 1]->getTrainerId() << "\n";
        outFile.close();
    }
    void showAllTrainers() {
        loadTrainers();
        cout << "All Trainers:" << endl;
        for (int i = 0; i < numTrainers; i++) { trainers[i]->display(); }
    }
    void loadTrainers() {
        ifstream inFile("trainer.txt");
        string name;
        int age, trainerId;
        if (!inFile) {
            cerr << "Error opening file for reading!" << endl; return;
        }
        numTrainers = 0; // Reset before loading
        while (getline(inFile, name, ' ') && inFile >> age >> trainerId) {
            inFile.ignore(); // Ignore leftover newline
            trainers[numTrainers++] = new Trainer(name, age, trainerId);
        }
        inFile.close();
    }
    void updateTrainer(int trainerId) {
        bool found = false;  string name; int age;
        loadTrainers();
        for (int i = 0; i < numTrainers; ++i) {
            if (trainers[i]->getTrainerId() == trainerId) {
                found = true;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//clear buffer
                cout << "Enter new Name: ";  getline(cin, name);
                trainers[i]->setName(name);
                cout << "Enter new Age: ";
                while (true) {
                    cin >> age;
                    if (age > 18 && age < 100) {
                        trainers[i]->setAge(age); break;
                    }
                    else
                        cout << "Invalid age. Please enter an age between 18 and 100.\n";
                }
                cout << "Trainer details updated successfully.\n";
                ofstream outFile("trainer.txt");
                for (int j = 0; j < numTrainers; ++j) {
                    outFile << trainers[j]->getName() << " " << trainers[j]->getAge() << " " << trainers[j]->getTrainerId() << "\n";
                }
                outFile.close(); break;
            }
        }
        if (!found) { cout << "Trainer ID not found.\n"; }
    }
    void deleteTrainer(int trainerId) {
        for (int i = 0; i < numTrainers; ++i) {
            if (trainers[i]->getTrainerId() == trainerId) {
                delete trainers[i];//delete the given space
                for (int j = i; j < numTrainers - 1; ++j) {
                    trainers[j] = trainers[j + 1];
                }
                numTrainers--;
                ofstream outFile("trainer.txt");
                for (int j = 0; j < numTrainers; ++j) {
                    outFile << trainers[j]->getName() << " " << trainers[j]->getAge() << " " << trainers[j]->getTrainerId() << "\n";
                }
                outFile.close();
                cout << "Trainer deleted successfully.\n";
                return;
            }
        }
        cout << "Trainer ID not found.\n";
    }                                                 //MEMBERS                    MEMBERS
    void addMember(Member* m) {
        if (numMembers < maxMembers) {
            members[numMembers++] = m;
            saveMembers();
        }
    }
    void loadMembers() {
        string name, membershipType, joiningDate, expiryDate;
        int age, memberId;
        ifstream inFile("members.txt");
        if (!inFile) {
            cerr << "Error opening file for reading!" << endl;
            return;
        }
        numMembers = 0;
        while (inFile >> ws && getline(inFile, name, ' ')) {
            inFile >> age >> memberId; inFile >> ws;
            getline(inFile, membershipType, ' '); getline(inFile, joiningDate, ' '); getline(inFile, expiryDate);
            members[numMembers++] = (new Member(name, age, memberId, membershipType, joiningDate, expiryDate));
        }  inFile.close();
    }
    void saveMembers() {
        ofstream outFile("members.txt", ios::app);
        outFile << members[numMembers - 1]->getName() << " " << members[numMembers - 1]->getAge() << " " << members[numMembers - 1]->getId() << " "
            << members[numMembers - 1]->getMembershipType() << " " << members[numMembers - 1]->getJoiningDate() << " " << members[numMembers - 1]->getExpiryDate() << "\n";
        outFile.close();
    }
    void showAllMembers() {
        loadMembers();
        cout << "All Members:" << endl;
        for (int i = 0; i < numMembers; i++) { members[i]->display(); }
    }
    void memberdisplay() {
        loadMembers(); // Load embers data
        int searchid, choice; char cont;
        cout << BLUE << "Welcome to Our Gym " << endl;
        while (true) {
            cout << MAGENTA << "Enter your Membership ID: ";
            cin >> searchid;
            bool found = false;// Search for the member with the entered ID
            for (int i = 0; i < numMembers; ++i) {
                if (members[i]->getId() == searchid) {
                    found = true;
                    cout << RESET << "Welcome, " << members[i]->getName() << "!" << endl << CYAN;
                    cout << "What would you like to do?" << endl << "1. View Trainer details" << endl << "2. Mark Attendance" << endl;
                    cout << "3. View Gym Timings" << endl << "4. Make Fee Payment" << endl;
                    cout << RESET << "Enter your choice: "; cin >> choice;
                    switch (choice) {
                    case 1:loadTrainers(); break;
                    case 2:attendance(searchid); break;
                    case 3: g1.displayTimings(); break;
                    case 4: {
                        int id; double  amount; string date;
                        cout << "Enter Payment ID, Amount, Date: "; cin >> id >> amount >> date;
                        addPayment(new Payment(id, amount, date));
                        break;
                    }
                    default:
                        cout << "Invalid choice! Please enter a valid option." << endl;
                    } break;
                }
            }
            if (!found) {
                cout << "Member ID not found. Please enter a valid ID." << endl;
            }
            cout << "Do you want to continue? (Y/N): "; cin >> cont;
            if (cont != 'Y' && cont != 'y') { break; }
        }
    }
    void updateMember(int memberId) {
        bool found = false; string name, membershipType, joiningDate, expiryDate; int age;
        loadMembers();
        for (int i = 0; i < numMembers; ++i) {
            if (members[i]->getId() == memberId) {
                found = true;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
                cout << "Enter new Name: "; getline(cin, name);
                members[i]->setName(name);
                cout << "Enter new Age: ";
                while (true) {
                    cin >> age;
                    if (age > 18 && age < 100) {
                        members[i]->setAge(age); break;
                    }
                    else
                        cout << "Invalid age. Please enter an age between 18 and 100.\n";
                }cin.ignore();
                cout << "Enter new Membership Type: "; getline(cin, membershipType);
                members[i]->setMembershipType(membershipType);
                cout << "Enter new Joining Date: "; getline(cin, joiningDate);
                members[i]->setJoiningDate(joiningDate);
                cout << "Enter new Expiry Date: "; getline(cin, expiryDate);
                members[i]->setExpiryDate(expiryDate);
                cout << "Member details updated successfully.\n";
                ofstream  outFile("members.txt");
                for (int i = 0; i < numMembers; ++i) {
                    outFile << members[i]->getName() << " " << members[i]->getAge() << " " << members[i]->getId() << " " << members[i]->getMembershipType() << " "
                        << members[i]->getJoiningDate() << " " << members[i]->getExpiryDate() << "\n";
                }
                outFile.close();
                break;
            }
        }
        if (!found) { cout << "Member ID not found.\n"; }
    }
    void deleteMember(int memberId) {
        for (int i = 0; i < numMembers; ++i) {
            if (members[i]->getId() == memberId) {
                delete members[i];//delete the given space
                for (int j = i; j < numMembers - 1; ++j) {
                    members[j] = members[j + 1];//copy previous data
                }
                numMembers--;
                ofstream outFile("members.txt");
                for (int i = 0; i < numMembers; ++i) {
                    outFile << members[i]->getName() << " " << members[i]->getAge() << " " << members[i]->getId() << " " << members[i]->getMembershipType() << " "
                        << members[i]->getJoiningDate() << " " << members[i]->getExpiryDate() << "\n";
                }
                outFile.close();
                cout << "Member deleted successfully." << endl;
                return;
            }
        }cout << "Member ID not found." << endl;
    }
    // STAFF                STAFF    
    void addStaff(Staff* s) {
        if (numStaff < maxStaff) { staff[numStaff++] = s;  saveStaff(); }
    }
    void loadStaff() {
        ifstream inFile("staff.txt");
        string name, job; int age, id; double fees; numStaff = 0;
        while (inFile >> name >> ws && inFile >> id >> ws && inFile >> job >> ws) {
            inFile >> age >> fees;
            staff[numStaff++] = (new Staff(name, id, job, age, fees));  // Corrected
        } inFile.close();
    }
    void saveStaff() {
        ofstream outFile("staff.txt", ios::app);
        outFile << staff[numStaff - 1]->getName() << " " << staff[numStaff - 1]->getId() << " " << staff[numStaff - 1]->getJob() << " "
            << staff[numStaff - 1]->getAge() << " " << staff[numStaff - 1]->getFees() << "\n";
        outFile.close();
    }
    void showAllStaff() {
        loadStaff(); cout << "All Staff:" << endl;
        for (int i = 0; i < numStaff; i++) { staff[i]->display(); }
    }
    void updateStaff(int staffId) {
        bool found = false; string name, job; int age; double fees;
        loadStaff();
        for (int i = 0; i < numStaff; ++i) {
            if (staff[i]->getId() == staffId) { // Assuming getId() is defined
                found = true;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Enter new Name: "; getline(cin, name);
                staff[i]->setName(name);
                cout << "Enter new Age: ";
                while (true) {
                    cin >> age;
                    if (age > 18 && age < 100) {
                        staff[i]->setAge(age); break;
                    }
                    else
                        cout << "Invalid age. Please enter an age between 18 and 100.\n";
                } cin.ignore();
                cout << "Enter new Job: "; getline(cin, job);
                staff[i]->setJob(job);
                cout << "Enter new Fees: ";
                while (true) {
                    cin >> fees;
                    if (fees > 0) {
                        staff[i]->setFees(fees); break;
                    }
                    else
                        cout << "Invalid fees. Please enter a positive value.\n";
                }
                cout << "Staff details updated successfully.\n";
                ofstream  outFile("staff.txt");
                for (int i = 0; i < numStaff; i++) {
                    outFile << staff[i]->getName() << " " << staff[i]->getId() << " " << staff[i]->getJob() << " " << staff[i]->getAge() << " " << staff[i]->getFees() << "\n";
                }   outFile.close();
                break;
            }
        }
        if (!found) { cout << "Staff ID not found.\n"; }
    }
    void deleteStaff(int staffId) {
        for (int i = 0; i < numStaff; ++i) {
            if (staff[i]->getId() == staffId) {
                delete staff[i];//delete the given space
                for (int j = i; j < numStaff - 1; ++j) {
                    staff[j] = staff[j + 1];// copy previous
                }
                numStaff--;
                ofstream outFile("staff.txt");
                for (int i = 0; i < numStaff; i++) {
                    outFile << staff[i]->getName() << " " << staff[i]->getId() << " " << staff[i]->getJob() << " " << staff[i]->getAge() << " " << staff[i]->getFees() << "\n";
                } outFile.close();
                cout << "Staff deleted successfully.\n";
                return;
            }
        }cout << "Staff ID not found.\n";
    }
    void staffdisplay() {
        bool found = false; loadStaff(); string searchname; int choice; char cont;
        cout << "Welcome to the Gym!\n";
        cout << "Enter your Name: "; cin.ignore(); getline(cin, searchname);
        while (true) {  // Search for the staff member with the entered name
            for (int i = 0; i < numStaff; ++i) {
                if (staff[i]->getName() == searchname) {
                    found = true;
                    cout << MAGENTA; cout << "Welcome, " << staff[i]->getName() << "!" << endl;
                    cout << GREEN; cout << "What would you like to do?" << endl; cout << "1. Mark Attendance" << endl; cout << "2. View Gym Timings" << endl;
                    cout << RESET;
                    cout << "Enter your choice: ";
                    cin >> choice;
                    switch (choice) {
                    case 1: { staffattendance(searchname); break; }
                    case 2: { gymtiming g2; g2.displayTimings(); break; }
                    default:
                        cout << "Invalid choice! Please enter a valid option." << endl; break;
                    }
                    break;
                }
            }
            if (!found) { cout << "No Staff Member found with name " << searchname << endl; }
            cout << "Do you want to continue? (Y/N): "; cin >> cont;
            if (cont != 'Y' && cont != 'y') { break; }
        }
    }

    void staffattendance(string name) {
        string date; Attendance a2;
        cout << "Enter todays date :";  cin >> date;
        a2.markstaffattendance(name, date, true);
    }
    //EQUIPMENT          EQUIPMENT
    void addEquipment(Equipment* e) {
        if (numEquipments < maxEquipments) { equipments[numEquipments++] = e; saveEquipments(); }
    }
    void loadEquipments() {
        ifstream inFile("equipment.txt");
        string equipmentName; int equipmentId;
        numEquipments = 0;
        while (inFile >> ws && getline(inFile, equipmentName, ' ')) {
            inFile >> equipmentId;
            equipments[numEquipments++] = (new Equipment(equipmentName, equipmentId));
        }
        inFile.close();
    }
    void saveEquipments() {
        ofstream outFile("equipment.txt", ios::app);
        outFile << equipments[numEquipments - 1]->getEquipmentName() << " " << equipments[numEquipments - 1]->getEquipmentId() << "\n";
        outFile.close();
    }
    void showAllEquipments() {
        loadEquipments(); cout << "All Equipment:" << endl;
        for (int i = 0; i < numEquipments; i++) { equipments[i]->display(); }
    }
    void updateEquipment(int equipmentId) {
        bool found = false; string equipmentName;
        loadEquipments();
        for (int i = 0; i < numEquipments; ++i) {
            if (equipments[i]->getEquipmentId() == equipmentId) {
                found = true;
                cout << "Enter new details (Equipment Name): "; cin.ignore(); getline(cin, equipmentName);
                equipments[i]->setEquipmentName(equipmentName);
                cout << "Equipment details updated successfully." << endl;
                ofstream  outFile("equipment.txt");
                for (int i = 0; i < numEquipments; i++) {
                    outFile << equipments[i]->getEquipmentName() << " " << equipments[i]->getEquipmentId() << "\n";
                }
                outFile.close();
                break;
            }
        }
        if (!found) { cout << "Equipment ID not found." << endl; }
    }
    void deleteEquipment(int equipmentId) {
        loadEquipments();
        for (int i = 0; i < numEquipments; ++i) {
            if (equipments[i]->getEquipmentId() == equipmentId) {
                delete equipments[i];//delete the given space
                for (int j = i; j < numEquipments - 1; ++j) { equipments[j] = equipments[j + 1]; }
                numEquipments--;
                ofstream outFile("equipment.txt");
                for (int i = 0; i < numEquipments; i++) {
                    outFile << equipments[i]->getEquipmentName() << " " << equipments[i]->getEquipmentId() << "\n";
                }
                outFile.close();
                cout << "Equipment deleted successfully." << endl;
                return;
            }
        } cout << "Equipment ID not found." << endl;
    }
    //SESSION                   SESSION 
    void addSession(Session* s) {
        if (numSessions < maxSessions) {
            sessions[numSessions++] = s; saveSessions();
        }
    }
    void loadSessions() {
        ifstream inFile("sessions.txt");
        int sessionId;  string sessionType, dateTime; numSessions = 0;
        while (inFile >> sessionId >> ws && getline(inFile, sessionType, ' ') && getline(inFile, dateTime)) {
            sessions[numSessions++] = (new Session(sessionId, sessionType, dateTime));
        }
        inFile.close();
    }
    void saveSessions() {
        ofstream outFile("sessions.txt");
        outFile << sessions[numSessions - 1]->getSessionId() << " " << sessions[numSessions - 1]->getSessionType() << " " << sessions[numSessions - 1]->getDateTime() << "\n";
        outFile.close();
    }
    void showAllSessions() {
        loadSessions(); cout << "All Sessions:" << endl;
        for (int i = 0; i < numSessions; i++) { sessions[i]->display(); }
    }
    //PAYMENTS                       PAYMENTS
    void addPayment(Payment* p) {
        if (numPayments < maxPayments) { payments[numPayments++] = p; savePayments(); }
    }
    void loadPayments() {
        ifstream inFile("payments.txt");
        int paymentId; double amount; string date; numPayments = 0;
        while (inFile >> paymentId >> amount >> ws && getline(inFile, date)) {
            payments[numPayments++] = (new Payment(paymentId, amount, date));
        }inFile.close();
    }
    void savePayments() {
        ofstream outFile("payments.txt", ios::app);
        outFile << payments[numPayments - 1]->getPaymentId() << " " << payments[numPayments - 1]->getAmount() << " " << payments[numPayments - 1]->getDate() << "\n";
        outFile.close();
    }
    void showAllPayments() {
        loadPayments();  cout << "All Payments:" << endl;
        for (int i = 0; i < numPayments; i++) { payments[i]->display(); }
    }
    void adminPanel() {
        int choice, memberId, trainerId, staffId, equipmentId; bool running = true;
        while (running) {
            system("cls");
            cout << "\n\t\t\t" << YELLOW << R"(   
  _____       .___      .__         __________                      .__   
  /  _  \    __| _/_____ |__| ____   \______   \_____    ____   ____ |  |  
 /  /_\  \  / __ |/     \|  |/    \   |     ___/\__  \  /    \_/ __ \|  |  
    |    \/ /_/ |  Y Y  \  |   |  \  |    |     / __ \|   |  \  ___/|  |__
\____|__  /\____ |__|_|  /__|___|  /  |____|    (____  /___|  /\___  >____/
        \/      \/     \/        \/                  \/     \/     \/                                                               )";
            cout << endl;
            cout << RED << "\t" << "\033[6mMEMBER\033[0m" << endl;
            cout << "\t" << BLUE << "1.  " << RESET << "Add Member\n" << RESET;
            cout << "\t" << BLUE << "2.  " << RESET << "Show All Members\n" << RESET;
            cout << "\t" << BLUE << "3.  " << RESET << "Update Member\n" << RESET;
            cout << "\t" << BLUE << "4.  " << RESET << "Delete Member\n" << RESET;
            cout << RED << "\t" << "\033[6mTRAINER\033[0m" << endl;
            cout << "\t" << BLUE << "5.  " << RESET << "Add Trainer\n" << RESET;
            cout << "\t" << BLUE << "6.  " << RESET << "Show All Trainers\n" << RESET;
            cout << "\t" << BLUE << "7.  " << RESET << "Update Trainer\n" << RESET;
            cout << "\t" << BLUE << "8.  " << RESET << "Delete Trainer\n" << RESET;
            cout << RED << "\t" << "\033[6mSTAFF\033[0m" << endl;
            cout << "\t" << BLUE << "9.  " << RESET << "Add Staff Members\n" << RESET;
            cout << "\t" << BLUE << "10. " << RESET << "Show All Staff Members\n" << RESET;
            cout << "\t" << BLUE << "11. " << RESET << "Update Staff\n" << RESET;
            cout << "\t" << BLUE << "12. " << RESET << "Delete Staff\n" << RESET;
            cout << RED << "\t" << "\033[6mEQUIPMENT\033[0m" << endl;
            cout << "\t" << BLUE << "13. " << RESET << "Add Equipment\n" << RESET;
            cout << "\t" << BLUE << "14. " << RESET << "Show All Equipments\n" << RESET;
            cout << "\t" << BLUE << "15. " << RESET << "Update Equipment\n" << RESET;
            cout << "\t" << BLUE << "16. " << RESET << "Delete Equipment\n" << RESET;
            cout << RED << "\t" << "\033[6mPAYMENT\033[0m" << endl;
            cout << "\t" << BLUE << "17. " << RESET << "Add Payment\n" << RESET;
            cout << "\t" << BLUE << "18. " << RESET << "Show All Payments\n" << RESET;
            cout << RED << "\t" << "\033[6mTIMINGS\033[0m" << endl;
            cout << "\t" << BLUE << "19. " << RESET << "Update Timings\n" << RESET;
            cout << "\t" << BLUE << "20. " << RESET << "See All Timings\n" << RESET;
            cout << RED << "\t" << "\033[6mOTHER\033[0m" << endl;
            cout << "\t" << BLUE << "21. " << RESET << "Set fees\n" << RESET;
            cout << "\t" << BLUE << "22. " << RESET << "Exit Admin Panel\n" << RESET;
            cout << "\t" << BLUE << "Enter your choice: ";
            bool f; string name, membershipType, equipmentName, sessionType, dateTime, date, job, date1, date2; int age, id, day, month, year, month1, day1, year1; double amount, fees;
            cin >> choice;
            switch (choice) {
            case 1: {
                cout << "Enter Name :"; cin.ignore(); getline(cin, name);
                while (true) {
                    cout << "Enter Age :"; cin >> age;
                    if (age < 18 || age > 100) {
                        cout << "Invalid Age." << endl;
                    }
                    else { break; }
                }
                while (true) {
                    cout << "Enter Id :"; cin >> id;
                    if (id < 0) {
                        cout << "Invalid Id.Id can't be Negative" << endl;
                    }  else { break; }
                }
                cout << "Enter Membership Type :";
                while (true) {
                    cin.ignore(); getline(cin, membershipType);
                    bool g = checkmemType(membershipType);
                    if (!g) {
                        cerr << "Invalid Membership Type.Enter Again : ";
                    }else { break; }
                }
                   cout << "Enter Joining Time (DD/MM/YYYY):";
                while (true) {
                    cin >> day >> month >> year;
                    date1 = datetostring(day, month, year);
                    if (date1 == "") {  cout << "Invalid Date. Try again :  ";}
                    else { break; }
                }
                cout << "\nEnter Expire Time (DD/MM/YYYY):";
                while (true) {
                    cin >> day1 >> month1 >> year1;
                    f = comparedate(day, month, year, day1, month1, year1);
                    date2 = datetostring(day1, month1, year1);
                    if (date2 == "") {
                        cout << "Invalid Date. Try again : ";
                    } else { break; }
                }
                addMember(new Member(name, age, id, membershipType, date1, date2));
                cout << "Member Added Successfully :)" << endl;
                break;
            }
            case 5: {
                cout << "Enter Name: "; cin.ignore(numeric_limits<streamsize>::max(), '\n'); getline(cin, name); // Read the full line for the nam
                while (true) {
                    cout << "Enter Age: "; cin >> age;
                    if (age < 18 || age > 100) {
                        cout << "Invalid Age" << endl;
                    }
                    else { break; }
                }
                while (true) {
                    cout << "Enter Id: ";  cin >> id;
                    if (id < 0) {
                        cout << "Invalid Id. Id can't be Negative" << endl;
                    }
                    else { break; }
                }
                addTrainer(new Trainer(name, age, id));
                cout << "Trainer added successfully :)" << endl;
                break;
            }
            case 9: { // Adding Staff
                cout << MAGENTA; cout << "Enter Name : "; cin.ignore(); getline(cin, name);
                while (true) {
                    cout << "Enter Age :";  cin >> age;
                    if (age < 18 || age > 100) {
                        cout << "Invalid Age" << endl;
                    }
                    else { break; }
                }
                while (true) {
                    cout << "Enter Id :"; cin >> id;
                    if (id < 0) {
                        cout << "Invalid Id.Id can't be Negative" << endl;
                    }
                    else { break; }
                }
                cout << "Enter Job :"; cin.ignore();  getline(cin, job);
                while (true) {
                    cout << "Enter Salary :"; cin >> fees;
                    if (fees < 1000) {
                        cout << "Invalid Salary." << endl;
                    }
                    else { break; }
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');   addStaff(new Staff(name, id, job, age, fees));
                cout << "Staff member added successfully :) ";
                break;
            }
            case 13: {
                cout << "Enter Equipment Name: "; cin.ignore(); getline(cin, equipmentName);
                while (true) {
                    cout << "Enter ID:";  cin >> id;
                    if (id < 0) {
                        cout << "Invalid Quantity.Quantity can't be Negative" << endl;
                    }
                    else { break; }
                }
                addEquipment(new Equipment(equipmentName, id));
                cout << "Equipment added successfully :) ";
                break;
            }
            case 17: {
                while (true) {
                    cout << "Enter Payment ID: "; cin >> id;
                    if (id < 0) {
                        cout << "Invalid ID. ID can't be Negative" << endl;
                    }
                    else { break; }
                }
                while (true) {
                    cout << "Enter Amount: ";  cin >> amount;
                    if (amount < 0) {
                        cout << "Invalid Amount. Amount can't be Negative" << endl;
                    }
                    else { break; }
                }
                cout << "Enter Date (DD/MM/YYYY):";
                while (true) {
                    cin >> day >> month >> year;
                    date1 = datetostring(day, month, year);
                    if (date1 == "") {
                        cout << "Invalid Date. Try again :  ";
                    }
                    else { break; }
                }
                addPayment(new Payment(id, amount, date1));
                cout << "Added successfully :) ";
            }
                   break;
            case 2: { showAllMembers(); break; }
            case 6: { showAllTrainers(); break; }
            case 10: { showAllStaff(); break; }
            case 14: { showAllEquipments(); break; }
            case 18: { showAllPayments(); break; }
            case 22: { running = false;     break; }
            case 3: {
                while (true) {
                    cout << "Enter Member ID to Update: "; cin >> memberId;
                    if (memberId < 0) {
                        cout << "Id can't be Negative\n";
                    }
                    else { updateMember(memberId); break; }
                }
                break;
            }
            case 4:
                while (true) {
                    cout << "Enter Member ID to Delete: "; cin >> memberId;
                    if (memberId < 0) {
                        cout << "Id can't be Negative\n";
                    }
                    else { break; }
                }
                deleteMember(memberId);
                break;
            case 15:
                while (true) {
                    cout << "Enter Equipment ID to Update: ";    cin >> equipmentId;
                    if (equipmentId < 0) {
                        cout << "Id can't be Negative\n";
                    }
                    else { break; }
                }
                updateEquipment(equipmentId);
                break;
            case 16:
                while (true) {
                    cout << "Enter Equipment ID to Delete: ";  cin >> equipmentId;
                    if (equipmentId < 0) {
                        cout << "Id can't be Negative\n";
                    }
                    else { break; }
                }
                deleteEquipment(equipmentId);
                break;
            case 7:
                while (true) {
                    cout << "Enter Trainer ID to Update: "; cin >> trainerId;
                    if (trainerId < 0) {
                        cout << "Id can't be Negative\n";
                    }
                    else { break; }
                }
                updateTrainer(trainerId);
                break;
            case 8:
                while (true) {
                    cout << "Enter Trainer ID to Delete: ";  cin >> trainerId;
                    if (trainerId < 0) {
                        cout << "Id can't be Negative\n";
                    }
                    else { break; }
                }
                deleteTrainer(trainerId);
                break;
            case 11:
                while (true) {
                    cout << "Enter Staff ID to Update: "; cin >> staffId;
                    if (staffId < 0) {
                        cout << "Id can't be Negative\n";
                    }
                    else { break; }
                }
                updateStaff(staffId);
                break;
            case 12:
                while (true) {
                    cout << "Enter Staff ID to Delete: "; cin >> staffId;
                    if (staffId < 0) {
                        cout << "Id can't be Negative\n";
                    }
                    else { break; }
                }
                deleteStaff(staffId);
                break;
            case 19: g1.setTimings(); break;
            case 20:g1.displayTimings();  break;
            case 21: { r.setfees(); break; }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
            }
            if (running) {
                char continueChoice;
                cout << "\nDo you want to continue in admin panel? (Y/N): "; cin >> continueChoice;
                if (continueChoice != 'Y' && continueChoice != 'y') {
                    running = false;
                }
            }
        }
    }
};
class NewMember : public GymManagement {
public:
    void visitingdisplay() {
        gymtiming v1; string name, membershipType, equipmentName, sessionType, dateTime, date, job; int age, choice, id; double amount, fees; bool running = true;
        while (true) {
            cout << CYAN;
            cout << "1. View Timings\n";
            cout << "2. View Fee Structure\n";
            cout << "3. Exit visiting member Panel\n";
            cout << YELLOW << "Enter your choice: " << RESET;  cin >> choice;
            switch (choice) {
            case 1: { cout << MAGENTA; v1.displayTimings(); break; }
            case 2: { Feestructure f1;  f1.displayfees();  break; }
            case 3: { running = false;  break; }
            default: { cout << "Invalid choice. Please try again.\n"; break; }
            }
            if (!running) {
                char continueChoice;
                cout << RESET << "\nDo you want to continue in Visiting panel? (Y/N): ";  cin >> continueChoice;
                if (continueChoice != 'Y' && continueChoice != 'y') { running = false;  break; }
            }
        }
    }
};
int main() {
    char ch; int chance = 3; GymManagement gym; bool running = true; string check, adminPassword; char userType, continueChoice;
    while (true) {
        cout << YELLOW << R"( 






   ________                   _____                                                             __      _________               __                  
 /  _____/___.__. _____     /     \ _____    ____ _____     ____   ____   _____   ____   _____/  |_   /   _____/__.__. _______/  |_  ____   _____  
   \  __|   |  |/     \   /  \ /  \\__  \  /    \\__  \   / ___\_/ __ \ /     \_/ __ \ /    \   __\  \_____   |  |  |/  ___/\   __\/ __ \ /     \ 
\    \_\  \___  |  Y Y  \ /    Y    \/ __ \|   |  \/ __ \_/ /_/  >  ___/|  Y Y  \  ___/|   |  \  |    /        \___  |\___ \  |  | \  ___/|  Y Y  \
 \______  / ____|__|_|  / \____|__  (____  /___|  (____  /\___  / \___  >__|_|  /\___  >___|  /__|   /_______  / ____/____  > |__|  \___  >__|_|  /
        \/\/          \/          \/     \/     \/     \//_____/      \/      \/     \/     \/               \/\/         \/            \/      \/ 
    )";
        cout << MAGENTA"-------------------------------------------------------------------------------------------------------------------------------------------";
        cout << RESET << endl << RED<<endl<<endl<<endl<<endl<<
           "                                                           Press ENTER : ";
        if (_kbhit) {
            ch = _getch();
            if (ch == '\r') {
                system("cls");
                break;
            }
            else { system("cls"); }
        }
    }
    system("cls");
    while (running) {
        cout << MAGENTA << R"(







        \     /  \ ____|  |   ____  ____   _____   ____   _/  |_  ____     /     \ _____  |__| ____     /     \   ____   ____  __ __ 
     \   \/\/   // __ \|  | _/ ___\/  _ \ /     \_/ __ \  \   __\/  _ \   /  \ /  \\__  \ |  |/    \   /  \ /  \_/ __ \ /    \|  |  \
      \        /\  ___/|  |_\  \__(  <_> )  Y Y  \  ___/   |  | (  <_> ) /    Y    \/ __ \|  |   |  \ /    Y    \  ___/|   |  \  |  /
       \__/\  /  \___  >____/\___  >____/|__|_|  /\___  >  |__|  \____/  \____|__  (____  /__|___|  / \____|__  /\___  >___|  /____/ 
            \/       \/          \/            \/     \/                         \/     \/        \/          \/     \/     \/      
)"; cout << RESET << "                  ---------------------------------------------------------------------------------------------------\n";
        cout << CYAN; cout << "Are you an Admin or a Member or Staff or Visiting Member? (A/M/S/V): "; cin >> userType; RESET;
        if (userType == 'A' || userType == 'a') {
            cout << CYAN << "Enter Admin password: "; cin >> adminPassword; RESET;
            if (adminPassword == "hi") { gym.adminPanel(); }
            else { cout << "Incorrect password. Access denied.\n"; }
        }
        else if (userType == 'M' || userType == 'm') { gym.memberdisplay(); }
        else if (userType == 'S' || userType == 's') { gym.staffdisplay(); }
        else if (userType == 'V' || userType == 'v') { NewMember v1; 
        system("cls");
        cout <<MAGENTA<< R"( 






                     ____   ____ __        __  __   __                  __________                       __  
                     \   \ /   /|__| _____|__|/  |_|__| ____    ____    \______   \_____    ____   ____ |  |  
                      \   Y   / |  |/  ___/  \   __\  |/    \  / ___\    |     ___/\__  \  /    \_/ __ \|  |  
                       \     /  |  |\___ \|  ||  | |  |   |  \/ /_/  >   |    |     / __ \|   |  \  ___/|  |__
                        \___/   |__/____  >__||__| |__|___|  /\___  /    |____|    (____  /___|  /\___  >____/
                                        \/                 \//_____/                    \/     \/     \/      
)"<<RESET;          
        cout << YELLOW << "                           ------------------------------------------------------------------------------\n";
        v1.visitingdisplay(); }
        else { cout << "Invalid choice. Please start again.\n"; }
        cout << RED<<"Do you want to continue using the system? (Y/N): ";
        cin >> continueChoice;
        if (continueChoice != 'Y' && continueChoice != 'y') { running = false; }
        system("cls");
    }
    system("cls");
    cout << YELLOW << R"(
 ___________.__                   __            
\__    ___/|  |__ _____    ____ |  | __  ______
  |    |   |  |  \\__  \  /    \|  |/ / /  ___/
  |    |   |   Y  \/ __ \|   |  \    <  \___ \ 
  |____|   |___|  (____  /___|  /__|_ \/____  >
                \/     \/     \/     \/     \/ )";
    cout << endl << RESET;
    return 0;
}