
/***********************************************************************************************

 CSci 4061 Fall 2017
 Assignment# 2:   I/O Programming on UNIX/LINUX

 Student name: Michael Nordby, Logan Stucker
 Student ID:   5159186 4969657
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

#define NORMAL_COLOR  "\x1B[0m"
#define GREEN  "\x1B[32m"
#define BLUE  "\x1B[34m"

int main(int argc, char *argv[])
{
	char *dirname;

    DIR *dp; 
    struct dirent *direntry;
    dirname = (char*)malloc(NAMESIZE*sizeof(char));
    int totalsum = 0;
	
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
	
	
	/**********************************************************/
	/*Form a full path to the directory and check if it exists*/
	/**********************************************************/


	if(choice == 1){
		printf("\nEXECUTING \"1. Find the 3 largest files in a directory\"\n");
	
	    /* Check if the directory entered exists or not*/
    stat(input_dir_name,&statbuf);
    if(!(S_ISDIR(statbuf.st_mode))){
        printf("The directory name is not valid. Directory does not exist\n");
        exit(0);
    }

    if((dp=opendir(input_dir_name))==NULL){
        perror("Error while opening the directory");
        exit(0);
    }
    /* Loop through the directory structure */
    chdir(input_dir_name); //previously missing
    while( (direntry = readdir(dp)) != NULL )
    {
	stat(direntry->d_name,&statbuf);
	if(!(S_ISDIR(statbuf.st_mode)))
	{
	    printf("The size of file %s is :%d bytes\n",direntry->d_name,(int) statbuf.st_size);
	    totalsum += (int) statbuf.st_size;
	}
    }

    printf("The total size of the files in %s is : %d bytes\n",dirname,totalsum);
	recsearch(input_dir_name);
	}

	else if(choice == 2){
		printf("\nEXECUTING \"2. List all zero length files in a directory\"\n");
		
			
	    /* Check if the directory entered exists or not*/
    stat(input_dir_name,&statbuf);
    if(!(S_ISDIR(statbuf.st_mode))){
        printf("The directory name is not valid. Directory does not exist\n");
        exit(0);
    }

    if((dp=opendir(input_dir_name))==NULL){
        perror("Error while opening the directory");
        exit(0);
    }
    /* Loop through the directory structure */
    chdir(input_dir_name); //previously missing
    while( (direntry = readdir(dp)) != NULL )
    {
	stat(direntry->d_name,&statbuf);
	if(!(S_ISDIR(statbuf.st_mode)))
	{
		if(((int) statbuf.st_size) == 0)
		{
			
	    printf("The size of file %s is :%d bytes\n",direntry->d_name,(int) statbuf.st_size);

	}
    }

	}
		
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

void recsearch (char * path) {
	DIR * dpp = opendir(path); // open the path
	if(dpp==NULL) return; // if was not able return
	struct dirent * dir; // for the directory entries

	while ((dir = readdir(dpp)) != NULL) 
	{
		if(dir-> d_type != DT_DIR) { 
			printf("Reg: %s\n",dir->d_name);
		}
		else if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 ) // if it is a directory
		{
			printf("Dir: %s\n",dir->d_name); // print its name in green
			char d_path[255]; // here I am using sprintf which is safer than strcat
			sprintf(d_path, "%s/%s", path, dir->d_name);
			recsearch(d_path); // recall with the new path
		}
	}
	closedir(dpp); // finally close the directory
}
	


	
// 	stat(dirnam,&statbuf);
//	 /* Loop through the directory structure */
 //   chdir(dirnam); //previously missing
//    while( (direntry = readdir(dp)) != NULL )
//    {
//	stat(direntry->d_name,&statbuf);
	
//	if (S_ISDIR(statbuf.st_mode)) {
//		printf("Dir: %s\n",direntry->d_name);
		//recsearch(direntry);
//    }
     
//    if (S_ISREG(statbuf.st_mode)) {
//	printf("Reg: %s\n",direntry->d_name);
//      }
	
//}
