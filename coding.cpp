#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <windows.h>
using std::setw;
using namespace std;


void chooseUserAdmin();
int inputChooseUserAdmin,inputLoginSign,inputUserChooseMenu,inputUserChooseBookCancel,inputUserChooseRoom,checkIn, checkOut,fillPeople,confirmBooking,inputPayMethod,inputAdminChooseMenu;
void userLogin();
string userN, userP, name, pass;
void userSign();
void adminLogin();
void userMenu(string userLoginMenu);
void logout();
void bookingService();
vector <string> showRoomType={"Normal Single Room","Luxury Single Room","Normal Double Room","Luxury Double Room"};
vector <int> availableRoom={2,1,1,1};
vector <int> roomPrices={78,188,148,288};
vector <vector <string>> roomID={{"RI01","RI02"},
                                 {"RI03","null"},
                                 {"RI04","null"},
                                 {"RI05","null"}};
void bookingServiceDetails(int userChooseRoom, string userLoginName);
char inputPriceAccept,enterMenuPage,inputAdminEdit,inputAdminExit,userChoosePayUP,userChoosePayUPB,userChooseCCB,userChooseCCBB;
void payment(string userLoginName);
void showSystemAdminHomePage();
void adminShowRoomStatus();
void adminEditRoomStatus();
void adminShowRoomPrice();
void adminEditRoomPrice();
void adminShowRoom();
void adminEditRoom();
void unpaid(string userName);
void deleteUnpaidOrder(const string& userName);
void deleteConfirmBooking(const string& userName);
void addRoomStatus(int userChooseRoom);
void cancelConfirmBooking(string UserLoginName);
bool isStreamEmpty(ifstream& stream);

int main() {
    chooseUserAdmin();
    switch(inputChooseUserAdmin){
        case 1:
        cout<<"\n\n1.Login here"<<"\n"<<"2.Have no accout yet? Sign up here"<<"\n";
        cout<<"\nType Here:";
        cin>>inputLoginSign;
        switch(inputLoginSign){
            case 1:
            O1:
            userLogin();
            O8:
            userMenu(userN);
            switch(inputUserChooseMenu){
                case 1:{
                    system("cls");
                    cout<<"1.\tEnter booking service\n2.\tEnter cancel previous booking service"<<endl;
                    cout<<"\n\nPlease choose one\n\n"<<setw(18)<<"Type here: ";
                    cin>>inputUserChooseBookCancel;
                    system("cls");
                    switch (inputUserChooseBookCancel){
                        case 1:{
                            bookingService();
                            bookingServiceDetails(inputUserChooseRoom, userN);
                            payment(userN);
                            break;
                        }

                        case 2 :{
                            cancelConfirmBooking(userN);
                            if(userChooseCCB=='N'|| userChooseCCB=='n' || userChooseCCBB=='Y' || userChooseCCBB=='y'){
                                system("cls");
                                goto O8;
                                break;
                            }else if(userChooseCCB=='Y'|| userChooseCCB=='y'){
                                deleteUnpaidOrder(userN);
                                deleteConfirmBooking(userN);
                                addRoomStatus(inputUserChooseRoom);
                                cout<<"You have successfully cancel the booked room\nAutomatically go to the home page after 5 seconds..."<<endl;
                                Sleep(5000);
                                system("cls");
                                goto O8;
                                break;
                                
                            }
                            break;
                        }

                        default:
                        cout<<"Please select from the options given above"<<endl;
                        main();
                    }
                    break;
                }

                case 2:{
                    unpaid(userN);
                    if(userChoosePayUP=='Y' || userChoosePayUP=='y'){
                        payment(userN);
                        break;
                    }else if(userChoosePayUP=='N' || userChoosePayUP=='n' || userChoosePayUPB=='Y' || userChoosePayUPB=='y'){
                        system("cls");
                        goto O8;
                        break;
                    }
                    
                    break;
                }

                case 3:{
                logout();
                break;
                }

                default:
                cout<<"Please select from the options given above"<<endl;
                main();
            }
            break; 

            case 2:
            userSign(); 
            goto O1;
            break;

            default:
            cout<<"Please select from the options given above"<<endl;
            main();
    }
    break;

        case 2:{
        adminLogin();
        O7:
        showSystemAdminHomePage();
        switch(inputAdminChooseMenu){
            system("cls");
            case 1:{
                adminShowRoomStatus();
                if(inputAdminEdit=='N' || inputAdminEdit=='n'){
                    system("cls");
                    goto O7;
                }else if(inputAdminEdit=='Y' || inputAdminEdit=='y'){
                    adminEditRoomStatus();
                }
                break;
            }

            case 2:{
                adminShowRoomPrice();
                if(inputAdminEdit=='N' || inputAdminEdit=='n'){
                    system("cls");
                    goto O7;
                }else if(inputAdminEdit=='Y' || inputAdminEdit=='y'){
                    adminEditRoomPrice();
                }
                break;
            }

            case 3:{
                adminShowRoom();
                if(inputAdminEdit=='N' || inputAdminEdit=='n'){
                    system("cls");
                    goto O7;
                }else if(inputAdminEdit=='Y' || inputAdminEdit=='y'){
                    adminEditRoom();
                }
                break;
            }

            case 4:{
                cout<<"\nMaintenance...";
                Sleep(2000);
                system("cls");
                goto O7;
            }

            case 5:{
                logout();
            }
            default:
            cout<<"Please select from the options given above"<<endl;
            main();
        }
        cout<<"\nSaving..."<<endl;
        cout<<"Do you want to exit the program? (Y=yes,Others=no) : ";
        cin>>inputAdminExit;
        if(inputAdminExit=='Y' || inputAdminExit=='y'){
            logout();
        }else{
            system("cls");
            goto O7;
        }
        break;
        }

        default:
        cout<<"Please select from the options given above"<<endl;
        main();
}
return 0;
        
}


