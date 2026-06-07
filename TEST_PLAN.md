# Test Plan

## 1. Objective

Dokumen ini berisi skenario pengujian untuk memastikan seluruh subsystem pada proyek Balatro Design Pattern berjalan sesuai spesifikasi.

Subsystem yang diuji:

* Poker Hand Evaluation
* Blind State System
* Blind Rule
* Reward System
* Shop System

---

## 2. Poker Hand Evaluation Tests

### TC-01 Pair Detection

Input:

* 7♠
* 7♥

Expected Result:

* Pair detected
* HandRank::PAIR

### TC-02 Two Pair Detection

Input:

* 7♠
* 7♥
* K♦
* K♣

Expected Result:

* Two Pair detected
* HandRank::TWO_PAIR

### TC-03 Three Of A Kind Detection

Expected Result:

* HandRank::THREE_OF_A_KIND

### TC-04 Straight Detection

Expected Result:

* HandRank::STRAIGHT

### TC-05 Flush Detection

Expected Result:

* HandRank::FLUSH

### TC-06 Full House Detection

Expected Result:

* HandRank::FULL_HOUSE

### TC-07 Four Of A Kind Detection

Expected Result:

* HandRank::FOUR_OF_A_KIND

### TC-08 Straight Flush Detection

Expected Result:

* HandRank::STRAIGHT_FLUSH

### TC-09 Royal Flush Detection

Expected Result:

* HandRank::ROYAL_FLUSH

---

## 3. Blind State Tests

### TC-10 Small Blind State

Expected Result:

* Name = Small Blind
* Target Score = 100
* Reward = 5
* Next State = Big Blind

### TC-11 Big Blind State

Expected Result:

* Name = Big Blind
* Target Score = 200
* Reward = 10
* Next State = Boss Blind

### TC-12 Boss Blind State

Expected Result:

* Name = Boss Blind
* Target Score = 400
* Reward = 20
* Next State = nullptr

---

## 4. Blind Rule Tests

### TC-13 Blind Win Condition

Input:

* Score = 150
* Target Score = 100

Expected Result:

* WIN

### TC-14 Blind Lose Condition

Input:

* Score = 50
* Target Score = 100

Expected Result:

* LOSE

---

## 5. Reward System Tests

### TC-15 Reward After Winning Blind

Expected Result:

* Reward granted
* Money increased

### TC-16 Reward After Losing Blind

Expected Result:

* No reward granted
* Money unchanged

---

## 6. Shop System Tests

### TC-17 Purchase Chips Upgrade

Expected Result:

* Bonus Chips increased

### TC-18 Purchase Mult Upgrade

Expected Result:

* Bonus Mult increased

---

## 7. Integration Test

### TC-19 Complete Gameplay Flow

Flow:

Generate Cards
→ Select Cards
→ Detect Poker Hand
→ Calculate Score
→ Check Blind
→ Receive Reward
→ Open Shop
→ Purchase Upgrade

Expected Result:

* All systems execute successfully
* No runtime errors occur
* Gameplay flow completes correctly
