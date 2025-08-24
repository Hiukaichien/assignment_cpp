# Hotel Booking System

This is a simple C++ console application for managing hotel room bookings, payments, and administration. The system supports both user and admin roles, allowing users to book rooms and admins to manage room status, prices, and room information.

## Features

- **User Functions:**
  - Sign up and log in
  - Book available rooms
  - View and cancel previous bookings
  - Make payments for bookings
  - View unpaid bills

- **Admin Functions:**
  - Log in with admin credentials
  - View and edit room status (availability)
  - View and edit room prices
  - View and edit room IDs
  - Manage member information (maintenance)

## File Structure

- `coding.cpp` - Main source code for the hotel booking system
- `records.txt` - Stores user credentials (username and password)
- `roomStatus.txt` - Stores the number of available rooms for each type
- `confirmBookingList.txt` - Stores confirmed bookings
- `unpaidList.txt` - Stores unpaid bookings
- `Assignment.code-workspace` - VS Code workspace settings
- Other files: images, documentation, and presentation files

## How to Run

1. **Compile the code:**
   ```sh
   g++ coding.cpp -o coding.exe
   ```

2. **Run the program:**
   ```sh
   ./coding.exe
   ```

3. **Follow the on-screen instructions** to log in as a user or admin.

## Default Admin Credentials

- **Username:** `eric_chien`
- **Password:** `3322112`

## Notes

- All data is stored in plain text files in the project directory.
- Make sure the program has permission to read/write these files.
- The system uses simple console input/output and is intended for educational purposes.

## License

This project is for educational
