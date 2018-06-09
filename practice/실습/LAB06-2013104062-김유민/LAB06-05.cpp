#include <Windows.h>
#include <iostream>
#include <sql.h>
#include <sqlext.h>
#include<string>
using namespace std;


void PrintResult()//Select문으로 가져온 데이터 접근하는 방법
{
	SQLINTEGER id,salary,manager_id,department_id;
	SQLCHAR first_name[20],last_name[25],email[25],phone[20],job[10];


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
		cout << id << ' ' << first_name << ' ' << last_name << ' ' << email << ' ' << phone << ' ' << job << ' '<< salary << ' '<< manager_id << ' ' <<department_id << endl;
	}

	//hStmt 커서 해제
	if (hStmt)
		SQLCloseCursor(hStmt);

}


void menu1()
{
	SQLCHAR* first_name;
	string first;
	cout << "FIRST_NAME을 입력하시오 : ";
	cin >> first;
	first_name = (SQLCHAR*)first.c_str();

	DBPrepare((SQLCHAR*)"select employee_id, first_name, last_name, email, phone_number, job_id, salary, manager_id, department_id from \"Employees_copy\" where first_name = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, first_name, 0, NULL);
	
	DBExecuteSQL();
	PrintResult();
	cout << endl;
}
void menu2()
{
	SQLCHAR* last_name;
	string last;
	cout << "LAST_NAME을 입력하시오 : ";
	cin >> last;
	last_name = (SQLCHAR*)last.c_str();

	DBPrepare((SQLCHAR*)"select employee_id, first_name, last_name, email, phone_number, job_id, salary, manager_id, department_id from \"Employees_copy\" where last_name = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, last_name, 0, NULL);

	DBExecuteSQL();
	PrintResult();
	cout << endl;
}
void menu3()
{
	SQLCHAR* name;
	string character;
	cout << "검색할 문자를 입력하시오 : ";
	cin >> character;
	character = "%" + character + "%";
	name = (SQLCHAR*)character.c_str();

	DBPrepare((SQLCHAR*)"select employee_id, first_name, last_name, email, phone_number, job_id, salary, manager_id, department_id from \"Employees_copy\" where first_name like ? or last_name like ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, name, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, name, 0, NULL);

	DBExecuteSQL();
	PrintResult();
	cout << endl;
}
void menu4()
{
	SQLCHAR* department;
	string dep;
	SQLCHAR* last_name;
	string last;

	cout << "검색할 부서명을 입력하시오 : ";
	cin >> dep;
	cout << "검색할 사람의 LAST_NAME을 입력하시오 : ";
	cin >> last;

	department = (SQLCHAR*)dep.c_str();
	last_name = (SQLCHAR*)last.c_str();

	DBPrepare((SQLCHAR*)"select e.employee_id, e.first_name, e.last_name, e.email, e.phone_number, e.job_id, e.salary, e.manager_id, e.department_id from \"Employees_copy\" e, \"Departments_copy\" d where e.department_id = d.department_id and d.department_name = ? and e.last_name = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, department, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, last_name, 0, NULL);

	DBExecuteSQL();
	PrintResult();
	cout << endl;
}
void menu5()
{
	SQLCHAR* department;
	string dep;

	cout << "검색할 부서명을 입력하시오 : ";
	cin >> dep;

	department = (SQLCHAR*)dep.c_str();

	DBPrepare((SQLCHAR*)"select * from(select e.employee_id, e.first_name, e.last_name, e.email, e.phone_number, e.job_id, e.salary, e.manager_id, e.department_id from \"Employees_copy\" e, \"Departments_copy\" d where e.department_id = d.department_id and d.department_name = ? order by e.salary desc) where rownum < 4 union all select * from(select e.employee_id, e.first_name, e.last_name, e.email, e.phone_number, e.job_id, e.salary, e.manager_id, e.department_id from \"Employees_copy\" e, \"Departments_copy\" d where e.department_id = d.department_id and d.department_name = ? order by e.salary) where rownum < 4");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, department, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, department, 0, NULL);

	DBExecuteSQL();
	PrintResult();
	cout << endl;
}
void menu6()
{
	SQLINTEGER employee_id;
	int emp ;
	SQLINTEGER employee_salary;
	int sal;

	cout << "검색할 사원 아이디를 입력하시오 : ";
	cin >> emp;
	cout << "수정할 봉급액을 입력하시오 : ";
	cin >> sal;

	employee_id = (SQLINTEGER)emp;
	employee_salary = (SQLINTEGER)sal;

	DBPrepare((SQLCHAR*)"update \"Employees_copy\" set salary = ? where employee_id = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &employee_salary, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &employee_id, 0, NULL);

	DBExecuteSQL();
	
	cout << "수정완료" << endl;
	PrintResult();

	cout << endl;
}
void menu7()
{
	SQLINTEGER employee_id;
	int emp;
	SQLINTEGER department_id;
	int dep;

	cout << "검색할 사원 아이디를 입력하시오 : ";
	cin >> emp;
	cout << "수정할 부서ID를 입력하시오 : ";
	cin >> dep;

	employee_id = (SQLINTEGER)emp;
	department_id = (SQLINTEGER)dep;

	DBPrepare((SQLCHAR*)"update \"Employees_copy\" set department_id = ? where employee_id = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &department_id, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &employee_id, 0, NULL);

	DBExecuteSQL();

	cout << "수정완료" << endl;
	PrintResult();

	cout << endl;
}
void menu8()
{
	SQLINTEGER employee_id;
	int emp;
	SQLCHAR* phone_number;
	string number;

	cout << "검색할 사원 아이디를 입력하시오 : ";
	cin >> emp;
	cout << "수정할 핸드폰 번호를 입력하시오 : ";
	cin >> number;

	employee_id = (SQLINTEGER)emp;
	phone_number = (SQLCHAR*)number.c_str();

	DBPrepare((SQLCHAR*)"update \"Employees_copy\" set phone_number = ? where employee_id = ?");

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
		cout << "============사원 관리 프로그램=============" << endl;
		cout << "1. FIRST_NAME을 이용한 사원 조회 기능" << endl;
		cout << "2. LAST_NAME을 이용한 사원 조회 기능" << endl;
		cout << "3. 이름(FIRST_NAME 혹은 LAST_NAME)에 특정 문자가 포함된 사원 조회 기능" << endl;
		cout << "4. 부서의 이름을 기준으로 부서 소속의 사원 조회 기능" << endl;
		cout << "5. 특정 부서에서 가장 적은 급여의 사원 3명과 가장 많은 급여의 3명을 조회하는 기능" << endl;
		cout << "6. 사원의 SALARY의 변경하는 기능" << endl;
		cout << "7. 사원의 부서 이동" << endl;
		cout << "8. 사원의 핸드폰 번호 수정" << endl;
		cout << "0. EXIT" << endl;
		cout << "===========================================" << endl;
		cout << "기능 선택 (기능에 해당하는 숫자를 입력하시오) : ";
		cin >> select;
		switch (select) {
		case 1:
			menu1();
			break;
		case 2:
			menu2();
			break;
		case 3:
			menu3();
			break;
		case 4:
			menu4();
			break;
		case 5:
			menu5();
			break;
		case 6:
			menu6();
			break;
		case 7:
			menu7();
			break;
		case 8:
			menu8();
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
