create table DEPT
( ID NUMBER(7), NAME VARCHAR2(25));

create table DEPT
as 
(select *
from departments);

create table EMP
( ID number(7),
LAST_NAME VARCHAR(25),
FIRST_NAME VARCHAR(25),
DEPT_ID number(7));

alter table EMP
modify( LAST_NAME varchar2(50));

drop table emp;

create table EMPLOYEES2
as (select employee_id as ID, first_name as FIRST_NAME,
last_name as LAST_NAME, salary as SALARY,
department_id as DEPT_ID
from Employees);

rename EMPLOYEES2 to EMP;

alter table emp
drop (first_name);