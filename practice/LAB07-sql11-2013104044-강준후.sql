--1
create sequence DEPT_ID_SEQ
increment by 10
start with 200
maxvalue 1000;

--2
select sequence_name, max_value,increment_by,last_number
from user_sequences;

--3
create index f_dept_id on employees(DEPARTMENT_ID);

--4
select ix.index_name, ix.uniqueness
from USER_INDEXES ix;

--5
create view EMPLOYEES_VU as 
select EMPLOYEE_ID,FIRST_NAME,DEPARTMENT_ID
from employees;

--6
select * from employees_vu;

--7
select first_name, department_id from employees_vu;

--8
create view DEPT50 as
select EMPLOYEE_ID,FIRST_NAME,DEPARTMENT_ID
from employees
where DEPARTMENT_ID = 50
with read only;

--9
update "DEPT50" set department_id = 80
where employee = 'Bell';

