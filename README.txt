PART1 Perl

Task #1. Write a Bourne or Bourne Again Shell [or perl or C/C++ program] to do the following.

The shell will create a directory (dir1) and a few files and a few subdirectories (with a few files), in the current working directory.

The "dir1" directory has the following files: c100.c, c200.c, c300.c, p010.pl, p020.pl, p030.pl, t001.txt, t002.txt, t003.txt files, f100, f200, dir11, dir12. The naming convention for each file is: ZNNN.Ext where ZNNN is the program name with size (e.g., c100) and Ext is the extension (".c"). There are two files (f100 and f200) without its file extension. There are two directories ("dir11" and "dir12").

The directory "dir11" will contain the files: c100.c, c200.c, c300.c, p010.pl, p020.pl, p030.pl, t001.txt, t002.txt, t003.txt files, f100, f200, dir111.

The directory "dir12" will contain the files: c100.c, c200.c, c300.c, p010.pl, p020.pl, p030.pl, t001.txt, t002.txt, t003.txt files, f100, f200, dir121.

The directory "dir111" has no files. 
The directory "dir121" has no files.

PART1
Task #2. Write a Perl program (name it "userinfo.pl") to do the following task.

(1) Write a Perl program (count2.pl) to count and accumulate the number of bytes of these files (for each file extension) in the working directory and all of its subdirectories, and print the result. 

(2) Use one hash table to keep the count of the files (with the same extension), and the other hash table to keep the accumulation of the size in byte of these files (with the same extension). Here the key is the file extension (e.g., ".c"). 

For example, if there are three files (c1.c, c2.c, and c3.c), then the first hash table keeps track of the count of these files (".c" => 3), and the other hash table keeps the sum of the sizes of these files.

Any file without file extension will be considered as the same one (with the key of "*") and to accumulate all the bytes of these files. Any directory entry should not be counted here.

For this task, you need to create a sample directory with several small files and a few subdirectories (with a few files with extension of .c, .txt, .pl, etc. and a few without any file extension), and run your perl program with these files in the directory and its subdirectories. You should provide your check and verification whether your perl program run correctly in your document here. 

The following output is a sample or a suggestion for your program output.

file extension       count
----------------    -------
.c                       3
.txt                     2
.pl                      1
*                        3
--------------------------
total                    9


file extension       total size
----------------    -----------
.c                       30
.txt                     20
.pl                      10
*                        30
-------------------------------
total                   90


PART2. 

C programming to implement a simple shell.

Warning: you should not use any "system" call throughout this assignment (and thereafter).

One to Three Commands in Pipe

You may use the sample code provided to handle two commands in pipe, to make a shell. 
Your shell handles one command, or two or three commands in pipe ("ls | wc -l" or "ls | grep ".c" | sot"). 

For example, if there are two commands in pipe, the parent gets the command (for example, "ls | wc -l") to recognize that there are two commands piped together. Thus it will have a pipe to be shared, and then fork a child process (to do "ls") which will fork its child process (to do "wc -l") with the pipe shared (so that the output of one process doing "ls" will be input to the input of the other process doing "wc -l"). Meanwhile the parent waits till all the child processes are terminated, and then back to the loop for the next command from the user. Extending the shell for two commands in pipe, your shell should handle up to "three commands in pipe" (for example, "ls | grep ".c" | sort").

Part3

Project Description

Movie-Shop has many DVD movies and its DVD listing in a database (named "movie.db") with sqlite3. The database maintains three tables of movies, acts_in, and persons. A person (in persons table) acts in a movie (in movies table) where acts_in table says who (a person in persons table) acts in a movie (a movie in movies table).

Each person record in persons table has 3 fields of last name (lname), first name (fname), person id (id). Each movie record in movies table has 4 fields of movie title, director id, year made, movie id where director should be defined in persons table. Each record in acts_in table has 2 fields where actor is a person acted in a movie and movie is movie id.

Tasks to do.

The shop-manager wants you (IT consultant) to do a project, to create a software system (using C/C++ with sqlite3 database) to restore the lost database. Your job is to write a C/C++ program to do the following tasks. Your C/C++ program will do (interacting with sqlite3 database, named "movie.db" which is initially empty). This is done by "touch movie.db" to create an empty file or you may use the movie.db file.

At each step (before and after), output a brief message to say something like "Part2 Task1 starts." and "Part2 Task1 done." etc. 


(Task 1) 
[Note: You need to create three text files for movies, persons, and acts_in tables (with each table-listing from movie.db shown in the previous page).]
Write a C/C++ program to read each file (persons.txt, movies.txt, and acts_in.txt) and tokenize each line to get each field. For example, the content of persons.txt file is:

Fellini|Federico|1
Noel|Magali|2
Zanin|Bruno|3
Maggio|Pupella|4
Drancia|Armando|5
Mcbride|Jim|6
Quaid|Dennis|7
Barkin|Ellen|8
Beatty|Ned|9
Persky|Lisa Jane|10
Goodman|John|11
Ludlam|Charles|12
Singleton|John|13
Gooding|Cuba Jr.|14
Cube|Ice|15
Fishburne|Larry|16
Ferrell|Tyra|17
Chestnut|Morris|18

After reading and tokenize each record, output the result of each line to a file ("persons.out" or console output to show that your code is working) with some helpful headings). For example (and you may use your own format here),

	Processing persons.txt file
		Record 1: Fellini|Federico|1
			Last name: Fellini
			Frist Name: Federico
			Person Id: 1
		…


(Task 2) 
In your C/C++ program (to movie.db) 
Use the result (from Task 1) to create sql statement(s) to be used to call the database to create each table and insert records. Your C++ program should generate sql statements which will be executed by sqlite3: (1) to create the persons table and (2) to insert each record (as each record is read from persons.txt file in your C++ program which will generate the following sql insert statements).
(Task 3) 
In your C/C++ program (from movie.db): Select and output to a file
To get each record from each table (from movie.db) using "select" statement for each table. And output all the  records (of each table) to a file, after (Task 2) is done. The output may have a proper heading for each table. You may use select statement to get all the records of each table (for example, "select * from artist;" to get all the records from persons table, output to a file "persons2.out" or to console to see your code is working correctly). 
