# Write your MySQL query statement below
select e.unique_id, ee.name from employees ee left join employeeuni e   on ee.id=e.id; 