# 📚 The Curriculum of Code: Learn-by-Concept Table

| Concept           | What You Learn                | Do It In Every Language?            |
| ----------------- | ----------------------------- | ----------------------------------- |
| ✅ Variables       | Declaring, mutability, types  | ✅ Yes                               |
| ✅ Data Types      | Ints, floats, strings, bools  | ✅ Yes                               |
| ✅ Operators       | Math, logical, bitwise        | ✅ Yes                               |
| ✅ Input/Output    | CLI reading, print formatting | ✅ Yes                               |
| ✅ Conditionals    | `if`, `else`, ternaries       | ✅ Yes                               |
| ✅ Loops           | `for`, `while`, loop control  | ✅ Yes                               |
| ✅ Functions       | Params, return, scope         | ✅ Yes                               |
| ✅ Data Structures | Lists, maps, sets, structs    | ✅ Yes                               |
| ✅ File I/O        | Read/write to text files      | ✅ Yes                               |
| ✅ Error Handling  | `try/catch`, error returns    | ✅ Most                              |
| ✅ Modules         | Imports, packages             | ✅ Most                              |
| ✅ Build & Run     | Compilation, execution models | ✅ Yes                               |
| ✅ Memory Model    | Stack vs heap, GC, pointers   | ⚠️ Only C, C++, Rust, Zig, Assembly |
| ✅ Concurrency     | Threads, async, goroutines    | ⚠️ Optional, advanced               |

## Variables Summary Table
| Language | Immutable?     | Type?          | Const Keyword       | Notes                          |
| -------- | -------------- | -------------- | ------------------- | ------------------------------ |
| Python   | No             | Dynamic        | No (ALL\_CAPS)      | Super flexible                 |
| JS/Node  | `const`        | Dynamic        | `const`             | Use `let`/`const`, avoid `var` |
| Rust     | Yes by default | Static         | `const`             | Super strict                   |
| Go       | No             | Static         | `const`             | Clean and simple               |
| Lua      | No             | Dynamic        | No (manual)         | `local` avoids global chaos    |
| Zig      | Yes            | Static         | `const`             | Compiler yells at bad code     |
| Haskell  | Always         | Static         | Everything          | Functional monk mode           |
| Bash     | No             | Strings only   | `readonly`          | Not a real language, lol       |
| Zsh      | No             | Shelly strings | `typeset -r`        | Better Bash                    |
| C        | No             | Static         | `const`             | Manual life                    |
| C++      | No             | Static         | `const`/`constexpr` | Auto typing is nice            |
| ASM      | N/A            | Manual         | N/A                 | You *are* the memory manager   |

### Homework
Make one file in each language that:
- Declares a variable `x = 5`
- Declares a constant `PI = 3.14`
- Prints both
