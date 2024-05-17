# Computer club event processing

### Intro

This is a programm on `C++` to process events happening in the computer center. Here i use STL-containers and onle standard library. You can count money you earned during the day and time when PC/table was taken (precised to minutes, but money is counted for table as every period of being taken rounds high to amout of hours. Examples:
3 minutes = 1 hour paid for;
01:01 = 2 hours paid for;
that is how market economy works, mate)

### How to create a file to process

Info for processing is stores in .txt file. Open it and write in appropriate way:
```
N //N - number of working tables, N >= 0
Time_opening Time_ending //format - HH:MM, like 17:03, 19:84
P //P - price for an hour
[events]
```
`events` are lines, format: `HH:MM ID username [table number]`, where
`ID` is a code for event:
- `1` - user comes, 
- `2` - user sits at the table `table number`, 
- `3` - user goes to queue (waiting for free PC/table),
- `4` - user goes away.
  
`[table number]` - is a field only for `2` action.

Example (like in `input.txt`):
```
3
09:00 19:00
10
08:48 1 client1
09:41 1 client1
09:48 1 client2
09:52 3 client1
09:54 2 client1 1
10:25 2 client2 2
10:58 1 client3
10:59 2 client3 3
11:30 1 client4
11:35 2 client4 2
11:45 3 client4
12:33 4 client1
12:43 4 client2
15:52 4 client4
```
### When programm stops and generate its own events
1. When some typo found, programm stops immediately
2. Events, generated by programm:
    - 2.1 `ID = 11` Client went away (in the end of the day in alphabetic order or in case when queue is full already)
    - 2.2  `ID = 12` Some of the tables became free and first user in the queue sat there
    - 2.3 `ID = 13` Any mistake found, which doesn't have an impact on processing events:
    - - `ClientUnknown` - when client hadn't come but wants to sit / wait / go away
    - - `YouShallNotPass` - when client is already inside and tries to come once more. strange one, this guy
    - - `ICanWaiNoLonger` - when client wants to wait when some of tables are free. strange one, too
    - - `PlaceIsBusy` - when client wants to take a sit, but it is already taken

### Usage
- with `make`
open terminal in folder with project and type:
```
make
./test input.txt
```
- with CMake:
```
mkdir build
cp input.txt  build
cd build
cmake ..
make
./test input.txt
```
