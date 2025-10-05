# ATM System

A **console-based ATM System** written in C++.

This project is part of my **Learning Path**, done during **Course 8 (Algorithms & Problem Solving Level 4)**  
from the **Programming Advices roadmap**.  
You can explore my full Learning Path repository here: [Learning Path Repository](https://github.com/itsamal0/learning-path)

This project helps me practice problem-solving, clean modular C++ coding, and applying concepts in a real project.

---

## Features

- User login with account number and PIN
- Quick Withdraw (predefined amounts)
- Normal Withdraw (custom amounts)
- Deposit money
- Check account balance
- Logout and return to login screen

---

## Getting Started

### 1. Clone the repository  
If you have Git installed, run:
```bash
git clone https://github.com/itsamal0/atm_system.git
cd atm_system
```
Or download the project as a ZIP file and extract it.

### 2. Build the project  
Make sure you have a C++ compiler (e.g., g++ or clang) installed. Then build the project:
```bash
g++ src/*.cpp include/helpers/*.cpp -o atm_system
```

### 3. Run the program  
After building successfully, run the program:
```bash
./atm_system
```