# Banh Chung - Banh Giay Legend

## 1. Problem Overview

**Goal:**
- Minimize leftover rice (**primary priority**)
- Maximize total number of cakes (**secondary priority**)

**Input (`input.inp`):**
- `n`: Total sticky rice (≤ 2000)
- `dc`: Side length of Banh Chung
- `dg`: Diameter of Banh Giay
- `ld`: Number of Dong leaves (1 → 600)
- `w`: Weather condition (`Rain`, `Sun`, `Cloud`, `Fog`, `Wind`)

**Output (`output.out`):**
- `bc`: Number of Banh Chung
- `bg`: Number of Banh Giay
- `nd`: Remaining rice (rounded to 3 decimal places)

---

## 2. Technical Formulas

- **Rice per Banh Chung:**

dc^2 * sqrt(dc)


- **Rice per Banh Giay:**

(dg^2 * π) / 3


- **Leaves per cake:**
- 1 leaf if `dc < 8` or `dg < 5`
- 2 leaves otherwise

- **Constant:**

π = 3.1415926535


---

## 3. Weather Logic

| Weather | Behavior |
|--------|---------|
| **Wind** | Maximize Banh Chung first, then Banh Giay |
| **Rain** | Balance `bc` and `bg` while minimizing leftover rice |
| **Sun** | Increase rice (+X%) and decrease leaves (-X), then update weather based on `(dc + dg) mod 3` |
| **Fog** | If `dc`, `dg` are Fibonacci → size reduced by 50%; otherwise → size doubled. Produce minimum cakes |
| **Cloud** | Maximize Banh Giay first. If `n` and `ld` are amicable numbers → produce 0 cakes |

---

## 4. Requirements

- **Language:** Pure C
- **Compiler:** `gcc` (Unix/Linux)
- **Constraints:**
- No extra output
- No `system("pause")` or `getch()`
- **Precision:**
- Do not round intermediate calculations
- Final leftover rice rounded to **3 decimal places**