void chooseUserAdmin(){
    cout<<"\t\t\t\t\t------------------------------------------------------\n\n\n";
    cout<< "\t\t\t\t\tWelcome to The Eric and Chien's Hotel Booking System!" << "\n\n\n";
    cout<<"\t\t\t\t\t-------------------------------------------------------\n\n\n";
    cout<< "You are...\n\n1.User\n"<<"2.Admin";
    cout<< "\n" << "\nType Here:";
    cin>>inputChooseUserAdmin;
    system("cls");
}

void userLogin(){
    int count;
    cout<<"\n\n";
    cout<<"===============\n";
    cout<<"User Login Page"<<endl;
    cout<<"===============\n";
    cout<<"\n\n";
    cout<<"Please enter the username: "<<endl;
    cin>>userN;
    cout<<"Please enter the password: "<<endl;
    cin>>userP;

    ifstream input("records.txt");
    while(input>>name>>pass){
        if(name==userN && pass==userP){
            count=1;
            system("cls");
        }

    }
    input.close();
    
    if(count==1){
        cout<<"Login Successful!"<<endl;
    
    }else{
        system("cls");
        cout<<"Username or Password wrong, Please try again!"<<endl;
        main();
    }
}

void userSign(){
    string sUserN, sUserP, sName, sPass;
    system("cls");
    cout<<"=================\n";
    cout<<"User Sign up Page"<<endl;
    cout<<"=================\n";
    cout<<"Please create a username: "<<endl;
    cin>>sUserN;
    cout<<"Please create a password: "<<endl;
    cin>>sUserP;
    system("cls");
    cout<<"Submitting..."<<endl;

    ofstream f1("records.txt", ios::app);
    f1<<sUserN<<' '<<sUserP<<endl;
    cout<<"Sign Up Successful!\nNow going to user login page..."<<endl;
}

void adminLogin(){
    O6:
    string adminN,adminP;
    cout<<"================\n";
    cout<<"Admin Login Page"<<endl;
    cout<<"================\n";
    cout<<"\n\n";
    cout<<"Please enter the admin name : "<<endl;
    cin>>adminN;
    cout<<"Please enter the admin passsword : "<<endl;
    cin>>adminP;
    system("cls");
    if(adminN=="eric_chien" && adminP=="3322112"){
       cout<<"Login Successful!"<<endl;
    }else{
        cout<<"Admin name or password wrong, Please try again!"<<endl;
        goto O6;
    }
}

