#include"basichead.h"
#include"DBFile.h"
#include"block.h"
#include"bufferManager.h"
#include"recordManager.h"
#include"CategoryManager.h"
#include"interpreter.h"
#include<afxwin.h>


#include<iostream>
using namespace std;


int main()
{
	char cmd[10000];
//	int i = 0;
	CString a,temp;
	interpreter b;
	/*if(freopen("d:\\test.txt","r",stdin)==NULL){
   
        exit(-1);
        }
	for( i = 0; (cmd[i] = getchar())!=EOF;i++);
		printf("%s",cmd);
        
*/
	while(1)
	{
		cout << "SQL Command: " << endl;
		a = "";
	
		do
		{
			gets(cmd);
			a += " ";
			a += cmd;

		}
		while(a.GetAt(a.GetLength() - 1) != ';');
		
	//	AfxMessageBox(a);

		if(a == " quit;")
			break;
		
		CString temp = a;
		temp.MakeLower();
		if(temp.Find("create") != -1 || temp.Find("drop") != -1
			|| temp.Find("select") != -1 || temp.Find("insert") != -1
			|| temp.Find("delete") != -1)
		{	
			if(b.ExecuteCommand(a))
				cout << "指令成功运行!" << endl;
			else
				cout << "error" << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
//	fclose(stdin);
	return 0;
}
