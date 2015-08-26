# Basic Link file C using Temperature Convertor between C and F

## File Structure 
```
temp.c   // Main file
temp.h   // Collecting all convertor
f2c.c    // fahrenheit to celsius convertor
c2f.c    // celsius to fahrenheit convertor

run_temp // code to Link all file quickly
```

## Note about flags in `gcc` 
- Normal use: `gcc [filename]` to compile executable file (a.out)
- `-Wall` Show all warning while compiling 
- `-DMAIN` Disable ignore main function
- `-c` Complile to object (.o)
- `-o [filename]` Compile to object with custom `[filename]` 
