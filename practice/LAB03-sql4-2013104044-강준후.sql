select e.last_name, e.department_id, d.department_name
from   employees e INNER JOIN departments d
       on e.department_id = d.department_id;


select distinct e.job_id, d.location_id 
from   employees e INNER JOIN departments d
       on e.department_id = 80;


select e.last_name, d.department_name, d.location_id,l.city
from employees e, departments d, locations l
where e.department_id=d.department_id 
and d.location_id=l.location_id
and e.commission_pct is not null;

select e.last_name, d.department_name
from employees e, departments d
where e.last_name like '%a%'
and e.department_id=d.department_id;

select e.last_name,e.job_id,e.department_id,d.department_name
from employees e, departments d, locations l
where l.city like 'Toronto'
and e.department_id=d.department_id
and d.location_id=l.location_id;

select e1.first_name as Employee, e1.employee_id as Emp#,
       e2.first_name as Manager, e2.employee_id as Mgr#
from   employees e1 left outer join employees e2
       on e1.manager_id = e2.employee_id;



select e1.department_id as DEPARTMENT, e1.last_name as EMPLOYEE,
       e2.last_name as COLLEAGUE
from   employees e1 inner join employees e2
       on e1.department_id = e2.department_id
where  not(e1.last_name = e2.last_name) 
order  by DEPARTMENT, EMPLOYEE, COLLEAGUE asc;


select e.last_name, e.hire_date
from employees e
where  hire_date >=
     ( select hire_date
       from   employees
       where  last_name = 'Davies' );



select e.last_name, e.hire_date, man.last_name, man.hire_date
from employees e , employees man
where 
e.manager_id=man.employee_id
and e.hire_date<man.hire_date;
