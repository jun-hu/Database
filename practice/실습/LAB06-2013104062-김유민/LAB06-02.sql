create table "Employees_copy" as select * from EMPLOYEES;
create table "Departments_copy" as select * from DEPARTMENTS;
create table "Countries_copy" as select * from COUNTRIES;
create table "Locations_copy" as select * from LOCATIONS;

select c.country_name,sum(e.salary) as "salary"
from countries c, employees e, locations l, departments d
where e.department_id = d.department_id and d.location_id = l.location_id
and l.country_id = c.country_id
group by c.country_name
order by "salary" desc;

select department_name,country_name,"salary"
from (select d.department_name, c.country_name, sum(e.salary) as "salary" 
from countries c, (select * from employees where salary >= 10000) e, locations l, departments d
where e.department_id = d.department_id and d.location_id = l.location_id
and l.country_id = c.country_id
group by c.country_name, d.department_name
order by "salary" desc)
where rownum < 3;

select * from employees where first_name like "%z%" or last_name like "%z%";

select e.employee_id,e.first_name
from employees e, departments d
where e.department_id = d.department_id and d.department_name = "Marketing"