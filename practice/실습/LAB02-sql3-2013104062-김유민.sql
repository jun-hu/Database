select sysdate "Date"
from dual;

select employee_id, last_name as name, salary, ROUND(salary*1.15) as "New Salary"
from employees;

select last_name as name,LENGTH(last_name) as length
from employees
where SUBSTR(last_name,1,1) in ('J','A','M')
order by last_name

select last_name as name, ROUND(MONTHS_BETWEEN(SYSDATE,hire_date)) as months_worked
from employees
order by months_worked;

select last_name || ' earns' || TO_CHAR(salary,'fm$99,999.00') || ' monthly but wants ' || TO_CHAR(salary*3,'fm$99,999.00') || '.' as "Dream Salaries"
from employees;

select last_name as name, LPAD(salary,15,'$') as salary
from employees;

select last_name as name, hire_date, TO_CHAR(NEXT_DAY(ADD_MONTHS(hire_date,6),'¿ù¿äÀÏ'),'DAY, "the" Ddspth "of" MONTH, YYYY') as review
from employees;

select last_name as name, hire_date, TO_CHAR(hire_date,'DAY') as "DAY"
from employees
order by TO_CHAR(hire_date-1,'d');

select last_name as name, NVL(TO_CHAR(commission_pct),'No Commission') as COMM
from employees;

select last_name || ' ' || rpad(' ',salary/1000+1,'*') as employees_and_their_salaries
from employees
order by salary desc;

select job_id, decode(job_id, 'AD_PRES','A','ST_MAN','B','IT_PROG','C','SA_REP','D','ST_CLERK','E','G') as grade
from employees;

select job_id, case job_id when 'AD_PRES' then 'A' when 'ST_MAN' then 'B' when 'IT_PROG' then 'C' when 'SA_REP' then 'D' when 'ST_CLERK' then 'E' else 'G' end as grade
from employees;