void userMenu(string userLoginName){
    cout<<"\t\t\t\t=========\n";
    cout<<"\t\t\t\tMenu Page\n";
    cout<<"\t\t\t\t=========\n";
    cout<<"Welcome back! "<<userLoginName<<"\n\n";
    vector <string> menu={"Booking page","Payment page","Log Out"}; 
    for(int i=0;i<3;i++){
        cout<<i+1<<"\t"<<menu[i]<<endl;
    }
    cout<<"\n\nPlease choose one\n\n"<<setw(18)<<"Type here: ";
    cin>>inputUserChooseMenu;
}

void logout(){
    system("cls");
    cout<<"Exiting...\n\nYou have successfully logged out our hotel booking system.\n\nThank You!"<<endl;
    exit (0);
}

void bookingService(){
    O2:
    system("cls");
    cout<<"================\n";
    cout<<"Booking room page"<<endl;
    cout<<"================\n";
    cout<<"Our room type have...\n\n";
    
    for(int i=0;i<4;i++){
        cout<<i+1<<"\t"<<showRoomType[i]<<endl;
    }
    cout<<"\nWhich room type are you looking for :";
    cin>>inputUserChooseRoom;
    system("cls");
    vector <string> roomDetails={"bed type :","bed number :","mountain view :","swimming pool :"};
    vector <string> roomDetails1={"small bed","1","no","no"};
    vector <string> roomDetails2={"medium bed","1","yes","yes"};
    vector <string> roomDetails3={"small bed","2","no","no"};
    vector <string> roomDetails4={"queen bed","2","yes","yes"};
    if(inputUserChooseRoom==1){
        for(int j=0;j<4;j++){
            cout<<setw(15)<<roomDetails[j]<<setw(10)<<roomDetails1[j]<<endl;
            }
            }else if(inputUserChooseRoom==2){
        for(int j=0;j<4;j++){
            cout<<setw(15)<<roomDetails[j]<<setw(11)<<roomDetails2[j]<<endl;
        }
    }else if(inputUserChooseRoom==3){
        for(int j=0;j<4;j++){
            cout<<setw(15)<<roomDetails[j]<<setw(10)<<roomDetails3[j]<<endl;
        }

    }else if(inputUserChooseRoom==4){
       for(int j=0;j<4;j++){
            cout<<setw(15)<<roomDetails[j]<<setw(10)<<roomDetails4[j]<<endl;
        }
    }else{
        cout<<"Please select from the options given above"<<endl;
        goto O2;
    }
    
}

void bookingServiceDetails(int userChooseRoom,string userLoginName){
            ifstream iRoomS("roomStatus.txt");
            if(!iRoomS){
            ofstream foRoomS("roomStatus.txt");
             if (foRoomS.is_open()) {
             for (int i = 0; i < availableRoom.size(); ++i) {
             foRoomS << availableRoom[i] << " ";
             }
            foRoomS.close();
             }
             iRoomS.open("roomStatus.txt");
            }
            if (iRoomS.is_open()) {
            vector<int> readNumbers;
            int number;
            while (iRoomS >> number) {
            readNumbers.push_back(number);
            }
            iRoomS.close();
            cout<<"\n"<<setw(38)<<"Number of rooms available : "<<readNumbers[userChooseRoom-1]<<endl;
            cout<<setw(41)<<"One night price : RM "<<roomPrices[userChooseRoom-1]<<endl;
            if(readNumbers[userChooseRoom-1]<=0){
                cout<<"Sorry, the room type is not available now\nGoing to back page...";
                Sleep(3000);
                bookingService();
                bookingServiceDetails(inputUserChooseRoom,userN);
                payment(userN);
            }else{
            cout<<"The price is accepted  (Y=Yes,N=No) : ";
            cin>>inputPriceAccept;
            switch(inputPriceAccept){
                case 'Y': case 'y':{
                O4:
                cout<<"\nPlease input the day of this month to check in :";
                cin>>checkIn;
                cout<<"\nPlease input the day of this month to check out :";
                cin>>checkOut;
                if(checkIn>=1 && checkOut<=31 && checkOut>checkIn){
                    cout<<"\nPlease fill in the number of people :";
                    cin>>fillPeople;
                    cout<<"\nPress 1 to confirm the booking"<<endl;
                    cin>>confirmBooking;
                    if(confirmBooking==1){
                         if (!readNumbers.empty()) {
                         readNumbers[userChooseRoom-1]-=1;
                          }
                    ofstream oRoomS("roomStatus.txt");
                    if (oRoomS.is_open()) {
                    for (int i = 0; i < readNumbers.size(); i++) {
                    oRoomS << readNumbers[i] << " ";
                    }
                   oRoomS.close();
                   ofstream oConfirmB("confirmBookingList.txt",ios::app);
                   if(oConfirmB.is_open()){
                    oConfirmB<< userLoginName << " " << userChooseRoom << " " <<checkIn << " " << checkOut << " "<< fillPeople<<endl;
                   }
                   oConfirmB.close();
                cout<<"\nRoom booked successfully!"<<endl;
                 } else {
                  cout << "Failed to open the file." << endl;
                       }
                    }else{
                        cout<<"Invalid action, Please try again!"<<endl;
                        goto O4;
                    }
                }else{
                    cout<<"\nInvalid date, Please try again!"<<endl;
                    goto O4;
                }
                break;
                }
                case 'N': case 'n':{
                    cout<<"\nContinue to searching room type (Y=Yes,N=No) :";
                    cin>>enterMenuPage;
                    switch(enterMenuPage){
                        case 'Y': case 'y':{
                            bookingService();
                            bookingServiceDetails(inputUserChooseRoom,userN);
                            payment(userN);
                            break;
                        }
                        case 'N': case 'n':{
                            logout();
                            break;
                            
                        }
                        default:
                        cout<<"Please select from the options given above"<<endl;
                        main();
                    }
                    break;
                }
                default:
                cout<<"Please select from the options given above"<<endl;
                main();
            }
            
            }
}
}



