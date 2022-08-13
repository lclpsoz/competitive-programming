# How to configure cf parse

## Add C++17 64 bits option manually

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

## cf-tool setup

1. `0) login`
2. `1) add a template`
   1. Language code for c++17 64 bits: `61`
   2. Input template absolute path, can be obtained with command `readlink -f 'filename'`
   3. Leave suffix empty
   4. Template alias: `cpp`
   5. Before script: `g++ $%full%$ -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wcast-qual -Wcast-align -Wsign-conversion -fsanitize=address -O2 -o $%file%$ -std=c++17`
   6. Script: `./$%file%$`
   7. Leave empty after script
3. `7) set folders' name`
   1. Root path: `CF`
   2. contest path: `.`
   3. gym path: `.`
   4. group path: `.`
   5. acmsguru path: `.`

- Activate option `4) run "cf gen" after "cf parse"`