select last_name as name,e.department_id,d.department_name
from employees e,departments d
where e.department_id = d.department_id;

select distinct job_id,location_id
from employees e,departments d
where e.department_id = d.department_id
and e.department_id = 80;

select last_name as name, d.department_name,d.location_id,l.city
from employees e, departments d, locations l
where e.department_id = d.department_id
and d.location_id = l.location_id
and e.commission_pct is not null;

select last_name, department_name
from employees e, departments d
where e.department_id = d.department_id
and e.last_name like '%a%';

select e.last_name,e.job_id,d.department_id,d.department_name
from employees e JOIN departments d on (e.department_id = d.department_id),
locations l JOIN departments d2 on (l.location_id = d2.location_id)
where l.city = 'Toronto';

select e1.last_name as "Employee",e1.employee_id as "Emp#", e2.last_name as "Manager", e2.employee_id as "Mgr#"
from employees e1, employees e2
where e1.manager_id = e2.employee_id(+);

select emp.department_id as department,emp.last_name as employee,col.last_name as colleague
from employees emp, employees col
where emp.department_id = col.department_id
and emp.last_name <> col.last_name
order by emp.department_id,emp.last_name,col.last_name;

select e.last_name,e.hire_date
from employees e, employees davies
where e.hire_date > davies.hire_date and davies.last_name = 'Davies';

select emp.last_name,emp.hire_date,man.last_name,man.hire_date
from employees emp, employees man
where emp.manager_id = man.employee_id
and emp.hire_date < man.hire_date