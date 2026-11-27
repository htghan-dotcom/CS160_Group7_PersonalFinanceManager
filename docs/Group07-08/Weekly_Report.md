# Weekly Report - Practical Week 08

* **Project:** Personal Finance Manager

* **Group ID:** Group07

* **Report Period:** 2026-11-21 to 2026-11-27

---

## 1. Summary of Weekly Activities

The team connected income and expense recording, wallet balances, transaction history, financial reports and monthly schedules to the menu.

---

## 2. Individual Member Reports

### Huỳnh Trần Gia Hân (`htghan-dotcom`)

* **Assigned Module:** Wallet Management & Data Persistence

* **Tasks Planned for the Week:**
* Continue work on wallet storage.

* **Work Completed / Progress:**
* No commits by this member appear in the main branch history for this week.

* **Obstacles / Blockers:**
* Wallet data is kept only for the current session.

* **Next Week Plan:**
* Implement binary save/load and check balances after a restart.

---

### Nguyễn Gia Khánh (`gkhanhh-debug`)

* **Assigned Module:** Master Data & CLI Navigation Framework

* **Tasks Planned for the Week:**
* Connect the menu and resolve build issues.

* **Work Completed / Progress:**
* Fixed header paths in the menu, master data manager and main program.

* **Obstacles / Blockers:**
* Some header paths did not match the project folders.

* **Next Week Plan:**
* Build from a fresh checkout and test invalid menu input.

---

### Nguyễn Bá Đạt (`DatJust`)

* **Assigned Module:** Transaction Management & Shared Utilities

* **Tasks Planned for the Week:**
* Add expense recording and update the shared date utilities.

* **Work Completed / Progress:**
* Added expense recording and updated the transaction and date interfaces.

* **Obstacles / Blockers:**
* Rejected expenses must leave the wallet balance unchanged.

* **Next Week Plan:**
* Test invalid IDs and expenses that exceed the wallet balance.

---

### Nguyễn Đức Thành Đạt (`hiepsimauhong`)

* **Assigned Module:** Recurring Automation & Financial Statistics

* **Tasks Planned for the Week:**
* Add monthly recurring transactions and extend financial reports.

* **Work Completed / Progress:**
* Connected monthly schedules and all five statistics options to the menu. Each schedule runs at most once per month during a session.

* **Obstacles / Blockers:**
* Checking for duplicates after a restart requires saved schedules and their last processed month.

* **Next Week Plan:**
* Test month-end schedules and repeat the checks once save/load is available.

---

## 3. Sprint Retrospective & Overall Project Status

* **Repository Status:** PR #5 merged the menu, statistics and recurring transactions into `main`.

* **Timeline Assessment:** Next, save wallets, transactions and schedules, then test the full workflow after restarting the app.
