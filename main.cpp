#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::to_string;

int main() {
  cout << "This program is entirely hardcode (for now).\n";

  string user="", pwd="";
  int choice = 0 ;
  string userType = "";
  int room = 0;
  float bill = 0.00;
  string keycode = "000000";
  string resv_input = "";
  bool checkin = false;
  bool checkout = false;
  bool guestConfirmed = false;

  //hardcode data
  string roomList = "101, 102, 103, 104, 105";
  int resv_num = 123456;
  string guest_name = "Joe";
  string guest_resv_num = "741852963";

  do
  {
    cout << "Log In\n";
    cout <<"Username:";
    cin >> user;
    cout <<"Password:";
    cin >> pwd;
  } while (user!="AlbertK" && pwd!="akpwd123");

  cout << "Options\n"
          "1 - Guest\n"
          "2 - Reservation Staff\n";
  cin >> choice;
  if (choice == 1)
  {
    userType = "Guest";
  } else if (choice == 2) {
    userType = "Reservation Staff";
  } else { 
    userType = "UNDEFINED";
  }
  cout << "You are a " + userType + ".\n";
  
  if (userType == "Guest") {
    do
    {
      choice = 0;
      cout << "\nOptions\n"
            "1 - Show Available Rooms\n"
            "2 - Create Reservation\n"
            "3 - Make Prepayment\n"
            "4 - Exit\n";
      cin >> choice;

      if (choice == 1)
      {
        cout << "List of rooms: " + roomList << endl;
        cout << "Select a room: ";
        cin >> room;
        cout << "You selected room " + to_string(room) + ".\n";
      } else if (choice == 2)
      {
        cout << "Creating reservation...\n";
        if (room != 0) {
          cout << "You selected to reserve room " + to_string(room) + ".\n";
          bill = 250;
          cout << "Your Reservation Number: " + to_string(resv_num) << endl;
          cout << "Your bill is $" + to_string(bill) + ". Please make the prepayment.\n";
        } else {
          cout << "No room has been selected.\n";
        }
      } else if (choice == 3) 
      {
        if (bill != 0)
        {
          cout << "Your bill is currently $" + to_string(bill) + ".\n";
          cout << "Processing payment...Complete\n";
          bill = 0;
        } else {
          cout << "You have no bill.\n";
        }
        

      }
      
    } while (choice != 4);
  } else if (userType == "Reservation Staff") 
  {
    do
    {
      choice = 0;
      cout << "\nOptions\n"
        "1 - Retrieve Guest Information\n"
        "2 - Check In\n"
        "3 - Check Out\n"
        "4 - Generate Key Code\n"
        "5 - Exit\n";
      cin >> choice;

        if (choice == 1)
        {
          cout << "Enter Reservation Number of the Guest: ";
          cin >> resv_input;
          if (resv_input == guest_resv_num)
          {
            cout << "Guest Name: " + guest_name + ".\n";
            guestConfirmed = true;
          } else {
            cout << "Invaid reservation number.\n";
          }
          
        } else if (choice == 2)
        {
          if (checkin) {
            cout << "Guest is already checked in.\n";
          } else if (!guestConfirmed)
          {
            cout << "Guest has not been confirmed yet. Please Retrieve Guest Information.\n";
          } else {
            checkin = true;
            cout << "Checking In....Complete!\n";
          }
        } else if (choice == 3)
        {
          if (!checkin) {
            cout << "Guest was not checked in.\n";
          }
          else if (checkout)
          {
            cout << "Guest is already checked out.\n";
          } else if (!guestConfirmed)
          {
            cout << "Guest has not been confirmed yet. Please Retrieve Guest Information.\n";
          }else {
            checkout = true;
            checkin = false;
            cout << "Checking out....Complete!\n";
          }
        } else if (choice == 4)
        {
          if (checkin)
          {
            cout << "Generating KeyCode...\n";
            keycode = "951asd";
            cout << "Your key code is " + keycode + ".\n";
          } else if (!guestConfirmed)
          {
            cout << "Guest has not been confirmed yet. Please Retrieve Guest Information.\n";
          }else {
            cout << "Guest is not checked in.\n";
          }
        }
        
    } while (choice != 5);
  }
  else {
    cout << "User type is " + userType + ".\n";
  }
  cout << "GOODBYE.\n";
  
  
  


}

