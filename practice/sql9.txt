alter table emp
add constraint "my_emp_id_pk" primary key(ID);

alter table dept
add constraint "my_dept_id_pk" primary key(department_id);

alter table emp 
      add (constraint "my_emp_dept_id_fk" foreign key(DEPT_ID) references dept(department_id))

select *
from user_constraints
where table_name = 'EMP' or table_name = 'DEPT' ;

alter table emp 
      add (COMISSION number(4, 2));
alter table emp 
      add (constraint "commisoin_ck" check(COMISSION > 0));