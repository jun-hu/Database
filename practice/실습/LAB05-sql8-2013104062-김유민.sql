create table DEPT(ID number(7),NAME varchar2(25));

insert into dept
select department_id,department_name from departments;

create table emp(id number(7),last_name varchar2(25),first_name varchar2(25),dept_id number(7));

alter table emp
modify(last_name varchar2(50));

drop table emp;

create table employees2(id,first_name,last_name,salary,dept_id) as
select employee_id,first_name,last_name,salary,department_id
from employees;

RENAME employees2 to emp;

alter table emp
drop (first_name);