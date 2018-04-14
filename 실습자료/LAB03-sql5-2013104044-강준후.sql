select max(salary) as Maximum,min(salary) as Minimum,sum(salary) as Sum,round(avg(salary)) as Average
from employees;

select job_id, max(salary) as Maximum,min(salary) as Minimum,sum(salary) as Sum,round(avg(salary)) as Average
from employees
group by job_id;

select job_id ,count(job_id)
from employees
group by job_id;

select count(distinct manager_id)as "Number of Managers"
from employees;

select (Max(salary)-Min(salary)) as "DIFFERENCE"
from employees;

select e.manager_id, min(salary)
from employees e
where manager_id is not null and salary>=6000
group by e.manager_id
order by min(salary) desc;

select d.department_name "Name",d.location_id "Location"
,count(e.employee_id) as "Number of People"
,round(avg(e.salary),2) "Salary"
from employees e, departments d
where e.department_id = d.department_id
group by d.department_name,d.location_id
;

select count(*) as "TOTAL",
       sum(decode(to_char(hire_date, 'yyyy'), 2005, 1, 0)) as "2005",
       sum(decode(to_char(hire_date, 'yyyy'), 2006, 1, 0)) as "2006",
       sum(decode(to_char(hire_date, 'yyyy'), 2007, 1, 0)) as "2007",
       sum(decode(to_char(hire_date, 'yyyy'), 2008, 1, 0)) as "2008"
from   employees;

select job_id as "Job",
       sum(decode(department_id, 20, salary, 0)) as "Dept 20",
       sum(decode(department_id, 50, salary, 0)) as "Dept 50",
       sum(decode(department_id, 80, salary, 0)) as "Dept 80",
       sum(decode(department_id, 90, salary, 0)) as "Dept 90",
       sum(salary) as Total 
from   employees
group by job_id;