void payment(string userLoginName){
    O5:
    char inputPay;
    system("cls");
    cout<<"Going to bill page..."<<endl;
    cout<<"=========\n";
    cout<<"Bill page"<<endl;
    cout<<"=========\n";
    cout<<"\nDear "<<userLoginName<<",here is your bill :"<<endl;
    int stayNights=checkOut-checkIn;
    int totalPayment=roomPrices[inputUserChooseRoom-1]*stayNights;
    cout<<"\t\t\t\t=============================================\n"<<endl;
    cout<<"\t\t\t\t"<<setw(23)<<"User Name : "<<"\t"<<userLoginName<<endl;
    cout<<"\t\t\t\t"<<setw(23)<<"Room Type : "<<"\t"<<showRoomType[inputUserChooseRoom-1]<<endl;
    cout<<"\t\t\t\t"<<setw(23)<<"Room One Night Price : "<<"\tRM"<<roomPrices[inputUserChooseRoom-1]<<endl;
    cout<<"\t\t\t\t"<<setw(23)<<"Stay Nights : "<<"\t"<<stayNights<<endl;
    cout<<"\t\t\t\t"<<setw(23)<<"Total Payment : "<<"\tRM"<<totalPayment<<endl;
    cout<<"\t\t\t\t=============================================\n"<<endl;
     cout<<"*Please complete the payment within 12 hours*"<<endl;
    cout<<"\nDo you want to pay the bill now? (Y=Yes,N=No) : ";
    cin>>inputPay;
    switch(inputPay){
        case 'Y': case 'y':{
            system("cls");
            vector <string> paymentMethod={"Online banking","Debit or Credit card"};
            cout<<"\nPlease choose the payment method...\n"<<endl;
            for(int i=0;i<2;i++){
                cout<<i+1<<"\t"<<paymentMethod[i]<<endl;
}
            cout<<"\nYour choice: ";
            cin>>inputPayMethod;
            if(inputPayMethod==1){
                string bankingUserN;
                long int bankingPass;
                cout<<"\n"<<setw(10)<<"User ID : ";
                cin>>bankingUserN;
                cout<<"\n"<<setw(10)<<"Password : ";
                cin>>bankingPass;
                system("cls");
                cout<<"Processing..."<<endl;
                if(bankingPass>=100000){
                    cout<<"\nYour payment is successful!"<<endl;
                    deleteUnpaidOrder(userN);
                    cout<<"Your receipt has been sent to you Gmail"<<endl;
                    cout<<"Automatically logout after 5 seconds..."<<endl;
                    Sleep(5000);
                    logout();
                    break;
                }else{
                    cout<<"\nYour payment is unsuccessful, Please try again!"<<endl;
                    Sleep(2000);
                    goto O5;
                    break;
                }
            }else if(inputPayMethod==2){
                string cardID,cardName;
                cout<<"\n"<<setw(11)<<"Card ID : ";
                cin>>cardID;
                cout<<"\n"<<setw(11)<<"Your Name : ";
                cin>>cardName;
                system("cls");
                cout<<"Processing..."<<endl;
                if(cardID.length()==16){
                    cout<<"\nYour payment is successful!"<<endl;
                    deleteUnpaidOrder(userN);
                    cout<<"Your receipt has been sent to you Gmail"<<endl;
                    cout<<"Automatically logout after 5 seconds..."<<endl;
                    Sleep(5000);
                    logout();
                    break;
                }else{
                    cout<<"\nYour payment is unsuccessful, Please try again!"<<endl;
                    Sleep(2000);
                    goto O5;
                    break;
                }
            }
        }
        case 'N': case 'n':{
           ofstream oUPL("unpaidList.txt",ios::app);
           if(oUPL.is_open()){
            oUPL<< userLoginName <<" " << inputUserChooseRoom << " " << checkIn << " " << checkOut <<endl;
           }else{
            cout<<"File cannot open"<<endl;
           }
           oUPL.close();

           logout();
            break;
        }
        default:
        cout<<"Please select from the options given above"<<endl;
        main();
    }
}

