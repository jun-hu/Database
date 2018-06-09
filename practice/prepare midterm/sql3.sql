--lpad n의 자릿수를 가진 문자열 형태로 오른쪽 정렬한다 나머지공간은 '*'로 채우면서
select lpad(first_name||' '||last_name,20,'*')
from employees;

--SELECT TRIM(' 테스트입니다 ') AS TRIM_ONE 
--           ,TRIM('다' FROM '다는 테스트입니다') AS TRIM_TWO
--           ,TRIM(BOTH '다' FROM '다는 테스트입니다') AS TRIM_THREE 
--           ,TRIM(LEADING '다' FROM '다는 테스트입니다') AS TRIM_FOUR
--           ,TRIM(TRAILING '다' FROM '다는 테스트입니다') AS TRIM_FIVE
--                                   FROM DUAL;
--replace(text,search_string,replacement_string)
select replace(last_name||' '||first_name,'ll','*****')
from employees;
--round(column,n) 값에 대해 소숫점 n번째 자리에서 반올림, -1이면 10의자리
--round(column,n) 소숫점 n자리까지만 표기
select trunc(45.9256,3)
from dual;
--mod(m,n) m을 n으로 나눈 나머지 반환
-- date-date= number of days date+number=date SYSDATE: 서버시간
select add_months(hire_date,168)
from employees;

--date-to_char->character-to_number->number-to_char->character-to_date->date
select last_name, to_char(hire_date,'yyyy year mm month mon dy day dd')
from employees;

select to_char(345234.235,'999,999.00')
from dual;

--TO_NUMBER(char[, 'format_model'])
--TO_DATE(char[, 'format_model'])
SELECT last_name, TO_CHAR(hire_date, 'DD－MON－YYYY')
FROM employees

--nvl(exp1,exp2) exp1이 널인 경우 exp2값을 반환 그렇지 않으면 exp1반환
--nvl2(exp1,exp2,exp3)expr1이널이아닌경우,NVL2는expr2를반환한다.expr1이널인경우,NVL2는expr3을반환한다.
--NULLIF(expr1, expr2)두표현식을비교하여동일한경우널을반환하고동일하지않은경우첫번째표현식을반환한다.
--exp1,exp2의 데이터 형식은 일치해야한다.
--NVL(hire_date, to_date('01/01/97‘, ‘dd/mm/yy’))
WHERE hire_date < TO_DATE('01－01－90', 'DD－MM－RR');

SELECT first_name, LENGTH(first_name) "expr1",
last_name, LENGTH(last_name) "expr2",
NULLIF(LENGTH(first_name) , LENGTH(last_name) ) result
FROM employees;

--1
select distinct sysdate as "Data"
from employees;
--2
select employee_id,last_name,salary,1.15*salary as "New Salary"
from employees;
--3
select initcap(last_name) name , length(last_name) length
from employees
where substr(last_name,1,1) in ('J','A','M')
order by name asc;
--4
select last_name,  round(months_between(sysdate,hire_date)) month_worked 
from employees
order by month_worked;
--5
select last_name||' earn '||salary||' monthly but wants 
'||3*salary as "Dream Salaries"
from employees;
--6
select last_name, lpad(salary,15,'$') salary
from employees;
--7
select last_name,hire_date,
to_char(next_day(add_months(hire_date,6),'월요일')
,'"Monday the "ddspth" of "MONTH, YYYY') as "Review"
from employees;
--8
select last_name,hire_date, to_char(hire_date,'DAY') as "Day"
from employees
order by to_char(hire_date-1,'D');
--일요일이 기준이기때문에 -1해줘서 미뤄준다.
--9
select last_name,nvl2(to_char(commission_pct),0||to_char(commission_pct),'No Commission')as comm
from employees;
--nvl은 파라미터 형식이 다 일정해야 되므로 to char로 바꿔주는데 그 과정에서 0이 사라지기 때문에 0을 붙여줘야 한다.
--10
SELECT last_name, LPAD(' ', TRUNC(salary/1000), '*') "EMPLOYEES_AND_THEIR_SALARIES"
FROM employees
ORDER BY salary DESC;
--11
select first_name,
DECODE(job_id, 'AD_PRES', 'A',
               'ST_MAN',  'B',
               'IT_PROG', 'C',
               'SA_REP',  'D',
               'ST_CLERK','E', '0') as GRADE
from   employees;
--12
select first_name,
CASE job_id WHEN   'AD_PRES'  THEN 'A'
            WHEN   'ST_MAN'   THEN 'B'
            WHEN   'IT_PROG'  THEN 'C'
            WHEN   'SA_REP'   THEN 'D'
            WHEN   'ST_CLERK' THEN 'E' ELSE '0' END as GRADE
from   employees;

