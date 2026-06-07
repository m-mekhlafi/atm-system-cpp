# 🏦 Bilingual ATM System in C++ | نظام الصراف الآلي ثنائي اللغة

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue.svg" alt="C++">
  <img src="https://img.shields.io/badge/Environment-Linux%20%2F%20Terminal-orange.svg" alt="Linux">
  <img src="https://img.shields.io/badge/License-MIT-green.svg" alt="License">
</p>

---

## 📝 Description (الوصف)

### [English]
A lightweight, console-based ATM (Automated Teller Machine) simulation system built using C++. The project features full **bilingual support (Arabic & English)**, custom sub-structures for managing dynamic interface text, and robust user session tracking (supporting up to 10 concurrent user profiles with custom PIN verification).

### [العربية]
نظام محاكاة صراف آلي (ATM) خفيف ومبني بالكامل ليعمل داخل التيرمينال باستخدام لغة C++. يتميز المشروع بـ **دعم كامل ومباشر للغتين (العربية والإنجليزية)** عبر مصفوفة وهياكل بيانات مخصصة (`struct Language`)، مع إمكانية إدارة حسابات المستخدمين وسحوباتهم المخططة (يدعم حتى 10 مستخدمين مع نظام التحقق من الرمز السري PIN).

---

## 🚀 Key Features (المميزات الرئيسية)

* **Bilingual Toggle:** Dynamic interface switching between Arabic and English at startup.
* **Account Management:** Secure registration for new users with PIN mismatch protection.
* **Core Banking Operations:** Integrated functional sub-routines for:
    * `Deposit()` - Add funds instantly with live balance updates.
    * `Withdraw()` - Securely subtract funds with automated insufficient balance checks.
    * `ShowAccount()` - Full profile overview including Name, unique UserID, and balance.
* **Data Consistency:** Safe buffer management via `cin.ignore()` to prevent character escaping during loop routines.

---

## 🛠️ How to Compile and Run (كيفية التشغيل)

You can easily compile and run this project on any Linux environment (like Debian/Ubuntu) using `g++`:

```bash
# 1. Compile the source code
g++ main.cpp -o atm_system

# 2. Run the executable
./atm_system
