SELECT SYSDATE as DATA
FROM employees;

SELECT employee_id, last_name, salary, salary*1.15 as "New Salary"
FROM employees;

SELECT last_name as name, length(last_name) as name_length
FROM employees
where SUBSTR(last_name,1,1) in ('A','J','M')
order by last_name ASC;

SELECT last_name, Round((SYSDATE-hire_date)/30) as MONTHS_WORKED
FROM employees
order by (SYSDATE-hire_date)/30;

select last_name||' earn '||salary||' monthly but wants '||3*salary as "Dream Salaries"
from employees;

select last_name, LPAD(salary,15,'$') as SALARY
from employees;

select last_name, hire_date, to_char(NEXT_DAY(ADD_MONTHS(hire_date,6),'¿ù¿äÀÏ'), '"Monday the "ddspth" of "MONTH, SYYYY') as "REVIEW"
from employees; 

SELECT first_name, hire_date, TO_CHAR(hire_date, 'DAY') as "DAY"
FROM employees
ORDER BY TO_CHAR(hire_date - 1, 'D');

SELECT last_name, NVL2(TO_CHAR(commission_pct), '0' || TO_CHAR(commission_pct), 'No Commission') "COMM"
FROM employees;

SELECT last_name, NVL(LPAD('*', TRUNC(salary/1000), '*'),' ') "EMPLOYEES_AND_THEIR_SALARIES"
FROM employees
ORDER BY salary DESC;

SELECT DECODE(job_id, 'AD_PRES', 'A', 
                    'ST_MAN', 'B',
                    'IT_PROG', 'C', 
                    'SA_REP', 'D',
                    'ST_CLERK', 'E',
                    '0')
FROM employees;

SELECT CASE job_id WHEN 'AD_PRES'  THEN 'A' 
                  WHEN 'ST_MAN'   THEN 'B'
                  WHEN 'IT_PROG'  THEN 'C' 
                  WHEN 'SA_REP'   THEN 'D'
                  WHEN 'ST_CLERK' THEN 'E'
                  ELSE '0'
      END
FROM employees;