void unpaid(string userName){
    system("cls");
    cout<<"===========\n";
    cout<<"Unpaid page"<<endl;
    cout<<"===========\n";

    ifstream iUPL("unpaidList.txt");
    if(iUPL.is_open()){
        if(isStreamEmpty(iUPL)){
        cout<<"\nEmpty Here...\nDo you want to go back to the Home Page (Y=Yes) : "<<endl;
        cin>>userChoosePayUPB;
        }else{
        int count=0;
        string loginName;
        int userChoose, nCheckIn, nCheckOut;
        while(iUPL>> loginName >>userChoose >> nCheckIn >> nCheckOut){
            if(loginName==userName){
                inputUserChooseRoom=userChoose;
                checkIn=nCheckIn;
                checkOut=nCheckOut;
                count+=1;
                break;
            }

        }
        if(count==1){
            cout<<"Welcome back!"<<userName<<", you have a unpaid bill.\nDo you want to check? (Y=Yes,N=No) :";
            cin>>userChoosePayUP;
            }else{
                cout<<"\nEmpty Here...\nDo you want to go back to the Home Page (Y=Yes) : "<<endl;
                cin>>userChoosePayUPB;
            }
        }
    }else{
        cout<<"\nEmpty Here...\nDo you want to go back to the Home Page (Y=Yes) : "<<endl;
        cin>>userChoosePayUPB;
    }
    iUPL.close();
}


void deleteUnpaidOrder(const string& userName) {
    ifstream inFile("unpaidList.txt");

    if (!inFile || isStreamEmpty(inFile)) {
        cout << "\nWaiting..." << endl;
        }else{
            ofstream outFile("temp.txt",ios::app);
            string loginName;
            int userChoose, nCheckIn, nCheckOut;

            while (inFile >> loginName >> userChoose >> nCheckIn >> nCheckOut) {
            if (loginName != userName) {
            outFile << loginName << " " << userChoose << " " << nCheckIn << " " << nCheckOut << endl;
        }
    }
    inFile.close();
    outFile.close();
    if (remove("unpaidList.txt") != 0) {
        cerr << "Error deleting file!" << endl;
        return;
    }
    if (rename("temp.txt", "unpaidList.txt") != 0) {
        cerr << "Error renaming file!" << endl;
        return;
    }

        }
        
}

