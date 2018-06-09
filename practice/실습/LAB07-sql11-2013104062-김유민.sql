create sequence DEPT_ID_SEQ increment by 10 start with 200 maxvalue 1000 nocycle nocache;

select sequence_name, max_value, increment_by, last_number
from USER_SEQUENCES;

create index my_index on employees(department_id);

select * from user_indexes where table_name = 'DEPARTMENTS';

create view EMPLOYEES_VU as 
select employee_id,last_name as "EMPLOYEE",department_id
from employees;

select * from employees_vu;

select employee,department_id
from employees_vu;

create view "DEPT50" as
select employee_id,last_name as "EMPLOYEE",department_id
from employees
with read only;

update "DEPT50" set department_id = 80
where employee = 'Bell';