# Balatro Design Pattern Project

## 1. Project Overview

Proyek ini merupakan implementasi beberapa Design Pattern dalam C++ untuk mensimulasikan gameplay sederhana yang terinspirasi dari Balatro.

Sistem mencakup:

* Poker Hand Detection
* Blind Progression
* Scoring System
* Reward System
* Shop System

Tujuan utama proyek adalah menunjukkan penerapan Design Pattern pada sistem permainan yang modular dan mudah dikembangkan.

---

## 2. Design Patterns

### 2.1 Chain of Responsibility Pattern (Poker Hand Detection)

Digunakan untuk mendeteksi kombinasi kartu poker berdasarkan prioritas hand.

#### Implementasi

Base Class:

* PokerHandChecker

Concrete Checkers:

* RoyalFlushChecker
* StraightFlushChecker
* FlushFiveChecker
* FlushHouseChecker
* FiveOfAKindChecker
* FourOfAKindChecker
* FullHouseChecker
* FlushChecker
* StraightChecker
* ThreeOfAKindChecker
* TwoPairChecker
* PairChecker
* HighCardChecker

#### Cara Kerja

Setiap checker akan memeriksa apakah hand memenuhi kriterianya.

Jika tidak memenuhi, maka request diteruskan ke checker berikutnya dalam chain.

#### Chain Order

Royal Flush
→ Straight Flush
→ Flush Five
→ Flush House
→ Five of a Kind
→ Four of a Kind
→ Full House
→ Flush
→ Straight
→ Three of a Kind
→ Two Pair
→ Pair
→ High Card

---

### 2.2 State Pattern (Blind Progression)

Digunakan untuk mengatur progresi blind dalam permainan.

#### Implementasi

Abstract State:

* BlindState

Concrete States:

* SmallBlindState
* BigBlindState
* BossBlindState

#### Cara Kerja

Setiap state menyimpan:

* Nama blind
* Target score
* Reward money
* State berikutnya

#### Blind Progression

Small Blind
→ Big Blind
→ Boss Blind

---

### 2.3 Command Pattern (Shop System)

Digunakan untuk memisahkan aksi pembelian upgrade dari sistem shop.

#### Implementasi

Base Command:

* ShopCommand

Concrete Commands:

* AddChipsCommand
* AddMultCommand

#### Cara Kerja

Setiap command merepresentasikan satu aksi upgrade yang dapat dieksekusi oleh ShopSystem.

---

## 3. Core Components

### 3.1 GameManager

Mengatur alur permainan secara keseluruhan.

Tanggung jawab:

* Menjalankan gameplay loop
* Mengelola sesi permainan
* Menghubungkan seluruh sistem

---

### 3.2 ScoringRule

Mengubah hasil evaluasi poker hand menjadi score.

---

### 3.3 BlindRule

Menentukan apakah score pemain berhasil memenuhi target blind.

---

### 3.4 RewardManager

Mengelola reward yang diperoleh pemain.

---

### 3.5 ShopSystem

Mengelola pembelian upgrade menggunakan uang pemain.

---

### 3.6 UpgradeData

Menyimpan seluruh bonus yang diperoleh pemain.

```cpp
struct UpgradeData {
    int bonusChips = 0;
    int bonusMult = 0;
};
```

---

## 4. Supported Poker Hands

* Royal Flush
* Straight Flush
* Flush Five
* Flush House
* Five of a Kind
* Four of a Kind
* Full House
* Flush
* Straight
* Three of a Kind
* Two Pair
* Pair
* High Card

---

## 5. Gameplay Flow

Generate Cards
↓
Choose Cards
↓
Detect Poker Hand
↓
Calculate Score
↓
Check Blind
↓
Receive Reward
↓
Open Shop
↓
Purchase Upgrade
↓
Next Blind

---

## 6. Build & Run

```bash
g++ *.cpp -o main
./main
```

---

## 7. Technologies

* C++17
* Chain of Responsibility Pattern
* State Pattern
* Command Pattern

## 8. Collaboration & Git Workflow

Proyek dikembangkan secara kolaboratif dengan pembagian tugas pada branch masing-masing sesuai tanggung jawab fitur yang dikerjakan.

### Pembagian Pengerjaan

**Aulia**

* Reward System
* Shop System
* Command Pattern
* Gameplay Integration

**Nesya**

* Poker Hand Detection
* Chain of Responsibility Pattern
* Blind Progression
* State Pattern
* Scoring Logic

### Git Workflow

Pengembangan dilakukan pada branch masing-masing untuk meminimalkan konflik selama pengerjaan.

Workflow yang digunakan:

```text
Main Branch
   ↑
Nesya Branch
   ↑
Aulia Branch
```

Alur kerja:

1. Aulia mengembangkan fitur pada branch miliknya.
2. Perubahan di-push ke repository dan di-pull oleh Nesya.
3. Nesya melakukan integrasi, pengujian, dan validasi terhadap perubahan yang diterima.
4. Setelah seluruh fitur berjalan dengan baik, perubahan di-merge ke branch `main`.

Pendekatan ini memungkinkan proses pengembangan dan pengujian dilakukan secara bertahap sebelum fitur dirilis ke branch utama.
