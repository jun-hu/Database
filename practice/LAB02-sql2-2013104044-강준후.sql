SELECT last_name, salary
FROM employees
WHERE salary>12000;

SELECT last_name, department_id
FROM employees
WHERE employee_id=176;

SELECT last_name, salary
FROM employees
WHERE salary<5000 OR salary>12000;

SELECT last_name, job_id, hire_date
FROM employees
WHERE hire_date > DATE '2007-02-20' AND hire_date < DATE '2007-05-01'
ORDER BY hire_date ASC;

SELECT last_name, department_id
FROM employees
WHERE department_id=20 OR department_id=50
ORDER BY last_name ASC;

SELECT last_name as "Employee" , salary as "Monthly Salary"
FROM employees
WHERE salary between 5000 and 12000
 and department_id in (20,50) ;

SELECT last_name, hire_date
FROM employees
WHERE to_char(hire_date,'YYYY') like 1994;

SELECT last_name, job_id
FROM employees
WHERE manager_id IS NULL;

SELECT last_name, salary, commission_pct
FROM employees
WHERE  NOT commission_pct IS NULL
ORDER BY salary desc, commission_pct desc;

SELECT last_name
FROM employees
WHERE  substr(last_name, 1,3) in ('a');

SELECT last_name
FROM employees
WHERE  last_name like '%a%' and  last_name like '%e';

SELECT last_name, job_id, salary
FROM employees
where job_id in ('SA_REP','ST_CLERK') and salary not in(2500,3500,7000);

SELECT last_name, salary, concat('0',to_char(commission_pct))
FROM employees
where to_char(commission_pct) like '.2'