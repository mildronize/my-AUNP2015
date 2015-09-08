# A script for getting a name of free ebook from packtpub

## Linux Command trick
- `sed -e '1a#include <stdlib.h>' packtpub_sys_cmd.c` means appending
  `#include <stdlib.h>` into `packtpub_sys_cmd.c` file after line 1 but not save in
  the file
- `sed -i -e '1a#include <stdlib.h>' packtpub_sys_cmd.c` means appending
  `#include <stdlib.h>` into `packtpub_sys_cmd.c` file after line 1

- Use `stat` command to view detail of file using `stat [filename]` ex.
  ```
  ➜  get_free_ebook_name_packt git:(master) ✗ stat out.txt
    File: ‘out.txt’
      Size: 47366           Blocks: 96         IO Block: 4096   regular
      file
      Device: 803h/2051d      Inode: 28967758    Links: 1
      Access: (0644/-rw-r--r--)  Uid: ( 1000/mildronize)   Gid: (1000/mildronize)
      Access: 2015-09-02 14:31:53.540105013 +0700
      Modify: 2015-09-02 14:31:43.620417376 +0700
      Change: 2015-09-02 14:31:43.620417376 +0700
      Birth: -
  ```
## About time when file is changed
- Modify & Change time is changed by edit file

- `ls -t` sort newest file first
- `ls | cat` show list of file with seperate with new line


## echo
- `echo "a" | wc -c` word count out: 2
- `echo -e "a" | wc -c` word count out: 2
- `echo -n "a" | wc -c` word count out: 1

## Date time
- `date` -> `Wed Sep  2 14:41:20 ICT 2015`
- `date +%s` -> (timestamp) (epoch time) `1441179687`
- `date +%Y-%m-%d` -> `2015-09-02`

## show manual of command
- `man 2 stat` open manual `stat()` of C Lang
- `man stat` open manul stat from system cmd
- `man 2 gettimeofday`

## Compare before & after

- `ls -l a.txt; chmod 000 a.txt; ls -l a.txt;`

## Lib C
- `system()` from `stdlib.h`
- `stat()` from
  ```
  #include <unistd.h>
  #include <sys/stat.h>
  #include <sys/types.h>
  ```
- `gettimeofday()` from `sys/time.h`
- `ctime()` from `time.h`
