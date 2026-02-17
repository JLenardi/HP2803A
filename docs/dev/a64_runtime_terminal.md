# A64 Runtime Terminal Configuration

When running the A64 build (`./build/prog`), the terminal must be placed
into non-canonical, non-echo mode to allow non-blocking character input.

## Enable required mode

Before running the program:

```sh
stty -icanon -echo min 0 time 0

