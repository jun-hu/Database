select last_name,hire_date
from employees
where department_id = 
(select department_id from employees where last_name = 'Zlotkey')
and last_name <> 'Zlotkey';

select employee_id,last_name,salary
from employees
where salary >
(select AVG(salary) from employees)
order by salary;

select employee_id,last_name
from employees
where department_id in
(select department_id from employees where last_name like '%u%');

select last_name, department_id, job_id
from employees
where department_id in
(select department_id from departments where location_id = 1700);

select last_name,salary
from employees
where manager_id in
(select manager_id from employees where last_name = 'King');

select department_id, last_name, job_id
from employees
where department_id in
(select department_id from departments where department_name = 'Executive');

select employee_id,last_name,salary
from employees
where department_id in
(select department_id from employees where last_name like '%u%'
and salary > (select AVG(salary) from employees));

select employee_id, last_name, salary
from employees
where salary >
(select AVG(salary) from employees where department_id in
(select department_id from departments where location_id in
(select location_id from locations where country_id = 'US')));

select employee_id, last_name, salary, department_id
from employees a
where salary >= all (select salary from employees b where a.department_id = b.department_id)
order by department_id;

select a.employee_id, a.last_name, a.salary, a.department_id
from employees a, (select department_id, max(salary) as maxsalary from employees group by department_id) b
where a.salary = b.maxsalary and a.department_id = b.department_id
order by a.department_id;

select department_id, department_name
from departments d
where exists (select * from employees e where e.department_id = d.department_id);

select rownum, employee_id,last_name,salary
from (select * from employees order by salary) a
where rownum <= 5;