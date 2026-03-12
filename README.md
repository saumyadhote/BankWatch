Fraud Detection in Banking Transactions using the Two Pointer Algorithm
📌 Project Overview
FraudShield is a simple algorithm-based project that demonstrates how suspicious banking transactions can be detected efficiently. The system checks whether any two transaction amounts combine to reach a predefined fraud threshold.
Instead of comparing every possible pair of transactions, this project uses the Two Pointer Algorithm, which significantly improves efficiency when working with sorted transaction datasets.
🎯 Objective
Detect suspicious transaction pairs efficiently.
Demonstrate the real-world application of the Two Pointer Algorithm.
Reduce computational complexity compared to brute-force approaches.
⚙️ Algorithm Used
Two Pointer Algorithm
The technique works by placing:
One pointer at the beginning of the transaction list
One pointer at the end of the transaction list
The pointers move inward based on the comparison of the transaction sum with the fraud threshold.
🔄 Algorithm Workflow
Sort the transaction amounts in ascending order.
Initialize two pointers:
Left Pointer → smallest transaction
Right Pointer → largest transaction
Calculate the sum of the two transaction values.
Compare the sum with the suspicious threshold.
Move pointers accordingly:
If sum < threshold → move left pointer right
If sum > threshold → move right pointer left
Continue until:
A suspicious pair is found, or
The pointers meet.