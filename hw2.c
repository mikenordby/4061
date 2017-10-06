/***********************************************************************************************

 CSci 4061 Fall 2017
 Assignment# 2:   I/O Programming on UNIX/LINUX

 Student name: Michael Nordby, Logan Stucker
 Student ID: 5159186, 4969657
 X500 id: nordb132, stuck124

 Operating system on which you tested your code: Linux, Unix, MacOS
 CSELABS machine: <machine you tested on eg: xyz.cselabs.umn.edu>

 GROUP INSTRUCTION:  Please make only ONLY one  submission when working in a group.

***********************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#define NAMESIZE 256
#define TOKENSIZE 100

int main(int argc, char *argv[])
{
	int choice = -1;
	char *input_dir_name, *dirpath, *chptr;
	struct stat statbuf;
	long maxpath;
	char *cwdNamePntr; 
	mode_t  perms =  0740;
	char confirm[4];
	char pathname[1024];
	
	struct namensize{
    char path[NAMESIZE];
    int size;
	};


	input_dir_name = (char *) malloc(NAMESIZE * sizeof(char));
	dirpath = (char *) malloc(NAMESIZE * sizeof(char));
	printf("SELECT THE FUNCTION YOU WANT TO EXECUTE:\n");
	printf("1. Find the 3 largest files in a directory\n");
	printf("2. List all zero length files in a directory\n");
	printf("3. Find all files with permission 777 in a directory\n");
	printf("4. Create a backup of a directory\n");
	printf("5. Exit\n");
	printf("\n");
	printf("ENTER YOUR CHOICE: ");
	scanf("%d", &choice);
	printf("Enter a directory name in the current directory: ");
	scanf("%s", input_dir_name);
	
	DIR *dr = opendir(input_dir_name);
	
	if (dr == NULL) {
		printf("not a directory");
		return 0;
	}
	
	struct dirent *de;
	
	/**********************************************************/
	/*Form a full path to the directory and check if it exists*/
	/**********************************************************/


	if(choice == 1){
		printf("\nEXECUTING \"1. Find the 3 largest files in a directory\"\n");
			chdir (dr);
			struct namensize largest[2];
			while ((de = readdir(dr)) != NULL){
				printf("The size of file %s is :%d bytes\n",direntry->d_name,(int) statbuf.st_size);
				print(statbuf.st_size);
			
				if (current_file_size > largest[0].size)	
				{	
					largest[2] = largest[1];
					largest[1] = largest[0];
					largest[0].name = current_file_name;
					largest[0].size = current_file_size;
				}
				else if (current_file_size > largest[1].size)
				{
					largest[2] = largest[1];
					largest[1].name = current_file_name;
					largest[1].size = current_file_size;
				}
				else if current_file_size > largest[2].size)	
				{
					largest[2].name = current_file_name;
					largest[2].size = current_file_size;
				}	
			
			}
				
				
			closedir(dr);
			return 0;
	}

	else if(choice == 2){
		printf("\nEXECUTING \"2. List all zero length files in a directory\"\n");
		
	}

	else if(choice == 3){
		printf("\nEXECUTING \"3. Find all files with permission 777 in a directory\"\n");
		
	}

	else if(choice == 4){
		printf("\nEXECUTING \"4. Create a backup of a directory\"\n");
		
	}

	else if(choice == 5){
		printf("\nEXIT\n");
		/********************************************************/
		/**************Function to perform choice 5**************/
		/********************************************************/
	}

	else{
		printf("Invalid choice\n");
		exit(1);
	}
	free(input_dir_name);
	free(dirpath);
	return 0;
}
