#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

//function to delimit pipe
void delimitpipe(char *command, char** comms)
{
  int c;
  for(c = 0; c < sizeof(command); c++)
  {
    comms[c] = strsep(&command, "|");
    if(comms[c] == NULL)
      break;
  } 
}
//function to delimit space
void delimitspace(char *command, char** cmd)
{
  int c;
  for(c = 0; c < sizeof(command); c++)
  {
    cmd[c] = strsep(&command, " ");
    if(cmd[c] == NULL)
      break;
  }
}
//function to delimit space allow spacing after pipe
void delimitspace2(char *command, char** cmd)
{
  int c;
  int index;
  char *b;
  if (command[0] == ' ')
  {
    b = strsep(&command, " ");
  }
  for(c = 0; c < sizeof(command); c++)
  {
      cmd[c] = strsep(&command, " ");
      
      if(cmd[c] == NULL)
        break;
  }
}
//main
int main(int argc, char **argv)
{
  int status;
  int i;
  char str[1024];
  char *comms[3];
  //read in command input
  printf("ENTER A COMMAND: ");
  fgets(str, sizeof(str), stdin);
  //3 commands between pipes
  char *cmd1[1024];
  char *cmd2[1024];
  char *cmd3[1024];
  //get rid of null characters
  str[strlen(str)-1] = '\0';
  //delimit commands between pipes
  delimitpipe(str, comms);
  //delimit first command
  delimitspace(comms[0], cmd1);
  //delimit second command if there is one
  if (comms[1] != '\0')
  {
    delimitspace2(comms[1], cmd2);
    if (comms[2] != '\0')
    {
      delimitspace2(comms[2], cmd3);
    }
  }
  //delimit third command if there is one
  int a[4];
  pipe(a);
  pipe(a+2);
  //excution of the first command
  if (cmd2[0] == NULL && cmd3[0] == NULL)
  {
      int pid = fork();
      if (pid == 0)
      {
          dup2(a[0], 0);
          close(a[1]);
          execvp(*cmd1, cmd1);
      }
  }
  //command with one pipe
  else if (cmd3[0] == NULL)
  {
      int pid = fork();
      //execution of second command
      if (pid == 0)
      {
          dup2(a[0], 0);
          close(a[1]);
          execvp(*cmd2, cmd2);
      }
      //execution of first command
      else
      {
          dup2(a[1], 1);
          close(a[0]);
          execvp(*cmd1, cmd1);
      }
  }
  //command with two pipes
  else
  {
      //executing first command
      if (fork() == 0)
      {
          dup2(a[1], 1);
          close(a[0]);
          close(a[1]);
          close(a[2]);
          close(a[3]);
          execvp(*cmd1, cmd1);
      }
      else
      {
          //second command
          if (fork() == 0)
      	  {
        	  dup2(a[0], 0);
            dup2(a[3], 1);
            close(a[0]);
        	  close(a[1]);
        	  close(a[2]);
        	  close(a[3]);
        	  execvp(*cmd2, cmd2);
          }
          else
      	  {
             //and third command
              if (fork() == 0)
              {
                dup2(a[2], 0);
                close(a[0]);
        	      close(a[1]);
        	      close(a[2]);
        	      close(a[3]);
        	      execvp(*cmd3, cmd3);
              }
      	  }
       }         
  }
  //close pipes
    close(a[0]);
    close(a[1]);
    close(a[2]);
    close(a[3]);

    for (i = 0; i < 3; i++)
      wait(&status);
}