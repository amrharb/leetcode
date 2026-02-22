with cte as
(
    select id,
           temperature,
           recordDate,
           lag(temperature) over (order by recordDate) as prev_temp,
           lag(recordDate) over (order by recordDate) as prev_date
    from weather
)
select Id
from cte
where temperature > prev_temp and datediff(recordDate, prev_date) = 1;