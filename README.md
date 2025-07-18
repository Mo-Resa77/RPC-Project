# 🔁 Substring Check RPC Application

## 📌 Overview

This project implements a **client-server application using Remote Procedure Call (RPC) over UDP**.  
The server provides a service to check if one string is a substring of another.  
The client sends two strings to the server and receives the result.

The application is defined by an RPC specification (`square.x`) and implemented in C using:

- `square_server.c` – Server code
- `square_client.c` – Client code

---

## 🌟 Features

### 🖥️ Server:
- Implements remote procedure: `MORESA_CHECK_SUBSTRING`
- Checks if `str1` is a substring of `str2`
- Returns `1` (true) or `0` (false)
- Communicates over **UDP**

### 👤 Client:
- Takes **hostname** and **two strings** as command-line arguments
- Sends request via **RPC**
- Displays result:
  - `"Yes"` if substring
  - `"No"` if not

### 📜 RPC Specification (`square.x`)
- Defines `moresa_string_pair` struct with two strings
- Unique **program number**: `0x20000002`

---

## 📁 Files

- `square.x`: RPC specification
- `square_server.c`: Server logic
- `square_client.c`: Client logic
- 🔄 Generated via `rpcgen`:
  - `square.h`
  - `square_svc.c`
  - `square_clnt.c`

---

## 🧰 Prerequisites

- A **C compiler** (e.g., `gcc`)
- **rpcgen** tool (for stub generation)
- RPC libraries (`rpcsvc`, often built-in)
- **Unix-like environment** (Linux, macOS, WSL)

> ✅ Client and server can run on the same or different machines (if accessible via hostname)

---

## ⚙️ Compilation

### 🔧 Generate RPC Code
```bash
rpcgen square.x

