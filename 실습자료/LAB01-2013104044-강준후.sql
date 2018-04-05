SELECT employee_id, last_name, salary*12 "ANNUAL SALARY"
FROM employees;

SELECT * FROM DEPARTMENTS;

SELECT employee_id, first_name||' '||last_name "NAME",job_id,hire_date AS "STARTDATE"
FROM employees;

SELECT first_name||' '||last_name||', '||job_id AS "Employee and Title"
FROM employees

substr(last_name, 1, 1) in ('a','b','c')
라스트네임에 첫번째 문자가 