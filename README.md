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

g++ a.cpp -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wcast-qual -Wcast-align -Wsign-conversion         -fsanitize=address -O2 -o a -std=c++17

1. 0) login
2. 1) add a template
   1. Language code for c++17: 54
   2. Input template absolute path
   3. Leave suffix empty
   4. cpp as template alias
   5. Before script: g++ $%full%$ -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wcast-qual -Wcast-align -Wsign-conversion -fsanitize=address -O2 -o $%file%$ -std=c++17
   6. After script: ./$%file%$
   7. Leave empty after script
3. 7) set folders' name
   1. Root path: CF
   2. contest path: .
   3. gym path: .
   4. group path: .
   5. acmsguru path: .

- Activate option 4) run "cf gen" after "cf parse"

#### TODO

- Unify all CF contests names.
- Clean all unused files copied from one of the templates.
