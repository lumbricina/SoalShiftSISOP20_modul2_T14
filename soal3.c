#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <dirent.h>
#include <string.h>

int main() {
  pid_t child = fork();
  int status;
  if (child < 0) 
  {
    exit(EXIT_FAILURE); 
  }

  if (child == 0) 
{
  	pid_t child_1 = fork();
  	
	  if (child_1 < 0)
  	{
  		exit(EXIT_FAILURE);
	}
    
      if (child_1 == 0)
    {
		char *mkd[] = {"mkdir", "-p", "/home/lumbricina/modul2/indomie", NULL};
    	execv("/bin/mkdir", mkd);
    }
}
	else 
  {
		while ((wait(&status)) > 0);
    	sleep(5);
    	char *mkd[] = {"mkdir","/home/lumbricina/modul2/sedaap", NULL};
    	execv("/bin/mkdir", mkd);
    }
	else
    {
    	while ((wait(&status)) > 0);
    	pid_t child_2 = fork();
    	if (child_2 < 0){
      	exit(EXIT_FAILURE);
    }
    if (child_2 == 0)
	{
    	char *unzip[] = {"unzip", "/home/lumbricina/modul2/jpg.zip", NULL};
    	execv("/usr/bin/unzip", unzip);
    }
    else
{
    	while ((wait(&status)) > 0);
    	chdir("/home/lumbricina/modul2/jpg/");
    	DIR *directory;
    	directory = opendir ("jpg");
    	struct dirent *dir
    	if (dir)
    {
    	while((dir = readdir(directory)) != NULL)
		{
          pid_t child_3 = fork();
	        struct stat st;
	        stat(dir->d_name, &st);
	        if(child_3 < 0)
			{
	          exit(EXIT_FAILURE);
	        }
          if(child_3 == 0)
		  {
		  	struct stat info;
            char filename[1000];
            sprintf(filename, "/home/lumbricina/modul2/jpg/%s", dir->d_name);
            if (stat(filename, &info))
			{
              
		        exit(EXIT_FAILURE);
		    }
		    if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0);
              else
             {
              	pid_t child4 = fork();
              	if(child4 == 0)
              	{
				
              	char* move[] = {"mv", filename, "/home/lumbricina/modul2/indomie/", NULL};
                    execv("/bin/mv", move);
		             }
		    else
		    {
                char* move[] = {"mv", filename, "/home/lumbricina/modul2/sedaap/", NULL};
                execv("/bin/mv", move);
       
else 
                {
                  while ((wait(&status)) > 0);
                  pid_t child5 = fork ();
                  if (child_5 < 0) 
                  {
                    exit(EXIT_FAILURE); 
                  }
                  if(child_5 == 0)
                  {
                    char target[10000];
                    sprintf(target, "/home/lumbricina/modul2/indomie/%s/coba1.txt", dir->d_name);
                    char* file1[] = {"touch", target, NULL};
                    execv("/usr/bin/touch", file1);
                    
                  }
                  else 
                  {
                    while ((wait(&status)) > 0);
                    sleep(3);
                    char target[10000];
                    sprintf(target, "/home/lumbricina/modul2/indomie/%s/coba2.txt", dir->d_name);
                    char* file2[] = {"touch", target, NULL};
                    execv("/usr/bin/touch", file2);

                }
              }
            }
          }
          closedir(directory);
        }
      }
    }
  }
}



    
