create table cpy_emp as
select *
from employees;

insert into cpy_emp
values(300,'Ralph','Patel','Rpatel',null,SYSDATE,'SA_MAN',null,null,null,null);

insert into cpy_emp(employee_id,first_name,last_name,email,phone_number,hire_date,job_id,salary,commission_pct,manager_id,department_id)
values(301,'Dancs','Betty','Bdancs',null,SYSDATE,'SA_SEP',null,null,null,null);

update cpy_emp
set last_name = 'Drexler'
where employee_id = 301;

update cpy_emp
set phone_number = (select phone_number from cpy_emp where last_name = 'Jones'),
salary = (select salary from cpy_emp where last_name = 'Jones'),
commission_pct = (select commission_pct from cpy_emp where last_name = 'Jones'),
manager_id = (select manager_id from cpy_emp where last_name = 'Jones'),
department_id = (select department_id from cpy_emp where last_name = 'Jones')
where employee_id = 300 or employee_id = 301;

update cpy_emp
set salary = 3000
where salary < 3000;

delete from cpy_emp
where last_name = 'Drexler' and first_name = 'Dancs';