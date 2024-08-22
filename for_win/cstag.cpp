#include <iostream>
#include "io.h"
#include "string.h"
#include <windows.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


wchar_t str1[] = L"C:\\B2_GNU_Tools\\";
wchar_t str2[] = L"D:\\B2_GNU_Tools\\";
wchar_t str3[] = L"E:\\B2_GNU_Tools\\";
wchar_t str4[] = L"F:\\B2_GNU_Tools\\";
wchar_t str5[] = L"G:\\B2_GNU_Tools\\";
wchar_t str6[] = L"H:\\B2_GNU_Tools\\";
wchar_t str7[] = L"I:\\B2_GNU_Tools\\";
wchar_t str8[] = L"J:\\B2_GNU_Tools\\";
wchar_t str9[] = L"K:\\B2_GNU_Tools\\";
wchar_t str10[] = L"L:\\B2_GNU_Tools\\";


void Wchar_tToString(string & szDst, wchar_t*wchar)
{
	wchar_t * wText = wchar;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,wText,-1,NULL,0,NULL,FALSE);//WideCharToMultiByte的运用
	char *psText;  // psText为char*的临时数组，作为赋值给std::string的中间变量
	psText = new char[dwNum];
	WideCharToMultiByte (CP_OEMCP,NULL,wText,-1,psText,dwNum,NULL,FALSE);//WideCharToMultiByte的再次运用
	szDst = psText;// std::string赋值
	delete []psText;// psText的清除
}
func(wchar_t * path)
{		
	string  exe_ctag ; 
	string  exe_cscope ; 
	Wchar_tToString(exe_ctag,path);
	exe_cscope = exe_ctag+ "cscope.exe";
	exe_ctag=exe_ctag+"ctags.exe";

	system("del tags cscope*");
	system((exe_ctag+" -R").c_str());
	system((exe_cscope+" -Rbkq").c_str());
	
	system("dir /S/B *.c  > cscope.files");
	system("dir /S/B *.cpp  >> cscope.files");
	system("dir /S/B *.h  >> cscope.files");
	system("dir /S/B *.v  >> cscope.files");
	system("dir /S/B *.sv  >> cscope.files");
	system("dir /S/B *.svh  >> cscope.files");
}
  
int main(int argc, char** argv) {
	
	char c=0;

	if(_waccess(str1,0)!=-1){
		func(str1);
		return 0; 
	}
	else if(_waccess(str2,0)!=-1){
		func(str2);
		return 0; 
	}
	else if(_waccess(str3,0)!=-1){
		func(str3);
		return 0; 
	}
	else if(_waccess(str4,0)!=-1){
		func(str4);
		return 0; 
	}
	else if(_waccess(str5,0)!=-1){
		func(str5);
		return 0; 
	}
	else if(_waccess(str6,0)!=-1){
		func(str6);
		return 0; 
	}
	else if(_waccess(str7,0)!=-1){
		func(str7);
		return 0; 
	}
	else if(_waccess(str8,0)!=-1){
		func(str8);
		return 0; 
	}
	else if(_waccess(str9,0)!=-1){
		func(str9);
		return 0; 
	}
	else if(_waccess(str10,0)!=-1){
		func(str10);
		return 0; 
	}
}
