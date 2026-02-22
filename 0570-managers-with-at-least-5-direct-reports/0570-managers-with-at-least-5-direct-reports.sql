with cte as(
    select managerId, count(*) as cnt
    from employee
    group by managerId
)
select name
from employee emp join cte on emp.id = cte.managerId
where cnt >= 5;