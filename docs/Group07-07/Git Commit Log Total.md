# Weekly Report - Practical Week 07

* **Project:** Personal Finance Manager
* **Group ID:** Group07
* **Report Period:** 2026-11-14 to 2026-11-20

---

## 1. Summary of Weekly Activities

This sprint focused on the CLI layer and transaction logic. The menu structure of the
application was established, console helper functions were moved into the shared Utils
module, and the Transaction and Utils modules were updated and fixed. The statistics
feature branch was merged into `main` via Pull Request #4. Team members also spent time
synchronizing their local branches with `main` to keep the codebase consistent.

---

## 2. Individual Member Reports

### Huỳnh Trần Gia Hân (`htghan-dotcom`)
* **Assigned Module:** Wallet Management & Data Persistence
* **Tasks Planned for the Week:**
  * Implement binary file I/O for wallet persistence.
  * Review incoming pull requests from team members.
* **Work Completed / Progress:**
  * Reviewed teammates' pull requests, including the statistics feature branch.
  * Designed the binary file layout for saving and loading wallet data.
* **Obstacles / Blockers:**
  * Persistence work depends on the final shape of the transaction structs, which were still being updated this week.
* **Next Week Plan:**
  * Implement binary file read/write for wallets and connect it to the transaction data.
  * Test save/load round trips with several wallets.

### Nguyễn Gia Khánh (`gkhanhhh-debug`)
* **Assigned Module:** Master Data & CLI Navigation Framework
* **Tasks Planned for the Week:**
  * Complete the CLI navigation loop and menu structure.
  * Reorganize console helper functions for reuse.
* **Work Completed / Progress:**
  * Moved console utility functions into `Utils` for reuse across modules (`26538c4`).
  * Implemented the menu structure of the CLI (`06c3419`).
  * Synchronized local work with `main` (`07bacb0`).
* **Obstacles / Blockers:**
  * Merge conflicts and duplicated commits appeared when syncing with `main`, which cost some time to clean up.
* **Next Week Plan:**
  * Connect menu items to the Master Data, Wallet and Transaction functions.
  * Polish the Dashboard screen and input validation in the CLI.

### Nguyễn Bá Đạt (`DatJust`)
* **Assigned Module:** Transaction Management & Shared Utilities
* **Tasks Planned for the Week:**
  * Integrate transaction structs with the Date utility.
  * Fix issues in the transaction and utils modules.
* **Work Completed / Progress:**
  * Updated and fixed the transaction and utils modules (`60dc6bc`, `0c2aaa3`).
  * Converted string handling to dynamically allocated `char` arrays to follow the project's no-STL-container rule.
  * Synchronized local work with `main` (`5623a00`).
* **Obstacles / Blockers:**
  * Manual memory management for strings required careful allocation and cleanup to avoid leaks and double frees.
* **Next Week Plan:**
  * Implement `ExpenseTransaction` handling and balance update logic on transaction creation.
  * Add foreign key validation against wallets, income sources and expense categories.

### Nguyễn Đức Thành Đạt (`hiepsimauhong`)
* **Assigned Module:** Recurring Automation & Financial Statistics
* **Tasks Planned for the Week:**
  * Deliver the first version of the statistics feature.
* **Work Completed / Progress:**
  * Completed the statistics feature branch and merged Pull Request #4 into `main` (`3301247`).
* **Obstacles / Blockers:**
  * Statistics calculations rely on transaction data that is still being finalized.
* **Next Week Plan:**
  * Implement `RecurringTransaction` data models and the monthly trigger cycle.
  * Extend statistics to annual breakdowns and