void deleteConfirmBooking(const string& userName){
    ifstream iConfirmB("confirmBookingList.txt");

    if (!iConfirmB || isStreamEmpty(iConfirmB)) {
        cout << "\nWaiting..." << endl;
        }else{
            ofstream outFile("temp.txt", ios::app);
            string loginName;
            int userChoose, nCheckIn, nCheckOut,nFillPeople;

            while (iConfirmB >> loginName >> userChoose >> nCheckIn >> nCheckOut >> nFillPeople) {
            if (loginName != userName) {
            outFile << loginName << " " << userChoose << " " << nCheckIn << " " << nCheckOut << " "<<nFillPeople <<endl;
        }
    }
    iConfirmB.close();
    outFile.close();
    if (remove("confirmBookingList.txt") != 0) {
        cerr << "Error deleting file!" << endl;
        return;
    }
    if (rename("temp.txt", "confirmBookingList.txt") != 0) {
        cerr << "Error renaming file!" << endl;
        return;
    }

        }

}

void addRoomStatus(int userChooseRoom){
    ifstream iRoomS("roomStatus.txt");
            if (iRoomS.is_open()) {
            vector<int> readNumbers;
            int number;
            while (iRoomS >> number) {
            readNumbers.push_back(number);
            }
            iRoomS.close();

            readNumbers[userChooseRoom-1]+=1;

            ofstream oRoomS("roomStatus.txt");
                if (oRoomS.is_open()) {
                for (int i = 0; i < readNumbers.size(); i++) {
                oRoomS << readNumbers[i] << " ";
                }
                oRoomS.close();
}
}
}

bool isStreamEmpty(ifstream& stream) {
return stream.peek() == ifstream::traits_type::eof();
}


void cancelConfirmBooking(string userLoginName){
    system("cls");
    int count=0;
    int count1=0;
    cout<<"=========================\n";
    cout<<"Previous Booked Room Page"<<endl;
    cout<<"=========================\n";

    ifstream iConfirmB("confirmBookingList.txt");
    if(iConfirmB.is_open()){
        if(isStreamEmpty(iConfirmB)){
                cout<<"\nEmpty Here...\nDo you want to go back to the Home Page (Y=Yes) : "<<endl;
                cin>>userChooseCCBB;
    }else{
        string loginName;
        int userChoose, nCheckIn, nCheckOut,nFillPeople;
        while(iConfirmB>> loginName >>userChoose >> nCheckIn >> nCheckOut>>nFillPeople){
            if(loginName==userLoginName){
                inputUserChooseRoom=userChoose;
                checkIn=nCheckIn;
                checkOut=nCheckOut;
                fillPeople=nFillPeople;
                count+=1;
                break;
            }
        }
        
                if(count==1){
                     cout<<"\nHere is your previous booked room :\nUser Name: "<<userLoginName<<endl;
                vector <string> displayCBInfo={"Booked Room Type","This month of date check in", "This month of date checkout","People"};
                cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
                for(int i=0;i<displayCBInfo.size();i++){
                    cout<<displayCBInfo[i]<<"\t\t";
                }
                cout<<"\n-----------------------------------------------------------------------------------------------------------------------\n";
                cout<<showRoomType[inputUserChooseRoom-1]<<setw(40)<<checkIn<<setw(39)<<checkOut<<setw(20)<<fillPeople<<endl;

                ifstream iUPL("unpaidList.txt");
                if(iUPL.is_open()){
                    if(isStreamEmpty(iUPL)){
                        cout<<"\nYou have paid for this order\nDo you want to cancel the booked room? (Y=Yes,N=No): "; 
                        cin>>userChooseCCB;

                    }else{
                    while(iUPL>> loginName >>userChoose >> nCheckIn >> nCheckOut){
                     if(loginName==userLoginName){
                        count1+=1;
                     }
                    }
                        if(count1==1){
                        cout<<"\nYou have not paid for this order\nDo you want to cancel the booked room? (Y=Yes,N=No): ";
                        cin>>userChooseCCB;
                        }else{
                        cout<<"\nYou have paid for this order\nDo you want to cancel the booked room? (Y=Yes,N=No): "; 
                        cin>>userChooseCCB;
                        }
                        }
                    }else{
                    cout<<"\nYou have paid for this order\nDo you want to cancel the booked room? Y=Yes,N=No): "; 
                    cin>>userChooseCCB;
                }
                iUPL.close();
                }else{
                cout<<"\nEmpty Here...\nDo you want to go back to the Home Page (Y=Yes) : "<<endl;
                cin>>userChooseCCBB;
                }
               
                
        
            }
    }else{
        cout<<"\nEmpty Here...\nDo you want to go back to the Home Page (Y=Yes) : "<<endl;
        cin>>userChooseCCBB;
    }
    iConfirmB.close();
    }
        

