# C++ & Qt Best Practices Examples

A curated collection of tested and practical **C++ and Qt examples** focused on real-world best practices. This repository is designed to help developers learn, revisit, and apply clean, efficient, and modern patterns in their daily work.

---

## 🔧 What You'll Find

This repo includes categorized examples around:

- **🧵 Threading**
  - Safe usage of `QThread`, `std::thread`, and worker patterns
  - Event loop-based threading vs. raw threads
  - Thread synchronization with mutex, condition variables, and signals/slots

- **🔁 Pointer Management**
  - Smart pointers (`std::unique_ptr`, `std::shared_ptr`, `QSharedPointer`, `QSocpedPointer` ) vs. raw pointers
  - Ownership semantics in Qt with `QObject` trees
  - Lifetime management and avoiding memory leaks

- **🚀 Performance Tips**
  - Avoiding unnecessary heap allocations
  - Understanding copy/move semantics
  - Using references, reserve(), and other STL optimization tips
  - Qt's implicit sharing (copy-on-write) and how to use it efficiently

---

## 💡 Why This Exists

Too often, developers fall into common traps when using Qt or modern C++—from incorrect use of `QThread` to leaky object trees. This repo is a growing collection of **well-commented, testable examples** to:

- Serve as a reference during development
- Act as educational material for new developers on your team
- Benchmark patterns to choose the most suitable one

---

## 📂 Structure

Each topic has its own folder:

## 🌳 Project Tree

```bash
Project
│   .gitignore
│   CMakeLists.txt
│   CMakeLists.txt.user
│   main.cpp
│   README.md
│   tree.txt
│
├───Performance
│       CMakeLists.txt
│       gettersetterperf.cpp
│       gettersetterperf.h
│       main.cpp
│       mainclass.cpp
│       mainclass.h
│
├───Pointers
│       child.cpp
│       child.h
│       CMakeLists.txt
│       main.cpp
│       mainclass.cpp
│       mainclass.h
│       mythread.cpp
│       mythread.h
│
└───Threading
        CMakeLists.txt
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        worker.cpp
        worker.h
        workerthread.cpp
        workerthread.h
```

---

> [!NOTE] 
> Each file is standalone and runnable.

---

## 🧪 Requirements

- **Qt 5 or Qt 6**
- **C++17 or later**
- A compiler with CMake support (e.g. GCC, Clang, MSVC)

---

## 📈 Contributions

This repo is under active development. If you have a useful pattern, example, or benchmark, feel free to open a PR!

---

> Maintained with care by [Parsa Pournabi (@wearily)](https://github.com/parsapournabi)  
> _"Code it clean, test it hard."_ 🛠️
