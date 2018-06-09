select salary from employees where last_name = 'Bell';

update employees set salary = 5000 where last_name = 'Bell';

select salary from employees where last_name = 'Bell';

ROLLBACK;

select salary from employees where last_name = 'Bell';

update employees set salary = 5000 where last_name = 'Bell';

SAVEPOINT Salary5000;

update employees set salary = 7000 where last_name = 'Bell';

select salary from employees where last_name = 'Bell';

ROLLBACK to Salary5000;

select salary from employees where last_name = 'Bell';

COMMIT;

select salary from employees where last_name = 'Bell';