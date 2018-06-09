--answer------------------
select * from dictionary where comments like '%column information%';
select * from all_tbl_cols where table_name = 'EMPLOYEES'
-----------------------------
select *
from all_catalog
where owner='HR';

select table_name,column_name, data_type
from user_tab_columns
where table_name ='EMPLOYEES';

select view_name,text
from user_views;

select * from user_ind_columns
where table_name ='EMPLOYEES';

SELECT INDEX_NAME,INITIAL_EXTENT,DISTINCT_KEYS,
NUM_ROWS,LAST_ANALYZED
FROM USER_INDEXES
WHERE INDEX_NAME = 'EMP_DEPARTMENT_IX';INITIAL_EXTENT;

INSERT INTO EMPLOYEES (employee_id, first_name,
last_name, email, phone_number, hire_date,
job_id, salary, commission_pct, manager_id,
department_id)
VALUES (213, 'Tom', 'Smith', 'tsmith', '515.124.4567',
SYSDATE, 'AC_ACCOUNT', 6900, NULL, 205, 100);

SELECT INDEX_NAME,INITIAL_EXTENT,DISTINCT_KEYS,
NUM_ROWS, LAST_ANALYZED
FROM USER_INDEXES
WHERE INDEX_NAME = 'EMP_DEPARTMENT_IX';

ANALYZE INDEX EMP_DEPARTMENT_IX COMPUTE STATISTICS;

select * from user_tab_columns
where table_name ='EMPLOYEES';