void showSystemAdminHomePage(){
    cout<<"\t\t\t\t======================\n";
    cout<<"\t\t\t\tSystem Admin Home Page\n";
    cout<<"\t\t\t\t======================\n\n";
    vector <string> adminMenu={"edit or check room status","edit room prices","edit hotel rooms","edit member information","logout"};
    for(int i=0;i<adminMenu.size();i++){
        cout<<i+1<<"\t"<<adminMenu[i]<<endl;
    }
    cout<<"\nWhich one do you want to edit?\n"<<setw(31)<<"Type here : ";
    cin>>inputAdminChooseMenu;
    system("cls");
}

void adminShowRoomStatus(){
    cout<<"\n\t\tRooms\t\tStatus"<<endl;
    cout<<"\n\t\t-----\t\t------"<<endl;
    for(int i=0;i<showRoomType.size();i++){
        cout<<i+1<<"\t"<<showRoomType[i]<<"\t"<<setw(6)<<availableRoom[i]<<endl;
    }
    cout<<"\n\nDo you want to edit the room status? (Y=yes,N=no) : ";
    cin>>inputAdminEdit;
}

void adminEditRoomStatus(){
    int eRoom, eStatus;
    cout<<"\nWhich room do you want to edit? "<<endl;
    cout<<setw(32)<<"Type here : ";
    cin>>eRoom;
    cout<<"\nStatus change to : ";
    cin>>eStatus;

    ifstream iRoomS("roomStatus.txt");
            if(!iRoomS){
            ofstream foRoomS("roomStatus.txt");
             if (foRoomS.is_open()) {
             for (int i = 0; i < availableRoom.size(); ++i) {
             foRoomS << availableRoom[i] << " ";
             }
            foRoomS.close();
             }
             iRoomS.open("roomStatus.txt");
            }
            if (iRoomS.is_open()) {
            vector<int> readNumbers;
            int number;
            while (iRoomS >> number) {
            readNumbers.push_back(number);
            }
            iRoomS.close();

            if (!readNumbers.empty()) {
                         readNumbers[eRoom-1]=eStatus;
                          }
                    ofstream oRoomS("roomStatus.txt");
                    if (oRoomS.is_open()) {
                    for (int i = 0; i < readNumbers.size(); i++) {
                    oRoomS << readNumbers[i] << " ";
                    }
                   oRoomS.close();
            }
            
            
}
}

void adminShowRoomPrice(){
    cout<<"\n\t\tRooms\t\tPrices"<<endl;
    cout<<"\n\t\t-----\t\t------"<<endl;
    for(int i=0;i<roomPrices.size();i++){
        cout<<i+1<<"\t"<<showRoomType[i]<<"\tRM"<<setw(3)<<roomPrices[i]<<endl;
    }
    cout<<"\n\nDo you want to edit the room price? (Y=yes,N=no) : ";
    cin>>inputAdminEdit;
}

void adminEditRoomPrice(){
    int eRoom, ePrice;
    cout<<"\nWhich room do you want to edit? "<<endl;
    cout<<setw(32)<<"Type here : ";
    cin>>eRoom;
    cout<<"\nPrice change to : RM";
    cin>>ePrice;
}

void adminShowRoom(){
    cout<<"\n\t\tRooms\t\t     ID"<<endl;
    cout<<"\n\t\t-----\t\t    ----"<<endl;
    for(int i=0;i<showRoomType.size();i++){
        cout<<i+1<<"\t"<<showRoomType[i];
        for(int j=0;j<2;j++){
            cout<<"\t"<<roomID[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n\nDo you want to edit the rooms? (Y=yes,N=no) : ";
    cin>>inputAdminEdit;
}
void adminEditRoom(){
    int eRoom; 
    string eID;
    cout<<"\nWhich room do you want to edit? "<<endl;
    cout<<setw(32)<<"Type here : ";
    cin>>eRoom;
    cout<<"\nAdd or Delete Room ID : ";
    cin>>eID;
}



