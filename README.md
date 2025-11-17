# loading_cpp

Small C++ demo that shows a console "loading" spinner and how to call it from a main program.

Files
- `call.cpp` — program entrypoint; calls `ShowLoading`.
- `loading.cpp` — implementation of the `ShowLoading` function (spinner).
- `loading.h` — declaration of `ShowLoading` (should be present and included by both `call.cpp` and `loading.cpp`).
- `Makefile` — builds the project into `call.exe`.

Requirements
- g++ (MinGW-w64 on Windows) with C++17 support.
- `mingw32-make` or `make` available in your PATH when building on Windows.

Build (Windows / PowerShell)

Open a PowerShell terminal in the repository folder and run:

```powershell
# If you have mingw32-make available
mingw32-make

# or, if using msys/cygwin make
make
```

The build produces `call.exe` (or `call` on POSIX systems).

Run

```powershell
# Run the generated executable from PowerShell
.\call.exe
```

Notes and troubleshooting
- Encoding: The program calls `system("chcp 65001 > nul")` in `call.cpp` to enable UTF-8 output on Windows consoles. If your console does not display the Braille spinner characters correctly, try running the program in Windows Terminal or change the font to a Unicode-capable font.

- Multiple-definition error (linker: `multiple definition of 'main'`):
  - If you see an error about multiple definitions of `main` during linking, it means both `call.cpp` and another source (commonly `loading.cpp`) contain a `main` function. Ensure only `call.cpp` contains `main` and remove any `main` from `loading.cpp`.

- If `loading.exe` is not found: The Makefile produces `call` / `call.exe`, not `loading.exe`. Run `call.exe` as shown above.

Suggested next steps
- Confirm `loading.h` exists and contains:

```cpp
#ifndef LOADING_H
#define LOADING_H

#include <string>

void ShowLoading(const std::string& message, int durationInSeconds);

#endif // LOADING_H
```

- Ensure `loading.cpp` includes `loading.h` and does not define `main`.

If you want, I can also:
- Run quick edits to add `loading.h` if it's missing.
- Remove an accidental `main` from `loading.cpp` if present.
- Update the `Makefile` to produce `call.exe` explicitly or add a `run` target.



**Spinner frames (plain text)**

- The spinner uses the following Braille frames (plain text):

```
⠋ ⠙ ⠹ ⠸ ⠼ ⠴ ⠦ ⠧ ⠇ ⠏
```

- Preview them in PowerShell:

```powershell
Write-Host "⠋ ⠙ ⠹ ⠸ ⠼ ⠴ ⠦ ⠧ ⠇ ⠏"
```

- Preview in a Bash-like shell:

```bash
echo "⠋ ⠙ ⠹ ⠸ ⠼ ⠴ ⠦ ⠧ ⠇ ⠏"
```

- Note: If characters don't display correctly, set your terminal to UTF-8 (PowerShell: `chcp 65001`) and use a Unicode-capable font (Windows Terminal, Cascadia Code, Consolas, etc.).
