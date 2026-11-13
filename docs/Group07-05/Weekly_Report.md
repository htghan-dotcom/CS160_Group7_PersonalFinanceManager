# Weekly Report - Practical Week 05

* **Project:** Personal Finance Manager 


* **Group ID:** Group07


* **Report Period:** 2026-10-31 to 2026-11-06



---

## 1. Summary of Weekly Activities

During this sprint, the team's primary focus was on expanding core data models, Master Data interfaces, and common utilities. Two members (Huỳnh Trần Gia Hân and Nguyễn Đúc Thành Đạt) were temporarily allocated to university midterm examination schedules and academic tasks, and their development backlog will resume in the subsequent week. The remaining two members (Nguyễn Gia Khánh and Nguyễn Bá Đạt) pushed functional progress on Master Data management and system utility components.

---

## 2. Individual Member Reports

### Huỳnh Trần Gia Hân (`htghan-dotcom`)

* **Assigned Module:** Wallet Management & Data Persistence


* **Tasks Planned for the Week:**
* Complete midterm examination preparation and academic evaluations.
* Review and merge incoming pull requests from team members.




* **Work Completed / Progress:**
* Reviewed and merged Pull Request #1 (`IncomeSources` branch) into `main`.


* Resolved repository branching and sync conflicts.




* **Obstacles / Blockers:**
* Academic midterm exam schedule and concurrent coursework deadlines temporarily delayed code development for the binary serialization module.




* **Next Week Plan:**
* Resume implementation of `Wallet` CRUD logic and persistent binary file I/O operations (`<fstream>`).





---

### Nguyễn Gia Khánh (`gkhanhhh-debug`)

* **Assigned Module:** Master Data & CLI Navigation Framework


* **Tasks Planned for the Week:**
* Build header models for master data categories and establish manager skeletons.




* **Work Completed / Progress:**
* Implemented header entity structures: `IncomeSources.hpp` and `ExpenseCategory.hpp`.


* Developed initial member definitions and manager prototypes: `MasterDataManager.hpp` and `MasterDataManager.cpp`.


* Verified compilation compatibility for category addition and code/name bindings.




* **Obstacles / Blockers:**
* Designing custom dynamic array structures without STL containers requires careful manual memory allocation design.




* **Next Week Plan:**
* Complete the remaining CRUD methods in `MasterDataManager` (update, delete, and validation).


* Scaffold the CLI navigation loop and primary Dashboard screen.





---

### Nguyễn Bá Đạt (`DatJust`)

* **Assigned Module:** Transaction Management & Shared Utilities


* **Tasks Planned for the Week:**
* Develop and refine shared utility functions.




* **Work Completed / Progress:**
* Updated and expanded common utilities (`UpdateUtils` commit `ca42c05`).


* Standardized Date string parsing, formatting, and validation helpers.


* Added boundary checks for leap years and month-end dates to support transactions and recurring logs.




* **Obstacles / Blockers:**
* None significant; awaiting Master Data entity completion to wire foreign key validations.




* **Next Week Plan:**
* Scaffold `IncomeTransaction` and `ExpenseTransaction` structs and integrate them with the Date utility.


* Implement basic balance update logic on transaction creation.





---

### Nguyễn Đức Thành Đạt (`hiepsimauhong`)

* **Assigned Module:** Recurring Automation & Financial Statistics


* **Tasks Planned for the Week:**
* Midterm examination and academic schedule.


* **Work Completed / Progress:**
* Reviewed project requirements for recurring triggers and annual breakdown algorithms.


* No repository commits submitted during this reporting window due to midterm exam week.




* **Obstacles / Blockers:**
* Temporary halt in development due to university midterm examinations.


* **Next Week Plan:**
* Implement `RecurringTransaction` data models and define the monthly trigger cycle algorithm.


* Begin algorithmic design for time-based net balance calculations.





---

## 3. Sprint Retrospective & Overall Project Status

* **Repository Status:** Branch `main` is stable and synchronized. Key master data headers and core utility methods are compiled and integrated.


* **Timeline Assessment:** On track for subsequent phase integration as scheduled. Next sprint will emphasize transaction recording, wallet persistence, and initial CLI dashboard menus.