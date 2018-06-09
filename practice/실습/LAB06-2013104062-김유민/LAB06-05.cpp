#include <Windows.h>
#include <iostream>
#include <sql.h>
#include <sqlext.h>
#include<string>
using namespace std;


void PrintResult()//Select������ ������ ������ �����ϴ� ���
{
	SQLINTEGER id,salary,manager_id,department_id;
	SQLCHAR first_name[20],last_name[25],email[25],phone[20],job[10];


	SQLLEN i_id, i_salary, i_manager_id, i_department_id, i_first_name, i_last_name, i_email, i_phone, i_job;

	//select ���� ���� ����� ������ ������ �����Ѵ�.(Column Number�� 1���� �����Ѵ�)

	SQLBindCol(hStmt, 1, SQL_INTEGER, &id, sizeof(id), &i_id);
	SQLBindCol(hStmt, 2, SQL_CHAR, first_name, sizeof(first_name), &i_first_name);
	SQLBindCol(hStmt, 3, SQL_CHAR, last_name, sizeof(last_name), &i_last_name);
	SQLBindCol(hStmt, 4, SQL_CHAR, email, sizeof(email), &i_email);
	SQLBindCol(hStmt, 5, SQL_CHAR, phone, sizeof(phone), &i_phone);
	SQLBindCol(hStmt, 6, SQL_CHAR, job, sizeof(job), &i_job);
	SQLBindCol(hStmt, 7, SQL_INTEGER, &salary, sizeof(salary), &i_salary);
	SQLBindCol(hStmt, 8, SQL_INTEGER, &manager_id, sizeof(manager_id), &i_manager_id);
	SQLBindCol(hStmt, 9, SQL_INTEGER, &department_id, sizeof(department_id), &i_department_id);
	//���� �������� hStmt�� �����´�. �̶�, ���ε��� ������ ���� �Ҵ�ȴ�.
	while (SQLFetch(hStmt) != SQL_NO_DATA)
	{
		cout << id << ' ' << first_name << ' ' << last_name << ' ' << email << ' ' << phone << ' ' << job << ' '<< salary << ' '<< manager_id << ' ' <<department_id << endl;
	}

	//hStmt Ŀ�� ����
	if (hStmt)
		SQLCloseCursor(hStmt);

}


void menu1()
{
	SQLCHAR* first_name;
	string first;
	cout << "FIRST_NAME�� �Է��Ͻÿ� : ";
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
	cout << "LAST_NAME�� �Է��Ͻÿ� : ";
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
	cout << "�˻��� ���ڸ� �Է��Ͻÿ� : ";
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

	cout << "�˻��� �μ����� �Է��Ͻÿ� : ";
	cin >> dep;
	cout << "�˻��� ����� LAST_NAME�� �Է��Ͻÿ� : ";
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

	cout << "�˻��� �μ����� �Է��Ͻÿ� : ";
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

	cout << "�˻��� ��� ���̵� �Է��Ͻÿ� : ";
	cin >> emp;
	cout << "������ ���޾��� �Է��Ͻÿ� : ";
	cin >> sal;

	employee_id = (SQLINTEGER)emp;
	employee_salary = (SQLINTEGER)sal;

	DBPrepare((SQLCHAR*)"update \"Employees_copy\" set salary = ? where employee_id = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &employee_salary, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &employee_id, 0, NULL);

	DBExecuteSQL();
	
	cout << "�����Ϸ�" << endl;
	PrintResult();

	cout << endl;
}
void menu7()
{
	SQLINTEGER employee_id;
	int emp;
	SQLINTEGER department_id;
	int dep;

	cout << "�˻��� ��� ���̵� �Է��Ͻÿ� : ";
	cin >> emp;
	cout << "������ �μ�ID�� �Է��Ͻÿ� : ";
	cin >> dep;

	employee_id = (SQLINTEGER)emp;
	department_id = (SQLINTEGER)dep;

	DBPrepare((SQLCHAR*)"update \"Employees_copy\" set department_id = ? where employee_id = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &department_id, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &employee_id, 0, NULL);

	DBExecuteSQL();

	cout << "�����Ϸ�" << endl;
	PrintResult();

	cout << endl;
}
void menu8()
{
	SQLINTEGER employee_id;
	int emp;
	SQLCHAR* phone_number;
	string number;

	cout << "�˻��� ��� ���̵� �Է��Ͻÿ� : ";
	cin >> emp;
	cout << "������ �ڵ��� ��ȣ�� �Է��Ͻÿ� : ";
	cin >> number;

	employee_id = (SQLINTEGER)emp;
	phone_number = (SQLCHAR*)number.c_str();

	DBPrepare((SQLCHAR*)"update \"Employees_copy\" set phone_number = ? where employee_id = ?");

	SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_CHAR, SQL_CHAR, 0, 0, &phone_number, 0, NULL);
	SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, SQL_INTEGER, SQL_INTEGER, 0, 0, &employee_id, 0, NULL);

	DBExecuteSQL();

	cout << "�����Ϸ�" << endl;
	PrintResult();

	cout << endl;
}

int main()
{
	if (DBConnect() == false)
	{
		cout << "���� ����" << endl;
		return -1;
	}
	int select;

	while (1)
	{
		cout << "============��� ���� ���α׷�=============" << endl;
		cout << "1. FIRST_NAME�� �̿��� ��� ��ȸ ���" << endl;
		cout << "2. LAST_NAME�� �̿��� ��� ��ȸ ���" << endl;
		cout << "3. �̸�(FIRST_NAME Ȥ�� LAST_NAME)�� Ư�� ���ڰ� ���Ե� ��� ��ȸ ���" << endl;
		cout << "4. �μ��� �̸��� �������� �μ� �Ҽ��� ��� ��ȸ ���" << endl;
		cout << "5. Ư�� �μ����� ���� ���� �޿��� ��� 3��� ���� ���� �޿��� 3���� ��ȸ�ϴ� ���" << endl;
		cout << "6. ����� SALARY�� �����ϴ� ���" << endl;
		cout << "7. ����� �μ� �̵�" << endl;
		cout << "8. ����� �ڵ��� ��ȣ ����" << endl;
		cout << "0. EXIT" << endl;
		cout << "===========================================" << endl;
		cout << "��� ���� (��ɿ� �ش��ϴ� ���ڸ� �Է��Ͻÿ�) : ";
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
			cout << "����" << endl;
			DBDisConnect();
			return 0;
		}
	}

	DBDisConnect();
	return 0;
}
