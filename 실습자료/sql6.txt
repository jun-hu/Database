select last_name,hire_date
from employees
where department_id =(select department_id
from employees
where last_name like 'Zlotkey') and last_name not like 'Zlotkey';

select employee_id, last_name,salary
from employees
where salary> (select avg(salary) from employees)
order by salary asc;

select employee_id, last_name
from employees
where department_id in (select department_id
from employees
where last_name like '%u%');

select last_name,employee_id,job_id
from employees natural join departments
where location_id=1700;

select last_name,salary
from employees 
where manager_id in (select employee_id
from employees
where last_name like 'King');

select department_id,last_name,job_id
from employees 
where department_id =(select department_id
from departments
where department_name like 'Executive');

select employee_id,last_name,salary
from employees 
where salary>(select avg(salary) from employees)
and  department_id in (select department_id
from employees where last_name like '%u%');

select employee_id, last_name, salary
from   employees
where  salary > (select avg(salary)
                 from   employees)
  and  department_id in (select department_id
                         from   departments
                         where  location_id in (select location_id
                                                from   locations
                                                where  country_id = 'US'));

select employee_id, last_name, salary, department_id
from   employees e1
where  salary >= all( select salary
                     from   employees e2
                     where  e1.department_id = e2.department_id)
order by department_id;

select e1.employee_id, e1.last_name, e1.salary, e1.department_id
from   employees e1 inner join (select department_id, max(salary) as getSalary
                                from   employees
                                group by department_id) e2
       on e1.salary = e2.getSalary and e1.department_id = e2.department_id
order by e1.department_id;

 select department_id, department_name
from   departments d
where  exists(select department_id
              from   employees e
              where  d.department_id = e.department_id);

--d.department_id=e.department_id를 만족하는 d의 department_id와 department_name 출력

select rownum, employee_id, last_name, salary
from   (select employee_id, last_name, salary
        from   employees
        order by salary asc)
where  rownum <= 5;








