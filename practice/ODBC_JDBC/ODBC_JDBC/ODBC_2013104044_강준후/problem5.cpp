#include <Windows.h>
#include <iostream>
#include <sql.h>
#include <sqlext.h>
#include<string>
using namespace std;


//ODBC conn
SQLHENV hEnv;
SQLHDBC hDbc;
SQLHSTMT hStmt;

//접속 정보
SQLCHAR *ODBC_Name = (SQLCHAR*)"TIBERO";
SQLCHAR *ODBC_ID = (SQLCHAR*)"HR";
SQLCHAR *ODBC_PW = (SQLCHAR*)"tibero";

bool DBConnect();
void DBDisConnect();
bool DBExecuteSQL();
bool DBExecuteSQL(SQLCHAR* query);
bool DBPrepare(SQLCHAR* query_for_statement);


void PrintResult()//Select문으로 가져온 데이터 접근하는 방법
{
	SQLINTEGER id, salary, manager_id, department_id;
	SQLCHAR first_name[20], last_name[25], email[25], phone[20], job[10];


	SQLLEN i_id, i_salary, i_manager_id, i_department_id, i_first_name, i_last_name, i_email, i_phone, i_job;

	//select 질의 수행 결과를 저장할 변수를 지정한다.(Column Number는 1부터 시작한다)

	SQLBindCol(hStmt, 1, SQL_INTEGER, &id, sizeof(id), &i_id);
	SQLBindCol(hStmt, 2, SQL_CHAR, first_name, sizeof(first_name), &i_first_name);
	SQLBindCol(hStmt, 3, SQL_CHAR, last_name, sizeof(last_name), &i_last_name);
	SQLBindCol(hStmt, 4, SQL_CHAR, email, sizeof(email), &i_email);
	SQLBindCol(hStmt, 5, SQL_CHAR, phone, sizeof(phone), &i_phone);
	SQLBindCol(hStmt, 6, SQL_CHAR, job, sizeof(job), &i_job);
	SQLBindCol(hStmt, 7, SQL_INTEGER, &salary, sizeof(salary), &i_salary);
	SQLBindCol(hStmt, 8, SQL_INTEGER, &manager_id, sizeof(manager_id), &i_manager_id);
	SQLBindCol(hStmt, 9, SQL_INTEGER, &department_id, sizeof(department_id), &i_department_id);
	//질의 수행결과를 hStmt로 가져온다. 이때, 바인딩된 변수에 값이 할당된다.
	while (SQLFetch(hStmt) != SQL_NO_DATA)
	{
		cout << id << ' ' << first_name << ' ' << last_name << ' ' << email << ' ' << phone << ' ' << job << ' ' << salary << ' ' << manager_id << ' ' << department_id << endl;
	}

	//hStmt 커서 해제
	if (hStmt)
		SQLCloseCursor(hStmt);

}


bool InsertJob(SQLCHAR* job_id, SQLCHAR* job_name, SQLINTEGER min_salary, SQLINTEGER max_salary)
{
	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, job_id, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, job_name, 0, NULL);
	SQLBindParameter(hStmt, 3, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &min_salary, 0, NULL);
	SQLBindParameter(hStmt, 4, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &max_salary, 0, NULL);

	if (DBExecuteSQL())
		return true;
	return false;
}

void InsertTest() //Insert질의 테스트
{
	DBPrepare((SQLCHAR*)"insert into jobs_copy values(?,?,?,?)");

	InsertJob((SQLCHAR*)"CP_EN", (SQLCHAR*)"Computer Engineer", 20000, 60000);
	InsertJob((SQLCHAR*)"AT_PT", (SQLCHAR*)"Artist Painter", 10000, 80000);
}

