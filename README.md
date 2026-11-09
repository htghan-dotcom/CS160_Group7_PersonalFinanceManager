# CS160 - Group07 - Personal Finnance Manager Project 

## Build and Run Guide

### Prerequisites
- **C++ Compiler**: Supporting C++17 (GCC, Clang, or MSVC)
- **CMake**: Version 3.16 or newer
- **Terminal / Shell**: Command Prompt, PowerShell, or Bash

---

### Step-by-Step Instructions

#### 1. Windows (MinGW / GCC)
Open PowerShell or Command Prompt at the project root directory:
```cmd
# 1. Generate build files
cmake -B build -G "MinGW Makefiles"

# 2. Compile the project
cmake --build build

# 3. Run the application
.\build\app.exe

```

#### 2. Windows (Visual Studio / MSVC)

```cmd
# 1. Generate Visual Studio project
cmake -B build

# 2. Compile Release executable
cmake --build build --config Release

# 3. Run the application
.\build\Release\app.exe

```

#### 3. Linux / macOS (Unix Makefiles)

Open terminal at the project root directory:

```bash
# 1. Generate build files
cmake -B build

# 2. Compile the project
cmake --build build

# 3. Run the application
./build/app

```

---

### Run in Visual Studio Code (Quick Workflow)

1. Install the **C/C++** and **CMake Tools** extensions.
2. Open the project root folder in VS Code.
3. Select your compiler kit from the bottom status bar (GCC, Clang, or MSVC).
4. Press **`F7`** to build.
5. Press **`Shift + F5`** (or click **Run** on the status bar) to launch the app.

```
