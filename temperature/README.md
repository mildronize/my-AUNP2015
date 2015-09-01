# Basic Link file C using Temperature Convertor between C and F

## File Structure
```
temp.c   // Main file
temp.h   // Collecting all convertors
f2c.c    // fahrenheit to celsius convertor
c2f.c    // celsius to fahrenheit convertor

run_temp // code to Link all file quickly
```
## Reversion
- [26 Aug 2015][rev01] &raquo; A simple temp convertor
- [1 Sep 2015][rev02] &raquo; Update temp convertor to get input from command line ( arg ) ex `./temp_arg 32c f`

[rev01]: https://github.com/mildronize/AUNP2015/commit/8b55668509eac4fb99a53e93f381d758fb8c48a0
[rev02]: https://github.com/mildronize/AUNP2015/commit/85ab7465d47249e00dbe9b8cf26b5d9b94ee55ce

## Note about flags in `gcc`
- Normal use: `gcc [filename]` to compile executable file (a.out)
- `-Wall` Show all warning while compiling
- `-DMAIN` Disable ignore main function
- `-c` Complile to object (.o)
- `-o [filename]` Compile to object with custom `[filename]`

## Note about linux command
- `cat [file_input] | [executable_program]` means using `file_input` as a
  input of `executable_program`
