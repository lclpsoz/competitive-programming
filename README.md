# Competitive Programming
## Repository with my codes related to competitive programming.

### Folders meaning:

### /

Templates, makefiles, and out of contests codes that I've coded recently.


### ATC/

Folder with contests from AtCoder. Folders name are the 'atc-' concatenated with contest id from AtCoder. Contest can be found at atcoder.jp/contests/id/

**Ex:**

Folder: ATC/atc-abc148
Found at: atcoder.jp/contests/abc148

### CF/

Folder with contests from codeforces. The majority of them in the format cf-id, id being the id of the contest. Can be found on www.codeforces.com/contest/id. Some folders are using the round code as name, like 869-r#439(div.2)/

**Ex:**

cf-1095/

Contest found at: www.codeforces.com/contest/1095/

### ARCHIVE/

Folder with a large variety of codes. From contests from outside codeforces to stand-alone problems. The majority of the files are in date-hour folders. In those, most filenames will follow these patterns:

- 4 digit number: URI online judge
Ex: 1487.cpp

- Only number, with more than 5 digits: UVA Online Judge (recently changed to just Online Judge)
Ex: 10315.cpp

- A number and a letter, it's from codeforces.
Ex: 279C.cpp

### LIB/

Code templates for competition.

Other folders not described above that can appear eventually are for recent contests.

#### How to configure cf parse

To use C++17 64 bits on CF compile cf-tool manually:

Steps executed in go version 1.12.17 for linux/amd64

1. run `go get github.com/xalanq/cf-tool`
2. run `cd $GOPATH/src/github.com/xalanq/cf-tool`

`GOPATH` variable may not exist, if on linux, run: `export GOPATH=~/go`

3. run `sudo vim client/langs.go`
4. Add the following option to map Langs:

`"61": "GNU G++17 9.2.0 (64 bit, msys 2)"`

5. Save with option `w!`
6. Build with: `go build -ldflags "-s -w"`
7. Move the executable `cf-tool` to home (`~/`) and rename it to `cf`
8. Add this line to the end of `~/.bashrc`

`alias cf='~/cf'`

That way it's possible to run cf-tool from any terminal by default.

Configuration steps:

1. `0) login`
2. `1) add a template`
   1. Language code for c++17 64 bits: `61`
   2. Input template absolute path, can be obtained with command `readlink -f 'filename'`
   3. Leave suffix empty
   4. Template alias: `cpp`
   5. Before script: `g++ $%full%$ -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wcast-qual -Wcast-align -Wsign-conversion -fsanitize=address -O2 -o $%file%$ -std=c++17`
   6. After script: `./$%file%$`
   7. Leave empty after script
3. `7) set folders' name`
   1. Root path: `CF`
   2. contest path: `.`
   3. gym path: `.`
   4. group path: `.`
   5. acmsguru path: `.`

- Activate option `4) run "cf gen" after "cf parse"`

#### TODO

- Unify all CF contests names.
- Clean all unused files copied from one of the templates.
