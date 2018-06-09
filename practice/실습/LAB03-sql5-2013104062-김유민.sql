select MAX(salary) as "Maximim",MIN(salary) as "Minimum",SUM(salary) as "Sum",ROUND(AVG(salary)) as "Average"
from employees;

select job_id, MAX(salary) as "Maximim",MIN(salary) as "Minimum",SUM(salary) as "Sum",ROUND(AVG(salary)) as "Average"
from employees
group by job_id;

select job_id,COUNT(employee_id) as count
from employees
group by job_id;

select COUNT(distinct manager_id) as "Number of Managers"
from employees;

select MAX(salary) - MIN(salary) as difference
from employees;

select manager_id, MIN(salary) as "MIN(SALARY)"
from employees
where manager_id is not null
group by manager_id
having MIN(salary) >= 6000;

select d.department_name as "Name",d.location_id as "Location",COUNT(e.employee_id) as "Number of People", ROUND(AVG(e.salary),2) as "Salary"
from employees e, departments d
where e.department_id = d.department_id
group by d.department_name, d.location_id;

select COUNT(*) "TOTAL",
sum(decode(to_char(hire_date,'YYYY'),2005,1,0)) "2005",
sum(decode(to_char(hire_date,'YYYY'),2006,1,0)) "2006",
sum(decode(to_char(hire_date,'YYYY'),2007,1,0)) "2007",
sum(decode(to_char(hire_date,'YYYY'),2008,1,0)) "2008"
from employees;

select job_id as "Job",
sum(decode(department_id, 20, salary, 0)) as "Dept 20",
sum(decode(department_id, 50, salary, 0)) as "Dept 50",
sum(decode(department_id, 80, salary, 0)) as "Dept 80",
sum(decode(department_id, 90, salary, 0)) as "Dept 90",
sum(salary) as "Total"
from employees
group by job_id
