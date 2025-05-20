# Queue Implementation in C

This project provides a simple implementation of a **linear queue using an array** in the C programming language.

## 🚀 Features

- Fixed-size queue using an array (`#define Que_Size 100`)
- Basic queue operations:
  - Enqueue
  - Dequeue
  - Peek (front element)
  - End (rear element)
  - Display the queue
- Overflow and underflow checks
- Menu-driven console interface

## 🛠️ How It Works

- The queue uses two indices: `Front` and `Rare` (rear).
- On enqueue, the element is added at the rear.
- On dequeue, the element is removed from the front.
- If the queue becomes empty, both `Front` and `Rare` are reset to `-1`.

## 💡 Limitation

This is a **linear queue**, so:
- Once the rear reaches the end (`Rare == Que_Size - 1`), the queue cannot accept more elements even if space is freed at the front.
- To fix this, a **circular queue** implementation can be used.

## 📂 File Structure

- `queue.c` - Main C program implementing the queue logic.

## 📦 How to Compile and Run

```bash
gcc queue.c -o queue
./queue
