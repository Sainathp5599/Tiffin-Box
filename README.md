# 🍱 TIFFIN BOX MANAGEMENT SYSTEM

## 🎯 Project Summary
The **Tiffin Box Management System** is a console-based application developed in **C programming** to automate and manage daily food orders between **buyers** (customers) and **distributors** (tiffin providers). It serves as a practical demonstration of **structures, file handling, and menu-driven logic**.

---

## 🧠 Objectives
* To automate the daily tiffin ordering process efficiently.
* To maintain and manage buyer registration data and daily menus using text files.
* To provide separate, secure dashboards for buyers and the distributor.
* To practice core C concepts like file I/O (`orders.txt`, `buyer.txt`), data structures (structs), and conditional logic.

---

## 🖥️ Technical Specifications
| Requirement | Details |
| :--- | :--- |
| **Language** | C Programming |
| **Compiler** | GCC / Turbo C / Code::Blocks |
| **Operating System** | Windows / Linux / macOS |
| **Storage** | **Text File-based** Data Handling |
| **Source File** | `tiffin_box.c` |

---

## 🧩 Key Features

### 👤 Buyer Dashboard
| Feature | Description |
| :--- | :--- |
| **Registration & Login** | Create and securely access an account. |
| **Show Today’s Menu** | View items and prices added by the distributor. |
| **Place Order** | Select items, specify quantity, and confirm the order. |
| **Cancel Order** | Remove an existing, active order. |
| **View My Orders** | Check a summary of all placed orders and the total amount. |

### 👨‍🍳 Distributor Dashboard
| Feature | Description |
| :--- | :--- |
| **Login** | Secure access using predefined credentials (`admin`/`1234`). |
| **Add Today’s Menu** | Overwrite/update the daily menu with new items and prices. |
| **View Buyer Orders** | Display all active orders placed by all buyers, calculating total potential revenue. |

---

## 💾 Data Files Used
The system relies on four primary text files for persistent data storage:

| File Name | Purpose | Data Fields Stored |
| :--- | :--- | :--- |
| `buyer.txt` | Stores buyer registration details. | Name, Mobile, Address, Username, Password |
| `menu.txt` | Stores the current day's menu items and prices. | Item ID, Item Name, Price |
| `orders.txt` | Stores all currently **active** buyer orders. | Order ID, Buyer Username, Item ID, Quantity, Total Amount |
| `cancelled.txt` | Logs all orders that have been cancelled (for record keeping). | Order details + 'CANCELLED' flag |

---

## 🧭 Program Flowchart (Text Diagram)

```text
       +-----------------------+
       |        START          |
       +-----------+-----------+
                   |
                   v
       +-----------------------+
       |      Display MAIN     |
       |      MENU (1-4)       |
       +-----------+-----------+
                   |
             +-----v------+
             | Get Choice |
             +-----^------+
                   |
      +------------+-------------+
      |  CASE 1: Buyer Reg.  |
      |  CASE 2: Buyer Login |
      |  CASE 3: Dist. Login |
      |  CASE 4: Exit        |
      +------------+-------------+
        /    |     \        \
       /     |      \        \
      v      v       v        v
[Register] [Go to] [Go to]  [END]
           [BUYER] [DIST.]
           [MENU]  [MENU]

BUYER MENU: -> Show Menu -> Place Order -> Cancel Order -> View Orders -> Logout
DIST. MENU: -> Add Menu -> View Orders -> Logout