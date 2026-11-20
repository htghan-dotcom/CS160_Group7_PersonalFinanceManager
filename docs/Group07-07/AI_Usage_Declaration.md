# AI Usage Declaration - Practical Week 07

- **Project:** Personal Finance Manager 
- **Group ID:** Group07
- **Report Period:** Start - Practical Week 07 (From: 2026-11-14 to 2026-11-20)

---

## 1. Team Summary Overview

| No. | Student ID | Full Name | GitHub Username | AI Tool Used | Status / Declaration |
| :---: | :---: | :--- | :--- | :---: | :--- |
| 1 | 25125042 | Huỳnh Trần Gia Hân | `htghan-dotcom` | None | Did not use AI during this period |
| 2 | 26125014 | Nguyễn Bá Đạt | `DatJust` | None | Did not use AI during this period |
| 3 | 26125015 | Nguyễn Đức Thành Đạt | `hiepsimauhong` | None | Did not use AI during this period |
| 4 | 26125036 | Nguyễn Gia Khánh | `gkhanhhh-debug` | Gemini 2.5 Flash | Declared with full prompt log below |

---

## 2. Individual Declarations

### 2.1. Member: Huỳnh Trần Gia Hân
- **Student ID:** 25125042
- **GitHub Username:** `htghan-dotcom`
- **Assigned Module:** Wallet Management & Data Persistence
- **Declaration:** I did not use any AI tools during this reporting period.

---

### 2.2. Member: Nguyễn Bá Đạt
- **Student ID:** 26125014
- **GitHub Username:** `DatJust`
- **Assigned Module:** Transaction Management & Shared Utilities
- **Declaration:** I did not use any AI tools during this reporting period.

---

### 2.3. Member: Nguyễn Đức Thành Đạt
- **Student ID:** 26125015
- **GitHub Username:** `hiepsimauhong`
- **Assigned Module:** Recurring Automation & Financial Statistics
- **Declaration:** I did not use any AI tools during this reporting period.

---

### 2.4. Member: Nguyễn Gia Khánh
- *Student ID:* 26125036
- *GitHub Username:* gkhanhhh-debug
- *Assigned Module:* Master Data & CLI Navigation Framework
- *AI Tool Used:* Gemini. Gemini 2.5 Flash, gemini.google.com, accessed on 20/11/2026

#### Prompt & Interaction Log:

*Prompt 1:* chia nhỏ việc ra nữa (Breaking down remaining CLI integration tasks into smaller milestones)  

    I use this as a planning aid to break down the module integration phase into smaller, incremental steps so that each component can be compiled and verified independently. I reviewed the proposed task breakdown and organized my local implementation workflow accordingly.



*Prompt 2:* làm mục 1 (Clarifying C++ header/source separation and inline linkage rules)  

    I use this to understand C++ translation unit compilation rules and how to properly separate function declarations in header files from implementations in `.cpp` files to prevent `undefined reference` linker errors. I studied the explanation and structured `ConsoleUtils.h` and `Utils.h` cleanly.



*Prompt 3:* rồi (Designing the minimal Menu loop skeleton and dynamic memory cleanup flow)  

    I use this to verify how to structure a minimal CLI navigation skeleton (`Menu.h` / `Menu.cpp`) and ensure safe dynamic memory deallocation (`freeWallets`, `freeIncomeList`) upon program exit. I reviewed the execution flow and wrote the initial skeleton to test Dashboard rendering.



*Prompt 4:* biên dịch thử theo cấu trúc này [Attached project directory structure]  

    I use this to understand how to configure `g++` compiler include paths (`-Iinclude`) and link multiple `.cpp` source files across nested directories (`src/managers`, `src/ui`). I ran and verified the build command locally to confirm there were no compilation or linking errors.



*Prompt 5:* biên dịch được rồi (Structuring multi-level menu routing for Master Data CRUD operations)  

    I use this as a reference to design clean `switch-case` sub-menus that connect my `MasterDataManager` CRUD functions (`IncomeSource` and `ExpenseCategory`) with the automated Dashboard refresh loop. I reviewed the routing pattern and adapted the menu handlers to match my repository's file names (`Menu.h`, `Menu.cpp`).
