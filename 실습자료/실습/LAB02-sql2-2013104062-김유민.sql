SELECT last_name AS name, salary
FROM employees
WHERE salary >= 12000;

SELECT last_name AS name, department_id
FROM employees
WHERE employee_id = 176;

SELECT last_name AS name, salary
FROM employees
WHERE salary < 5000 OR salary > 12000;

SELECT last_name AS name, job_id, hire_date
FROM employees
WHERE hire_date < '1998-05-01' AND hire_date > '1998-02-20'
ORDER BY hire_date;

SELECT last_name AS name, department_id
FROM employees
WHERE department_id >= 20 AND department_id <= 50
ORDER BY name;

SELECT last_name AS Employee, salary AS "Monthly Salary"
FROM employees
WHERE (salary > 5000 AND salary < 12000) AND department_id IN (20,50);

SELECT last_name AS name, hire_date
FROM employees
WHERE hire_date like '1994%';

SELECT last_name AS name, job_id
FROM employees
WHERE manager_id is NULL;

select last_name as name,salary,salary*commission_pct as commission
from employees
where commission_pct is not null
order by salary desc, commission_pct desc;

select last_name as name
from employees
where last_name like '__a%';

select last_name as name
from employees
where last_name like '%a%' AND last_name like '%e%';

select last_name as name, job_id as job,salary
from employees
where job_id in ('SA_REP','ST_CLERK') and salary not in (2500,3500,7000);

select last_name as name,salary,salary*commission_pct as commission
from employees
where commission_pct = .2;