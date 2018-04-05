SELECT last_name, NVL(LPAD('*', TRUNC(salary/1000), '*'),' ') "EMPLOYEES_AND_THEIR_SALARIES"
FROM employees
ORDER BY salary DESC;