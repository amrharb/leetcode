with cte as
(
    select name, bonus
    from employee e left join bonus b
    on e.empId = b.empId
)

select *
from cte
where bonus is null or bonus < 1000;