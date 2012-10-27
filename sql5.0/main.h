#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define CREATE 0  //first key
#define USE 100
#define SELECT 1
#define DROP 2
#define DELETE 3
#define INSERT 4
#define SHOW 5
#define QUIT 14
#define COMMIT 15
#define EXECFILE 16
#define ALTER 17
#define RENAME 18
#define UPDATE 19

#define TABLE 6   //second key
#define INDEX 7
#define UNKNOWN 8
#define DATABASE 9
#define DATABASES 10
#define COLUMN 11

#define AND 12	//logic
#define OR 13


int re_count;       //rename db��table ѡ��
int fk_word;		//��һ�ؼ��֡�
int sk_word;		//�ڶ��ؼ��֡�
string fileName;	//��������
string tableName;   //��
string colName;    // ��
string colType;  //����
string new_name;//�µ�db table name
string old_name;//�ϵ�db table name

string DropFword;
string DropSword;

int alt_count;      //alter��ʽѡ��
int con_count;		//where�������ĸ�����
int logic;		//��������֮����߼����ӷ���
vector<string> selection;   //ѡȡ������
string operater1;	//����һ�еĹ�ϵ�������
string operater2;	//�������еĹ�ϵ�������
string col1;		//where�ؼ��ֺ��һ���������漰��������
string col2;		//where�ؼ��ֺ�ڶ����������漰��������
string  condition1;	//where�ؼ��ֺ��һ���������߼��������ĳ�����
string  condition2;	//where�ؼ��ֺ�ڶ����������߼��������ĳ�����

vector<string> insertValue;  	//insert�����values�������еĸ���ֵ��������һ��vector�����У�
vector<string> TableCloumns;    //insert�����table �еĸ�ֵ

vector<string> Type;		//create��佨��ʱ�������ԣ���˳�����һ��vector������
vector<string> Colu;		//create��佨��ʱ��������
vector<int> uniq;		//create��佨��ʱ��������
string primKey;			//create��佨��ʱ����ĸñ���primary key

vector<string> values;
string operater;
string condition;
vector<string> colname;
string cond;

typedef struct column_info
{
    string colname;
    string coltype;
    vector<string> line;
}column_info;

typedef struct table_info
{
    string tablename;
    vector<column_info> colist;
}table_info;

typedef struct db_info
{
    string dbname;
    vector<table_info> tlist;
}db_info;

vector<db_info> dblist;          //ȫ�ֱ���,��ǰ�õ����ݿ�
string current_dbname="";
vector<db_info>::iterator db_p;   //ȫ�ֱ�����ָ��ǰ�����ݿ�




string getWord(string s, int *tmp);
int interpreter(string s);
int Matching(string ColType,string Value,string Condition,string Operation);
bool CreateDatabase(string DbName) ;
bool ShowDatabase(void);
bool ShowColumn(string TableName);
bool UseDatabase(string DbName);
bool CreateTable(string filename,vector<string> colname,vector<string> coltype);
bool Drop(string FirstWord, string SecondWord) ;
bool Select0(string TableName, vector<string> Selection);
bool Select1(vector<string> Selection, string TableName,string Column, string Condition ,string Operation );
bool Insert(string TableName,vector<string> TableCloumn, vector<string> Values);
bool Delete(string TableName, string Column, string Condition, string Operation);
bool Alter_1(string tableName,string delName);
void Alter(string tablename,string colName,string colType);
bool Alter_2(string tableName,string colName,string colType);
bool Rename_Table(string old_name,string new_name);
bool Rename_Database(string old_name,string new_name);
bool ShowTables(void);
void update_cond1(string filename,vector<string> colname,vector<string> values,string cond,string operater,string condition);