void first_name()
{
	SQLCHAR* first_name;
	string first;
	cout << "first_name을 입력하시오 : ";
	cin >> first;
	first_name = (SQLCHAR*)first.c_str();

	DBPrepare((SQLCHAR*)"select employee_id, first_name, last_name, email, phone_number, job_id, salary, manager_id, department_id from Employees_copy where first_name = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, first_name, 0, NULL);

	DBExecuteSQL();
	PrintResult();
	cout << endl;
}
void last_name()
{
	SQLCHAR* last_name;
	string last;
	cout << "last_name을 입력하시오 : ";
	cin >> last;
	last_name = (SQLCHAR*)last.c_str();

	DBPrepare((SQLCHAR*)"select employee_id, first_name, last_name, email, phone_number, job_id, salary, manager_id, department_id from Employees_copy where last_name = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, last_name, 0, NULL);

	DBExecuteSQL();
	PrintResult();
	cout << endl;
}
void special()
{
	SQLCHAR* name;
	string character;
	cout << "검색할 키워드를 입력하시오 : ";
	cin >> character;
	character = "%" + character + "%";
	name = (SQLCHAR*)character.c_str();

	DBPrepare((SQLCHAR*)"select employee_id, first_name, last_name, email, phone_number, job_id, salary, manager_id, department_id from Employees_copy where first_name like ? or last_name like ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, name, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, name, 0, NULL);

	DBExecuteSQL();
	PrintResult();
	cout << endl;
}
void department_search()
{
	SQLCHAR* department;
	string dep;
	SQLCHAR* last_name;
	string last;

	cout << "검색할 부서명을 입력하시오 : ";
	cin >> dep;
	cout << "검색할 사람의 last_name을 입력하시오 : ";
	cin >> last;

	department = (SQLCHAR*)dep.c_str();
	last_name = (SQLCHAR*)last.c_str();

	DBPrepare((SQLCHAR*)"select e.employee_id, e.first_name, e.last_name, e.email, e.phone_number, e.job_id, e.salary, e.manager_id, e.department_id from Employees_copy e, Departments_copy d where e.department_id = d.department_id and d.department_name = ? and e.last_name = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, department, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, last_name, 0, NULL);

	DBExecuteSQL();
	PrintResult();
	cout << endl;
}
void search_min_max()
{
	SQLCHAR* department;
	string dep;

	cout << "검색할 부서명을 입력하시오 : ";
	cin >> dep;

	department = (SQLCHAR*)dep.c_str();

	DBPrepare((SQLCHAR*)"select * from(select e.employee_id, e.first_name, e.last_name, e.email, e.phone_number, e.job_id, e.salary, e.manager_id, e.department_id from Employees_copy e, departments_copy d where e.department_id = d.department_id and d.department_name = ? order by e.salary desc) where rownum < 4 union all select * from(select e.employee_id, e.first_name, e.last_name, e.email, e.phone_number, e.job_id, e.salary, e.manager_id, e.department_id from Employees_copy e, Departments_copy d where e.department_id = d.department_id and d.department_name = ? order by e.salary) where rownum < 4");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, department, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, department, 0, NULL);

	DBExecuteSQL();
	PrintResult();
	cout << endl;
}
void modify_salary()
{
	SQLINTEGER employee_id;
	int emp;
	SQLINTEGER employee_salary;
	int sal;

	cout << "검색할 사원 id를 입력하시오 : ";
	cin >> emp;
	cout << "salary를 입력하시오 : ";
	cin >> sal;

	employee_id = (SQLINTEGER)emp;
	employee_salary = (SQLINTEGER)sal;

	DBPrepare((SQLCHAR*)"update Employees_copy set salary = ? where employee_id = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &employee_salary, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &employee_id, 0, NULL);

	DBExecuteSQL();

	cout << "수정완료" << endl;
	PrintResult();

	cout << endl;
}
void move_department()
{
	SQLINTEGER employee_id;
	int emp;
	SQLINTEGER department_id;
	int dep;

	cout << "검색할 사원 id를 입력하시오 : ";
	cin >> emp;
	cout << "수정할 부서 id를 입력하시오 : ";
	cin >> dep;

	employee_id = (SQLINTEGER)emp;
	department_id = (SQLINTEGER)dep;

	DBPrepare((SQLCHAR*)"update Employees_copy set department_id = ? where employee_id = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &department_id, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &employee_id, 0, NULL);

	DBExecuteSQL();

	cout << "수정완료" << endl;
	PrintResult();

	cout << endl;
}
void modify_phonenum()
{
	SQLINTEGER employee_id;
	int emp;
	SQLCHAR* phone_number;
	string number;

	cout << "검색할 사원 id를 입력하시오 : ";
	cin >> emp;
	cout << "수정할 핸드폰 번호를 입력하시오 : ";
	cin >> number;

	employee_id = (SQLINTEGER)emp;
	phone_number = (SQLCHAR*)number.c_str();

	DBPrepare((SQLCHAR*)"update Employees_copy set phone_number = ? where employee_id = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, &phone_number, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &employee_id, 0, NULL);

	DBExecuteSQL();

	cout << "수정완료" << endl;
	PrintResult();

	cout << endl;
}

int main()
{
	if (DBConnect() == false)
	{
		cout << "접속 에러" << endl;
		return -1;
	}

	int select;

	while (1)
	{
		cout << "1.first_name 조회" << endl;
		cout << "2.last_name 조회" << endl;
		cout << "3.특정문자 포함 조회" << endl;
		cout << "4.부서소속 사원 조회" << endl;
		cout << "5.특정 부서 가장 적은 급여 받는 3명과 가장 많이 받는 3명 조회" << endl;
		cout << "6.salary 변경" << endl;
		cout << "7.부서이동" << endl;
		cout << "8.핸드폰 번호 수정" << endl;
		cout << "->";
		cin >> select;
		switch (select) {
		case 1:
			first_name();
			break;
		case 2:
			last_name();
			break;
		case 3:
			special();
			break;
		case 4:
			department_search();
			break;
		case 5:
			search_min_max();
			break;
		case 6:
			modify_salary();
			break;
		case 7:
			move_department();
			break;
		case 8:
			modify_phonenum();
			break;
		default:
			cout << "종료" << endl;
			DBDisConnect();
			return 0;
		}
	}
	DBDisConnect();
	return 0;
}

bool DBConnect() //데이터베이스 연결
{
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS)
		return false;
	if (SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)
		return false;
	if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) != SQL_SUCCESS)
		return false;
	if (SQLConnectA(hDbc, ODBC_Name, SQL_NTS, ODBC_ID, SQL_NTS, ODBC_PW, SQL_NTS) != SQL_SUCCESS)
		return false;
	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) != SQL_SUCCESS)
		return false;
	return true;
}
void DBDisConnect() //데이터베이스 연결 해제
{
	if (hStmt)
		SQLFreeHandle(SQL_HANDLE_STMT, hStmt); //statement핸들러 해제
	if (hDbc)
		SQLDisconnect(hDbc); //데이터베이스 연결 종료
	if (hDbc)
		SQLFreeHandle(SQL_HANDLE_DBC, hDbc); //데이터베이스 연결 핸들러 해제
	if (hEnv)
		SQLFreeHandle(SQL_HANDLE_ENV, hEnv); //데이터베이스 연결 환경 핸들러 해제
}
bool DBExecuteSQL()
{
	if (SQLExecute(hStmt) != SQL_SUCCESS)
		return false;
	return true;
}
bool DBPrepare(SQLCHAR* query_for_statement)
{
	if (SQLPrepareA(hStmt, query_for_statement, SQL_NTS) != SQL_SUCCESS)
		// 주어진 질의를 수행하는 odbc기반의 질의 수행함수임.
		return false;
	return true;
}

bool DBExecuteSQL(SQLCHAR* query) //질의 수행
{
	if (SQLExecDirectA(hStmt, query, SQL_NTS) != SQL_SUCCESS)
		return false;
	return true;
}