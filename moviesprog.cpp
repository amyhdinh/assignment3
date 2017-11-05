#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
using namespace std;
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
int main()
{
    //sqlite3 variables
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  char const *sql;
  //file to read from
  std::ifstream file("persons.txt");
  //open database and confirm if database has been opened
  rc = sqlite3_open("movie.db", &db);
    if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }
    //Create table and confirm if table has been created successfully
  sql = "create table persons (lname varchar(40) not null,fname varchar(40),id int,primary key (id))";
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
     if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Table created successfully\n");
   }

  std::string str;
  ofstream ofile("persons.out");

  ofile << "Processing persons.txt file" << endl;
  int count = 1;

    while (std::getline(file, str))
    {
        //print records for persons.txt
        ofile << "\tRecord ";
        ofile << count;
        ofile << ": ";
        ofile << str;
        stringstream ss(str);
        string str2;
        vector<string> r;
        while(ss.good())
        {
            //add each string to a vector delimited by |
            string str2;
            getline(ss, str2, '|');
            r.push_back(str2);
        }
        //print each persons info
        ofile << "\n\t\tLast name: ";
        ofile << r.at(0);
        ofile << "\n\t\tFirst Name: ";
        ofile << r.at(1);
        ofile << "\n\t\tPerson Id: ";
        ofile << r.at(2);
        //insert info to persons table
        string str3 = "insert into persons (lname,fname,id) values('" + r.at(0) + "','" + r.at(1) + "'," + r.at(2) + ");";
        const char * sqlstatement = str3.c_str();
        sql = sqlstatement;
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        count++;
    }
    //confirm if records were created
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records for persons created successfully\n");
   }

    //reset count and str
    count = 1;
    str = "";
    //read in movie.txt file
    std::ifstream file2("movies.txt");
    ofile << "\n\nProcessing movies.txt file" << endl;

    //create table for movies
    sql = "create table movies (title varchar(40) not null,director int not null,year_made int not null,id int,primary key (id),foreign key (director) references persons(id))";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    //confirm if table has been created successfully
    if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Table created successfully\n");
   }

   //read through movie file
    while (std::getline(file2, str))
    {
        //print records for movies.txt
        ofile << "\tRecord ";
        ofile << count;
        ofile << ": ";
        ofile << str;
        stringstream ss(str);
        string str2;
        vector<string> r;
        while(ss.good())
        {
            //add each string to a vector delimited by |
            string str2;
            getline(ss, str2, '|');
            r.push_back(str2);
        }
        ofile << "\n\t\tMovie Title: ";
        ofile << r.at(0);
        ofile << "\n\t\tDirector Id: ";
        ofile << r.at(1);
        ofile << "\n\t\tYear Made: ";
        ofile << r.at(2);
        ofile << "\n\t\tMovie Id: ";
        ofile << r.at(3);
        string str3 = "insert into movies (title,director,year_made,id) values('" + r.at(0) + "'," + r.at(1) + "," + r.at(2) + "," + r.at(3) + ");";
        const char * sqlstatement = str3.c_str();
        sql = sqlstatement;
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        count++;
    }
    //confirm if records were created
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records for movies created successfully\n");
   }

    //reset count and str
    count = 1;
    str = "";
    //read in acts_in.txt file
    std::ifstream file3("acts_in.txt");
    ofile << "\n\nProcessing acts_in.txt file" << endl;

    //create table for acts_in
    sql = "CREATE TABLE acts_in (actor int,movie int,primary key (actor, movie),foreign key (actor) references persons(id),foreign key (movie) references movies(id))";
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    //confirm if table has been created successfully
    if( rc != SQLITE_OK ){
   fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Table created successfully\n");
   }

   //read in file acts_in
   while (std::getline(file3, str))
    {
        //print records for acts_in.txt
        ofile << "\tRecord ";
        ofile << count;
        ofile << ": ";
        ofile << str;
        stringstream ss(str);
        string str2;
        vector<string> r;
        while(ss.good())
        {
            //add each string to a vector delimited by |
            string str2;
            getline(ss, str2, '|');
            r.push_back(str2);
        }
        ofile << "\n\t\tPerson Id: ";
        ofile << r.at(0);
        ofile << "\n\t\tMovie Id: ";
        ofile << r.at(1);
        string str3 = "insert into acts_in (actor,movie) values(" + r.at(0) + "," + r.at(1) + ");";
        const char * sqlstatement = str3.c_str();
        sql = sqlstatement;
        rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
        count++;
    }
    //confirm if records were created
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records for acts_in created successfully\n");
   }
    //print out persons table
    printf("\n\n\n");
    printf(" %23s \n","PERSONS TABLE");
    sqlite3_stmt* statement;
    sqlite3_prepare_v2(db, "select * FROM persons", -1, &statement, NULL);
    printf(" %-15s %-15s %-15s \n","LAST NAME","FIRST NAME","ID");
    while (sqlite3_step(statement) == SQLITE_ROW)
    {
       printf(" %-15s %-15s %-15s \n",sqlite3_column_text(statement, 0),sqlite3_column_text(statement, 1),sqlite3_column_text(statement, 2));
    }
    sqlite3_finalize(statement);
    //print out movies table
    sqlite3_prepare_v2(db, "select * FROM movies", -1, &statement, NULL);
    printf("\n\n\n");
    printf(" %32s \n","MOVIES TABLE");
    printf(" %-17s %-17s %-17s %-5s \n","TITLE","DIRECTOR","YEAR MADE","MOVIE ID");
    while (sqlite3_step(statement) == SQLITE_ROW)
    {
       printf(" %-17s %-17s %-17s %-5s \n",sqlite3_column_text(statement, 0),sqlite3_column_text(statement, 1),sqlite3_column_text(statement, 2),sqlite3_column_text(statement, 3));
    }
    sqlite3_finalize(statement);
    //print out acts_in table
    sqlite3_prepare_v2(db, "select * FROM acts_in", -1, &statement, NULL);
    printf("\n\n\n");
    printf("%17s \n","ACTS_IN TABLE");
    printf(" %-10s %-10s \n","ACTOR ID","MOVIE ID");
    while (sqlite3_step(statement) == SQLITE_ROW)
    {
       printf(" %-10s %-10s \n",sqlite3_column_text(statement, 0),sqlite3_column_text(statement, 1));
    }
    sqlite3_finalize(statement);
    printf("\n\n");

    //create star wars records
    sql = "insert into persons values('Kershner', 'Irwin', 19);" \
    "insert into persons values('Hamill', 'Mark', 20);" \
    "insert into persons values('Ford', 'Harrison', 21);" \
    "insert into persons values('Fisher', 'Carrie', 22);" \
    "insert into movies values('Star Wars', 19, 1977, 4);" \
    "insert into acts_in values(20, 4);" \
    "insert into acts_in values(21, 4);" \
    "insert into acts_in values(22, 4);";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    //confirm if records were created
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records for Star Wars created successfully\n");
   }

   //print stars war information using star wars key
    printf("\n\n");
    printf("STAR WARS MOVIE INFORMATION\n");
    sql = "select * from movies where movies.title='Star Wars';"; \
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    printf("STAR WARS DIRECTOR INFORMATION\n");
    sql = "select persons.* from movies join persons on movies.director = persons.id where movies.title='Star Wars';"; \
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    printf("STAR WARS CASTING MEMBERS INFORMATION\n");
    sql = "select persons.* from movies join persons on acts_in.actor = persons.id join acts_in on movies.id = acts_in.movie where movies.title='Star Wars';"; \
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    //update director to correct name
    sql = "update persons set fname='Irvin' where id=19;";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    //confirm if it was updated
    if( rc != SQLITE_OK )
    {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
    }
    else
    {
      fprintf(stdout, "Record was updated successfully\n");
    }

    //print new stars war information using star wars key
    printf("\n\n");
    printf("STAR WARS MOVIE INFORMATION\n");
    sql = "select * from movies where movies.title='Star Wars';"; \
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    printf("STAR WARS DIRECTOR(NEW) INFORMATION\n");
    sql = "select persons.* from movies join persons on movies.director = persons.id where movies.title='Star Wars';"; \
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    printf("STAR WARS CASTING MEMBERS INFORMATION\n");
    sql = "select persons.* from movies join persons on acts_in.actor = persons.id join acts_in on movies.id = acts_in.movie where movies.title='Star Wars';"; \
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    sqlite3_close(db);
    return 0;
}
