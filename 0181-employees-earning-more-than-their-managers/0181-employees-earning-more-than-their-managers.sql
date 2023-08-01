# Write your MySQL query statement below
SELECT name as Employee from Employee e where salary > (select salary from Employee where id=e.managerId);