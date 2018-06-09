alter table emp
add constraint my_emp_id_pk primary key(id);

alter table dept
add constraint my_dept_id_pk primary key(id);

alter table emp
add constraint my_emp_dept_id_fk foreign key(dept_id) references departments(department_id);

select constraint_name,constraint_type,search_condition
from user_constraints
where table_name = 'EMP' or table_name = 'DEPT';

alter table emp
add (COMMISSION number(4,2));
alter table emp
add constraint commission_ck check(COMMISSION > 0);